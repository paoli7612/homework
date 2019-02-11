<?php
  $a = 10;
  $b = "10";
  $c = "dieci";

  echo gettype($a)."<br/>";
  echo gettype($b)."<br/>";
  echo gettype($c)."<br/>";

  srand();
  $x = $a/rand(1,9);

  echo "$x $c $b";
?>
