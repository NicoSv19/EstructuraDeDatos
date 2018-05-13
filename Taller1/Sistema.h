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
	Cola c;
public:
	Sistema();
	virtual ~Sistema();
	bool readGames();
	bool readClient();
	int regularBisiesto( Fecha fecha1 ); 
	int diferenciaFechas(Fecha fecha1, Fecha fecha2);
	int regularBisiesto( Fecha fechaRb );
	void Carrito(Cliente* cliente);
	void ProcesoPago(bool tienda, Cliente* cliente);
	bool Tienda();
	void NumeroVentaBodega();
	void VentaBodega();
	string printListGames();
	string printListClient();

};
#endif /* SISTEMA_H_ */
