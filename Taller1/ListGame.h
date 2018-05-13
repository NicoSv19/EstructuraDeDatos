/*
 * ListGame.h
 *
 *  Created on: 09-05-2018
 *      Author: carlo
 */

#ifndef LISTGAME_H_
#define LISTGAME_H_
#include "NodoGame.h"

class ListGame {
private:
	NodoGame* first;
public:
	ListGame(NodoGame* f=NULL):first(f){};
	virtual ~ListGame();
	void insert(Game game);
	string printList();
	Game* search(string codigo);
	bool editarStock(string codigo);

};


#endif /* LISTGAME_H_ */
