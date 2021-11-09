function ocultarEventos(){
    $('#listaEventos').fadeOut();
}

function mostrarEventos(datos){
    $('#listaEventos').fadeIn();
    $('#listaEventos').html(datos);
}

function eventoPulsarTecla(){
    // Accedo al campo del input
    var consulta = $(this).val();

    if(consulta != '' && consulta.length > 1){
        configuracionAJAX = {
            url: "search.php",
            method: "POST",
            data: {consulta: consulta},
            success: mostrarEventos 
        };

        $.ajax(configuracionAJAX);
    } else {
        ocultarEventos();
    }

    // Cuando hagamos click en los elementos, se ponga el texto en el cuadro
    $(document).on('click', 'li', function() {
        $('#evento').val($(this.text()));
        ocultarEventos();
    });
}

function cargarDatos(){
    $('#evento').keyup(eventoPulsarTecla);
}

$(document).ready(cargarDatos);