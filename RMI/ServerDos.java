import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.ArrayList;

public class ServerDos{
    public static void main(String[] args){
        if(System.getSecurityManager()==null){
            System.setSecurityManager(new SecurityManager());
        }try{
            ArrayList<String> array=new ArrayList<>();
            array.add("ServerUno");
            array.add("ServerTres");
            ServidorDonacion server2=new ServidorDonacion("localhost","ServerDos",array);
            Naming.rebind("ServerDos", server2);
            System.out.println("ServerDos funcionando");
        }catch(RemoteException | MalformedURLException e){
            System.out.println(e.toString());
        }
    }
}
