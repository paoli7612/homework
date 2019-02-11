<!DOCTYPE html>
<html >
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
    <?php
		function formatString(){
			for ($i=0; $i <3 ; $i++) {
				$randValue =rand(0,99);
				if($randValue>0 and $randValue<=20){
					echo "2";
				}elseif ($randValue>20 and $randValue<=55) {
					echo "X";
				}else{
					echo "1";
				}
			}
		}
		function show_table($righe,$colonne) {
			for ($i=0; $i < $righe ; $i++) {
				echo "\t\t<tr>\n\t\t\t";
				for ($j=0; $j <$colonne ; $j++) {
					echo "<td>";
					formatString();
					echo "</td>";
				}
				echo "\n\t\t</tr>\n";
			}
		}
		srand();
		$randomTablenum = rand(0,6);
		echo "<table>\n";
		switch ($randomTablenum) {
			case 0:
				show_table(2,20);
				break;
			case 1:
				show_table(4,10);
				break;
			case 2:
				show_table(5,8);
				break;
			case 3:
				show_table(8,5);
				break;
			case 4:
				show_table(10,4);
				break;
			case 5:
				show_table(20,2);
				break;
			case 6:
				show_table(2,20);
				break;
		}
		echo "\t</table>\n";
	?>
  </body>
</html>
