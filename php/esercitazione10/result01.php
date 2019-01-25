<?php
    function is_primo($n){
      for ($i=2; $i<=$n/2; $i++)
        if ($n%$i==0)
          return false;
      return true;
    }

    $n = $_GET['number']
    if (is_primo($n)){
      echo $n . "é primo";
    } else {
      echo $n . "non è primo";
    }
?>
