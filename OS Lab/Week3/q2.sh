read a b c
d=$((b*b-4*a*c))
if [ $d -ge 0 ]
then
	case $d in
		"0" )
			#x=`expr sqrt\(d\) | bc -l `
			r1=`expr 0 - $b / \( 2 \* $a \) `
			echo Roots are equal and They are $r1
			;;	
		*	)
			#x=`expr sqrt\($d\) | bc -l `
			#y="scale = 3; sqrt( $d )" | bc
			#echo $x
			#r1 = $((-1*b/2*a + x/2*a))
			#ans=`expr $x \ / \( 2 \* $a \) `
			r1=$(echo "scale = 2; -($b)/(2*$a) + sqrt($d)/(2*$a)" | bc -l) 
			#echo $r1
			r2=$(echo "scale = 2; -($b)/(2*$a) - sqrt($d)/(2*$a)" | bc -l) 
			#r1=`expr 0 - $b / \( 2 \* $a \) + $ans `
			#r2 = $((-1*b/2*a - x/2*a))
			#r2=`expr 0 - $b / \( 2 \* $a \) - $ans `
			echo Roots are $r1 and $r2
			;;
	esac
else
	real=$(echo "scale = 2; -($b)/(2*$a)" | bc -l)
	img=$(echo "scale = 2; (sqrt(-($d)))/(2*$a)" | bc -l)
	echo Roots are imaginary and they are $real + i$img and $real - i$img 
fi
#echo $d