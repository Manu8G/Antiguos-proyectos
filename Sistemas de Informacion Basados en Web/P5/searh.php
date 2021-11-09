<?php
    function consultarEvento($nombre){
        $conexion = new mysqli("localhost", "alvaro", "pass", "SIBW");

        if(isset($nombre)){
            $consulta = "SELECT * FROM eventos WHERE nombre LIKE '%$nombre%'";

            $respuesta = mysqli_query($conexion, $consulta);

            $listaEventos = [];

            if(mysqli_num_rows($respuesta) > 0){
                while($fila = mysqli_fetch_array($respuesta)){
                    // Coger datos
                    array_push($listaEventos, $fila);
                }
            }
        }

        // Cargar por medio de una plantilla la lista
        echo $twig->render('lista.html', ["listaEventos" => $listaEventos]);
    }

    // Cuando se haga el post
    if(isset($_POST['consulta'])){
        consultarEvento($_POST['consulta']);
    }
?>