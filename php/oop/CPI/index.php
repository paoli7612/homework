<?php

    $s = $_POST['aritmetiche_righe'] * $_POST['aritmetiche_cicli'] + 
        $_POST['loadstore_righe'] * $_POST['loadstore_cicli'] + 
        $_POST['branch_righe'] * $_POST['branch_cicli'];
    $s /= 100;

?>

<?php $b = $_SERVER['REQUEST_METHOD'] == 'POST' ?>

<html>
    <head>
        <title> Architettura di calcolatori</title>
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-eOJMYsd53ii+scO/bJGFsiCZc+5NDVN2yr8+0RDqr0Ql0h+rP48ckxlpbzKgwra6" crossorigin="anonymous">
    </head>
    <body class="bg-dark">
    <div class="row h-100">
        <div class="col-3"></div>
        <div class="col-6 my-auto">
            <div class="panel p-3 bg-white">
                    <form action="" method="post">
                        <table class="table">
                            <thead>
                                <tr>
                                    <th>Tipo</th>
                                    <th>Cicli</th>
                                    <th>% righe</th>
                                </tr>
                            </thead>
                            <tbody>
                                <tr>
                                    <td>Aritmetiche</td>
                                    <td><input
                                        type="text"
                                        class="form-control"
                                        name="aritmetiche_cicli"
                                        required="required"
                                        <?php if ($b){ echo 'value="'.$_POST['aritmetiche_cicli'].'"'; }?>></td>
                                    <td><input
                                        type="text" 
                                        class="form-control"
                                        name="aritmetiche_righe"
                                        required="required"
                                        <?php if ($b){ echo 'value="'.$_POST['aritmetiche_righe'].'"'; }?>></td>
                                </tr>
                                <tr>
                                    <td>Load/Store</td>
                                    <td><input
                                        type="text"
                                        class="form-control"
                                        name="loadstore_cicli"
                                        required="required"
                                        <?php if ($b){ echo 'value="'.$_POST['loadstore_cicli'].'"'; }?>></td>
                                    <td><input
                                        type="text"
                                        class="form-control"
                                        name="loadstore_righe"
                                        required="required"
                                        <?php if ($b){ echo 'value="'.$_POST['loadstore_righe'].'"'; }?>></td>
                                </tr>
                                <tr>
                                    <td>Branch</td>
                                    <td><input
                                        type="text"
                                        class="form-control"
                                        name="branch_cicli"
                                        required="required"
                                        <?php if ($b){ echo 'value="'.$_POST['branch_cicli'].'"'; }?>></td>
                                    <td><input
                                        type="text"
                                        class="form-control"
                                        name="branch_righe"
                                        required="required"
                                        <?php if ($b){ echo 'value="'.$_POST['branch_righe'].'"'; }?>></td>
                                </tr>
                            </tbody>
                        </table>
                        <input type="submit" value="ok" class="btn btn-primary ml-auto">
                        <?php if ($b): ?>
                            <a href="/" class="btn btn-danger"> reload </a>
                            <div class="container">
                                CPI medio <?= $s ?>
                            </div>
                        <?php endif ?>
                    </form>
                </div>
            </div>
        </div>
    </body>
</html>