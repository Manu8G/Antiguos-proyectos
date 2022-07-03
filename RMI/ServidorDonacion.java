import java.rmi.*;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;

public class ServidorDonacion extends UnicastRemoteObject implements I_Donacion{
    private ArrayList<Entidad> entidades;
    private boolean bloqueado;
    private String host;
    private String nombreServer;
    private ArrayList<Replica> replicas;
    private double donadoAqui;

    public ServidorDonacion(String host, String nombre, ArrayList<String> arrayReplicas) throws RemoteException{
        this.host=host;
        this.nombreServer=nombre;
        replicas=new ArrayList<>();
        entidades=new ArrayList<>();
        bloqueado=false;
        donadoAqui=0.0;
        for(String string : arrayReplicas){
            replicas.add(new Replica(string));
        }
    }

    @Override
    public String getNombre() throws RemoteException{
        return nombreServer;
    }

    @Override
    public ArrayList<Entidad> getEntidades() throws RemoteException{
        return entidades;
    }

    @Override
    public Replica getReplica(Replica replica) throws RemoteException{
        Replica repli=replica;
        I_Donacion inter=null;
        Registry localizacion=LocateRegistry.getRegistry(host,1099);
        try{
            inter=(I_Donacion)localizacion.lookup(replica.getNombre());
            repli.setInterfaz(inter);
            for(Replica rep : replicas){
                if(rep.getNombre().equals(repli.getNombre())){
                    rep=repli;
                }
            }
        }catch(RemoteException | NotBoundException e){
            System.out.println("Exception: " + e.getMessage());
        }
        return repli;
    }


    @Override
    public boolean isBloqueado(){
        return bloqueado;
    }

    @Override
    public double getDonado() throws RemoteException{
        return this.donadoAqui;
    }

    @Override
    public void setBloqueado(boolean locked){
        bloqueado=locked;
    }

    @Override
    public void lockAll() throws RemoteException{
        this.setBloqueado(false);
        for(Replica replica : replicas){
            replica.getInterfaz().setBloqueado(true);
        }
    }

    @Override
    public void unlockAll() throws RemoteException{
        this.setBloqueado(false);
        for(Replica replica : replicas){
            replica.getInterfaz().setBloqueado(false);
        }
    }
    
    @Override
    public void registrar(String entidad) throws RemoteException{//cambiar
        unlockAll();
        if(!existeEntidad(entidad)){
            I_Donacion inter=this;
            int numRegistrados=entidades.size();
            
            for(Replica replica : replicas){
                this.getReplica(replica);
                if(replica.getInterfaz().getEntidades().size()<numRegistrados){
                    numRegistrados=replica.getInterfaz().getEntidades().size();
                    inter=replica.getInterfaz();
                }
            }
            if(inter==this){
                Entidad nueva=new Entidad(entidad);
                entidades.add(nueva);
                System.out.println("Se ha registrado a " + nueva.getNombre() + " en el sistema");
            }else{
                inter.registrar(entidad);
            }
        }
    }

    @Override
    public void donar(String entidad, double dinero) throws RemoteException{//cambiar
        if(existeEntidad(entidad) && dinero>0.0){
            Entidad resultado=buscarEntidad(entidad);
            resultado.donarDinero(dinero);
            System.out.println(resultado.getNombre()+" ha donado "+dinero+"€");
            this.modificarEntidad(resultado);
            donadoAqui+=dinero;
            this.unlockAll();
        }else if(dinero<0.0){
            System.err.println("La cantidad a donar debe ser mayor que 0");
        }else{
            System.err.println("La entidad no existe");
        }
    }

    @Override
    public boolean existeEntidad(String entidad) throws RemoteException{
        return (buscarEntidad(entidad)!=null);
    }

    @Override
    public Entidad buscarEntidad(String entidad) throws RemoteException{//cambiar
        Entidad enti=buscarEntidadAqui(entidad);
        if(enti==null){
            setBloqueado(true);
            if(!replicas.isEmpty()){
                for(Replica replica : replicas){
                    this.getReplica(replica);
                    if(enti==null && !replica.getInterfaz().isBloqueado()){
                        enti=replica.getInterfaz().buscarEntidadAqui(entidad);
                    }
                }
            }
        }
        setBloqueado(false);
        return enti;
    }

    @Override
    public Entidad buscarEntidadAqui(String entidad) throws RemoteException{
        Entidad enti=null;
        if(!entidades.isEmpty()){
            for(Entidad ent : entidades){
                if(ent.getNombre().equals(entidad)){
                    enti=ent;
                }
            }
        }
        return enti;
    }

    @Override
    public synchronized void modificarEntidad(Entidad entidad) throws RemoteException{//cambiar
        boolean encontrada=modificarEntidadAqui(entidad);
        
        if(!encontrada){
            setBloqueado(true);
            if(!replicas.isEmpty()){
                for(Replica replica : replicas){
                    this.getReplica(replica);
                    replica.getInterfaz().modificarEntidadAqui(entidad);
                }
            }
        }
        setBloqueado(false);
    }

    @Override
    public synchronized boolean modificarEntidadAqui(Entidad entidad) throws RemoteException{
        boolean encontrada=false;
        if(!entidades.isEmpty()){
            for(Entidad enti : entidades){
                if(enti.getNombre().equals(entidad.getNombre())){
                    encontrada=true;
                    lockAll();
                    entidades.remove(entidades.indexOf(enti));
                    entidades.add(entidad);
                    unlockAll();
                }
            }
        }
        return encontrada;
    }

    @Override
    public Entidad iniciarSesion(String entidad) throws RemoteException{
        if(existeEntidad(entidad)){
            if(buscarEntidad(entidad).getConect()){
                 System.out.println("La entidad "+entidad+" ya tiene una sesion activa");
                 return null;
            }else{
                System.out.println("Sesion de "+entidad+" iniciada");
                Entidad resultado=buscarEntidad(entidad);
                resultado.setConect(true);
                this.modificarEntidad(resultado);
                this.unlockAll();
                return buscarEntidad(entidad);
            }
        }else{
            return null;
        } 
    }

    @Override
    public void cerrarSesion(String entidad) throws RemoteException{
        if(existeEntidad(entidad)){     
            if(buscarEntidad(entidad).getConect()){
                Entidad resultado=buscarEntidad(entidad);
                resultado.setConect(false);
                this.modificarEntidad(resultado);
                this.unlockAll();
                System.out.println("La sesion de "+entidad+" se ha cerrado con exito");
            }else{
                System.out.println("ERROR-No se puede cerrar sesion de una entidad que no esta conectada...");
            }
        }else{
            System.out.println("ERROR-Se ha intentado cerrar sesion de una entidad inexistente...");
        } 
    }

    @Override
    public double consultarTotalDonaciones(String entidad) throws RemoteException{
        return this.buscarEntidad(entidad).getTotalDonado();
    }

    @Override
    public double fondoTotal() throws RemoteException{
        double total=0.0;
        for(Replica replica : replicas){
            total+=replica.getInterfaz().fondoTotalAqui();
        }
        total+=this.fondoTotalAqui();
        return total;
    }

    @Override
    public double fondoTotalAqui() throws RemoteException{
        double total=0.0;
        for(Entidad entidad : entidades){
            total+=entidad.getTotalDonado();
        }
        return total;
    }

}
