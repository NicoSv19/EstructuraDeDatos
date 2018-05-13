/*
 * NodoGame.h
 *
 *  Created on: 09-05-2018
 *      Author: carlo
 */

#ifndef NODOGAME_H_
#define NODOGAME_H_
#include "Game.h"

class NodoGame {
	friend class ListGame;
private:
	Game game;
	NodoGame* siguiente;
public:
	NodoGame(const Game g, NodoGame* s= NULL):game(g),siguiente(s) {};
	virtual ~NodoGame();
};

#endif /* NODOGAME_H_ */
