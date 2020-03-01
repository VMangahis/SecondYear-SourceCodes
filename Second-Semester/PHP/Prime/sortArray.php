<?php

$arr = array(8,4,2,10,5);

function sortArray($arr)
{
	for($sor = 0; $sor < count($arr)-1; $sor++)
	{
		for($insor=0; $insor < count($arr)-$sor-1; $insor++)
		{
		if($arr[$insor] > $arr[$insor+1])
		{
			$temp = $arr[$insor];
			$arr[$insor] = $arr[$insor+1];
			$arr[$insor+1] = $temp;
		}
		}
	}
	return $arr;
}


echo "Unsorted Array".'<br>';
foreach($arr as $x)
{
	echo $x.',';
}

$arr = sortArray($arr);



echo '<br>'."Sorted Array".'<br>';
foreach($arr as $s)
{
	echo $s.',';
}



?>