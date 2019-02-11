
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8"/>
    <title>Index 03</title>
  </head>
  <body>
    <script type="text/javascript">
      <?php
        define("PIGRECO", 3.14);
		
		srand();
        $nn = rand(10, 99);
        $mm = rand(10, 99);

        $raggio = (float)($nn.",".$mm);
        $diametro = $raggio*2;
        $perimetro = PIGRECO * $diametro;
        $area = PIGRECO * ($raggio*$raggio);
        echo "alert('area=$area perimetro=$perimetro');\n";
      ?>
    </script>
  </body>
</html>
