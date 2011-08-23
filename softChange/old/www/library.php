<?php

   function Get_Lines($text, $fromLine, $toLine)
   {
      $count = 0;
      $index = 0;
      $output = '';

      echo "<pre>\n[$fromLine, $toLine]\n</pre>";

      while ($index < strlen($text) && $count < $fromLine) {
	 if ($text[$index] == "\n") {
	    $count++;
	 }
	 $index ++;
      }
      
# We start here...
      $start = $index;

      while ($index < strlen($text) && $count < $toLine) {
	 if ($text[$index] == "\n") {
	    $count++;
	 }
	 $index ++;
      }

      $output = substr($text, $start, $index-$start);
      return $output;
   }

?>

