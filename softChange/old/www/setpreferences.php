<?php
require_once 'softchange.php';


$year 	= $_POST['year'];
$month 	= $_POST['month'];
$day 	= $_POST['day'];
$year2 	= $_POST['year2'];
$month2 = $_POST['month2'];
$day2 	= $_POST['day2'];
$referer  = $_POST['referer'];

$developers1 = $_POST['developers1'];


$project = $_GET['project'];


if (!$developers1){
  $softChange = new Soft_Change($project);
  $softChange->Connect();
  $developerX = $softChange->Retrieve_Developers();
  $au = "any";
}
else{
  $developersX = implode("', '", $developers1);
  $au = $developersX;
}

$select_start = "$year-$month-$day";
$select_end  = "$year2-$month2-$day2";

$serverName = getenv("SERVER_NAME");

Setcookie("start_time", $select_start);
Setcookie("end_time", $select_end);
Setcookie("authorn", $developersX);


$start_time = $select_start;
$end_time = $select_end;
$authorn = $developersX;
$var1 = $referer;


echo "

<html>
<head>
<title>Untitled Document</title>
</head>




<BODY BGCOLOR=#FFFFFF TEXT=#000000>
<img src='art/softchange.gif'><br><img src='art/line.gif' width='600' height='4'>


<h3>Your Preference are</h3>
";


echo "
<ul>
<li>From: '$start_time' 
<li>To: '$end_time'
<li>Authors: $au
</ul>

To return click <a href='$referer'>here</a>

</body>
</html>
";
?>
