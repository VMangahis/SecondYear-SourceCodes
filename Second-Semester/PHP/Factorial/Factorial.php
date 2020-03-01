<?php

$num = $_POST['fact'];
function factorial($n)
{
	if($n == 1)
	{
		return 1;
	}	
	else
	{
		return $n*factorial($n-1);
	}
}


echo "Number: ".$num."<br>";
echo "Factorial Value: ".factorial($num);

	
?>
