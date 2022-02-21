
#include <stdio.h>
#include <Socket_Cliente.h>
#include <Socket.h>

main ()
{
	
	int Socket_Con_Servidor;
   int Longitud_Cadena = 0;
   int Aux;
	char Cadena[100];

	
	Socket_Con_Servidor = Abre_Conexion_Inet ("localhost", "cpp_java");
	if (Socket_Con_Servidor == 1)
	{
		printf ("No puedo establecer conexion con el servidor\n");
		exit (-1);
	}

    strcpy (Cadena, "Hola :)");
   Longitud_Cadena = 10;


   Aux = htonl (Longitud_Cadena);
   Escribe_Socket (Socket_Con_Servidor, (char *)&Aux, sizeof(Longitud_Cadena));

 Escribe_Socket (Socket_Con_Servidor, Cadena, Longitud_Cadena);

   Lee_Socket (Socket_Con_Servidor, (char *)&Aux, sizeof(int));
   Longitud_Cadena = ntohl (Aux);

   Lee_Socket (Socket_Con_Servidor, Cadena, Longitud_Cadena);
   printf ("Servidor en java responde : %s\n", Cadena);
   
	close (Socket_Con_Servidor);
}

