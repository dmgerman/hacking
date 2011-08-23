<?php


require_once 'softchange.php';
require_once 'library.php';

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

  $softChange->Header_Logo('Choose Project');

   echo "
   <ul>
   <li> <a href='index.php?project=Evolution'>Evolution</a>
   <li> <a href='index.php?project=GroupA'>Small project</a>
   </ul>
   ";

  $softChange->Footer();


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

        
# The user did not specify any operation. 
#
# Allow user to narrow date, developer
#

if ($operation == '') {

  #print_r($_COOKIE);

   $softChange->Header('Modification Requests by Month', 'art/bymonth.png');

   $softChange->Connect();

   $months = $softChange->Retrieve_Dates();
   
   echo "<table border=0>";
   echo "<tr class=black><td><b>Month</b></td><td><b>Count</b></td></tr>\n";

   $even = 0;
   foreach ($months as $month => $count) {
      if ($even++ % 2) {
         echo "<tr class=back0>\n";
      } else {
         echo "<tr class=back1>\n";
      }
      echo "<td>\n";
      echo "
         <a href='index.php?project=" . $softChange->project . 
         "&operation=detailsbymonth" . 
         "&month=$month&orderby=order%20by%20daterev'>$month</a></td><td> $count</td>\n";
      echo "</tr>\n";
   }
   echo "</table>";
}

if ($operation == 'file') {

   $softChange->Header('Modification Requests by File', 'art/byfile.png');


   $softChange->Connect();

   $fileName = $_GET['file'];
   $orderBy = $_GET['orderby'];

    if ($orderBy == '') {
      $orderBy = 'order by mrsfiles.daterev';
   } else {
      $orderBy .= ', daterev, timerev';
   }

   $result = pg_query ($softChange->conn, 

                       "select mrsfiles.mrid, revisionid, author, mrsfiles.daterev, mrsfiles.timerev, log,
                        linesadd, linesrm, state
                        from revisions natural join mrsfiles, mrs2 
                        where filename='$fileName' 
                        and mrsfiles.mrid = mrs2.mrid $range2 $range1
                        $orderBy
                        ");

   if (!$result) {
      echo "An error occured.\n";
	$softChange->Disconnect();
     exit;
   }
   
   echo "<h3>File: $fileName</h3>\n";
   echo "<table border=0>\n";
   echo "<tr class=black>\n";
   echo "<td><b>MR Id</b></td>
         <td><b>";
   echo $softChange->Create_URL('Author', array('operation' => 'file',
                                                      'file' => $fileName,
                                                'orderby'   => 'order by author'
                                                ),'black') ;
   echo  "</b></td>";


   echo "<td><b>Revision Id</b></h>";
   echo "<td><b>Lines Added</b></h>";
   echo "<td><b>Lines Removed</b></h>";
   echo "<td><b>Lines Abs</b></h>";
   echo "<td><b>State</b></h>";
   echo "<td><b>";

   echo $softChange->Create_URL('Date', array('operation' => 'file',
                                                      'file' => $fileName,
                                                'orderby'   => ''
                                                ),'black') ;

   echo  "</td></b>";

   echo "<td><b>Time</b></td>
         <td><b>Description</b></td>";
   echo "</tr>\n";

   $odd = 0;
   $prevrev = '';
   while ($row = pg_fetch_row($result, $i)) {
      $mrid = $row[0];
      $revid = $row[1];
      $author = $row[2];
      $log = $row[5];
      $log = $softChange->Format_Log($log);
      $linesAdd = $row[6];
      $linesRm = - $row[7];
      $linesAbs = $row[6] + $row[7];

      $state = $softChange->Format_File_State($row[8]);

      if ($odd++ % 2) {
         echo "<tr class=back0>\n";
      } else {
         echo "<tr class=back1>\n";
      }

      echo "<td valign=top>";
      echo $softChange->Create_URL_Complete($softChange->MR_DETAILS_URL, $mrid, 
				   array('mrid' => $mrid),
	                           '') ;
      echo "</td>\n";
      
      echo "<td valign=top>";
      echo $softChange->Create_URL($author, array('operation' => 'author',
                                            'author' => $author),'') ;
      echo "</td>\n";

      echo "<td valign=top>";
      
      echo $softChange->Create_URL_Complete($softChange->REVISION_DETAILS_URL, $revid, 
					          array('revisionid' => $revid,
						  'filename' => $fileName),'') ;

      echo "</td>";
      $previd = $revid;
      echo "<td valign=top>$linesAdd</td>";
      echo "<td valign=top>$linesRm</td>";
      echo "<td valign=top>$linesAbs</td>";
      echo "<td valign=top>$state</td>";
      echo "<td valign=top>$row[3]</td>";
      echo "<td valign=top>$row[4]</td>";
      echo "<td valign=top><pre>$log</pre></td>";
      echo "</tr>\n";
   }

   echo "</table>\n";



      
}

if ($operation == 'revision') {


   $softChange->Header('Display a Given Revision', 'art/byfile.png');


   $softChange->Connect();

   $fileName = $_GET['file'];
   $revisionId = $_GET['revisionid'];

   echo "<h3>File: $fileName, Revisionid: $revisionId</h3>\n";


   $result = pg_query ($softChange->conn, 
		       "
		       select newfile, cleanfile from filerevisions 
                       where  filename = '$fileName' and revisionid = '$revisionId' 
                        ");

   if (!$result) {
      echo "An error occured.\n";
	$softChange->Disconnect();
     exit;
   }

   echo "<table border=1>";
   $odd = 0;
   $prevrev = '';
   if ($row = pg_fetch_row($result, $i)) {

      $source = $row[1];
      # Now we have the file, we need the identifiers that correspond to it

      $idents = pg_query ($softChange->conn, 
		       "
                        select definition, index, typedef, line, cleanline, length 
                        from  revdefs where
                        filename = '$fileName' and revisionid = '$revisionId'
                        order by cleanline
                        ");

      if (!$idents) {
	 echo "An error occured.\n";
	 $softChange->Disconnect();
	 exit;
      }
      

      echo "<tr><td></td><td>";

      $fromLine = 0;
      while ($rowIdents = pg_fetch_row($idents, $j)) {

	 /* So first we write what we have before this line */
	 $definition = $rowIdents[0];
	 $lineNo = $rowIdents[4];
	 
	 $lines = Get_Lines($source, $fromLine, $lineNo-1);

	 $fromLine = $lineNo-1;

	 echo "<pre>$lines</pre>\n";
	 echo "</tr><tr><td>$definition";

	 echo trim($rowIdents[0]), ",$rowIdents[1], $rowIdents[2], $rowIdents[3], $rowIdents[4],$rowIdents[5] $lineNo\n";
	 echo "</td><td>";
      }
      $lines = Get_Lines($source, $fromLine, 100000000);
      
      echo "<pre>$lines</pre>";
      echo "</td></tr>";

   }


   echo "</table>\n";

      
}



if ($operation == 'detailsmr') {

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
        ";
   echo "</tr>\n";

   $totalAdd = 0;
   $totalRm  = 0;

   $odd = 0;
   $previd = "";
   while ($row = pg_fetch_row($result, $i)) {

      $fileName = $row[0];
      $revid = $row[1];
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
      if ($previd == '') {
	echo "$revid";
      } else {
	echo "<a target=_new href='";
	echo $softChange->Bonsai_Revision_URL($fileName, $revid, $previd);
	echo "'>$revid</a>";
      } 
      echo "</td>";

#      $previd = $revid;
      echo "<td align=right>$row[2]</td>";
      echo "<td align=right>$rem</td>";
      echo "<td align=right>$abs</td>";
      echo "<td align=right>$state</td>";

      echo "</tr>\n";
   }

   $totalAbs = $totalAdd - $totalRm;

   echo "<tr>";
   echo "<td><b>Total</b></td>";
   echo "<td align=right><b>$odd</b></td>";
   echo "<td align=right><b>$totalAdd</b></td>";
   echo "<td align=right><b>$totalRm</b></td>";
   echo "<td align=right><b>$totalAbs</b></td>";
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



}

if ($operation == 'listauthors') {
   
   $softChange->Header('Modification Requests by Author', 'art/bydeveloper.png');

   $orderby = $_GET['orderby'];

   $softChange->Connect();

   if ($orderby == '') {
      $orderby = 'order by author';
   }

   echo "<h3>Authors of MR</h3>\n";

   $result = pg_query ($softChange->conn, 
                       "select  author, count(*) as count, min(daterev) as first, max(daterev) as last
                        from mrs2
                        where TRUE $range1 $range2
                        group by author
                        $orderby
                        ");

   if (!$result) {
      echo "An error occured.\n";
	$softChange->Disconnect();
      exit;
   }



   echo "<table border=0 >\n";
   echo "<tr class=black>\n";
   echo "<td><b>";
   echo $softChange->Create_URL('Authors', array('operation' => 'listauthors',
                                                  'orderby' => 'order by author '),'black') ;

   echo "</b></td>";

   echo "<td><b>";
   echo $softChange->Create_URL('No of Mrs', array('operation' => 'listauthors',
                                                  'orderby' => 'order by count '),'black') ;
   echo "</b></td>";

   echo "<td><b>";
   echo $softChange->Create_URL('Date First', array('operation' => 'listauthors',
                                                  'orderby' => 'order by first '),'black') ;
   echo "</b></td>";
   echo "<td><b>";
   echo $softChange->Create_URL('Date Last', array('operation' => 'listauthors',
                                                  'orderby' => 'order by last '),'black') ;
   echo "</b></td>";

   echo "</tr>\n";

   $odd = 0;
   while ($row = pg_fetch_row($result, $i)) {

      $author = $row[0];
      $mrs = $row[1];
      $first = $row[2];
      $last = $row[3];

      if ($odd++ % 2) {
         echo "<tr class=back0>\n";
      } else {
         echo "<tr class=back1>\n";
      }

      echo "<td>";
      echo $softChange->Create_URL($author, array('operation' => 'author',
                                                  'author'   => $author),'') ;

      echo "</td>";
      echo "<td align=right>$mrs</td>";
      echo "<td align=right>$first</td>";
      echo "<td align=right>$last</td>";

      echo "</tr>\n";
   }

   echo "</table>";


}

if ($operation == 'listbugfixes') {
   
   $softChange->Header('Modification Requests fixing bugs in Bugzilla', 'art/bybug.png');

   $orderby = $_GET['orderby'];

   $softChange->Connect();

   if ($orderby == '') {
      $orderby = 'order by daterev';
   }

   echo "<h3>Likely to be Bugzilla Bug Fixes</h3>\n";
  
   $result = pg_query ($softChange->conn, 
                       "select  mrid, log
                        from mrs2
                        where (log ~ '#[0-9][0-9]+' or log ~ '[Bb][Uu][Gg][ \n\t\r][0-9][0-9]+') $range1 $range2
                        $orderby
                        ");

   if (!$result) {
      echo "An error occured.\n";
	$softChange->Disconnect();
      exit;
   }

   echo "<table border=0>\n";
   echo "<tr class=black>\n";
   echo "<td><b>";
   echo $softChange->Create_URL('MRis', array('operation' => $operation,
                                                  'orderby' => 'order by mrid '),'black') ;

   echo "</b></td>";

   echo "<td><b>Bugs";
   echo "</b></td>";

   echo "<td><b>Log";
   echo "</b></td>";

   echo "</tr>\n";

   $odd = 0;
   while ($row = pg_fetch_row($result, $i)) {

      $mrid = $row[0];

      $log = $softChange->Format_Log($row[1]);

      preg_match_all ("/(bug[ \t\n]+|#)([0-9][0-9]+)/i", $log, $matches);

      $bugs = "";
      for ($j=0; $j< count($matches[0]); $j++) {

	 $url = "<a href='$bugzillaURL" . $matches[2][$j] . "'>" . 
	    $matches[2][$j] . "<a";

         if ($bugs == "") {
            $bugs .=   $url . "&nbsp;";
         }
      }

      if ($odd++ % 2) {
         echo "<tr class=back0>\n";
      } else {
         echo "<tr class=back1>\n";
      }

      echo "<td valign=top>";
      echo $softChange->Create_URL_Complete($softChange->MR_DETAILS_URL,$mrid, array('operation' => 'detailsmr',
                                         'mrid' => $mrid),'') ;
      echo "</td>\n";

      echo "<td valign=top align=left>$bugs</td>";

      echo "<td valign=top align=left><pre>$log</pre></td>";
      echo "</tr>\n";
   }

   echo "</table>";

}



if ($operation == 'author') {

   $softChange->Header('Modification Requests by Author', 'art/bydeveloper.png');

   
   $softChange->Connect();

   $month = $_GET['month'];
   $author = $_GET['author'];
   $orderby = $_GET['orderby'];

   if ($orderby == '') {
      $orderby = 'order by daterev';
   }



   $result = pg_query ($softChange->conn, 
                          "select  mrs2.mrid, author, daterev, timerev, log
                           from mrs2 where
                           author = '$author' 
                           order by daterev
                           ");
   if (!$result) {
      echo "An error occured.\n";
	$softChange->Disconnect();
      exit;
   }

   echo "<h3>MRs by $author</h3>\n";


   $softChange->Display_Mrs($result, $operation);

}

if ($operation == 'date') {
   
   $softChange->Header('Modification Requests in a given Day', 'art/byday.png');


   $softChange->Connect();

   $date = $_GET['date'];

   $result = pg_query ($softChange->conn, 
                          "select  mrs2.mrid, author, daterev, timerev, log
                           from mrs2 where
                           daterev = '$date' $range1 $range2
                           order by daterev
                           ");
   if (!$result) {
      echo "An error occured.\n";
	$softChange->Disconnect();
      exit;
   }

   echo "<h3>MRs by date</h3>\n";

   $softChange->Display_Mrs($result, $operation);

}

if ($operation == 'listfiles') {
   
   $softChange->Header('Files in the Project', 'art/byfile.png');


   $softChange->Connect();

   $orderby = $_GET['orderby'];

   if ($orderby == '') {
      $orderby = 'order by filename';
   }

   echo "<h3>Files</h3>\n";

   $result = pg_query ($softChange->conn, 
                       "select filename, count(distinct mrs2.mrid) as mrs, 
                        count(distinct author) as authors,
                        min(mrsfiles.daterev) as first,
                        max(mrsfiles.daterev) as last
                        from mrsfiles, mrs2  
                        where mrs2.mrid = mrsfiles.mrid $range1 $range2 
                        group by filename
                        $orderby
                        ");

   if (!$result) {
      echo "An error occured.\n";
	$softChange->Disconnect();
      exit;
   }

   echo "<table border=0>\n";

   $softChange->Table_Header('listfiles',
			     array('# '                    => '',
				   'File'                  => 'order by filename',
				   '# Revisions'           => 'order by mrs',
				   '# Authors'             => 'order by authors',
				   'First<br>Modification' => 'order by first',
				   'Last<br>Modification'  => 'order by last')
			     );

   $odd = 0;
   while ($row = pg_fetch_row($result, $i)) {

      $filename = $row[0];
      $mrs      = $row[1];
      $authors  = $row[2];
      $first    = $row[3];
      $last     = $row[4];

      if ($odd++ % 2) {
         echo "<tr class=back0>\n";
      } else {
         echo "<tr class=back1>\n";
      }

      echo "<td align=right>$odd</td>";

      echo "<td>";
      echo $softChange->Create_URL($filename, array('operation' => 'file',
                                                  'file'   => $filename),'') ;

      echo "</td>";
      echo "<td align=right>$mrs</td>";
      echo "<td align=right>$authors</td>";
      echo "<td align=right>$first</td>";
      echo "<td align=right>$last</td>";

      echo "</tr>\n";
   }

   echo "</table>";





}



if ($operation == 'detailsbymonth') {
   
   $softChange->Header('Modification Requests by Month', 'art/bymonth.png');

   $softChange->Connect();

   $month = $_GET['month'];
   $orderby = $_GET['orderby'];

   $result = pg_query ($softChange->conn, 
                          "select  mrs2.mrid, author, daterev, timerev, log
                           from mrs2  where
                           date(date_trunc('month', daterev)) = '$month' $range1 $range2
                           $orderby
                           ");
   if (!$result) {
      echo "An error occured.\n";
	$softChange->Disconnect();
      exit;
   }

   echo "<h3>MRs during the month $month</h3>\n";

   $softChange->Display_Mrs($result, $operation);


}


if ($operation == 'abc') {

   $softChange->Connect();

   $softChange->Print_Form_Head('bymonth');
   
   $developers = $softChange->Retrieve_Developers();

   echo "<h3>Select a developer</h3>\n";
   echo "<select name=developers multiple><option selected value='_any_'>ANY</option>\n";
   foreach ($developers as $name) {
         echo "<option value=$name>$name</option>\n";
   }
   echo "</select>\n";

   $dirs = $softChange->Retrieve_Directories();

   echo "<h3>Select a directory you are interested in</h3>\n";
   echo "<select name=directories multiple><option selected value='_any_'>ANY</option>\n";
   foreach ($dirs as $name) {
      
      echo "<option value=$name>$name</option>\n";
   }
   echo "</select>\n";

   $softChange->Print_Form_Tail();
   

}

if ($operation == 'search') {

   $softChange->Header('Search Modification Requests', 'art/bymonth.png');

   $softChange->Connect();

   $log     = $_GET['log'];
   $orderby = $_GET['orderby'];

   if ($log != '') {


      $result = pg_query ($softChange->conn, 
			  "select  mrid, author, daterev, timerev, log
                           from mrs2  where log ~ '$log' $range1 $range2
                           order by daterev
                        ");
      
      if (!$result) {
	 echo "An error occured.\n";
         $softChange->Disconnect();
	 exit;
      }
      echo "<h3>Search Results</h3>\n";
   
      $softChange->Search_Form($log);

      $hits = $softChange->Display_Mrs($result, $operation);
      
      if ($hits == 0) {
	 echo "<h3>Nothing found</h3>\n";
      }

   } else {
      echo "<h3>No search query specified</h3>\n";

   }




}


if ($operation == 'searchform') {

   $softChange->Header('Search Modification Requests', 'art/bymonth.png');

   $softChange->Search_Form('');
}




#   $this->Connect();
#   $developers = $this->Get_Developers();

   
#echo "
#<form method=POST action='http://aries17/cgi-bin/dmg/isearch'>
#<input name='DATABASE' type=hidden value='tester'>
#<input name='SEARCH_TYPE' type=hidden value='ADVANCED'>
#<input name='HTTP_PATH' type=hidden value='http://aries17.uwaterloo.ca/~dmg/temp'>
#<b>Query:</b>
#<textarea rows=2 cols=75 maxcols=80 name='ISEARCH_TERM'>
#</textarea><br>
#<HR>
#Select Field to Display as Headline: <select name='ELEMENT_SET'>
#<option selected value='B'>Brief
#</select>
#<p>Enter maximum number of hits to retrieve: 
#<input size=4 name='MAXHITS' value='50'><p>
#<input type='submit' value=' Submit Query '>
#<input type=reset value=' Clear Entries '>
#</form>
#";
#}
#



$softChange->Footer();

$softChange->Disconnect();
    

?>
