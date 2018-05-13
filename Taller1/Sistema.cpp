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
ListaClientes lc;
Cola c;

typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;

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

int regularBisiesto( Fecha fecha1 ); 
int diferenciaFechas(Fecha fecha1, Fecha fecha2){
	int difAnios, difDias=0, i, regBisAnioF1 = 0, regBisAnioF2; 
    int tot_dias[] = { 00,31,28,31,30,31,30,31,31,30,31,30,31 };
    
    difAnios = fecha2.anio - fecha1.anio;
    regBisAnioF1 = regularBisiesto(fecha1);             
    
    if( difAnios == 0){
        if( fecha1.mes == fecha2.mes ){ 
            difDias += fecha2.dia - fecha1.dia;
        }
        else{
            difDias += (tot_dias[fecha1.mes] - fecha1.dia); 
            if( fecha1.mes == 2 ){
                difDias += regBisAnioF1;
            }       
            for( i=fecha1.mes+1; i < fecha2.mes; i++){
                if( i == 2 ){
                    difDias += regBisAnioF1; 
                }   
                difDias += tot_dias[i];                 
            }
            difDias += fecha2.dia;
        }   
    }
    else{ 
        difDias += (tot_dias[fecha1.mes] - fecha1.dia);
        if(fecha1.mes == 2){
            difDias += regBisAnioF1;
        }       
        if( fecha1.mes < 12 ){
            for( i = fecha1.mes +1; i <= 12; i++ ){
                difDias += tot_dias[i]; 
            }
        }
        for( i=fecha1.anio +1; i < fecha2.anio -1; i++){
            difDias += 365;
            regBisAnioF1 = regularBisiesto(fecha1);
            difDias += regBisAnioF1;
        }
        regBisAnioF2 = regularBisiesto(fecha2);
        for( i=1; i < fecha2.mes; i++ ){ 
            if( i == 2 ){
                difDias += regBisAnioF2; 
            }   
            difDias += tot_dias[i];
        }
        difDias += fecha2.dia;
    }
    return difDias;
}
int regularBisiesto( Fecha fechaRb ){
    if ((fechaRb.anio %4 == 0 && fechaRb.anio%100 != 0) || (fechaRb.anio%400) == 0){
        return 1;
    }
    else{
        return 0;
    }
}
void Carrito(Cliente* cliente){ //RF2
    Pila p =new Pila();
    Pila paux=new Pila();
    int op;
    cout<<"ListGames"<<endl;
    lj->imprimir();
    cout<<"Enter opcion pls(ex: 1)\n\t1\tEnter your game\n2\tView the list\n3\tDelete the last game\n4\tRedo the last game\n5\tFinish your buy\n6\tCancell"<<endl;
        cin>>op;
    while(op!=5 || op!=6){
        if(op==1){
            string codeG;
            cout<<"Enter your game(CodeGame) :"<<endl;
            cin>>codeG;
            Juego* j=lj->buscarPorCodigo(codeG);
            p.Push(j);
        }else if(op==2){
            lj->imprimir();
        }else if(op==3){
            Juego* jpop=p.Pop();
            paux.Push(jpop);
        }else if(op==4){
            Juego* jpopredo=paux.Pop();
            p.Push(jpopredo);
        }
        cout<<"Enter opcion pls(ex: 1)\n\t1\tEnter your game\n2\tView the list\n3\tDelete the last game\n4\tRedo the last game\n5\tFinish your buy\n6\tCancell"<<endl;
        cin>>op;
    }
        if(op==5){
            Juego *j=p.Pop();
            while(j!=NULL){
                lj.insertar(j);
                j=p.Pop();
                cliente->setListaJuegos(lj);
            }
        }
        if(op==6){
            Juego *j=p.Pop();
            while(j!=NULL){
                j=p.Pop();
            }
        }
}
void ProcesoPago(bool tienda, Cliente* cliente){ //RF3
	if(tienda){
		string confirmacion;
		if(cliente->listaGame->first != NULL){
			cout<<"Confirm to make the purchase"<<endl;
			cin>>confirmacion;
			if(confirmacion.compare("yes") || confirmacion.compare("Yes") || confirmacion.compare("YES")){
				int i = 0;
				NodoCliente* actual = cliente->listaGame->first;
				while(actual != NULL){
					cout<<i<<") "<<actual->game.gameName<<endl;
					actual = actual->link;
					i++;
				}
			}
			else{
				cout<<"ERROR";
			}
		}else{
			cout<<"you do not have games to withdraw"<<endl;
		}
	}
	if(!tienda){
		NodoCliente* actual = cliente->listaGame->first;
		while(actual != NULL){
			cout<<actual->game.gameName<<", READY_TO WITHDRAW "<<endl;
		}
	}
}
bool Tienda(){ //si es fisico retorna true
    int b;
    cout<<"Type of buy(ex: 1):\n1 Online\n2Store"<<endl;
    cin>>b;
    if(b==2){
        return true;
    }else{
        return false;
    }
}
void NumeroVentaBodega(){ //RF5
    if(Tienda==true){
        string rut;
        string name;
        string direccion;
        string email;
        int numero=1;;
        cout<<"Put your information(Rut, name, address and email): "<<endl;
        cout<<"Rut: "<<endl;
        cin>>rut;
        cout<<"Name: "<<endl;cin>>name;cout<<"Address: "<<endl;cin>>direccion;cout<<"Email: "<<endl;cin>>email;
        Cliente* cliente;
        if(lc.buscarCliente(rut)!=NULL){
            cliente=lc.buscarCliente(rut);
            cliente.setNumeroCola(numero);
            c.Push(cliente);
            numero++;
        }
        else{
        	bool existe;
        	if(!existe){
            	*cliente=new Cliente(rut,name,direccion,email);
            	cliente.setNumeroCola(numero);
            	c.Push(cliente);
            	numero++;
        	}
        	else{
        		cout<<"this rut already has a number of attention"<<endl;
			}
        }
    }
}
void VentaBodega(){
	NodoCliente actual = c->front;
	while(actual != NULL){
		string presente;
		cout<<"Number "<<actual->cliente.numeroCola<<" it's found yes,no,cancel purchase'"<<endl;
		cin>>presente;
		if(presente.compare("yes")){
			Cliente cliente = actual->cliente;
			Carrito(cliente);
			actual.pop();
		}else{
			actual.pop();
		}
	}
}

string Sistema::printListGames(){return listGames.printList();}
string Sistema::printListClient(){return listClients.printClients();
				 }
