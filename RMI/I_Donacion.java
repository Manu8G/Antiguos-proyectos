import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.ArrayList;

public interface I_Donacion extends Remote{
    public String getNombre() throws RemoteException;
    public ArrayList<Entidad> getEntidades() throws RemoteException;
    public Replica getReplica(Replica replica) throws RemoteException;
    public boolean isBloqueado() throws RemoteException;
    public double getDonado() throws RemoteException;
    public void setBloqueado(boolean locked) throws RemoteException;
    public void lockAll() throws RemoteException;
    public void unlockAll() throws RemoteException;
    public void registrar(String entidad) throws RemoteException;
    public void donar(String entidad, double cantidad) throws RemoteException;
    public boolean existeEntidad(String entidad) throws RemoteException;
    public Entidad buscarEntidad(String entidad) throws RemoteException;
    public Entidad buscarEntidadAqui(String entidad) throws RemoteException;
    public void modificarEntidad(Entidad entidad) throws RemoteException;
    public boolean modificarEntidadAqui(Entidad entidad) throws RemoteException;
    public Entidad iniciarSesion(String entidad) throws RemoteException;
    public void cerrarSesion(String entidad) throws RemoteException;
    public double consultarTotalDonaciones(String entidad) throws RemoteException;
    public double fondoTotal() throws RemoteException;
    public double fondoTotalAqui() throws RemoteException;
}
