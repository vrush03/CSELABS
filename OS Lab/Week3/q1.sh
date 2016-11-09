read x
if [ `expr $x % 2` -eq 0 ]
then
echo $x is Even
else
echo $x is Odd
fi