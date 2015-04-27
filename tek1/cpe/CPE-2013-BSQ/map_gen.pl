#!/usr/local/bin/perl -w
## map_gen.pl for bsq in /home/gicque_p/local/cpe/CPE_2013_BSQ
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Sun Dec  8 14:17:10 2013 Pierrick Gicquelais
## Last update Sun Dec  8 14:19:59 2013 Pierrick Gicquelais
##

if ((scalar @ARGV) != 3)
{
    print "program x y density\n";
    exit;
}

my $x = $ARGV[0];
my $y = $ARGV[1];
my $density = $ARGV[2];
my $i = 0;
my $j = 0;

print $y . "\n";

while ($i < $j)
{
    $j = 0;
    while ($j < $x)
    {
	if (int(rand($y)*2) < $density)
	{
	    printf "o";
	}
	else
	{
	    print ".";
	}
	$j++;
    }
    print "\n";
    $i++;
}
