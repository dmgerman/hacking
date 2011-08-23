<?php


require_once 'softchange.php';



function Print_Code($code) 
{
    $code = str_replace ( "\n>", "\n", $code);
    $code = str_replace ( "\n<", "\n", $code);
    $code = str_replace ( "<", "&lt;", $code);

    echo "<pre>";
    echo $code;
    echo "</pre>";
    
}

function Get_Method_Name($softChange, $fileName, $revisionId, $line, $clean)
{

    $fieldName = $clean ? 'cleanline' : 'line';

    $methodResult = pg_query ($softChange->conn, 
                       "select definition from revdefs 
                           where 
                              filename = '$fileName' and
                              revisionid = '$revisionId' and
                              $fieldName = (
                               select max($fieldName) 
                               from revdefs 
                               where filename = '$fileName' and revisionid='$revisionId' and
                                     $fieldName <= $line
                               and typedef in ('method','function') group by filename, revisionid)"
			      );

    if (!$methodResult) {
	echo "An error occured.\n";
	$softChange->Disconnect();
	exit;
    }
   
    if ($methodName = pg_fetch_row($methodResult, $i)) {
	return trim($methodName[0]);
    } else {
	return "";
    }

}

function Get_Next_Revision($softChange, $fileName, $revisionId)
{
    $revResult = pg_query ($softChange->conn, 
                       "select revisionid from revisiondiffs 
                           where 
                              filename = '$fileName' and
                              prevrevisionid = '$revisionId'");

    if (!$revResult) {
	echo "An error occured.\n";
	$softChange->Disconnect();
	exit;
    }
   
    if ($nextRev = pg_fetch_row($revResult, $i)) {
	return trim($nextRev[0]);
    } else {
	return "";
    }

}




function Get_MR($softChange, $fileName, $revisionId)
{
    $mrResult = pg_query ($softChange->conn, 
                       "select f.mrid from mrsfiles f, mrs2 m
                           where 
                              f.filename = '$fileName' and
                              f.revisionid = '$revisionId' and
			      f.mrid = m.mrid
			      ");

    if (!$mrResult) {
	echo "An error occured.\n";
	$softChange->Disconnect();
	exit;
    }
   
    $mrName = pg_fetch_row($mrResult, $i);
    return $mrName[0];

}




function Get_Line_Number($lines) 
{
    if (preg_match ("/^[0-9]+/", $lines, $lineMatch)) {
	return $lineMatch[0];
    } else{
	return $lines;
    }
}


function Display_Delta_Definitions_Each($deltaResult)
{
    echo "<td valign=top>\n";

    print "<table>";

   $odd = 0;
    while ($deltaName = pg_fetch_row($deltaResult, $i)) {
	if ($deltaName[2] == 0 ) {
	    $deltaName[2] = '';
	} else {
	    $deltaName[2] = '(' .  $deltaName[2] . ')';
	}
	if ($odd++ % 2) {
	    echo "<tr class=back0>\n";
	} else {
	    echo "<tr class=back1>\n";
	}

	echo "<td><b>$deltaName[0]</b> </td><td>$deltaName[1] $deltaName[2] </td></tr>";
    } 
    echo "</table>\n";
    echo "</td>";

}

function Display_Delta_Definitions($softChange,$fileName, $prevRevision, $revisionId) 
{
    echo "<table border=0>\n";

    $softChange->Table_Header($operation,
			     array(
				   'Removed'                   => '',
				   'Added'                    => ''
				   )
			     );
    echo "<tr >";


    $deltaResult = pg_query ($softChange->conn, 
                       "
                        select definition,typedef, index from revdefs 
                           where filename = '$fileName' and
                                 revisionid = '$prevRevision'

                        EXCEPT

                        select definition, typedef, index from revdefs 
                           where filename = '$fileName' and
                                 revisionid = '$revisionId'
			      ");
    if (!$deltaResult) {
	echo "An error occured.\n";
	$softChange->Disconnect();
	exit;
    }
   
    Display_Delta_Definitions_Each($deltaResult);


    $deltaResult = pg_query ($softChange->conn, 
                       "select definition, typedef, index from revdefs 
                           where filename = '$fileName' and
                                 revisionid = '$revisionId' 
                        EXCEPT
                        select definition,typedef, index from revdefs 
                           where filename = '$fileName' and
                                 revisionid = '$prevRevision' 
			      ");

    if (!$deltaResult) {
	echo "An error occured.\n";
	$softChange->Disconnect();
	exit;
    }
   
    Display_Delta_Definitions_Each($deltaResult);

    echo "</tr></table>";


}



function Display_Diff($softChange,$cleanDiff, $fileName, $prevRevision, $revisionId, $clean) 
{


    echo '<br><table border=0 width=100%>';
    echo "<tr>
           <td class=backtitle$clean><center><h3>Before ($prevRevision)</h3></center></td>
           <td class=backtitle$clean><center><h3>After  ($revisionId)</h3></center></td>
";
    echo "</tr>\n";

    while (preg_match ("/^([0-9,]+)([a-z])([0-9,]+)/",
		       $cleanDiff, $matches)) {
	
#	print "<tr><td>[$matches[0]]</td></tr>";
#	print "<tr><td>[$matches[1]]</td></tr>";
#	print "<tr><td>[$matches[2]]</td></tr>";
#	print "<tr><td>[$matches[3]]</td></tr>";
	$beforeInfo = $matches[1];
	$afterInfo = $matches[3];

	$afterInfo = Get_Line_Number($afterInfo) ;
	$beforeInfo = Get_Line_Number($beforeInfo) ;

	$type = $matches[2];

	$cleanDiff = substr($cleanDiff, strlen($matches[0]));
	
	if (preg_match ("/^[0-9]+/m",
			$cleanDiff, $body, PREG_OFFSET_CAPTURE)) {
	    # THere is a next record. SO set body to the prefix of this
	    # and set the cleanDiff to the next one

	    $diffBody = substr($cleanDiff, 0, $body[0][1]);

	    $cleanDiff = substr($cleanDiff, $body[0][1]);
	} else {
	    $diffBody = $cleanDiff;
	    $cleanDiff = "";
	}
	   
	echo "<tr>";
	echo "<td class=backlines><b>Line: $beforeInfo";
	if (preg_match("/^[0-9]+$/", $beforeInfo )) {
	    $methodName = Get_Method_Name($softChange, $fileName, $prevRevision, $beforeInfo, $clean);
	    if ($methodName != '') {
		echo "</b>   Method/Function:<b> " . $methodName;
	    }
	}

	echo "</b></td>";
	echo "<td class=backlines><b>Line: $afterInfo";
	if (preg_match("/^[0-9]+$/", $afterInfo )) {
	    $methodName = Get_Method_Name($softChange, $fileName, $revisionId, $afterInfo, $clean);
	    if ($methodName != '') {
		echo "</b>   Method/Function:<b> " . $methodName;
	    }
	}
	echo "</td></tr>";

#--        echo 
#--                      <td class=backlines><b>Lines: $afterInfo</b></td>
#--                      </tr>";


	if ($type == 'c') {

#	    echo "<tr><td class=backchange>CHange</td></tr>\n";
	    if ($sepBody = strpos($diffBody, "\n---")) {
		
		$firstPart = substr($diffBody, 0, $sepBody);
		
		$secondPart = substr($diffBody, $sepBody+4);
		
#		echo "<h3>First part</h3>";
		

		echo "<td class=backchange>";

		Print_Code($firstPart) ;

		echo "</td>";
		
#		echo "<h3>Second part</h3>";
		
		echo "<td class=backchange>";

		Print_Code($secondPart) ;

		echo "</td>";
		
	    }
	} else if ($type == 'd') {

	    echo "<td class=backdelete>";

	    Print_Code($diffBody) ;

	    echo "</td>";
	    echo "</tr>";
	} else if ($type == 'a') {

	    echo "<td class=backadded>";
	    echo "</td>";
	    echo "<td class=backadded>";
	    echo "<pre>";
	    Print_Code($diffBody) ;

	    echo "</pre>";
	    echo "</td>";
	    echo "</tr>";
	}



#	    echo "<h3>BOdy</h3>";


#	print "<tr><td><pre>$cleanDiff</pre></td></tr>";
#	print "<tr><td><hr></td></tr>";

    }

    echo "</tr>";
    echo "</table>";



}



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

        

$softChange->Header('Details of the Revision', 'art/bymodification.png');


$softChange->Connect();

$revisionId = $_GET['revisionid'];
$fileName = $_GET['filename'];
$mrid = $_GET['mrid'];

$result = pg_query ($softChange->conn, 
                       "select prevrevisionid, pluslines, minuslines, changedLines, diff, diffclean, state, linesAdd, linesRm
                           from revisiondiffs d, revisions r
                        where r.filename = '$fileName' and r.revisionid = '$revisionId' and 
                              d.filename = r.filename and d.revisionid = r.revisionid 
                        ");

if (!$result) {
    echo "An error occured.\n";
    $softChange->Disconnect();
    exit;
}
   
if ($row = pg_fetch_row($result, $i)) {

    $prevRevision = trim($row[0]);
    $diff = $row[4];

    $cleanDiff = $row[5];

    $state = $row[6];
    $linesAdded = $row[7];
    $linesRm = -$row[8];

    $lengthDiff = strlen($diff);


    echo "<h3>Details of the Revision</h3>";


######################################################################
    $nextRevision = Get_Next_Revision($softChange,$fileName, $revisionId);

    $mrid = $mrDetails[0];
    $author = $mrDetails[1];

    echo "<table border=0>\n";

    $softChange->Table_Header('listfiles',
			      array(
				    'File Name'             => '',
				    'Revision'              => '',
				    'Previous Revision'     => '',
				    'Next Revision'         => '',
				    'Lines Added'           => '',
				    'Lines Removed'         => '',
				    'Length of Diff'=>''
				    )
			      );
    
    echo "<tr class=back1>";
    echo "<td>";
    echo $softChange->Create_URL($fileName, array('operation' => 'file',
                                                  'file'   => $fileName),'') ;
    
    echo "</td>";
    
    echo "<td>$revisionId</td>";

    echo "<td>";
    echo $softChange->Create_URL_Complete($softChange->REVISION_DETAILS_URL,$prevRevision,
					  array('revisionid' => $prevRevision,
						'filename' => $fileName),'') ;
    
    
    echo "</td>\n";
    echo "<td>\n";
    echo $softChange->Create_URL_Complete($softChange->REVISION_DETAILS_URL,$nextRevision,
					          array('revisionid' => $nextRevision,
						  'filename' => $fileName),'') ;

    echo "</td>\n";
    echo "<td align=right>$linesAdded</td>\n";
    echo "<td align=right>$linesRm</td>\n";
    echo "<td align=right>$lengthDiff</td>\n";


    echo "</table><br><br>";

    echo "<table border>\n";
    
######################################################################

    $mrid = Get_MR($softChange,$fileName, $revisionId);

    $resultMR = pg_query ($softChange->conn, 
			"select  mrid, author, daterev, timerev, log
                           from mrs2  where mrid = '$mrid' 
                        ");
    
    if (!$resultMR) {
	echo "An error occured.\n";
	$softChange->Disconnect();
	exit;
    }

    $softChange->Display_Mrs($resultMR, $operation);



#    echo "<td>$row[1]</td>\n";
#    echo "<td>$row[2]</td>\n";
#    echo "<td>$row[3]</td>\n";
#    echo "<td>$row[4]</td>\n";
#    echo "<td><pre>$row[5]</pre></td>\n";
#    echo "<td><pre>$row[6]</pre></td>\n";
    echo "</tr>";
    echo "</table><br><br>";

    


    echo "<h3>Differences in definitions</h3>";

    Display_Delta_Definitions($softChange,$fileName, $prevRevision, $revisionId) ;

    if ($prevRevision != '') {

	$softChange->SubHeader("Differences in <i>clean</i> source code");
	
	Display_Diff($softChange,$cleanDiff, $fileName, $prevRevision, $revisionId, 1);
	
	$softChange->SubHeader("Differences in original source code");
	
	Display_Diff($softChange,$diff, $fileName, $prevRevision, $revisionId, 0);
    }

    
}



$softChange->Footer();

$softChange->Disconnect();
    

?>
