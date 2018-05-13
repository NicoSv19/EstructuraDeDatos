/*
 * Sistema.h
 *
 *  Created on: 09-05-2018
 *      Author: carlo
 */

#ifndef SISTEMA_H_
#define SISTEMA_H_
#include "ListGame.h"
#include "ListClient.h"
class Sistema {
private:
	ListGame listGames;
	ListClient listClients;
public:
	Sistema();
	virtual ~Sistema();
	bool readGames();
	bool readClient();
	string printListGames();
	string printListClient();

};
#endif /* SISTEMA_H_ */
