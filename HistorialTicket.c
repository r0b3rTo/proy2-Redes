/**
   CI-4835 Redes de Computadoras
   Fecha: Enero 2013
   Proyecto II
   Archivo: HistorialTicket.c
   Contiene funciones para el manejo de una lista enlazada de
   Tickets, con el nombre de la Bomba que posee el ticket, direccionIP de la Bomba, 
   claveMD5 y tiempo el cual se validó el ticket.
   Integrantes:
   Héctor López   05-38421
   Roberto Omaña  06-39990  
**/

#include "HistorialTicket.h"


/*
* Funcion insertarTicket
*    Parametros de entrada: Una estructura de tipo HistorialTicket que contiene 
*    Servidores, ademas de una cadena de caracteres con el nombre del servidor, 
*    un entero para su direccion, otra cadena de caracteres para su clave del MD5 
*    y otro más para su tiempo de respuesta.
*    Parametro de salida: Una estructura de tipo HistorialTicket.
*    Recibe el historial de Tickets de la lista e inserta un nuevo Servidor.
*/
HistorialTicket insertarTicket(HistorialTicket historialTickets, char* nombreBomba, char* direccionIP, char* claveMD5, int tiempoValidacion)
{ 
     HistorialTicket nuevoTicket = NULL;
     char* auxNombreBomba = (char*)malloc(sizeof(char)*100);
     if(auxNombreBomba == NULL){
          terminar("Error de asignacion de memoria: " );
     }
     char* auxDireccionIP = (char*)malloc(sizeof(char)*100);
     if(auxDireccionIP == NULL){
          terminar("Error de asignacion de memoria: " );
     }
     char* auxClaveMD5 = claveMD5;
     int auxTiempoValidacion = tiempoValidacion;
     strcpy(auxNombreBomba,nombreBomba);
     strcpy(auxDireccionIP,direccionIP);
     nuevoTicket =(TICKET*)malloc(sizeof(TICKET));
     if(nuevoTicket == NULL){
          terminar("Error de asignacion de memoria: " );
     }
     nuevoTicket->nombreBomba = auxNombreBomba;   
     nuevoTicket->direccionIP = auxDireccionIP;
     nuevoTicket->claveMD5 = auxClaveMD5;
     nuevoTicket->tiempoValidacion = auxTiempoValidacion;
     nuevoTicket-> siguiente = historialTickets; 
     
     historialTickets = nuevoTicket;
     
     return historialTickets;       
}

/* 
* Funcion insertarTiempoRespuesta
*    Parametros de entrada: Una estructura de tipo HistorialTicket, ademas de 
*    una cadena de caracteres con el nombre y un entero con su tiempo de
*    respuesta.
*    Parametro de salida: Una estructura de tipo HistorialTicket.
*    Busca en la lista de Servidores un servidor en específico y luego inserta
*    su tiempo de respuesta.
*/
HistorialTicket insertarTiempoValidacion(HistorialTicket historialTickets, char* nombreBomba, 
     int tiempoValidacion)
{
    HistorialTicket copiaHistorialTickets;
    copiaHistorialTickets=(TICKET*)malloc(sizeof(TICKET));
    if(copiaHistorialTickets == NULL){
         terminar("Error de asignacion de memoria: " );
    }
    copiaHistorialTickets = historialTickets;
    while(historialTickets != NULL && strcmp(historialTickets->nombreBomba,nombreBomba) != 0){
        historialTickets=historialTickets->siguiente;
    }
    if (historialTickets != NULL){ 
        historialTickets->tiempoValidacion = tiempoValidacion;
    }else{
        printf("El nombre de la Bomba NO se encuentra en el historial de tickets válidos.\n");
    }
    
    return copiaHistorialTickets;
}


/*  
* Funcion buscarTicket
*    Parametros de entrada: Una estructura de tipo HistorialTicket, ademas de una 
*    cadena de caracteres con el nombre del Servidor.
*    Parametro de salida: el Servidor buscado si se encuentra en la lista o
*    NULL si no se encuentra.
*    Busca en la lista y compara el nombre de cada Servidor, hasta encontrarlo
*    o se recorra toda  la lista.
*/
HistorialTicket buscarTicket(HistorialTicket historialTickets, char* nombreBomba){
   HistorialTicket ticketBuscado = NULL;
   while(historialTickets != NULL){
      if (strcmp(historialTickets->nombreBomba,nombreBomba) != 0){
          historialTickets = historialTickets->siguiente;
      } else {
          ticketBuscado = (TICKET*)malloc(sizeof(TICKET));
          if(ticketBuscado == NULL){
               terminar("Error de asignacion de memoria: " );
          }
          ticketBuscado->nombreBomba = historialTickets->nombreBomba;   
          ticketBuscado->direccionIP = historialTickets->direccionIP;
          ticketBuscado->claveMD5 = historialTickets->claveMD5;
          ticketBuscado->tiempoValidacion = historialTickets->tiempoValidacion;
          return ticketBuscado;
      } 
   }
   return ticketBuscado;
}

/*
 * Funcion ordenarHistorial
 */
HistorialTicket ordenarHistorial(HistorialTicket historialTickets){
   
   HistorialTicket copiaHistorialTickets = (TICKET*)malloc(sizeof(TICKET));
   if(copiaHistorialTickets == NULL){
      terminar("Error de asignacion de memoria: " );
   }
   copiaHistorialTickets = historialTickets;
   HistorialTicket cabeza = historialTickets, aux1 = historialTickets, aux2;
   int indiceHistorial, longitud = length(copiaHistorialTickets);
   
   for(indiceHistorial = 1; indiceHistorial <= longitud; indiceHistorial++){
      
      while(aux1->siguiente != NULL){
         aux2 = aux1->siguiente;
         if(aux1->tiempoValidacion > aux2->tiempoValidacion){
            aux1->siguiente = aux2->siguiente;
            aux2->siguiente = aux1;
            cabeza = aux2;
         }else{
            aux1 = aux2;
         }
      }
      aux1 = historialTickets;
   }
   
   return cabeza;
}


/* Funcion length
*    Parametros de entrada: Una estructura de tipo HistorialTicket que contiene elementos
*    Parametro de salida: ninguno.
*    Recibe la cabeza de la lista y calcula la cantidad de elementos que la lista posee.
 */
int length(HistorialTicket historialTickets){
   
   int longitud = 0;
   while(historialTickets != NULL){
      longitud= longitud + 1;
      historialTickets = historialTickets->siguiente;
   }
   return longitud;
}



/*   
* Funcion imprimirTickets
*    Parametros de entrada: Una estructura de tipo HistorialTicket.
*    Parametro de salida: Ninguno, imprime la lista por salida estandar.
*    Recorre la lista imprimiendo por consola cada nombre de los Servidores.
*/
void imprimirTickets(HistorialTicket historialTickets){

   while(historialTickets != NULL){
        printf("%s \n",historialTickets->nombreBomba);
        historialTickets = historialTickets->siguiente;
   }
   printf("\n");
}