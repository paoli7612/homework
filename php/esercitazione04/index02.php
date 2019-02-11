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

      $k = rand(50,100);
      for ($i=0; $i<$k; $i++){
        if (is_primo($i)){
          echo "$i </br>";
        }
      }
    ?>
  </body>
</html>
