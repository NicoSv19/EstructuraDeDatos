/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: carlo
 * 
 * Created on 28 de abril de 2018, 7:32
 */

#include "Game.h"
#include <string>
#include <ctime>
using namespace std;
//Constructor
Game::Game(string gameCode,string gameName,string developerName,string plataform,string releaseDate,int initialStock,int actualStock,int price) {
    this->gameCode=gameCode;
    this->gameName=gameName;
    this->developerName=developerName;
    this->plataform=plataform;
    this->releaseDate=releaseDate;
    this->initialStock=initialStock;
    this->actualStock=actualStock;
    this->price=price;
}
//Destructor
Game::~Game(){}
//Metodos
string Game::getDates(){
	string cadena="";
	cadena+="Game_Code: "+this->gameCode+"\n";
	cadena+="Game_Name: "+this->gameName+"\n";
	int precio= this->price;
	std::string p_str=std::to_string(precio);
	cadena+="Game_Price:"+ p_str +"\n";
	return cadena;
}
double Game::descuento(){
	double desc=0;
//	int dia,mes,anio,actDia,actMes,actAnio;
//	time_t now= time(0);
//	tm* time= localtime(&now);
//	string fecha= this->releaseDate;
//	dia= stoi(fecha.substr(0,2));
//	mes= stoi(fecha.substr(3,5));
//	anio= stoi(fecha.substr(6,10));
//	actDia= time->tm_mday;
//	actMes= time->tm_mon +1;
//	actAnio= time->tm_year+1900;
//	unsigned int restMes= mes-actMes;
//
//	//falta codigo

	return desc;
}

//Getters
string Game::getGameCode(){return this->gameCode;}
string Game::getGameName(){return this->gameName;}
string Game::getDeveloperName(){return this->plataform;}
string Game::getReleaseDate(){return this->releaseDate;}
int Game::getInitialStock(){return this->initialStock;}
int Game::getActualStock(){return this->actualStock;}
int Game::getPrice(){return this->price;}
//Setters
void Game::setGameCode(string gameCode){this->gameCode=gameCode;}
void Game::setGameName(string GameName){this->gameName=GameName;}
void Game::setDeveloperName(string developerName){this->developerName=developerName;}
void Game::setPlataform(string plataform){this->plataform=plataform;}
void Game::setReleaseDate(string releaseDate){this->releaseDate=releaseDate;}
void Game::setInitialStock(int initialStock){this->initialStock=initialStock;}
void Game::setActualStock(int actualStock){this->actualStock=actualStock;}
void Game::setPrice(int price){this->price=price;}
