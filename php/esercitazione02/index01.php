<?php
	srand();
	$sentinella = rand();
	$somma = 0; 
	$n = 0;	// contatore numeri che superano la sentinella
	$a = 0; // contatore numeri totali
?>
<!doctype HTML>
<html>
	<head>
		<title>Index01</title>
		<meta charset="utf-8"/>
	</head>
	<body>
		<p>
			<?php echo "sentinella: $sentinella\n" ?>
		</p>
		<p>
			<?php
				while ($n<10){
					$r = rand();
					$a++;
					$somma += $r;
					
					if ($r > $sentinella){
						$n++;
						echo "<span style=\"color:red;\">$r</span>\n";
					} else {
						echo "$r\n";
					}
					echo "\t\t\t";
					
				}	
				echo "\n";
			?>
		</p>
		<p>
			<?php
				$media = $somma / $a;
				echo "media: $media\n";	
			?>
		</p>
	</body>
</html>
