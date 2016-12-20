#!/bin/sh
echo "Enter the l and b of rectangle"
read l
read b
area=`expr $l \* $b`
p=`expr $l + $b`
peri=`expr 2 \* $p `
echo "Area = $area"
echo "Perimeter = $peri"
echo "Enter radius"
read r
areac=`expr 2 \* 3 \* $r`
echo "Area of Circle = $areac"
