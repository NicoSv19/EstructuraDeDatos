/*
 * Sistema.cpp
 *
 *  Created on: 09-05-2018
 *      Author: carlo
 */

#include "Sistema.h"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

Sistema::Sistema() {
}

Sistema::~Sistema() {}

bool Sistema::readGames(){
	ifstream arch("files/games.txt",ios::in);
	string name,cod,dev,plt,date;
	int iStk,aStk,prc;
	char ch;
	if (arch){
		string linea;
		while (getline(arch, linea)){
			stringstream ln(linea);
			getline(ln,cod,',');
			getline(ln,name,',');
			getline(ln,dev,',');
			getline(ln,plt,',');
			getline(ln,date,',');
			ln>> iStk;
			ln>>ch;
			ln>> aStk;
			ln>>ch;
			ln>>prc;
			Game g= Game(cod,name,dev,plt,date,iStk,aStk,prc);
			listGames.insert(g);
		}
		arch.close();
		return true;
	}
	return false;
}

bool Sistema::readClient(){
	ifstream entrada("files/customers.txt",ios::in);
	string rut, name, direccion, email;
	Client c;
	if(!entrada.fail()){
		while (!entrada.eof()){
			getline(entrada,rut,',');
			getline(entrada,name,',');
			getline(entrada,direccion,',');
			getline(entrada,email);
			c= Client(rut, name, direccion, email);
			listClients.insert(c);

		}
		entrada.close();
		return true;
	}
	return false;
}

string Sistema::printListGames(){return listGames.printList();}
string Sistema::printListClient(){return listClients.printClients();}
