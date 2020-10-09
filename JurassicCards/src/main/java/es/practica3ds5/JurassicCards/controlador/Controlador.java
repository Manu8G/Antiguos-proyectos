package es.practica3ds5.JurassicCards.controlador;

import es.practica3ds5.JurassicCards.bd.Cartas;
import es.practica3ds5.JurassicCards.bd.Jugadores;
import es.practica3ds5.JurassicCards.modelo.Partida;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.ArrayList;

@Controller
@RequestMapping("/jurassic")
public class Controlador {
    @Autowired
    private Cartas cartas;
    @Autowired
    private Jugadores jugadores;

    Partida partida = new Partida();
    ArrayList<String> nombres = new ArrayList<>();
    ArrayList<String> casillasJugador1 = new ArrayList<>();
    ArrayList<String> casillasJugador2 = new ArrayList<>();

    public Controlador(){
        casillasJugador1.add("CasillaJugador1_0");
        casillasJugador1.add("CasillaJugador1_1");
        casillasJugador1.add("CasillaJugador1_2");
        casillasJugador1.add("CasillaJugador1_3");
        casillasJugador1.add("CasillaJugador1_4");
        casillasJugador2.add("CasillaJugador2_0");
        casillasJugador2.add("CasillaJugador2_1");
        casillasJugador2.add("CasillaJugador2_2");
        casillasJugador2.add("CasillaJugador2_3");
        casillasJugador2.add("CasillaJugador2_4");
    }

    @RequestMapping(value = "", method = RequestMethod.GET)
    public String regristarse(){
        return "registrar";
    }

    @RequestMapping(value="/",method=RequestMethod.POST)
    public String registroExitoso(@RequestParam("name1") String userName1, @RequestParam("name2") String userName2, Model model){
        nombres.add(userName1);
        nombres.add(userName2);
        partida.init(nombres);
        verJugadores(model);
        return "redirect:/jurassic/partida";
    }

    @GetMapping("/partida")
    public String jugar(Model model){
        actualizar(model);
        return "index";
    }

    public void verJugadores(Model model){
        model.addAttribute("Jugador1", partida.getJugador(0));
        model.addAttribute("Jugador2", partida.getJugador(1));
    }

    public void obtenerCartasManoJugador1(Model model){
        model.addAttribute("ManoJugador1_0", partida.getJugador(0).getMano().get(0));
        model.addAttribute("ManoJugador1_1", partida.getJugador(0).getMano().get(1));
        model.addAttribute("ManoJugador1_2", partida.getJugador(0).getMano().get(2));
        model.addAttribute("ManoJugador1_3", partida.getJugador(0).getMano().get(3));
        model.addAttribute("ManoJugador1_4", partida.getJugador(0).getMano().get(4));
    }

    public void obtenerCartasManoJugador2(Model model){
        model.addAttribute("ManoJugador2_0", partida.getJugador(1).getMano().get(0));
        model.addAttribute("ManoJugador2_1", partida.getJugador(1).getMano().get(1));
        model.addAttribute("ManoJugador2_2", partida.getJugador(1).getMano().get(2));
        model.addAttribute("ManoJugador2_3", partida.getJugador(1).getMano().get(3));
        model.addAttribute("ManoJugador2_4", partida.getJugador(1).getMano().get(4));
    }

    public void obtenerCartaCampoJugador1(Model model, String casilla, int indice){
        model.addAttribute(casilla, partida.getJugador(0).getCartaCampo(indice));
    }

    public void obtenerCartaCampoJugador2(Model model, String casilla, int indice){
        model.addAttribute(casilla, partida.getJugador(1).getCartaCampo(indice));
    }

    public void cambio(Model model, int i){
        if(i==1){
            model.addAttribute("ManoJugador2_0", partida.getJugador(1).getMano().get(0));
            model.addAttribute("ManoJugador2_1", partida.getJugador(1).getMano().get(1));
            model.addAttribute("ManoJugador2_2", partida.getJugador(1).getMano().get(2));
            model.addAttribute("ManoJugador2_3", partida.getJugador(1).getMano().get(3));
            model.addAttribute("ManoJugador2_4", partida.getJugador(1).getMano().get(4));
            model.addAttribute("ManoJugador1_0", partida.getGenerica());
            model.addAttribute("ManoJugador1_1", partida.getGenerica());
            model.addAttribute("ManoJugador1_2", partida.getGenerica());
            model.addAttribute("ManoJugador1_3", partida.getGenerica());
            model.addAttribute("ManoJugador1_4", partida.getGenerica());
        }else{
            model.addAttribute("ManoJugador1_0", partida.getJugador(0).getMano().get(0));
            model.addAttribute("ManoJugador1_1", partida.getJugador(0).getMano().get(1));
            model.addAttribute("ManoJugador1_2", partida.getJugador(0).getMano().get(2));
            model.addAttribute("ManoJugador1_3", partida.getJugador(0).getMano().get(3));
            model.addAttribute("ManoJugador1_4", partida.getJugador(0).getMano().get(4));
            model.addAttribute("ManoJugador2_0", partida.getGenerica());
            model.addAttribute("ManoJugador2_1", partida.getGenerica());
            model.addAttribute("ManoJugador2_2", partida.getGenerica());
            model.addAttribute("ManoJugador2_3", partida.getGenerica());
            model.addAttribute("ManoJugador2_4", partida.getGenerica());
        }
    }

    @RequestMapping(value="/partida", method = RequestMethod.POST)
    public String atacar(Model model, @RequestParam String action, @RequestParam String c){
        if (action.equals("atacar"))
            partida.atacar(partida.getOtroJugador());

        if (action.equals("ponercarta") && partida.getJugadorActual().getCampo().size() < 5){
            partida.getJugadorActual().sacarCarta();
            if (c.equals("1"))
                partida.ponerCartaCampo(0);
            if (c.equals("2"))
                partida.ponerCartaCampo(1);
            if (c.equals("3"))
                partida.ponerCartaCampo(2);
            if (c.equals("4"))
                partida.ponerCartaCampo(3);
            if (c.equals("5"))
                partida.ponerCartaCampo(4);
        }

        if (action.equals("pasarturno"))
            partida.pasarTurno();

        actualizar(model);
        return "index";
    }

    public void actualizar(Model model) {
        obtenerCartasManoJugador1(model);
        obtenerCartasManoJugador2(model);
        verJugadores(model);

        if (partida.getJugador(0).getCampo().size() > 0)
            for (int i = 0; i < partida.getJugador(0).getCampo().size(); i++)
                obtenerCartaCampoJugador1(model, casillasJugador1.get(i), i);

        if (partida.getJugador(1).getCampo().size() > 0)
            for (int i = 0; i < partida.getJugador(1).getCampo().size(); i++)
                obtenerCartaCampoJugador2(model, casillasJugador2.get(i), i);

        model.addAttribute("turno", "Turno: ");
        model.addAttribute("Turno", partida.getJugadorActual().getNombre());
        cambio(model, partida.getIndiceJugadorActual());

        if (partida.getJugadorActual().getSalud() == 0 || partida.getOtroJugador().getSalud() == 0){
            model.addAttribute("texto1", "El jugador ");
            model.addAttribute("Final", partida.getJugadorActual().getNombre());
            model.addAttribute("texto2", " ha ganado la partida ");
        }
    }
}
