public class Replica{
    private String nombre;
    private I_Donacion interfazReplica;

    public Replica(String nombre){
        this.nombre=nombre;
    }

    public String getNombre(){
        return this.nombre;
    }

    public I_Donacion getInterfaz(){
        return this.interfazReplica;
    }

    public void setInterfaz(I_Donacion interfazReplica){
        this.interfazReplica=interfazReplica;
    }

}
