#!/usr/bin/perl

# THe idea is to create a program that does graphing easier

# Input Format:
# Two files
# Nodes: nodeid;label
# Edges: nodeid1;nodeid2;label;width;color




use strict;
use Graph::Directed;
use Getopt::Long;
use GraphViz2;

my $rankDir = "LR";

my $defaultPenWidth = 1;
my $defaultColorEdge = 'black';

my $defaultGraphColorScheme;

#$defaultGraphColorScheme = "/spectral11";
$defaultGraphColorScheme = "/set312";
$defaultGraphColorScheme = "/paired12";

my $defaultNodeColor = "1";
my $defaultNodeShape = 'oval';
my $defaultNodeSize = 1;
my $defaultNodeFill = 'white';

my $format = <<END;

The input format is:

Nodes:
nodeid;label;color;shape

Edges:
nodeid1;nodeid2;label;weight;color

END

my $nodesFile = shift @ARGV;
my $edgesFile = shift @ARGV;
my $outputFile = shift @ARGV;
my $root = shift @ARGV;

if ($nodesFile eq "" or $edgesFile eq "" or $outputFile eq "") {
    Usage();
}

my $g = Read_Graph($nodesFile, $edgesFile);

if (defined($root)) {
    $g = Create_Subgraph($g, $root);
}

my $gv =  Create_GraphViz($g);

$gv -> run(format => "dot", output_file => "/tmp/debug.dot", directed=> 1);
$gv -> run(format => "png", output_file => "/tmp/debug.png", directed=> 1);
$gv -> run(format => "pdf", output_file => $outputFile);

exit(0);

sub Create_Subgraph {
    my ($g, $root) = @_;
    
    print "Creating subgraph from node [$root]\n";

    die "this root does not exit [$root] " unless $g->has_vertex($root);

    my %toKeep = map { $_ => 1 } $g->all_successors($root);
    $toKeep{$root} = 1;
    my @nodes = $g->vertices();
    for my $n (@nodes) {
	if (not exists($toKeep{$n}) and 
	    not Contiguous($g, $n, keys %toKeep)
	    ) {
	    print "---Deleting $n\n";
	    $g->delete_vertex($n);
	}

    }
    print "Done with subgraph\n";

    return $g;

}

sub Contiguous
{
    my ($g, $t, @toKeep) =@_;

    foreach my $n (@toKeep) {
	print "Checking ... [$t][$n]\n";
	if ($g->has_edge($t, $n)) {
	    return 1;
	}
    }
    return 0;
}

sub Create_GraphViz {
    my ($g) = @_;

    my $gv = GraphViz2->new(
	global => {directed => 1},
	node => {shape => 'oval',style=>'bold', fontsize=>13},
	edge => {fontsize=>11},
	graph=> {colorscheme=>$defaultGraphColorScheme, splines=>'true', rankdir => $rankDir, margin=>0.0},
	nodesep => 20,
	name => "simple graph",
	);
    
    my @nodes = $g->vertices();
    for my $e (@nodes) {
	print "To add node [$e]\n";
	my $shape = $g->get_vertex_attribute($e, "shape");
	my $color = $g->get_vertex_attribute($e, "color");
	my $label = $g->get_vertex_attribute($e, "label");
	my $size = $g->get_vertex_attribute($e, "size");
	my $fill = $g->get_vertex_attribute($e, "fillcolor");
	$color = Translate_Color($color);
	$gv->add_node(name=>$e, label=>$label, color=>"$color", shape=>$shape, width=>$size, fillcolor=>$fill, style=>'filled');
    }
    print "Done part 1\n";
    my @edges = $g->edges;

    for my $e (@edges) {
	my $label = $g->get_edge_attribute($$e[0], $$e[1], "label");
	my $width = $g->get_edge_attribute($$e[0], $$e[1], "width");
	my $color = $g->get_edge_attribute($$e[0], $$e[1], "color");
#	my $color = $g->get_vertex_attribute($$e[0], "color");

	my $color = Translate_Color($color);

	printf("Node ", $$e[0], " does not exist in nodes\n") if (not $g->has_vertex($$e[0]));
	printf("Node ", $$e[1], " does not exist in nodes\n") if (not $g->has_vertex($$e[1]));
	print "Adding ", $$e[0], " " , $$e[1], " [$label]\n";
	$gv->add_edge(from=>$$e[0], to=> $$e[1], label=>$label, penwidth=>$width, color=>"$color", arrowhead=>'normal', dir=>'forward');
    }
    return $gv;
}

sub Translate_Color
{
    my ($color) = @_;
    if (int($color) eq $color) {
	if ($color != 6) {
	    $color = "$defaultGraphColorScheme/$color";
	} else {
#	    $color = "/pastel23/1";
	    $color = "/pubugn5/5";
	}
    } 
    return $color;
}


sub Read_Graph
{
    my ($nodesFile, $edgesFile) = @_;
    my $g = Graph::Directed->new();
    Read_Nodes($g, $nodesFile);
    Read_Edges($g, $edgesFile);
    return $g;
}


sub Read_Nodes
{
    my ($g, $fname) = @_;
    my %nodes;
    open(IN, $fname) or die "unable to read [$fname]";
    while (<IN>) {
	next if /^\s*#/;
	chomp;
	my ($id, $label, $color, $shape, $size,$fill) = split(';');
	if ($id eq '' or $label eq '') {
	    print "illegal record [$_]\n";
	    next;
	}
	if ($shape eq '') {
	    $shape = $defaultNodeShape;
	}
	if ($color eq '') {
	    $color = $defaultNodeColor;
	}
	if ($size eq '') {
	    $size = $defaultNodeSize;
	}
	if ($fill eq '') {
	    $fill = $defaultNodeFill;
	}
	print "reading node [$id][$label] color [$color] size [$size] fill [$fill]\n";
	$g->add_vertex($id);
	$g->set_vertex_attribute($id, "label", $label);
	$g->set_vertex_attribute($id, "color", $color);
	$g->set_vertex_attribute($id, "shape", $shape);
	$g->set_vertex_attribute($id, "size", $size);
	$g->set_vertex_attribute($id, "fillcolor", $fill);
    }
    print "1. this graph has ", scalar($g->vertices()), " vertices\n";

    close($fname);
}

sub Read_Edges
{
    my ($g, $fname) = @_;
    my %edges;
    open(IN, $fname) or die "unable to read [$fname]";
    while (<IN>) {
	next if /^\s*#/;
	chomp;
	my ($a, $b, $label, $width, $color) = split(';');
	if ($a  eq '' or $b eq '' or $label eq '') {
	    print "illegal record [$_]\n";
	    next;
	}
	if ($width <= 0) {
	    $width = $defaultPenWidth;
	}
	if ($color eq '') {
	    $color = $defaultColorEdge;
	}

	print "reading edge [$a]->[$b] label [$label] color [$color] size [$width]\n";
	$g->add_edge($a, $b);
	$g->set_edge_attribute($a, $b, 'label', $label);
	$g->set_edge_attribute($a, $b, 'width', $width);
	$g->set_edge_attribute($a, $b, 'color', $color);
    }
    close($fname);
}


sub Usage{
    die "Usage $0 <nodes> <edges> <outputfile>\n" . $format;
}

