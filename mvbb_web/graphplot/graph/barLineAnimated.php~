<!DOCTYPE html>
<html>
<head>
<?php $page = $_SERVER['PHP_SELF'];
$sec = "5";?>
    <title>Animated Charts</title>
   <meta http-equiv="refresh" content="<?php echo $sec?>;URL='<?php echo $page?>'">
    <link class="include" rel="stylesheet" type="text/css" href="../jquery.jqplot.min.css" />
    <link rel="stylesheet" type="text/css" href="examples.min.css" />
    <link type="text/css" rel="stylesheet" href="syntaxhighlighter/styles/shCoreDefault.min.css" />
    <link type="text/css" rel="stylesheet" href="syntaxhighlighter/styles/shThemejqPlot.min.css" />
  
    <!--[if lt IE 9]><script language="javascript" type="text/javascript" src="../excanvas.js"></script><![endif]-->
    <script class="include" type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.9.1/jquery.min.js"></script>
    
   
</head>
<body>
    
<h1>Motor vehicle Black Box</h1>

  
<!-- Example scripts go here -->

    <div id="chart1" style="width:500px; height:200px"></div>
     <div id="chart2" style="width:500px; height:200px"></div>

    
   
 <script  type="text/javascript">
   //var s2=[(Math.random()*912)+523,(Math.random()*842)+323,(Math.random()*924)+635,(Math.random()*910)+530,(Math.random()*598)+875];
        
    $(document).ready(function () {
        var s1="<?php echo json_decode($enginbrk)?>";
         var s2="<?php echo json_decode($engin)?>";
      // var s1=[Math.floor((Math.random()*2)+1),Math.floor((Math.random()*2)),Math.floor((Math.random()*2)),Math.floor((Math.random()*2)),Math.floor((Math.random()*2))];
       

        plot1 = $.jqplot("chart1", [s1], {
            // Turns on animatino for all series in this plot.
            animate: true,
            // Will animate plot on calls to plot1.replot({resetAxes:true})
            animateReplot: true,
            cursor: {
                show: true,
                zoom: true,
                looseZoom: true,
                showTooltip: false
            },
            series:[
                {
                    pointLabels: {
                        show: true
                    },
                   // renderer: $.jqplot.BarRenderer,
                    showHighlight: false,
                   // yaxis: 'y2axis',
                    rendererOptions: {
                        // Speed up the animation a little bit.
                        // This is a number of milliseconds.  
                        // Default for bar series is 3000.  
                        animation: {
                            speed: 2500
                        },
                        barWidth: 15,
                        barPadding: -15,
                        barMargin: 0,
                        highlightMouseOver: false
                    }
                }, 
                {
                    rendererOptions: {
                        // speed up the animation a little bit.
                        // This is a number of milliseconds.
                        // Default for a line series is 2500.
                        animation: {
                            speed: 2000
                        }
                    }
                }
            ],
            axesDefaults: {
                pad: 0
            },
            axes: {
                // These options will set up the x axis like a category axis.
                xaxis: {
                    tickInterval: 1,
                    drawMajorGridlines: false,
                    drawMinorGridlines: true,
                    drawMajorTickMarks: false,
                    rendererOptions: {
                    tickInset: 0.5,
                    minorTicks: 1
                }
                },
                // yaxis: {
                //     tickOptions: {
                //         formatString: "$%'d"
                //     },
                //     rendererOptions: {
                //         forceTickAt0: true
                //     }
                // },
                y2axis: {
                    tickOptions: {
                        formatString: "%'d"
                    },
                    rendererOptions: {
                        // align the ticks on the y2 axis with the y axis.
                        alignTicks: true,
                        forceTickAt0: true
                    }
                }
            },
            highlighter: {
                show: true, 
                showLabel: true, 
                tooltipAxes: 'y',
                sizeAdjust: 7.5 , tooltipLocation : 'ne'
            }
        });
      
    });

$(document).ready(function () {
        //var s1="<?php echo json_decode($engin)?>";
      
       

        plot1 = $.jqplot("chart2", [s2], {
            // Turns on animatino for all series in this plot.
            animate: true,
            // Will animate plot on calls to plot1.replot({resetAxes:true})
            animateReplot: true,
            cursor: {
                show: true,
                zoom: true,
                looseZoom: true,
                showTooltip: false
            },
            series:[
                {
                    pointLabels: {
                        show: true
                    },
                   // renderer: $.jqplot.BarRenderer,
                    showHighlight: false,
                   // yaxis: 'y2axis',
                    rendererOptions: {
                        // Speed up the animation a little bit.
                        // This is a number of milliseconds.  
                        // Default for bar series is 3000.  
                        animation: {
                            speed: 2500
                        },
                        barWidth: 15,
                        barPadding: -15,
                        barMargin: 0,
                        highlightMouseOver: false
                    }
                }, 
                {
                    rendererOptions: {
                        // speed up the animation a little bit.
                        // This is a number of milliseconds.
                        // Default for a line series is 2500.
                        animation: {
                            speed: 2000
                        }
                    }
                }
            ],
            axesDefaults: {
                pad: 0
            },
            axes: {
                // These options will set up the x axis like a category axis.
                xaxis: {
                    tickInterval: 1,
                    drawMajorGridlines: false,
                    drawMinorGridlines: true,
                    drawMajorTickMarks: false,
                    rendererOptions: {
                    tickInset: 0.5,
                    minorTicks: 1
                }
                },
                // yaxis: {
                //     tickOptions: {
                //         formatString: "$%'d"
                //     },
                //     rendererOptions: {
                //         forceTickAt0: true
                //     }
                // },
                y2axis: {
                    tickOptions: {
                        formatString: "%'d"
                    },
                    rendererOptions: {
                        // align the ticks on the y2 axis with the y axis.
                        alignTicks: true,
                        forceTickAt0: true
                    }
                }
            },
            highlighter: {
                show: true, 
                showLabel: true, 
                tooltipAxes: 'y',
                sizeAdjust: 7.5 , tooltipLocation : 'ne'
            }
        });
      
    });


</script>
<!-- End example scripts -->

<!-- Don't touch this! -->


    <script class="include" type="text/javascript" src="../jquery.jqplot.min.js"></script>
    <script type="text/javascript" src="syntaxhighlighter/scripts/shCore.min.js"></script>
    <script type="text/javascript" src="syntaxhighlighter/scripts/shBrushJScript.min.js"></script>
    <script type="text/javascript" src="syntaxhighlighter/scripts/shBrushXml.min.js"></script>
<!-- Additional plugins go here -->

  <script class="include" type="text/javascript" src="../plugins/jqplot.barRenderer.min.js"></script>
  <script class="include" type="text/javascript" src="../plugins/jqplot.highlighter.min.js"></script>
  <script class="include" type="text/javascript" src="../plugins/jqplot.cursor.min.js"></script> 
  <script class="include" type="text/javascript" src="../plugins/jqplot.pointLabels.min.js"></script>

<!-- End additional plugins -->

       
    <script type="text/javascript" src="example.min.js"></script>

</body>
 


</html>

<?php      


//echo '<meta http-equiv="refresh" content='.$secURL.'='.$page.'>';
error_reporting(E_ALL);
ini_set('display_errors', '1');
include "php_serial.class.php";


// $read=array('0','0','0','0','0','date('Y-m-d H:i:s')');
$serial = new phpSerial;
$serial->deviceSet('/dev/ttyUSB0');
$serial->confBaudRate(9600);
$serial->confParity("none");
$serial->confCharacterLength(24);
$serial->confStopBits(1);
$serial->deviceOpen();
$serial->sendMessage("Welcome");
$read = $serial->readPort();

// $dev_e=$read[1];
// $dev_b=$read[2];
// $dev_a=$read[3];
// $dev_f=$read[4];
// $dev_g=$read[5];

$con=mysqli_connect('localhost','root','','mvbb');
// Check connection
if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
}


$e=array();
$count=0;
$result= mysqli_query($con,"SELECT * FROM vehicles order by 'timestamp'");
while($row = mysqli_fetch_array($result)) {
  echo "engine stat : ". $row['engine'] . "gear  :" . $row['gear']."";
  echo "seat belt :". $row['seatbelt'] . "acceleration :" . $row['acceleration']."";
  echo "engine stat". $row['timestamp'] ."<br>";

  echo "<br>";
    $e[$count]=$row['engine'];

}
mysqli_close($con);
$con2=mysqli_connect('localhost','root','','mvbb');
// Check connection
if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
}
mysqli_query($con2,"INSERT INTO vehicles VALUES ('0','1','1','0','1411','date('Y-m-d H:i:s')')");
mysqli_close($con2);

echo "Present serial data";
echo "Engine status ".$read[1]."<br>";
echo "Break status ".$read[2]."<br>";
echo "Seat Belt status ".$read[3]."<br>";
echo " fuel".$read[4]."<br>";

print($read);

$serial->deviceClose();


?>

