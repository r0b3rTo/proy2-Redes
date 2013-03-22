/**
   CI-4835 Redes de Computadoras
   Fecha: Enero 2013
   Proyecto II
   Archivo: HistorialTicket.h
   Contiene la estructura del HistorialTicket, y cada uno de sus elementos.
   Integrantes:
   Héctor López   05-38421
   Roberto Omaña  06-39990  
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Ticket {
   char* nombreBomba;
   char* direccionIP;
   char* claveMD5;
   int tiempoValidacion;
   struct Ticket *siguiente; 
};

typedef struct Ticket TICKET;/*por convencion en mayusculas */
typedef struct Ticket *HistorialTicket;/*Direccion de inicio de la lista */

extern HistorialTicket insertarTicket(HistorialTicket, char*, char*, char*, int);
extern HistorialTicket insertarTiempoValidacion(HistorialTicket,char*,int);
extern HistorialTicket buscarTicket(HistorialTicket,char*);
extern HistorialTicket ordenarHistorial(HistorialTicket);
extern int length(HistorialTicket);
extern void imprimirTickets(HistorialTicket);