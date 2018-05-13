/*
 * Client.h
 *
 *  Created on: 10-05-2018
 *      Author: carlo
 */

#ifndef CLIENT_H_
#define CLIENT_H_
#include <iostream>
#include <string>
using namespace std;

class Client {
	friend class ListClient;
public:
	Client(string r="",string n="",string a ="",string e=""):rut(r),clientName(n),address(a),email(e){};
	virtual ~Client();
	string getDatos();
	string rut,clientName,address,email;
private:
//	string rut,clientName,address,email;
};

#endif /* CLIENT_H_ */
