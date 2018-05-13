/*
 * Client.cpp
 *
 *  Created on: 10-05-2018
 *      Author: carlo
 */

#include "Client.h"
Client::~Client() {}

string Client::getDatos(){
	string cadena="";
	cadena+= "Rut: "+rut+"\n";
	cadena+= "Name: "+clientName+"\n";
	cadena+= "Address: "+address+"\n";
	cadena+= "Email: "+email+"\n";

	return cadena;
}


