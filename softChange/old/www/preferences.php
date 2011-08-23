<?php


function Date_Field($fromYear, $toYear, $defaultYear,
	            $defaultMonth, $defaultDay,
		    $fieldNameYear, $fieldNameMonth, $fieldNameDay)
{
    $noYears = $toYear - $fromYear +1;

#echo "<h3>[$noYears]Yearfrom, to, default, $fromYear, $toYear, $defaultYear</h3>";
#echo "<h3>monty, day $defaultMonth, $defaultDay</h3>";

    echo "<select name=$fieldNameYear size=$noYears>\n";

    for ($i = 0; $i < $noYears; $i++) {
	$y = $fromYear+$i;
	if ($defaultYear  == $y) { 
	    $selected="SELECTED";
	} else {
	    $selected="";
	}
	echo "<option $selected value=\"$y\" >$y</option>\n";
    }
    echo "</select>\n";
    
## Month
#    
    echo "<select name=$fieldNameMonth size=12>\n";
    for ($m=1;$m<=12;$m++) {
	if ($defaultMonth  == $m) {
	    $selected="SELECTED";
	} else {
	    $selected="";
	}
	echo "<option $selected value=\"$m\">".date(M,mktime(0,0,0,$m,1,2000))."</option>\n";
    }
    echo "</select>\n";
    
    
    echo "<select name=$fieldNameDay size=15>\n";
    $default1c= $pieces1[2];
    for ($d=1;$d<=31;$d++) {
	if ($defaultDay  == $d) {
	    $selected="SELECTED";
	} else {
	    $selected="";
	}
	echo "<option $selected value='$d'>$d</option>\n";
    }
    echo "</select>\n";
#

}



echo "
<HTML>
<HEAD>
<TITLE>PREFERENCES </TITLE>
</HEAD>
<BODY BGCOLOR=#FFFFFF TEXT=#000000>
<img src='art/softchange.gif'><br><img src='art/line.gif' width='600' height='4'>

    <h1>Preference</h1>
";


$var = getenv("HTTP_REFERER");

$project = $_GET['project'];

require_once 'softchange.php';

$softChange = new Soft_Change($project);
$softChange->Connect();
$developers = $softChange->Retrieve_Developers();

echo "<FORM METHOD=POST ACTION=setpreferences.php>
<input type=hidden name=referer value=$var>
<br> 
<P><strong>Enter the time range. </strong>
<P> From 

"; 

if ($_COOKIE[start_time])
     $pieces1 = explode("-", $_COOKIE[start_time]);

if ($_COOKIE[end_time])
     $pieces2 = explode("-", $_COOKIE[end_time]);



$dates = $softChange->Retrieve_Min_Max_Date();

# set default for  FROM

$defaultYearFrom= $pieces1[0];

$yearMax  = $dates[0];
$monthMax = $dates[1];
$dayMax   = $dates[2];

$yearMin  = $dates[3];
$monthMin = $dates[4];
$dayMin   = $dates[5];

if ($defaultYearFrom < $yearMin) {
    $defaultYearFrom = $yearMin;
}

$defaultMonthFrom= $pieces1[1];
if ($defaultMonthFrom < $monthMin) {
    $defaultMonthFrom = $monthMin;
}

$defaultDayFrom= $pieces1[2];
if ($defaultDayFrom < $dayMin) {
    $defaultDayFrom = $dayMin;
}

# Set defaults for TO

$defaultYearTo= $pieces2[0];

if ($defaultYearTo < $yearMax) {
    $defaultYearTo = $yearMax;
}

$defaultMonthTo =  $pieces2[1];
if ($defaultMonthTo < $monthMax) {
    $defaultMonthTo = $monthMax;
}

$defaultDayTo= $pieces2[2];
if ($defaultDayTo < $dayMax) {
    $defaultDayTo = $dayMax;
}

if ($defaultYearFrom > $defaultYearTo) {
    $temp = $defaultYearFrom;
    $defaultYearFrom = $defaultYearTo;
    $defaultYearTo =$defaultYearFrom;
}


#echo "dates: $dates[0] $dates[1] $dates[2] $dates[3] $dates[4] $dates[5]\n";
#echo "Defaults: defaultDayTo $defaultDayTo<br>";
#echo "Defaults: defaultDayFrom $defaultDayFrom<br>";
#echo "Defaults: defaultYearTo $defaultYearTo<br>";
#echo "Defaults: defaultYearFrom $defaultYearFrom<br>";
#echo "Defaults: defaultMonthTo $defaultMonthTo<br>";
#echo "Defaults: defaultMonthFrom $defaultMonthFrom<br>";
#
#$softChange->Assert($dates[1] >= $yearMax, "year[1] >= year[0]");

# Fill year from

echo "From:";

Date_Field($yearMin, $yearMax, $defaultYearFrom,
	   $defaultMonthFrom, $defaultDayFrom,
	   'year', 'month','day');


echo " To: ";

Date_Field($yearMin, $yearMax, $defaultYearTo,
	   $defaultMonthTo, $defaultDayTo,
	   'year2', 'month2','day2');


echo "<h3>Select a developer</h3>";


if ($_COOKIE[authorn]) {
   $defaultD = explode ("\',\'",$_COOKIE[authorn]);
#  print_r($defaultD);
}
#print_r($developers);


echo "<select name=developers1[] multiple>\n";
foreach ($developers as $name) {
  print "'$name'\n";
  if (in_array(trim($name), $defaultD)){ 
     echo "<option value=$name selected>$name</option>\n"; }
      else{
	echo "<option value=$name>$name</option>\n";
      }
}

echo "</select>\n";
?>

    <input type="submit" name="submit" value="Set Disp Pref">
  </form>
</Body>
</HTML>


