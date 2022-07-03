import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.ArrayList;

public class ServerUno{
    public static void main(String[] args){
        if(System.getSecurityManager()==null){
            System.setSecurityManager(new SecurityManager());
        }try{
            Registry reg=LocateRegistry.createRegistry(1099);
            ArrayList<String> array=new ArrayList<>();
            array.add("ServerDos");
            array.add("ServerTres");
            ServidorDonacion server1=new ServidorDonacion("localhost","ServerUno",array);
            Naming.rebind("ServerUno", server1);
            System.out.println("ServerUno funcionando");
        }catch(RemoteException | MalformedURLException e){
            System.out.println(e.toString());
        }
    }
}
