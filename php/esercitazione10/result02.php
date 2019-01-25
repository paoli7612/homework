<?php
  function is_empty($value){
    return trim($value) == "";
  }

  function gender($sesso){
    if ($sesso == "m")
      return "benvenuto signor ";
    else return "benvenuta signora ";
  }

  $compiled = true;
  foreach ($_POST as $key => $value) {
    if (is_empty($value)){
      $compiled = false;
    }
  }

  if ($compiled){
    echo gender($_POST['sesso']) . $_POST['nome'] . $_POST['cognome'];
  } else {
    echo "ERROR<br>";
    echo "<a href=\"index02.php\">torna alla pagina precedente</a>";
  }



?>
