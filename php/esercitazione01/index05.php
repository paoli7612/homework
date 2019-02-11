<?php
  srand();
  $dividendo = rand(0, 100);
  $divisore = rand(1, 100);
  $quoziente = (int)($dividendo / $divisore);
  $resto = $dividendo % $divisore
?>

<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Index 05</title>
  </head>
  <body>
    <ul>
      <li>Dividendo <?php echo "$dividendo"; ?></li>
      <li>Divisore <?php echo "$divisore"; ?></li>
      <li>Quoziente <?php echo "$quoziente"; ?></li>
      <li>Resto <?php echo "$resto"; ?></li>
    </ul>
  </body>
</html>
