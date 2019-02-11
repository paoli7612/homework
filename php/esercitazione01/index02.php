<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Index 02</title>
  </head>
  <body>
    <p>
      <?php
        $a = 10;
        $b = "10";
        $c = "dieci";
        srand();
        $x = $a/rand(1,9);
        echo ("\t".gettype($a)." <br/>\n");
        echo ("\t\t".gettype($b)." <br/>\n");
        echo ("\t\t".gettype($c)." <br/>\n");
        echo "\t\t$x $c $b \n";
      ?>
    </p>
  </body>
</html>
