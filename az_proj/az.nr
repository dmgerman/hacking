 (text from the Central States VHF Soc abstracts, 1994                    




           az_proj.ps - A program to create azimuthal equidistant
                               map projections

      Joseph Mack (NA3T) and Michael Katzmann (NV3Z / VK2BEA / G4NYV) *



   Abstract

        The azimuthal equidistant, or 'great circle' map  projection  is  a
   useful  tool  for  the  radio amateur in quickly determining the correct
   direction to point antennas between two points on  the  surface  of  the
   earth.  Unlike  conventional maps, that attempt to maintain the shape of
   surface features, the azimuthal projection maintains only the  direction
   and  distance  from a single site. The map, consequently, is only useful
   for that site.

        It was felt that a simple, inexpensive method for the individual to
   create their own azimuthal projections was desirable. The flexibility to
   customize the map, in order to show a particular area  of  interest  and
   include  features  required  by the user, were of prime importance.  The
   criteria of simplicity, and  non-dependence  on  specific  hardware  and
   software  were  the  principle  motives  in choosing the Postscript page
   description language to implement this idea.


   Capabilities

        The program is capable of displaying a map from almost any point on
   the  earth  at  any scale. The map may be offset, so that an area can be
   enlarged without having to include the base site. Thus a  map  based  on
   Washington  DC  has  the ability to show, for example, only Europe. Grid
   squares, based on the Maidenhead system, may be overlayed on the map  at
   the  discretion  of  the  user. Likewise compass bearings are optionally
   available.  Facilities have been included to print either  callsigns  or
   country  names from a standard file of DXCC callsigns available from the
   ARRL bulletin board.  Labels  may  be  added  to  the  map  to  indicate
   features at the discretion of the user. One use of this might be to pro-
   duce a local repeater or beacon map.

        All of the program and data files in this package are freely redis-
   tributable.   The  main  map data is derived from the C.I.A. world data-
   base. It has a resolution of between 50 and 100 metres. Maps can thus be
   produced  of quite small areas whilst retaining reasonable detail. Coun-
   try borders, major rivers and lakes, islands and U.S., Canadian and Aus-
   tralian states are included in the database. There is approximately four
   megabytes of ascii data files, split into continents.

   ________
     *
       Joseph Mack.      (301) 402-4573 (Work)   Internet: mack@ncifcrf.gov
       Michael Katzmann. (410) 721-5151 (Work)   Internet: michael%vk2bea@secondsource.COM











    NV3Z & NA3T            Azimuthal Map Projections                 Page 2


   Implementation

        Postscript is a programming language developed by Adobe Systems for
   use in desktop publishing. It is a page description language. That is to
   say, one uses instructions to tell the device how to print characters or
   figures  on  the  page. A Postscript printer differs from a conventional
   printer in that you must send it not just the text you want printed, but
   a  program that tells the printer how the text or data received is to be
   interpreted.  Postscript is  a  stack  orientated  language,  much  like
   Forth,  and  its  operation  is somewhat analogous to an RPN calculator.
   Data is pushed on the stack (last in first out) and then  operated  upon
   by   a   function.   The  az_proj.ps  program  is  entirely  written  in
   Postscript, so that with a  Postscript  capable  printer,  all  that  is
   required to create a map is to customize the program options and send it
   (azproj.ps) and the data files to the printer. It is the  printer,  not
   the  computer  that  executes the program, transforming the latitude and
   longitude information from the data files into bearing and distance, and
   then  drawing  the  map.  In that sense the program is computer indepen-
   dent, since the only purpose of the computer is to store the plain ASCII
   files.



   ...but I don't have a Postscript printer!

        If your printer doesn't understand Postscript, it  is  still  quite
   likely   that  you  can  use  this  program.  A  freely  redistributable
   Postscript interpreter is available that supports a myriad  of  printers
   and  display  devices.  This  program  is Ghostscript and is distributed
   under the terms of the GNU  public  license.  It  runs  on  MS-DOS,  MS-
   Windows,  Unix,  VMS  and  other  systems.   Ghostscript  interprets the
   Postscript code and creates a bitmap that is printed or displayed. Under
   this  arrangement,  the program is executed by the host computer, and it
   is the printer that is the 'dumb' recipient of the bitmap.

        Printer drivers for HP deskjet and paintjet  series,  HP  laserjet,
   Cannon   bubblejet,   Epson   dot  matrix  and  others  are  built  into
   Ghostscript. Video display  drivers,  which  render  Postscript  on  the
   screen,  are  present for VGA, super VGA, MS-windows, the X Windows sys-
   tem, GIF and PCX formats. This is an ideal way to preview  the  program,
   to ensure that the output is what you expect, even if you actually print
   it on a Postscript printer.  If you have a fast  computer,  Ghostscript*
   will  probably  give  you  better performance than a Postscript printer.
   Postscript printers rarely have floating point math hardware  installed,
   which speeds the execution of this program greatly. An Intel 486/66 pro-
   cessor is 18 times faster than an HP1200C/PS Postscript printer in  exe-
   cuting this program.
   ________
     * Ghostscript is freely available (with the GNU License), on the
       internet from ftp.cs.wisc.edu:/pub/ghost, and from the GNU servers
       everywhere.
       Ghostscript is Copyright Aladdin Enterprises.











    NV3Z & NA3T            Azimuthal Map Projections                 Page 3


   Customizations

        The program has been designed to allow easy modification, in  order
   to  tailor  the map to the user's preferences. Those parameters that are
   most often changed, are clustered in the 'options' array.   These  vari-
   ables are:

      o latitude and longitude of the QTH, (the position that the  distance
        and bearing is referenced to)

      o latitude and longitude of the center of the map, (the center of the
        map does not need to be the same as the QTH)

      o scale of the map in either km:cm or degrees  of  solid  angle  sub-
        tended  from  the  center  of the earth (each degree is 60 nautical
        miles)

      o title of the map

      o enable printing of lettered Maidenhead grid square boundaries

      o enable printing of lettered Maidenhead designators

      o enable printing of numbered Maidenhead grid square boundaries

      o enable printing of numbered Maidenhead designators

      o enable printing of compass bearing lines

      o enable printing of distance circle

      o enable printing of outer bearing circle

      o if DXCC data file supplied, print either callsign or country name

   The options array for a map of the continental US, based on Greenbelt MD
   but centered on the mid west, would be configured as follows:
   /options
   [
       39.0        -76.845         (WA3NAN - NASA Goddard)
       40          -89             true    % The midwest & enable offset
       200         true                    % scale, km/cm (degrees),
       true                                % landscape (portrait)
       on          on                      % letter grid squares, labels
       on          on                      % number grid squares, labels
       on                                  % compass circumference,
       on          off                     % compass radial spokes, outerborder
       true                                % callsigns (country name)
   ] def

   A comment in Postscript is preceded by  a  '%',  thus  we  are  able  to
   include  some explanation with each variable.  Other standard Postscript











    NV3Z & NA3T            Azimuthal Map Projections                 Page 4


   variables can be modified to change color,  line  thickness,  fonts  and
   font  sizes.  These  are  heavily  sign-posted  throughout the code, and
   should be obvious to non-Postscript programmers.  Colors for the various
   features  are  defined  in  terms  of  R  G  B values from 0 (dark) to 1
   (bright). For example we define a variable lightred as:
   /lightred      { 1.0 0.33 0.33  }  def

   We can use this later to define the color of, say, our grid square boun-
   daries.
   /grid_locator_letter_color      /lightred cvx   def

   In Postscript a variable name is preceded by a '/'. The def assigns  the
   value to the variable.


   Examples

        The following example maps are intended to show some  of  the  pro-
   grammes  capabilities.  Since they are rendered in monochrome here, ena-
   bling all the features on the one map  would  be  quite  confusing.  The
   enhanced  definition  available  with a color print makes this practical
   however.  The following prints show:

    1.  The whole world with the compass lines and outer border.

    2.  Western Europe as it appears from Annapolis.

           - This also shows the DXCC  country  callsigns  which  are  read
             directly from the ARRL file.

    3.  A regional map of the north-east US based on Newington CT.

           - This includes  both  lettered  and  numbered  Maidenhead  grid
             squares.

    4.  The CONUS based on Annapolis but centered on the mid-west.


   Conclusion

        It is hoped that this program will be of use to the amateur commun-
   ity,  and we encourage its wide distribution. There are still many ideas
   to be included in future versions, and with constructive  feedback  from
   users, no doubt its utility will be enhanced.
















