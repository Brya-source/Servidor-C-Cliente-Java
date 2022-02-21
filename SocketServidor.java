import java.net.*;
import java.io.*;

public class SocketServidor
{    
    public static void main (String [] args)
    {
        
        new SocketServidor();
    }
    
   
    public SocketServidor()
    {
        try
        {
      
            ServerSocket socket = new ServerSocket (25557);
            
    
            System.out.println ("Esperando cliente...");
            Socket cliente = socket.accept();
            System.out.println ("Conectado con cliente de " + cliente.getInetAddress());
            
           
            cliente.setSoLinger (true, 10);


            DatoSocket dato = new DatoSocket("Hola, como estas?");

         
            DataOutputStream bufferSalida = new DataOutputStream (cliente.getOutputStream());
            

            DataInputStream bufferEntrada = new DataInputStream (cliente.getInputStream());
         
            DatoSocket aux = new DatoSocket("");
            aux.readObject (bufferEntrada);
            System.out.println ("Enviado del cliente " + aux.toString());

            dato.writeObject (bufferSalida);
            
            cliente.close();
            
       
            socket.close();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }
}
