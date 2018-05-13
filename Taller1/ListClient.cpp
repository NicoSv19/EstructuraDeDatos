/*
 * ListClient.cpp
 *
 *  Created on: 10-05-2018
 *      Author: carlo
 */

#include "ListClient.h"

ListClient::~ListClient() {}

void ListClient::insert(Client client){primero= new nodo(client,primero);}

string ListClient::printClients(){
	string cadena="";
	if(!primero)cadena="No hay nada";
	else{
		nodo* c = primero;
		while(c != NULL ){
			cadena+= c->cliente.getDatos()+ "\n";
			c=c->siguiente;
		}
	}
	return cadena;
}

Client* ListClient::search(string rut){
	nodo* c= primero;
	while(c!= NULL && c->cliente.rut.compare(rut)) c=c->siguiente;
	if(c != NULL)return &(c->cliente);
	return nullptr;
}
