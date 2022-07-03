import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.ArrayList;

public class ServerTres{
    public static void main(String[] args){
        if(System.getSecurityManager()==null){
            System.setSecurityManager(new SecurityManager());
        }try{
            ArrayList<String> array=new ArrayList<>();
            array.add("ServerUno");
            array.add("ServerDos");
            ServidorDonacion server3=new ServidorDonacion("localhost","ServerTres",array);
            Naming.rebind("ServerTres", server3);
            System.out.println("ServerTres funcionando");
        }catch(RemoteException | MalformedURLException e){
            System.out.println(e.toString());
        }
    }
}
