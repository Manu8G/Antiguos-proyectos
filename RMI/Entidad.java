import java.io.Serializable;

public class Entidad implements Serializable{
    private String nombre;
    private double totalDonado;
    private boolean conect;

    public Entidad(String nombre){
        this.nombre=nombre;
        this.totalDonado=0.0;
        conect=false;
    }

    public String getNombre(){
        return this.nombre;
    }

    public double getTotalDonado(){
        return this.totalDonado;
    }

    public boolean getConect(){
        return this.conect;
    }

    public void setConect(boolean estado){
        this.conect=estado;
    }

    public void donarDinero(double dinero){
        this.totalDonado+=dinero;
    }
}
