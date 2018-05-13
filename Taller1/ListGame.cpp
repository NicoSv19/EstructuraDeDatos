/*
 * ListGame.cpp
 *
 *  Created on: 09-05-2018
 *      Author: carlo
 */

#include "ListGame.h"

#include <string>
using namespace std;

ListGame::~ListGame() {}

void ListGame::insert(Game game){first= new NodoGame(game,first);}

string ListGame::printList(void){
	string cadena;
	if (!first){
		cadena="no hay nada";
	}
	else{
		NodoGame* c= first;
		cadena="";
		while(c != NULL){
			cadena+= c->game.getDates() +"\n";
			c= c->siguiente;
		}
	}
	return cadena;
}

Game* ListGame::search(string codigo){
	NodoGame* c = first;
	while(c != NULL && codigo.compare(c->game.getGameCode()) != 0 )	c=c->siguiente;
	if(c == NULL) return NULL;
	return &(c->game);

}

bool ListGame::editarStock(string codigo){
	NodoGame* c = first;
	int stock=0;;
	while(c != NULL && codigo.compare(c->game.getGameCode())!=0 )	c=c->siguiente;
	if(c != NULL && c->game.getActualStock() >0){
		stock= c->game.getActualStock();
		c->game.setActualStock(stock-1);
		return true;
	}
	return false;
}

