<!doctype>
<html>
  <head>
    <meta charset="UTF-8"/>
    <title> Esercizio 09.02</title>
  </head>
  <body>
    <?php
      $base = $_POST['base'];
      $esponente = $_POST['esponente'];
      echo "La potenza con base".$base." e con esponente ".$esponente." è ". pow($base,$esponente);
    ?>
  </body>
</html>
