<?php
session_start();
if(isset($_SESSION['myusername'])){
header("location:main_login.php");

$fp =fopen("/dev/ttyUSB0", "w+");

if( !$fp) {
        echo "Error";die();
}

fwrite($fp, $_SERVER['argv'][1] . 0x00);
echo fread($fp, 10);


fclose($fp);
}
?>


