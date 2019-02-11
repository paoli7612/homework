<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Index 03</title>
    <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
  </head>
  <body>
    <div class="w3-display-container w3-center">
      <img src="circonferenza.png" width="40%"/>
      <p class="w3-display-middle">
        <?php
          define("PIGRECO", 3.14);

          $nn = rand(10, 99);
          $mm = rand(10, 99);

          $raggio = (float)($nn.",".$mm);
          $diametro = $raggio*2;
          $perimetro = PIGRECO * $diametro;
          $area = PIGRECO * ($raggio*$raggio);
          echo "raggio=$raggio\n";
        ?>
      </p>
    </div>
    <form class="w3-panel w3-center">
      <p>
        <label for="area">Area</label>
        <input id="area" type="text" value="<?php echo "$area"; ?>" disabled="disabled">
      </p>
      <p>
        <label for="perimetro">Perimetro</label>
        <input id="perimetro" type="text" value="<?php echo "$perimetro"; ?>" disabled="disabled">
      </p>
    </form>
  </body>
</html>
