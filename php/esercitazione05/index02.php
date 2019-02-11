<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
    <?php
      function foo($min, $max){
        $vettore = array_fill(0,9,0);
        for ($i=0; $i<count($vettore); $i++){
          $vettore[$i] = rand($min, $max);
        }
        return $vettore;
      }

      $vettore = foo(10,99);
      for ($i=0; $i<count($vettore); $i++){
        echo $vettore[$i]." ";
      }

    ?>

  </body>
</html>
