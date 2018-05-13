
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#
#include "Sistema.h"
using namespace std;

Sistema sistema;

bool lecturaTxt(){
	if(sistema.readGames() && sistema.readClient()){
		cout<<"Right read the txt"<<endl;
		return true;
	}
	else {
		cout<<"Incorrect read the txt"<<endl;
		return false;
	}
}
void mostrarListaGame(){
	sistema.printListGames();
}
bool isNum(string num){
	signed int n= num.length();
	for( int i=0 ; i< n; i++ ) if(!isdigit(num[i])) return false;
	return true;
}

void printmenuWarehouse(){
	cout<<"|================================================|"<<endl;
	cout<<"|                 Warehouse Menu                 |"<<endl;
	cout<<"|================================================|"<<endl;
	cout<<"| Options:                                       |"<<endl;
	cout<<"|	>> 1 << Reserve number for Warehouse sale.  |"<<endl;
	cout<<"|    >> 2 << Attend by number.                   |"<<endl;
	cout<<"|    >> 4 << Close the Menu.                     |"<<endl;
	cout<<"|================================================|"<<endl;
	cout<<"	Enter one option(1,2,3):  ";
}

void menuWarehouse(){
	bool fin= false;
	while(!fin){
		printmenuWarehouse();
		string option;
		getline(cin,option);
		while(!isNum(option) || stoi(option)< 1 || stoi(option)>3){
			cout<<"Input Error"<<endl;
			printmenuWarehouse();
			getline(cin,option);
		}
		switch (stoi(option)){
		case 1:
			break;
		case 2:
			break;
		case 3:
			fin= true;
		}
	}
}

void printmenuWeb(){
	cout<<"|================================================|"<<endl;
	cout<<"|                    Web Menu                    |"<<endl;
	cout<<"|================================================|"<<endl;
	cout<<"| Options:                                       |"<<endl;
	cout<<"|	>> 1 << The cashier view.                   |"<<endl;
	cout<<"|    >> 2 << Show sales details.                 |"<<endl;
	cout<<"|    >> 3 << Close the Menu.                     |"<<endl;
	cout<<"|================================================|"<<endl;
	cout<<"	Enter one option(1,2,3):  ";
}

void menuWeb(){
	bool fin= false;
	while(!fin){
		printmenuWeb();
		string option;
		getline(cin,option);
		while(!isNum(option) || stoi(option)< 1 || stoi(option)>3){
			cout<<"Input Error"<<endl;
			printmenuWeb();
			getline(cin,option);
		}
		switch (stoi(option)){
		case 1:
			break;
		case 2:
			break;
		case 3:
			fin= true;
		}

	}
}

void printmenuVenta(){
	cout<<"|================================================|"<<endl;
	cout<<"|                   Sale Menu                    |"<<endl;
	cout<<"|================================================|"<<endl;
	cout<<"| Options:                                       |"<<endl;
	cout<<"|	>> 1 << Warehouse sale Menu.                |"<<endl;
	cout<<"|    >> 2 << The cashier view.                   |"<<endl;
	cout<<"|    >> 3 << Show sales details.                 |"<<endl;
	cout<<"|    >> 4 << Close the Menu.                     |"<<endl;
	cout<<"|================================================|"<<endl;
	cout<<"	Enter one option(1,2,3,4):  ";
}

void menuVentas(){
	bool fin= false;
	while(!fin){
		printmenuVenta();
		string option;
		getline(cin,option);
		while(!isNum(option) || stoi(option)< 1 || stoi(option)>4){
			cout<<"Input Error"<<endl;
			printmenuVenta();
			getline(cin,option);
		}sti
		switch (stoi(option)){
		case 1:
			menuWarehouse();
			break;
		case 2:

			break;
		case 3:
			break;
		case 4:
			fin= true;
		}

	}
}


void printmenu(){
	cout<<"|================================================|"<<endl;
	cout<<"|            Initial System Menu                 |"<<endl;
	cout<<"|================================================|"<<endl;
	cout<<"| Options:                                       |"<<endl;
	cout<<"|	>> 1 << Initialize to the Sale Menu.        |"<<endl;
	cout<<"|    >> 2 << Initialize to the Web Menu.         |"<<endl;
	cout<<"|    >> 3 << Close the System.                   |"<<endl;
	cout<<"|================================================|"<<endl;
	cout<<"	Enter one option(1,2,3):  ";
}
void initMenu(){

	bool fin= false;
	while(!fin){
		printmenu();
		string option;
		getline(cin,option);
		while(!isNum(option) || stoi(option)< 1 || stoi(option)>3){
			cout<<"Input Error"<<endl;
			printmenu();
			getline(cin,option);
		}
		switch (stoi(option)){
		case 1:
			menuVentas();
			break;
		case 2:
			menuWeb();
			break;
		case 3:
			fin= true;
		}

	}
}



int main(){

	if(lecturaTxt()){
		mostrarListaGame();
		initMenu();
	}
	cout<< "The End "<<endl;
	return 0;
}






