<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title> Login </title>
    <link rel="stylesheet" href="master.css">
    <script type="text/javascript">
      function reset(){
        var inputs = document.getElementsByClassName("resetable");
        for (var i=0; i<input.length; i++){
          input[i].value = "";
        }
      }
    </script>
  </head>
  <body>
    <form action="result02.php" method="post">
      <table>
        <tr>
          <td> Nome </td>
          <td><input type="text" name="nome" placeholder="nome" class="resetable"></td>
        </tr>
        <tr>
          <td> Cognome </td>
          <td><input type="text" name="cognome" placeholder="password" class="resetable"></td>
        </tr>
        <tr>
          <td> Sesso </td>
          <td>
            <div class="row">
              <input id="m" type="radio" name="sesso" value="m" checked="checked">
              <label for="m">maschio</label>
            </div>
            <div class="row">
              <input id="f" type="radio" name="sesso" value="f">
              <label for="f">femmina</label>
            </div>
          </td>
        </tr>
        <tfoot>
          <td> <button type="button" onclick="reset()"> reset </button> </td>
          <td> <button type="submit"> ok </button> </td>
        </tfoot>
      </table>
    </form>
  </body>
</html>
