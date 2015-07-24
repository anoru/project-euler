#!/usr/bin/perl

use strict;
use warnings;

use Test::More tests => 9;

use Test::Differences (qw( eq_or_diff ));

sub mytest
{
    local $Test::Builder::Level = $Test::Builder::Level + 1;

    my ($needle, $count, $blurb) = @_;

    return eq_or_diff(
        scalar(`perl euler-305-v1.pl $needle $count`),
        scalar(`bash good-results.bash $needle $count`),
        "$blurb - $needle $count",
    );
}

{
    # TEST
    mytest(1, 100, "Euler 305");

    # TEST
    mytest(2, 100, "Euler 305");

    # TEST
    mytest(3, 100, "Euler 305");

    # TEST
    mytest(10, 100, "Euler 305");

    # TEST
    mytest(11, 100, "Euler 305");

    # TEST
    mytest(9, 100, "Euler 305");

    # TEST
    mytest(100, 100, "Euler 305");

    # TEST
    mytest(101, 20, "Euler 305");

    # TEST
    mytest(102, 20, "Euler 305");
}
