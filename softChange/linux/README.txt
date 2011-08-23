
I have prepared data for three projects: linux, ruby-on-rails and
postgresql (each in its corresponding directory).

The data extracted from their version control systems is split into
the following files:

- Files.txt
- logs.txt
- meta.txt

Each of these files is in plain text, one record per line, and each
field is separated by a ; 

Each commit in version control is composed of one or more changes to a
file. Each commit is identified by its id (commit-id), composed of 40
characters.

The format of the files is the following:

----------------------------------------------------------------------
- meta.txt. This file contains the main information of each commit:

commit-id;author;date;is-merge?

   commit-id: the commit id
   
   author:    its author (an email address, some persons might have more
              than one email address, for example, Linus Torvalds has used
              Linus Torvalds <torvalds@linux-foundation.org> 
              and Linus Torvalds <torvalds@ppc970.osdl.org>
   
   date:      date and Time of commit (includes Timezone)

   is-merge?  In git, commits can be of two types: regular ones, and
              merges. A merge joins two or more branches. If this
              field is a 1, then it is a merge, otherwise a regular
              commit.

----------------------------------------------------------------------
- Files.txt. This file contains the files that are modified in a given
  commit, and the number of lines added and lines removed in such file.

commit-id;filename;lines-added;lines-removed

   commit-id: the commit id

   filename:  a filename modified in such commit
 
   lines-added: How many lines were added in such commit to the file.

   lines-removed: how many lines were removed.

----------------------------------------------------------------------
- logs.txt: this file contains the log of the commit

commit-id;log

   commit-id: the commit id
  
   log: the description of the commit as submitted by the author. Some
        fields are replaced to avoid problems during processing: ; is
        replaced with <<SEMICOLON>>; new lines with <<NL>>; returns
        with <<RETURN>>.

----------------------------------------------------------------------





