s=0
for (( c=2; c<100; c++))
do
   flag=0
   for (( j=2;j<=c/2;j++))
   do
   	if [ `expr $c % $j` -eq 0 ]
   	then
   		flag=1
   		#echo here
   		break
   	fi
   done
if [ $flag -eq 0 ]
then
	echo $c
	s=$((s+$c))
fi
done
echo $s