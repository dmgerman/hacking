#!/usr/bin/perl

my $penalty = 0;
my $thisPenalty = 3;

my @elements = (
'Ac',
'Ag',
'Al',
'Am',
'Ar',
'As',
'At',
'Au',
'B',
'Ba',
'Be',
'Bh',
'Bi',
'Bk',
'Br',
'C',
'Ca',
'Cd',
'Ce',
'Cf',
'Cl',
'Cm',
'Co',
'Cr',
'Cs',
'Cu',
'Db',
'Dy',
'Er',
'Es',
'Eu',
'F',
'Fe',
'Fm',
'Fr',
'Ga',
'Gd',
'Ge',
'H',
'He',
'Hf',
'Hg',
'Ho',
'Hs',
'I',
'In',
'Ir',
'K',
'Kr',
'La',
'Li',
'Lr',
'Lu',
'Md',
'Mg',
'Mn',
'Mo',
'Mt',
'N',
'Na',
'Nb',
'Nd',
'Ne',
'Ni',
'No',
'Np',
'O',
'Os',
'P',
'Pa',
'Pb',
'Pd',
'Pm',
'Po',
'Pr',
'Pt',
'Pu',
'Ra',
'Rb',
'Re',
'Rf',
'Rh',
'Rn',
'Ru',
'S',
'Sb',
'Sc',
'Se',
'Sg',
'Si',
'Sm',
'Sn',
'Sr',
'Ta',
'Tb',
'Tc',
'Te',
'Th',
'Ti',
'Tl',
'Tm',
'U',
'Uub',
'Uuh',
'Ds',#'Uun',
'Uuo',
'Uup',
'Uuq',
#'Uus',
'Uut',
'Rg',#'Uuu',
'V',
'W',
'Xe',
'Y',
'Yb',
'Zn',
'Zr',
);

my %ph;

foreach my $a (@elements) {
    $ph{$a} = $a;
}

while (<>) {
    $thisPenalty = $penalty;
    chomp;
    if (Is_Elementic($_)) {
        print "YES: [$_] [$thisPenalty]\n";
    } else {
        print "NO: [$_]\n";
    }
}




sub Is_Elementic
{
    my ($w) = @_;
    

    while ($w =~ /^[^a-z]/i) {
        $w = $'; # $';
    }
    return 1 if $w eq "";


    foreach my $l (@elements) {
        if ($w =~ /^$l/i) {
            my $t = $'; #';
            return Is_Elementic($t); #'; #'
        } 
    }
    if ($thisPenalty > 0) {
        $thisPenalty--;
        return 1;
    }
    return 0;
}
