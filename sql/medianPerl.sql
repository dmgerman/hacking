CREATE OR REPLACE FUNCTION median(text, text)
RETURNS float
LANGUAGE plperl AS
$$
BEGIN { strict->import(); }

  my ($tname,$cname) = @_;

  my $SQL = "SELECT count($cname) AS t FROM $tname";
  my $rc = spi_exec_query($SQL);
  my $total = $rc->{rows}[0]{'t'};
  $total < 2
     and die qq{Median needs at least 2 rows\n};

  my $offset = ($total-1)/2;
  if ($total%2) {
    $SQL = "SELECT $cname AS median FROM $tname
       ORDER BY $cname OFFSET $offset LIMIT 1";
  }
  else {
    $offset--;
    $SQL = "SELECT avg($cname) AS median FROM
    (SELECT $cname FROM $tname
     ORDER BY $cname
     OFFSET $offset LIMIT 2
  ) AS foo";
}
$rc = spi_exec_query($SQL);
return $rc->{rows}[0]{median};
$$;
