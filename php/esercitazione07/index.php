<style> body { font-family: monospace; } </style>
<?php

  // function to show arrays
  function show($array){
    foreach ($array as $e){
      if ($e == " ")
        echo " &nbsp;";
      echo " $e";
    }
    echo "<br/>";
  }

  // read file and create array 'regioni'
  $file = file('regioni.txt');
  $regioni = array();
  foreach ($file as $line){
    array_push($regioni, $line);
  }

  // select a random element
  $regione = $regioni[rand(0,count($regioni)-1)];
  $word = str_split($regione);

  // remove '\n'
  array_pop($word);
  array_pop($word);
  $last = count($word)-1;

  // remember the final result
  $final = $word;

  // hide word
  for ($i=1; $i<$last; $i++){
    $word[$i] = "_";
  }

  // remember position showed
  $showed = array_fill(0, $last, 0);
  $showed[0] = 1;
  $showed[$last] = 1;

  while (in_array(0, $showed)){
    show($word);
    do {
        $n = rand(1,$last);
    } while ($showed[$n]);
    $showed[$n] = 1;
    $word[$n] = $final[$n];
  }


  // show
  show($final);



?>
