<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
    <?php
      
	  // creo un vettore posizioni con 
	  //  5 valori casuali in [0..9] 
	  //  senza ripetizioni
      $posizioni = array_fill(0,4,-1);
      for ($i=0; $i<count($posizioni); $i++){
        do {
          $p = rand(0,9);
        }while(in_array($p, $posizioni));
        $posizioni[$i] = $p;
      }

	  // creo un vettore esplictamente e
	  //  mostro il valore di cinque celle
	  //  a caso (sempre diversi)
	  $vettore = array(1,2,3,4,5,6,7,8,9,10);
      for ($i=0; $i<count($posizioni); $i++){
        echo $vettore[$posizioni[$i]]. " ";
      }
    ?>
  </body>
</html>
