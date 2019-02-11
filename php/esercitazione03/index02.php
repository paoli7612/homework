<html>
  <head>
    <meta charset="utf-8">
    <title>14-03-02</title>
  </head>
  <body>
    <?php

      function trovaMDC($a, $b){
        $r=$a%$b;
        $r2=$b%$a;
        if($a==0){
          return $b;
        }elseif($b==0){
          return $a;
        }elseif($r==0){
          return $b;
        }elseif($r2==0){
          return $a;
        }else
          $a=$b;
          $b=$r;
          if($r!=0){
            return trovaMDC($a, $b);
          }else {
            return $b;
          }
      }

      $x=36;
      $y=48;
      $MCD= trovaMDC($x, $y);
      echo $MCD;
    ?>
  </body>
</html>
