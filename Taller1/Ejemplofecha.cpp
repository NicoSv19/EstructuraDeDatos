#include <iostream>
using namespace std;
typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;

int regularBisiesto( Fecha fecha1 ); //A0001
int diferenciaFechas(Fecha fecha1, Fecha fecha2){
	int difAnios, difDias=0, i, regBisAnioF1 = 0, regBisAnioF2;
    int tot_dias[] = { 00,31,28,31,30,31,30,31,31,30,31,30,31 };

    difAnios = fecha2.anio - fecha1.anio; //A0003
    regBisAnioF1 = regularBisiesto(fecha1); //A0004

    if( difAnios == 0){ //A0005
        if( fecha1.mes == fecha2.mes ){ //A0006
            difDias += fecha2.dia - fecha1.dia;
        }
        else{ //A0007
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
    else{ //A0008
        difDias += (tot_dias[fecha1.mes] - fecha1.dia); //B0008
        if(fecha1.mes == 2){
            difDias += regBisAnioF1;
        }
        if( fecha1.mes < 12 ){
            for( i = fecha1.mes +1; i <= 12; i++ ){
                difDias += tot_dias[i];
            }
        }
        for( i=fecha1.anio +1; i < fecha2.anio -1; i++){ // A0009
            difDias += 365;
            regBisAnioF1 = regularBisiesto(fecha1);
            difDias += regBisAnioF1;
        }
        regBisAnioF2 = regularBisiesto(fecha2);
        for( i=1; i < fecha2.mes; i++ ){ //A0010
            if( i == 2 ){
                difDias += regBisAnioF2;
            }
            difDias += tot_dias[i];
        }
        difDias += fecha2.dia; //A0011
    }
    return difDias;
}

int main(void){
	Fecha fecha1 ={15,05,2018}, fecha2 = {18,06,2018};
	int re = diferenciaFechas(fecha1,fecha2);
	cout<<re;
    return 0;
}

int regularBisiesto( Fecha fechaRb ){ //A0001
    if ((fechaRb.anio %4 == 0 && fechaRb.anio%100 != 0) || (fechaRb.anio%400) == 0){
        return 1;
    }
    else{
        return 0;
    }
}
