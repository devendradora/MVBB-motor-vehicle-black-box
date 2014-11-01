<?php
$host = "localhost";
$myusername="root";
$mypassword="";
$tb_name="users";
$db_name="mvbb";

mysql_connect("$host", "$myusername", "$mypassword")or die("cannot connect"); 
mysql_select_db("$db_name")or die("cannot select DB");


$myusername=$_POST['myusername']; 
$mypassword=$_POST['mypassword']; 

$sql="SELECT * FROM $tb_name WHERE myusername='$myusername' and mypassword='$mypassword'";
$result=mysql_query($sql);

$count=mysql_num_rows($result);

if($count==1){
//session_register("myusername");
$_SESSION["myusername"] = $myusername;
//session_register("mypassword"); 
$_SESSION["mypassword"] = $mypassword;
header("location:graphplot/graph/barLineAnimated.php");
}
else {
echo "Wrong Username or Password";
}
?>
