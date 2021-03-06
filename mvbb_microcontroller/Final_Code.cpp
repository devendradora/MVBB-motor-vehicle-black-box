#include"main.h"
#include"timers.h"
#include"clcd.h"
#include "uart.h"
#include "adc.h"
#include"switch.h"


__CONFIG( DEBUG_OFF & LVP_OFF & FCMEN_OFF & IESO_OFF & BOREN_OFF & CPD_OFF & CP_OFF & MCLRE_ON & PWRTE_ON & WDTE_OFF & FOSC_HS);
__CONFIG(WRT_OFF & BOR4V_BOR40V);


int count = 0;//For Password Checking
int cursor = 0;//For Displaying Stars for Password Characters Entered


//Function to Introduce delay (while displaying characters on LCD)
void delay_ms(unsigned short cnt)
{
        unsigned short i, j;


        for(i = cnt; i--; )
        {
                for(j = 310; j--; );
        }
}


//Function to check if entered password is correct to authenticate the administrator
int pswd_chk(unsigned char switch_pressed)
{


        //Password = 1234
        if( (switch_pressed == 0x01 && count == 0) || (switch_pressed == 0x02 && count == 1) || (switch_pressed == 0x04 && count == 2)
                || (switch_pressed == 0x08 && count == 3) )
        { 
                       count++;//Count incremented if correct character is entereted
    }


//Function to display stars for password characters
               if(read_switches(0)!=0x00)
               {
                       clcd_putch('*', LINE2(cursor));
                       cursor++;
                       delay_ms(200);
//If 4 correct characters are entered the user is autenticated to see the logged information
                       if( count == 4)
                            return(1);//Correct Password entered
                        
                        if(cursor==4) 
                        {
                                cursor =0;
                                count =0;
                                clcd_print("Wrong Password", LINE1(0));
                                delay_ms(500);
                                clcd_print("               ", LINE2(0));
                        }
                }


                else 
                        return(0);
}


static void init_config(void)
{
        TRISA = 0xFF;
        TRISB = 0x01;
        TRISD = 0x00;
        init_adc();


        init_clcd();
        init_timer0();
        init_uart();
        
        GIE = 1;
        ANSELH = 0x00;


        //puts("Trying to send time... \n\r");
}


//Sends data through Serial Communication
void display(unsigned short seconds, unsigned short minutes)
{
        unsigned char i, value;


        //clcd_print("se-",LINE2(0));
        //clcd_print("mi-",LINE2(9));


        i = 0;
        do
        {
                value = seconds % 10;
                seconds = seconds / 10;
                clcd_putch(value + '0', LINE2(15 - i));
                //putch(value + '0');
        } while (i++ < 1);
        clcd_putch(':',LINE2(13));


        i = 0;
        do
        {         
                value = minutes % 10;
                minutes = minutes / 10;
                clcd_putch(value + '0', LINE2(12 - i));
                //putch(value + '0');
        } while (i++ < 1);
        puts("\r");
}






void main(void)
{


        unsigned short channel1, channel2;
        unsigned char Switch,a=0,b=0,c=0,d=0,e=0,value;
        unsigned short flag=0,eng=0, gear=0,seat=0,brk=0,Acc=0,i=0;


        init_config();        


   //Asks the user to enter the password
        clcd_print("Enter password", LINE1(0));


        while (flag == 0)
        {
                clcd_print("Enter password", LINE1(0));
                flag = pswd_chk(read_switches(1));
        }


    //Indicates that the user is authenticated
        clcd_print("                ", LINE1(0));
        clcd_print("                ", LINE2(0));
        clcd_print("Authenticated", LINE1(0));
        delay_ms(1000);


    //Simulating Engine ON/OFF with SW1
        //Assume the Engine is OFF initially 
        clcd_print("                ", LINE1(0));
        clcd_print("Engine OFF", LINE1(0));
        
        while(1)
        {
                Switch = read_switches(1);
                if(Switch == 0x01)
                        break;
        }
        
        //Indication of Engine Status
        clcd_print("Engine ON ", LINE1(0));
        
        //Display status of other parameters
        clcd_print("Stat0000", LINE2(0));
        
        while (1)
        {
                
                Switch = read_switches(0);
                if(Switch !=0x00)
                {
                        //eng = 0 Engine OFF and eng = 1
                        if(Switch == 0x01 && eng ==0)
                        {
                                clcd_print("                ", LINE1(0));
                                clcd_print("Engine ON", LINE1(0));
                                eng = 1;
                        }
                        
                        else if(Switch == 0x01 && eng ==1)
                        {
                                clcd_print("               ", LINE1(0));
                                clcd_print("Engine OFF", LINE1(0));
                                eng = 0;
                        }
                        
                        a = eng;
                        
                        //Gear Simulation using SW2(increase gear) and SW3(decrease gear)
                        if(eng==1)
                        {
                                if(Switch == 0x02)
                                {
                                        gear++;  //If SW2 is pressed increase the gear
                                        
                                        if(gear>5)
                                        gear = 5; //Maximum gear = 5
                                        
                                        b = gear;
                                        clcd_putch(b+'0', LINE2(4)); //Display on LCD
                            }


                                if(Switch == 0x04)
                                {
                                        if(gear!=0)gear--;//If SW3 is pressed decrease the gear
                                                                          //Minimum gear = 0
                                        
                                        b = gear;
                                        clcd_putch(b+'0', LINE2(4));//Display on LCD
                                }
                        
                                //Seat Belt Status Simulation
                                if(Switch == 0x08)
                                {        
                                        seat=!(seat);
                                        c = seat;
                                        clcd_putch(c+'0', LINE2(5));//Display on LCD                                
                                }


                                //Break Simulation
                                if(Switch == 0x10)
                                {
                                        brk=!(brk);
                                        d = brk;
                                        clcd_putch(d+'0', LINE2(6));//Display on LCD                                
                                }


                                
                                //Accident Simulation
                            if(Switch == 0x20)
                            {
                                        delay_ms(50);
                                        Acc=!(Acc);
                                        e = Acc;
                                        clcd_putch(e+'0', LINE2(7));//Display on LCD                                
                                }


                        }


                }
        
                puts("\n");
                putch(a+'0');
                putch(b+'0');
                putch(c+'0');
                putch(d+'0');
                putch(e+'0');


                channel2 = get_voltage(CHANNEL1);//For Speed Simulation (data obtained from a potentiometer)


                do
                {
                        value = channel2 % 10;
                        channel2 = channel2 / 10;
                        clcd_putch(value + '0', LINE1(15 - i));
                        putch(value + '0');
                } while (i++ < 3);
                
                i=0;
                //puts("pot- ");
                display(channel1, channel2);


#if 1
                //puts("time- ");
                display(seconds,minutes);//Display Time
#endif
                
                Switch = 0x00;
                delay_ms(100);
        }
}
