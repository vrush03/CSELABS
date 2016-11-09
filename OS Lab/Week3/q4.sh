read n
f=n
ans=0
until [ $f -eq 0 ]
do
	rem=$(($f%10))
	ans=$(($ans*10 + $rem))
	f=$(($f/10))
	
done
echo $ans