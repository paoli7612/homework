<!doctype>
<html>
  <head>
    <meta charset="UTF-8"/>
    <title> Esercizio 09.01</title>
  </head>
  <body>
    <?php
      function fattoriale($num){
        $fattoriale=1;
        for($i=1;$i<=$num;$i++){
          $fattoriale= $fattoriale*$i;
        }
        return $fattoriale;
      }

      $numero = $_GET['number'];
      echo "Il fattoriale del numero ".$numero." è ". fattoriale($numero);
    ?>
  </body>
</html>
