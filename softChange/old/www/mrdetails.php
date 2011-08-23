<?php


require_once 'softchange.php';

$project = $_GET['project'];
$operation = $_GET['operation'];
$name1 = $_POST['name1'];

$softChange = new Soft_Change($project);

if ( $_COOKIE[start_time]) 
$range1 = "AND mrs2.daterev >= '$_COOKIE[start_time]' AND mrs2.daterev <= '$_COOKIE[end_time]'";


if ( $_COOKIE[authorn]) {
$range2x = "AND author IN ('$_COOKIE[authorn]')";
$range2 =  stripslashes ($range2x);
}

if ($project == 'Gnumeric' || 
    $project == 'Evolution') {
   $bugzillaURL = 'http://bugzilla.gnome.org/show_bug.cgi?id=';
} else {
   $bugzillaURL = 'http://bugzilla.mozilla.org/show_bug.cgi?id=';
}

$serverName = getenv("SERVER_NAME");
#$serverName = "si.dmg";


if ($softChange->database() == "") {

  setcookie('pname', '');
  setcookie('start_time', "");
  setcookie('authorn', '');
  setcookie('end_time', '');

   echo "
   <ul>
   <li> <a href='index.php?project=Evolution'>Evolution</a>
   <li> <a href='index.php?project=GroupA'>GroupA</a>
   <li> <a href='index.php?project=GroupC'>GroupC</a>
   <li> <a href='index.php?project=GroupD'>GroupD</a>
   </ul>
   ";

#
#   echo "<br>";
#   echo "<br>";
#   echo "<br>";
#   echo "\n<ul>";
#   echo "<FORM METHOD=POST ACTION=index.php?project=$name>";
#   echo "<P><strong>Please select one of the following projects::</strong><br>";
#   echo "<br>";
#   echo "<br>";
#   echo "<input type=radio name=name1 value=gnumeric> Gnumeric";
#   echo "<br>";
#   echo "<br><input type=radio name=name1 value=Evolution> Evolution"; 
#   echo "<br>";
#   echo "<br><input type=radio name=name1 value=Mozilla> Mozilla";
#   echo "<br>";
#   echo "<br>";
#   echo "<br> <input type=submit name=submit value=SoftChange>";
#   echo "</form>";  
#   echo "\n</ul>";

   exit;
}

        

$softChange->Header('Details of Modification Request', 'art/bymodification.png');


$softChange->Connect();

$mrid = $_GET['mrid'];
$orderby = $_GET['orderby'];

	
$result = pg_query ($softChange->conn, 
                       "select  mrid, author, daterev, timerev, log
                           from mrs2  where mrid = '$mrid' $range1 $range2
                        ");

if (!$result) {
    echo "An error occured.\n";
    $softChange->Disconnect();
    exit;
}
   
$softChange->Display_Mrs($result, $operation);


$result = pg_query ($softChange->conn, 
                       "
select  mrsfiles.filename, mrsfiles.revisionid, linesadd, linesrm, state
from mrsfiles, revisions, mrs2
where mrs2.mrid = '$mrid' and mrs2.mrid = mrsfiles.mrid and
      mrsfiles.filename  = revisions.filename and
      mrsfiles.revisionid = revisions.revisionid
$range1 $range2
                        ");

if (!$result) {
    echo "An error occured.\n";
    $softChange->Disconnect();
    exit;
}

echo "<h3>Files in MR</h3>\n";

echo "<table border=0>\n";
echo "<tr class=black>\n";
echo "
         <td></td>
         <td><b>Filename</b></td>
         <td><b>RevisionId</b></td>
         <td><b>Lines Added</b></td>
         <td><b>Lines Removed</b></td>
         <td><b>Lines Total</b></td>
         <td><b>State</b></td>
         <td><b>Methods Added</b></td>
         <td><b>Methods Removed</b></td>
         <td><b>Methods After</b></td>
         <td><b>Methods Before</b></td>
        ";
echo "</tr>\n";

$totalAdd = 0;
$totalRm  = 0;

$odd = 0;
$previd = "";

$totalMethodsAdded = 0;
$totalMethodsRemoved = 0;

while ($row = pg_fetch_row($result, $i)) {
    
    $fileName = trim($row[0]);
    $revid = trim($row[1]);
    $rem = -$row[3];
    $added = $row[2];
    $abs = $added - $rem;
    $state = $softChange->Format_File_State($row[4]);
    
    $totalAdd += $added;
    $totalRm  += $rem;
    
    if ($odd++ % 2) {
	echo "<tr class=back0>\n";
    } else {
	echo "<tr class=back1>\n";
    }
    echo "<td>$odd</td>";
    echo "<td>";
    echo $softChange->Create_URL($fileName, array('operation' => 'file',
						  'file' => $fileName),'') ;
    echo "</td>\n";
    
    echo "<td>";

    echo $softChange->Create_URL_Complete($softChange->REVISION_DETAILS_URL,$revid,
					          array('revisionid' => $revid,
						  'filename' => $fileName),'') ;

    echo "</td>";
    
#      $previd = $revid;
    echo "<td align=right>$row[2]</td>";
    echo "<td align=right>$rem</td>";
    echo "<td align=right>$abs</td>";
    echo "<td align=right>$state</td>";

    $fileDetails = pg_query ($softChange->conn, 
			"select methodsadded, methodsdeleted, methodsafter, methodsbefore
                            from methoddeltas 
                         where filename = '$fileName' and revisionid = '$revid'
                        ");

    $totalMethodsAdded += $fileDetailsRow[0];
    $totalMethodsDeleted += $fileDetailsRow[1];

    if (!$fileDetails) {
	echo "An error occured.\n";
	$softChange->Disconnect();
	exit;
    }
    if ($fileDetailsRow = pg_fetch_row($fileDetails, $indexFile)) {
	echo "
         <td align=right><b>$fileDetailsRow[0]</b></td>
         <td align=right><b>$fileDetailsRow[1]</b></td>
         <td align=right><b>$fileDetailsRow[2]</b></td>
         <td align=right><b>$fileDetailsRow[3]</b></td>
        ";
    }

#----------------------------------------------------------------------

#    $deltas = pg_query ($softChange->conn, 
#			"
#    select distinct definition from revdefs r
#       where methoddeltas.filename = '$filename' and
#          methoddeltas.revisionid = '$revid' and
#          r.typedef in ('method' , 'function')
#    EXCEPT
#    select distinct definition from revdefs r
#       where methoddeltas.filename = r.filename and
#          methoddeltas.prevrevisionid = $prevrevid' and
#          r.typedef in ('method' , 'function')
#                        ")
#    if (!$fileDetails) {
#	echo "An error occured.\n";
#	$softChange->Disconnect();
#	exit;
#    }
#    if ($fileDetailsRow = pg_fetch_row($fileDetails, $indexFile)) {
#	echo "
#         <td><b>$fileDetailsRow[0]</b></td>
#         <td><b>$fileDetailsRow[1]</b></td>
#         <td><b>$fileDetailsRow[2]</b></td>
#         <td><b>$fileDetailsRow[3]</b></td>
#        ";
#    }
#
#

    
    echo "</tr>\n";

}

$totalAbs = $totalAdd - $totalRm;

echo "<tr>";
echo "<td></td>";
echo "<td><b>Total</b></td>";
echo "<td align=right><b>$odd</b></td>";
echo "<td align=right><b>$totalAdd</b></td>";
echo "<td align=right><b>$totalRm</b></td>";
echo "<td align=right><b>$totalAbs</b></td>";
echo "<td></td>";
echo "<td align=right><b>$totalMethodsAdded</b></td>";
echo "<td align=right><b>$totalMethodsRemoved</b></td>";
echo "</tr>";


echo "</table>\n";


echo "<h3>MR Statistics </h3>\n\n";

$result = pg_query ($softChange->conn, 
		    "select  mrid, code, filesCount, filesAdded, filesRemoved, 
                                methodsadded,methodsremoved
			from mrstats where mrid = '$mrid'
                        ");

if (!$result) {
    echo "An error occured.\n";
    $softChange->Disconnect();
    exit;
}

if ($row = pg_fetch_row($result, $i)) {
    echo "<table>\n";
    
    echo "
         <tr class=black>
         <td><b>Source code?</b></td>
         <td><b>Files</b></td>
         <td><b>Files Added</b></td>
         <td><b>Files Removed</b></td>
         <td><b>Methods Added</b></td>
         <td><b>Methods Removed</b></td>
        ";
    echo "</tr>\n";
    
    
    
    echo "<tr>\n";
    for ($fields = 1; $fields < 7; $fields++) {
	echo "<td>" . $row[$fields] . "</td>\n";
    }
    echo "</tr>\n";
    echo "</table>\n";
}


$softChange->Footer();

$softChange->Disconnect();
    

?>
