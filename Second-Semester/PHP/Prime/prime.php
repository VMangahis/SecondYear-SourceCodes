<?php


$num = $_POST['prim'];


function isPrime($n){
	$divisor = 0;
	for($i = 1; $i<= $n ; $i++)
	{
		if($n%$i==0)
		{
			$divisor+=1;
		}
	}
	
	
	if($divisor>2)
	{
		echo $n." is not prime number";
	}
	else{
		echo $n." is a prime number";
	}
	
}
isPrime($num);


?>