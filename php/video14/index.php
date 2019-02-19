<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Esercizio 1</title>
    <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">

  <?php if (array_key_exists('color', $_POST)): ?>
    <style>
      body {
        background-color: <?php echo $_POST['color']; ?>;
      }
    </style>
  <?php endif; ?>
  </head>
  <body>
    <?php
      if ($_SERVER['REQUEST_METHOD'] == 'GET'){
        include "form1.php";
      } elseif ($_POST['n_form'] == 1){
        include "form2.php";
      } elseif ($_POST['n_form'] == 2) {
        include "result.php";
      }
    ?>
  </body>
</html>
