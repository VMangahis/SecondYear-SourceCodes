<?php

$origString = $_POST['orig'];
$arrayString = str_split($origString);

function reverse($arrayString)
{
	echo count($arrayString);
	for($i = count($arrayString)-1; $i >=0; $i--)
	{
		echo $arrayString[$i];
	}
	
}

reverse($arrayString);





?>