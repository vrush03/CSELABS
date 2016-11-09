read a b

while [ $a != $b ]
do
	if [ $a -gt $b ] 
	then
		a=$((a-b))
	#echo $a
	else
	b=$((b-a))
	fi
done
echo $a