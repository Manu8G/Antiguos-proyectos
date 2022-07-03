import java.net.MalformedURLException;
import java.rmi.registry.LocateRegistry;
import java.rmi.*;
import java.rmi.registry.Registry;
import java.util.Scanner;

public class cliente{
    public static void main(String[] args){
        if(System.getSecurityManager()==null){
            System.setSecurityManager(new SecurityManager());
        }try{
            Registry mireg=LocateRegistry.getRegistry("127.0.0.1", 1099);
            String[] servers=mireg.list();
            Entidad usuario=null;
            boolean logueado=false, salir=false;
            Scanner myObj=new Scanner(System.in);
            String opcion, servidorDestino=args[0];
            I_Donacion interfaz=(I_Donacion)mireg.lookup(servidorDestino);

            System.out.println("\n\nConectado al "+interfaz.getNombre()+".\nElige una opcion: ");

            while(!salir){
                if(!logueado){

                    System.out.println("\t R - Registrarse\n\t L - Iniciar sesión\n\t S - Salir");
                    opcion=myObj.nextLine();

                    switch(opcion){
                        case "R":
                            System.out.println("Introduce tu nombre: ");
                            opcion=myObj.nextLine();
                            if(!interfaz.existeEntidad(opcion)){
                               interfaz.registrar(opcion);
                               System.out.println("Registrado con exito.");
                            }else{
                                System.out.println("Este usuario ya existe");
                            }
                        break;

                        case "L":
                            System.out.println("Introduce el nombre de usuario: ");
                            opcion=myObj.nextLine();
                            if(interfaz.existeEntidad(opcion)){
                                usuario=interfaz.iniciarSesion(opcion);
                                System.out.println("Sesion iniciada.");
                                logueado=true;
                                System.out.println("Buenas "+usuario.getNombre());
                            }else{
                                System.out.println("El usuario introducido no existe.");
                            }
                        break;

                        case "S":
                            salir=true;
                            System.out.println("Hasta pronto.");
                        break;

                        default:
                            System.out.println("La opcion escogida es incorrecta, se lo volvere a repetir...");
                        break;
                    }
                }else{
                    System.out.println("¿Que quieres hacer?:");
                    System.out.println("\t D - Donar\n\t T - Ver mi total de donaciones\n\t H - Ver total donado en este servidor\n\t A - Ver total donado a la causa por todas las entidades\n\t S - Cerrar Sesion");

                    opcion=myObj.nextLine();
                    double donado=0.0;
                    switch(opcion){
                        case "S":
                            interfaz.cerrarSesion(usuario.getNombre());
                            salir=true;
                        break;

                        case "D":
                            System.out.println("¿Cuánto quieres donar?");
                            double donacion=Double.parseDouble(myObj.nextLine());
                            interfaz.donar(usuario.getNombre(), donacion);
                            System.out.println("Donacion realizada con exito");
                        break;

                        case "T":
                            donado=interfaz.consultarTotalDonaciones(usuario.getNombre());
                            if(donado==0.0){
                                System.out.println("Para consultar lo que has donado antes tienes que realizar una donacion...");
                            }else{
                                System.out.println("Has donado un total de "+donado+"€.");
                            }
                        break;
                    
                        case "H":
                            donado=interfaz.getDonado();
                            if(donado==0.0){
                                System.out.println("Para consultar lo que has donado en este servidor antes tienes que donar...");
                            }else{
                                System.out.println("Has donado un total de "+donado+"€ en este servidor.");
                            }
                        break;

                        case "A":
                            System.out.println("EL total donado a la causa por todas las entidades es "+interfaz.fondoTotal());
                        break;

                        default:
                            System.out.println("La opcion escogida es incorrecta, se lo volvere a repetir...");
                        break;
                    }
                }
            }
        }catch(NotBoundException | RemoteException e){
            System.err.println("Exception del sistema: "+e);
        }
        System.exit(0);
    }
}