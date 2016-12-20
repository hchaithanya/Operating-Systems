echo Enter first filename
read first
echo Enter second filename
read second
cat $first > third
cat $second >> third
clear
echo After concatination of contents of entered two files
echo ---------------------
cat third | more
echo ---------------------
