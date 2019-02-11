<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
    <link rel="stylesheet" href="css03.css">
  </head>
  <body>
    <?php
      function is_magic($n){
          return !($n%2 || $n%3 || $n%5);
      }

      $r = rand(1,1000);
      if (is_magic($r)){
          echo "<img class=\"magic\" src=\"a.png\"/>";
      } else {
        echo "<p class=\"normal\">Marie Curie</p>";
      }
    ?>
  </body>
</html>
