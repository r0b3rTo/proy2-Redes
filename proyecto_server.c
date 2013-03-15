/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "proyecto.h"
#include "centro.h"

Servidor servidor;

int *
obtener_tiempo_respuesta_1_svc(void *argp, struct svc_req *rqstp)
{
	static int  result;
	printf("Entro a la llamada remota del tiempo de respuesta\n");
	result = servidor.tiempo;

	return &result;
}

int *
solicitar_envio_gasolina_1_svc(void *argp, struct svc_req *rqstp)
{
	static int  result;

	printf("Entro a la llamada remota del envío de gasolina\n");	
	if(servidor.inventario >= 38000){
		result = 1;
      servidor.inventario = servidor.inventario - 38000;
//      escribirArchivoLog(nombreArchivoLog, "Suministro", parametros->servidor->tiempoSimulacion, 
//                         parametros->servidor->inventario, nombreBomba, mensajeOk);
   }else{
		result = 0;
//      escribirArchivoLog(nombreArchivoLog, "Suministro", parametros->servidor->tiempoSimulacion, 
//                         parametros->servidor->inventario, nombreBomba, mensajeNoDisponible);
   }

	return &result;
}
