read n
i=0
a=0
b=1
c=0
while [ $i -lt $n ]
do
	echo $c
	a=$(($b))
	b=$(($c))
	c=$(($a+$b))
	i=$(($i+1))
done
