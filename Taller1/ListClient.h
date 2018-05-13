/*
 * ListClient.h
 *
 *  Created on: 10-05-2018
 *      Author: carlo
 */

#ifndef LISTCLIENT_H_
#define LISTCLIENT_H_
#include "Client.h"

#include<string>
using namespace std;

class nodo {
   public:
    nodo( Client c, nodo* sig = NULL):cliente(c),siguiente(sig) {    }
   private:
    Client cliente;
    nodo *siguiente;

   friend class ListClient;
};

class ListClient {
public:
	ListClient(nodo* p= NULL):primero(p){};
	virtual ~ListClient();
	void insert(Client client);
	string printClients();
	Client* search(string rut);
private:
	nodo* primero;
};

#endif /* LISTCLIENT_H_ */
