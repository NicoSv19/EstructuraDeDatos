/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: carlo
 *
 * Created on 28 de abril de 2018, 7:32
 */

#ifndef GAME_H
#define GAME_H

#include <iostream>
using namespace std;
class Game {
public:
    Game(string gameCode,string gameName,string developerName,string plataform,string releaseDate,int initialStock,int actualStock,int price);
    virtual ~Game();
    //Metodos
    string getDates();
    double descuento();
    //Getters
    string getGameCode();
    string getGameName();
    string getDeveloperName();
    string getPlataform();
    string getReleaseDate();
    int getInitialStock();
    int getActualStock();
    int getPrice();
    //Setters
    void setGameCode(string gameCode);
    void setGameName(string GameName);
    void setDeveloperName(string developerName);
    void setPlataform(string plataform);
    void setReleaseDate(string releaseDate);
    void setInitialStock(int initialStock);
    void setActualStock(int actualStock);
    void setPrice(int price);
private:
    string gameCode;
    string gameName;
    string developerName;
    string plataform;
    string releaseDate;
    int initialStock;
    int actualStock;
    int price;
    
};

#endif /* GAME_H */

