<!DOCTYPE html>
<html >
  <head>
    <meta charset="utf-8">
    <title> Index 03 </title>
  </head>
  <body>
    <?php
		function formatString(){
			for ($a=0; $a <3 ; $a++) {
				$randValue =rand(97,122);
				if (in_array(chr($randValue), ["j", "k", "x", "y", "z"])){
					echo "<span style='color:green'>".chr($randValue)."</span>";
				}elseif (in_array(chr($randValue), ["a","w","i","o","u"])){
					echo "<span style='color:red'>".chr($randValue)."</span>";
				}else{
					if (in_array(chr($randValue), ["c","g"])){
						echo "<span style='color:blue'>".chr($randValue)."</span>";
					}else{
						echo chr($randValue);
					}
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
