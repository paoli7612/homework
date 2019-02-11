<!doctype HTML>
<html>
	<head></head>
	<body>
		<?php
			function is_primo($n){
				$i = 2;
				while ($n > $i){
					if ($n%$i == 0)
						return false;
					$i++;
				}
				return true;
			}
		
			function random_array($len=10, $min=0, $max=1000){
				$array = array_fill(0,$len-1,-1);
				for ($i=0; $i<10; $i++){
					do{
						$r = rand($min,$max);
					} while(in_array($r, $array));
					$array[$i] = $r;
				}
				return $array;
			}
			
			$array = random_array();
			echo "<table border=\"2\">";
			for ($i=0; $i<count($array); $i++){
				if (is_primo($array[$i]))
					$color="red";
				else $color="black";
				echo "<tr><td style=\"color: $color\">$array[$i]</td></tr>";
			}
			echo "</table>";
		?>
		
		<script>
			var n = prompt("inserisci il numero");
			
		</script>
	</body>
</html>
