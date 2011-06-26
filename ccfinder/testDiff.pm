#!/usr/bin/perl


use strict;
require "ccdiff.pm";
require "cctokens.pm";

my $diff = <<END
--- ./apache.5007/src/modules/standard/mod_auth.c	2008-04-12 10:42:49.000000000 -0700
+++ ./apache.6075/src/modules/standard/mod_auth.c	2008-04-12 17:10:06.000000000 -0700
@@ -2 +2 @@
- * Copyright (c) 1995-1998 The Apache Group.  All rights reserved.
+ * Copyright (c) 1995-1999 The Apache Group.  All rights reserved.
@@ -77,3 +76,0 @@
-#if defined(HAVE_CRYPT_H)
-#include <crypt.h>
-#endif
@@ -205,0 +203 @@
+    char *invalid_pw;
@@ -222,2 +220,2 @@
-    /* anyone know where the prototype for crypt is? */
-    if (strcmp(real_pw, (char *) crypt(sent_pw, real_pw))) {
+    invalid_pw = ap_validate_password(sent_pw, real_pw);
+    if (invalid_pw != NULL) {
@@ -225 +223,2 @@
-		    "user %s: password mismatch: %s", c->user, r->uri);
+		      "user %s: authentication failure for \"%s\": %s",
+		      c->user, r->uri, invalid_pw);
END
    ;

my $oldClones = <<END
287	./src/modules/standard/mod_auth.c       	   629	     2	    87    13    52    97     8
289	./src/modules/standard/mod_auth.c       	   825	    52	    97     8   117   122     8
288	./src/modules/standard/mod_auth.c       	    92	   558	   208     8   648   223     5
290	./src/modules/standard/mod_auth.c       	  1046	   839	   261     5   901   270     2
291	./src/modules/standard/mod_auth.c       	   652	   903	   270     5   953   277     2
END
    ;

my $newClones = <<END
454	./src/modules/standard/mod_auth.c       	   599	     2	    84    13    52    94     8
456	./src/modules/standard/mod_auth.c       	  1187	    52	    94     8   117   119     8
450	./src/modules/standard/mod_auth.c       	   884	   372	   159    26   505   178    24
455	./src/modules/standard/mod_auth.c       	   913	   562	   206     8   652   220     5
451	./src/modules/standard/mod_auth.c       	   602	   781	   249     8   838   258    43
452	./src/modules/standard/mod_auth.c       	  1148	   841	   260     5   903   269     2
457	./src/modules/standard/mod_auth.c       	   956	   905	   269     5   955   276     2
453	./src/modules/standard/mod_auth.c       	  1128	   959	   276    10  1019   285     4
END
    ;

my @olds = split(/\n/, $oldClones);

my $d = ccdiff->new("before.c", "after.c");

my $tOld = cctokens->new("before.c.cpp.ccfxprep");
my $tNew = cctokens->new("after.c.cpp.ccfxprep");

#$d->Hunk_Locations_Print;

# these are the old...
printf("%-40s %6s:%6s  %6s:%6s (%6s)\n", "Name","Line","Col","Line", "Col","Len");

foreach my $a (@olds) {
    chomp $a;
    my @f = split(/[ \t]+/, $a);
#    printf("-------------------                                                   %s %6d:%6d  %6d:%6d (%6d)\n", $f[1], $f[4], $f[5], $f[7], $f[8], $f[7]-$f[4]+1);

    printf("%-40s %6d:%6d  %6d:%6d (%6d)\n", $f[1], $d->line_Translate($f[4]), $f[5], $d->line_Translate($f[7]), $f[8], $f[7]-$f[4]+1);

    # build the clone...
#    my $s = $tOld->token_Sequence_Abstract($f[3], $f[6]);
    my $s = $tOld->token_Sequence($f[3], $f[6]);
#    print ">>>$s\n";

}


print "-------------------------------\n";
my @news = split(/\n/, $newClones);

foreach my $a (@news) {
    chomp $a;
    my @f = split(/[ \t]+/, $a);
    printf("%-40s %6d:%6d  %6d:%6d (%6d)\n", $f[1], $f[4], $f[5], $f[7], $f[8], $f[7]-$f[4]+1);
#    my $s = $tNew->token_Sequence_Abstract($f[3], $f[6]);
    my $s = $tNew->token_Sequence($f[3], $f[6]);
#    print ">>>$s\n";
}


#for my $i (1..240){
#    print "$i:", $d->line_Translate($i), "\n";
#}
#
