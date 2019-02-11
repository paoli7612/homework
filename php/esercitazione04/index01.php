<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
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

      // stampo i primi 10 primi
      $primi = 0;
      $n = 1;
      while ($primi < 10){
        if (is_primo($n)){
          echo "$n </br>";
          $primi++;
        }
        $n++;
      }
    ?>
  </body>
</html>
