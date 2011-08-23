<?php

class Soft_Change 
{
	
   var $project;
   var $dataSets = array("Mozilla" => 'mozilla',
	                 "Evolution" => 'evolution',
			 "gnumeric"  => 'gnumeric',
			 "gnumeric"  => 'gnumeric',
			 "GroupA"  => 'GroupA',
			 "GroupB"  => 'GroupB',
			 "GroupC"  => 'GroupC',
			 "GroupD"  => 'GroupD',
			 "GroupE"  => 'GroupE',
	);
	
   var $connect;
   var $connected =0 ;
   var $MR_DETAILS_URL = 'mrdetails.php';
   var $REVISION_DETAILS_URL = 'revisiondetails.php';

   function Soft_Change($nameProject)
   {
	$this->project = $nameProject;
   }

   function List_Datasets()
   {
	return $this->dataSets;
   }

   function Database()
   {
        return $this->dataSets[$this->project];
   }

   function __destruct() 	
   {
	print "<h3>Distructor</h3>";
   }


######################################################################
# Database funtcions

   function Connect()
   {
      
	$this->conn = pg_pconnect ("dbname=" . $this->Database() . 
			     " user=www password=evolution");
	if (!$this->conn) {
	   echo "An error occured.\n";
	   exit;
	}
	$this->connected = 1;
   }

   function Disconnect()
   {
        pg_close($this->conn);
   }	

#   function Die($errorSt) 
#   {
#        echo "<h3>error [$errorSt]</h3>";
#	echo "<h3>dieing...</h3>"; 
#	$this->Close_DB();
#	exit;
#   }
#
#   function Assert($condition, $error) 
#   {
#	if (not $condition) {
#	    $this->Die("Assertion failed: [$error]");
#	}
#   }
#
	
   function Retrieve_Min_Max_Date()
   {
     
      $date = array();
      $result = pg_query ($this->conn, "
                                        SELECT extract (year from max(daterev)),
                                               extract (month from max(daterev)),
                                               extract (day from max(daterev)),
                                               extract (year from min(daterev)),
                                               extract (month from min(daterev)),
                                               extract (day from min(daterev))
                                        FROM mrs2 ");
      if (!$result) {
	 echo "An error occured.\n";
 	 $softChange->Disconnect();
	 exit;
      }
      $date = pg_fetch_row($result, $i);

      return $date;
   }


   function Retrieve_Developers()
   {
     
      $developers = array();
      $result = pg_query ($this->conn, "SELECT distinct author 
                                        FROM mrs2 
                                        order by author");
      if (!$result) {
	 echo "An error occured.\n";
	 exit;
      }
      while ($row = pg_fetch_row($result, $i)) {
	 $developers[] = trim($row[0]);
      }
      return $developers;
   }

      
   function Retrieve_Directories()
   {
      $data = array();
      $result = pg_query ($this->conn, "SELECT distinct directory 
                                        FROM directories order by directory");
      if (!$result) {
	 echo "An error occured.\n";
	 exit;
      }
      while ($row = pg_fetch_row($result, $i)) {
	 $data[] = $row[0];
      }
      return $data;
   }

      
   function Retrieve_Dates()
   {
  if ( $_COOKIE[authorn]) {
       $range2x = " AND author in ('$_COOKIE[authorn]')";
       $range2 =  stripslashes ($range2x);
 
 }

     if ( $_COOKIE[start_time])
 $range1 = "AND daterev >= '$_COOKIE[start_time]' AND daterev <= '$_COOKIE[end_time]'";
     
      $data = array();
      $result = pg_query ($this->conn, 
			  "select  date(date_trunc('month', daterev)) as month, count(*)
			   from mrs2
                           where TRUE $range1 $range2
                           group by month
                           ");
      if (!$result) {
	 echo "An error occured.\n";
	 exit;
      }
      while ($row = pg_fetch_row($result, $i)) {
	 $data[$row[0]] = $row[1];
      }
      return $data;
   }

      
   function Create_URL($anchor, $fields, $class)
   {


      $result = "<a ";
      if ($class != '') {
         $result .=  "class=$class " ;
      }
      $result .= "href='index.php?project=" . $this->project;
      foreach ($fields as $name => $value) {
	 $result = $result . "&$name=$value";
      }
      $result = $result . "'>$anchor</a>";
      return $result;
   }

   function Create_URL_Complete($url,$anchor, $fields, $class)
   {
      $result = "<a ";
      if ($class != '') {
         $result .=  "class=$class " ;
      }
      $result .= "href='$url?project=" . $this->project;
      foreach ($fields as $name => $value) {
	 $result = $result . "&$name=$value";
      }
      $result = $result . "'>$anchor</a>";
      return $result;
   }




   function Count_Files_in_MR($mr) 
   {
      $result = pg_query ($this->conn, 
			  "select mrid, count(*) 
                           from mrsfiles
                            where mrid = '$mr' 
                           group  by mrid
                        ");
      if (!$result) {
	 echo "An error occured.\n";
	 exit;
      }
      $row = pg_fetch_row($result, $i)   ;
      return $row[1];
      
   }


######################################################################


   function Header_Logo($title)
   {
       echo "
<html>
<title>$title</title>
<head>
<link rel=\"stylesheet\" type=\"text/css\"
href=\"style.css\">
</head>
<body>

<img src='art/softchange.gif'><br><img src='art/line.gif' width='600' height='4'><br><br>

<table border=0>
   <tr>
      <td valign=top>
               <h3>$title </h3><img src='art/line.gif'>
      </td>
   </tr>
   </table>
</tr>
";

   }


   function Header($title, $icon)
   {


       $byDate = $this->Create_URL('By Date', array('operation' => ''),'');
#      $byDate = str_replace('By Date', '<b><font color=white>By Date</font></b>', $byDate);

      $byAuthor = $this->Create_URL('By Author', array('operation' => 'listauthors'),'');
#      $byAuthor = str_replace('By Author', '<b><font color=white>By Author</font></b>', $byAuthor);

      $byFile = $this->Create_URL('By File Name', array('operation' => 'listfiles'),'');
#      $byFile = str_replace('By File Name', '<b><font color=white>By File Name</font></b>', $byFile);

      $byBugzilla = $this->Create_URL('By Bugzilla Bug Number', array('operation' => 'listbugfixes'),'');
#      $byFile = str_replace('bugzilla', '<b><font color=white>By Bugzilla Bug Number</font></b>', $byFile);

      $search = $this->Create_URL('Search', array('operation' => 'searchform'),'');
#      $byFile = str_replace('bugzilla', '<b><font color=white>By Bugzilla Bug Number</font></b>', $byFile);
      $AuthorsNames =  stripslashes ($_COOKIE[authorn]);
      if (!$AuthorsNames){
	$AuthorsNames = "any";
      }
      $timerange1 = $_COOKIE[start_time];
      if (!$timerange1){
	$timerange1 = "any"; 
      }

      $project = $this->project;
      print "<html>
<title>$title</title>
<head>
<link rel=\"stylesheet\" type=\"text/css\"
href=\"style.css\">
</head>
<body>

<img src='art/softchange.gif'><br><img src='art/line.gif' width='600' height='4'>



<table border=0>
   <tr>
      <td valign=top><img src=art/$project-small.png></td>
      <td valign=top>
         <table border=0>
         <tr>
            <td valign=top>
               <h3>Project <font color=darkblue>$project</font><br><img src='art/line.gif'></h3>
            </td>
         </tr>
         <tr>
           <td colspan=1 valign=top><h3>$title</h3>
           </td>
            <td valign=top>
               <img src=$icon>
            </td>
         </tr>
         <tr>
           <td colspan=2 valign=top>
              <table border='0' cellpadding='1' cellspacing='3'>
              <tr>
 <td class=bar colspan=2><b><a href=index.php>Change Project</a></b></td>

              <td class=bar><b>$byDate</b></td>
              <td class=bar><b>$byAuthor</b></td>
              <td class=bar><b>$byFile</b></td>
              <td class=bar><b>$byBugzilla</b></td>
              <td class=bar><b>$search</b></td>
              </tr>
              <tr>
                <td colspan=5>
                   <hr>
                </td>
              </tr>
</table>
<table>
              <tr>
<td valign=top class=bar><b><a href='preferences.php?project=$project'>Preferences</a></b></td>
<td valign=top>The Time range is:<b> '$timerange1'  $_COOKIE[end_time]</b> </td>
<td valign=top>The Authors are: <b> '$AuthorsNames' </b></td>
<td valign=top><form name=form3 method=post action=index.php><input type=submit name=Submit value=Reset></form></td>
              </tr>
              </table>
            </td>
         </tr>
         </table>
      </td>
   </tr>
</table>

<hr>
 </b></td>

";
	
   }

   function SubHeader($title)
   {
	echo "<hr><h2>$title</h2>";
   }


   function Footer()
   {
	
   }

   function Print_Form_Head($operation)
   {
      echo "<form method=GET action='index.php'>";
      echo "<input name='project' type=hidden value='". $this->project . "'>\n";
      echo "<input name='operation' type=hidden value='$operation'>\n";
   }
 
   function Print_Form_Tail()
   {
      echo "
<input type='submit' value=' Submit Query '>
<input type=reset value=' Clear Entries '>
    </form>
";

   }

   function Display_Mr_Details($mr, $author, $date, $time, $log, $odd)
   {
	 $countFiles = $this->Count_Files_in_MR($mr);

	 if ($odd % 2) {
	    echo "<tr class=back1>\n";
	 } else {
	    echo "<tr class=back0>\n";
	 }

	 echo "<td valign=top>";
	 echo $this->Create_URL_Complete($this->MR_DETAILS_URL, $mr, array('operation' => 'detailsmr',
					 'mrid' => $mr),'') ;
	 echo "</td>\n";
      
	 echo "<td valign=top>";
	 echo $this->Create_URL($author, array('operation' => 'author',
						     'author' => $author),'') ;
	 echo "</td>\n";

	 echo "<td valign=top>$countFiles</td>";

	 echo "<td valign=top>";
	 echo $this->Create_URL($date, array('operation' => 'date',
						     'date' => $date),'') ;
	 echo "</td>\n";

	 echo "<td valign=top>$time</td>";
	 echo "<td valign=top><pre>$log</pre></td>";
	 echo "</tr>\n";

   }

   function Display_Mrs_Header($operation)
   {
      echo "<table border=0>\n";

      $this->Table_Header($operation,
			     array('MR id'                    => '',
				   'Author'                   => '',
				   'Files<br>Modified'        => '',
				   'Date'                     => '',
				   'Time'                     => '',
				   'Description'              => '')
			     );


   }

   function Display_Mrs($result, $operation) 
   {
      $this->Display_Mrs_Header($operation);

      $odd = 0;
      while ($row = pg_fetch_row($result, $i)) {
	 $mr = $row[0];
	 $author = $row[1];
	 $date = $row[2];
	 $time = $row[3];
	 $log = $row[4];
	 $log = $this->Format_Log($log);
	 $this->Display_Mr_Details($mr, $author, $date, $time, $log, $odd++);
      }
   
      echo "</table>";
      return $odd;
   }

   function Format_Log($log) 
   {
      $log = str_replace("<", "&lt;", $log);      
      $log = str_replace(">", "&gt;", $log);      

      $log = str_replace("NEWLINE", "<br>", $log);
      $log = str_replace("SEMICOLON", ";", $log);
      return $log;
   }

   function Format_File_State($state)
   {
      if ($state = 'Exp') {
	 $state = 'Active';
      } else {
	 $state = 'Removed';
      }
      return $state;
   }

   function Table_Header($operation, $columns)
   {
      echo "<tr class=black>\n";
      foreach ($columns as $name => $order) {
	 echo "<td valign=center><b>\n";
	 if ($order != '') {
	    echo $this->Create_URL($name, array('operation' => $operation,
                                                'orderby' => "$order "),'black') ;
	 } else {
	    echo $name;
	 }
	 echo "</b></td>\n";

      }
      echo "</tr>";
   }

   function Search_Form($default)
   {
   
  
  $project = $this->project;
  
      echo "
<form method=GET action='index.php'>
<input name='operation' type=hidden value='search'>
<input name='project' type=hidden value='$project'>
<b>Query:</b>
<input size=80 name='log' value='$default'>
</textarea><br>
<HR>
<input type='submit' value=' Submit Query '>
<input type=reset value=' Clear Entries '>
</form>
     ";
   }

   function Bonsai_Revision_URL($filename, $revision, $revisionold)
   {
     
     $dir = $this->project . '/' . dirname($filename);
     $name = basename($filename);

     $url = 'http://cvs.gnome.org/bonsai/cvsview2.cgi?diff_mode=context&whitespace_mode=show&file=' .
       $name . "&branch=&root=/cvs/gnome&subdir=$dir&command=DIFF_FRAMESET&rev1=$revision&rev2=$revisionold";
     return $url;
   }


}
?>
