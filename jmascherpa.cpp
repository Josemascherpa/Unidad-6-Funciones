#include <iostream>
#include <conio2.h>
#include <ctime>
using namespace std;

//Prototipo de funcion:
void tiradaDados(int arreglo[],int);//Tirada de dados.
void tablaPuntos(int arreglo[],int,int&,int&,int&,int&,int&,int&,int&,int&,int&,int&);// Tabla de puntos cuando se tiraron los dados para el jugador.
void tablaPuntosComp(int arreglo[],int,int&,int&,int&,int&,int&,int&,int&,int&,int&,int&);//Tabla de puntos cuando se tiraron los dados para la compu.
int puntajeJug(int,int,int,int,int&,int,int,int,int,int,int);//Obtenemos el mayor puntaje para el jugador.
int puntajeComp(int,int,int,int,int&,int,int,int,int,int,int);//Obtenemos el mayor puntaje para la compu.
void ganador(int&,int&);//Se declara el ganador de la mano.
	
int main(int argc, char *argv[]) {
	srand(time(NULL));
	int full=0,poker=0,escalera=0,generala=0,maxPuntaje=0,punt1=0,punt2=0,punt3=0,punt4=0,punt5=0,punt6=0;//Variables para el uso del jugador.
	int fullComp=0,pokerComp=0,escaleraComp=0,generalaComp=0,maxPuntajeComp=0,punt1Comp=0,punt2Comp=0,punt3Comp=0,punt4Comp=0,punt5Comp=0,punt6Comp=0;//variables para el uso de la compu.
	bool juego= false;
	cout<<"La generala se juega con 5 dados de 6 caras, se tiran y se forman jugadas con los numeros salientes. El juego consiste en una tirada el jugador y una tirada la PC, aquel con la mano más alta, gana." <<endl;
	
	cout<<endl<<"Presione S para tirar los dados."<<endl;
	while(juego==false){
		int dadosUsu[5];//Dados jugador
		int dadosComp[5];//Dados Compu
		
		if(kbhit()){
			int tecla=getch();
			
			switch(tecla){
				case 115:{//Juego Usuario
					cout<<endl;
					tiradaDados(dadosUsu,5); //se llama a la funcion para tirar los dados del jugador.				
					tablaPuntos(dadosUsu,5,full,poker,escalera,generala,punt1,punt2,punt3,punt4,punt5,punt6);//se llama la funcion para obtener la tabla de puntos y mostrarla para el jugador.
					puntajeJug(full,poker,escalera,generala,maxPuntaje,punt1,punt2,punt3,punt4,punt5,punt6);//Se llama a la funcion para obtener el puntaje mas alto del jugador.
					
					cout<<endl<<"Listo, ahora le toca a la Compu."<<endl;//Turno de la compu.
					cout<<endl;
					
					tiradaDados(dadosComp,5);//se llama a la funcion para tirar los dados de la compu.			
					tablaPuntosComp(dadosComp,5,fullComp,pokerComp,escaleraComp,generalaComp,punt1Comp,punt2Comp,punt3Comp,punt4Comp,punt5Comp,punt6Comp);//se llama a la funcion para obtener la tabla de puntos y mostrarla para la compu.
					puntajeComp(fullComp,pokerComp,escaleraComp,generalaComp,maxPuntajeComp,punt1Comp,punt2Comp,punt3Comp,punt4Comp,punt5Comp,punt6Comp);//Se llama a la funcion para obtener el puntaje mas alto de la compu.
					
					ganador(maxPuntaje,maxPuntajeComp);//Se llama a la funcion para obtener el mayor puntaje, y decidir quien gana.
					
					
					}break;
				default:break;
			}break;
			
		}
	}
	
	return 0;
}

//Declaracion de funcion:
void tiradaDados(int arreglo[],int n){//Funcion tirada de dados.
	cout<<"Tirada: ";
	for(int i=0;i<n;i++){ //Recorrer el arreglo y generar numeros random del 1 al 6.
		arreglo[i] = 1+(rand()%6);
		cout<<arreglo[i]<<" ";
	}
	
}
void tablaPuntos(int arreglo[],int n,int& full,int& poker,int& escalera,int& generala,int& punt1,int& punt2,int& punt3,int& punt4,int& punt5,int& punt6){//Funcion tabla de puntos para le jugador.
	int cont1=0,cont2=0,cont3=0,cont4=0,cont5=0,cont6=0; //Contadores para ver cuantas veces sale un numero.
	for(int i=0;i<n;i++){ //Bucle para sumar cuantas veces sale un numero.
		if(arreglo[i] == 1){
			cont1++;
		}
		if(arreglo[i] == 2){
			cont2++;
		}
		if(arreglo[i] == 3){
			cont3++;
		}
		if(arreglo[i] == 4){
			cont4++;
		}
		if(arreglo[i] == 5){
			cont5++;
		}
		if(arreglo[i] == 6){
			cont6++;
		}
	}
	
	punt1=cont1*1;//multiplicando numero por las veces que salio y obtener puntos.
	punt2 = cont2*2;
	punt3 = cont3*3;
	punt4 = cont4*4;
	punt5 = cont5*5;
	punt6 = cont6*6;
	cout<<endl<<"Todo al 1:"<<punt1<<" puntos."<<endl;//Mostrando tabla con puntos.
	cout<<"Todo al 2:"<<punt2<<" puntos."<<endl;
	cout<<"Todo al 3:"<<punt3<<" puntos."<<endl;
	cout<<"Todo al 4:"<<punt4<<" puntos."<<endl;
	cout<<"Todo al 5:"<<punt5<<" puntos."<<endl;
	cout<<"Todo al 6:"<<punt6<<" puntos."<<endl;
	
	if((cont1==2 || cont2==2 || cont3==2 || cont4==2 || cont5==2 || cont6==2) && (cont1==3 || cont2==3 ||cont3==3 ||cont4==3 || cont5==3 || cont6==3)){ //Verificar si un numero salio 3 veces y asi lograr el full
		full = full + 30;
		cout<<"Full: "<<full<<endl;
	} else{
		cout<<"Full: 0."<<endl;
	}
	if(cont1==4|| cont2==4 || cont3==4 || cont4==4 || cont5==4 || cont6==4){ //Verificar si un numero se repitio 4 veces y asi lograr el poker.
		poker = poker + 40;
		cout<<"Poker: "<<poker<<"."<<endl;
	}else{
		cout<<"Poker: 0."<<endl;
	}
	if((cont1==1 && cont2==1 && cont3==1 && cont4==1 && cont5==1)||(cont2==1 && cont3==1 && cont4==1 && cont5==1 && cont6==1)){ //Verificando la escalera.
		escalera = escalera + 50;
		cout<<"Escalera: "<<escalera<<"."<<endl;		
	}else{
		cout<<"Escalera: 0."<<endl;
	}
	if(cont1==5 || cont2==5 || cont3==5 || cont4==5 || cont5==5 || cont6==5){//Verificando la generala, todos numeros iguales.
		generala = generala + 60;
		cout<<"Generala: "<<generala<<"."<<endl;
	}else{
		cout<<"Generala: 0."<<endl;
	}
	
}
	
int puntajeJug(int full,int poker,int escalera,int generala,int& maxPuntaje,int punt1,int punt2,int punt3,int punt4,int punt5,int punt6){//Funcion de puntaje del jugador.
	
	
	if((punt1>=punt2 && punt1>=punt3 && punt1>=punt4 && punt1>=punt5 && punt1>=punt6)&& (full==0 && poker==0 && escalera==0 && generala ==0 )){ //Verificando y guardando en la variable Max puntaje, el mayor puntaje del jugador.
		maxPuntaje=punt1;
		cout<<"El mayor puntaje es: "<<maxPuntaje<<endl;		
		
	}else if((punt2>=punt1 && punt2>=punt3 && punt2>=punt4 && punt2>=punt5 && punt2>=punt6)&& (full==0 && poker==0 && escalera==0 && generala ==0 )){
		maxPuntaje=punt2;
		cout<<"El mayor puntaje es: "<<maxPuntaje<<endl;	
	}else if((punt3>=punt1 && punt3>=punt2 && punt3>=punt4 && punt3>=punt5 && punt3>=punt6)&& (full==0 && poker==0 && escalera==0 && generala ==0 )){
		maxPuntaje=punt3;
		cout<<"El mayor puntaje es: "<<maxPuntaje<<endl;	
	}else if((punt4>=punt1 && punt4>=punt2 && punt4>=punt3 && punt4>=punt5 && punt4>=punt6)&& (full==0 && poker==0 && escalera==0 && generala ==0 )){
		maxPuntaje=punt4;
		cout<<"El mayor puntaje es: "<<maxPuntaje<<endl;	
	}else if((punt5>=punt1 && punt5>=punt2 && punt5>=punt3 && punt5>=punt4 && punt5>=punt6)&& (full==0 && poker==0 && escalera==0 && generala ==0 )){
		maxPuntaje=punt5;
		cout<<"El mayor puntaje es: "<<maxPuntaje<<endl;	
	}else if((punt6>=punt1 && punt6>=punt2 && punt6>=punt3 && punt6>=punt4 && punt6>=punt5)&& (full==0 && poker==0 && escalera==0 && generala ==0 )){
		maxPuntaje=punt6;
		cout<<"El mayor puntaje es: "<<maxPuntaje<<endl;	
	}
	
	if(full!=0){ //Verificando si salio full que se guarde como mayor puntaje.
		maxPuntaje=full;
		cout<<"Mayor puntaje:Full "<<maxPuntaje<<" puntos."<<endl;
	}else if(poker!=0){//Verificando si salio poker que se guarde como mayor puntaje.
		maxPuntaje=poker;
		cout<<"Mayor puntaje:Poker "<<maxPuntaje<<" puntos."<<endl;
	}else if(escalera!=0){//Verificando si salio escalera que se guarde como mayor puntaje.
		maxPuntaje=escalera;
		cout<<"Mayor puntaje:Escalera "<<maxPuntaje<<" puntos."<<endl;
	}else if(generala!=0){//Verificando si salio generala que se guarde como mayor puntaje.
		maxPuntaje=generala;
		cout<<"Mayor puntaje:Generala "<<maxPuntaje<<" puntos."<<endl;
	}
	
	return maxPuntaje;
}

void tablaPuntosComp(int arreglo[],int n,int& fullComp,int& pokerComp,int& escaleraComp,int& generalaComp,int& punt1Comp,int& punt2Comp,int& punt3Comp,int& punt4Comp,int& punt5Comp,int& punt6Comp){//Funcion tabla de puntos para la compu.
	int cont1=0,cont2=0,cont3=0,cont4=0,cont5=0,cont6=0;
	for(int i=0;i<n;i++){
		if(arreglo[i] == 1){
			cont1++;
		}
		if(arreglo[i] == 2){
			cont2++;
		}
		if(arreglo[i] == 3){
			cont3++;
		}
		if(arreglo[i] == 4){
			cont4++;
		}
		if(arreglo[i] == 5){
			cont5++;
		}
		if(arreglo[i] == 6){
			cont6++;
		}
	}
	
	punt1Comp=cont1*1;
	punt2Comp = cont2*2;
	punt3Comp = cont3*3;
	punt4Comp = cont4*4;
	punt5Comp = cont5*5;
	punt6Comp = cont6*6;
	cout<<endl<<"Todo al 1:"<<punt1Comp<<" puntos."<<endl;
	cout<<"Todo al 2:"<<punt2Comp<<" puntos."<<endl;
	cout<<"Todo al 3:"<<punt3Comp<<" puntos."<<endl;
	cout<<"Todo al 4:"<<punt4Comp<<" puntos."<<endl;
	cout<<"Todo al 5:"<<punt5Comp<<" puntos."<<endl;
	cout<<"Todo al 6:"<<punt6Comp<<" puntos."<<endl;
	
	if((cont1==2 || cont2==2 || cont3==2 || cont4==2 || cont5==2 || cont6==2) && (cont1==3 || cont2==3 ||cont3==3 ||cont4==3 || cont5==3 || cont6==3)){
		fullComp = fullComp + 30;
		cout<<"Full: "<<fullComp<<endl;
	} else{
		cout<<"Full: 0."<<endl;
	}
	if(cont1==4|| cont2==4 || cont3==4 || cont4==4 || cont5==4 || cont6==4){
		pokerComp = pokerComp + 40;
		cout<<"Poker: "<<pokerComp<<"."<<endl;
	}else{
		cout<<"Poker: 0."<<endl;
	}
	if((cont1==1 && cont2==1 && cont3==1 && cont4==1 && cont5==1)||(cont2==1 && cont3==1 && cont4==1 && cont5==1 && cont6==1)){
		escaleraComp = escaleraComp + 50;
		cout<<"Escalera: "<<escaleraComp<<"."<<endl;		
	}else{
		cout<<"Escalera: 0."<<endl;
	}
	if(cont1==5 || cont2==5 || cont3==5 || cont4==5 || cont5==5 || cont6==5){
		generalaComp = generalaComp + 60;
		cout<<"Generala: "<<generalaComp<<"."<<endl;
	}else{
		cout<<"Generala: 0."<<endl;
	}
	
}
int puntajeComp(int fullComp,int pokerComp,int escaleraComp,int generalaComp,int& maxPuntajeComp,int punt1Comp,int punt2Comp,int punt3Comp,int punt4Comp,int punt5Comp,int punt6Comp){//funcion puntaje de la compu.
	
	if((punt1Comp>=punt2Comp && punt1Comp>=punt3Comp && punt1Comp>=punt4Comp && punt1Comp>=punt5Comp && punt1Comp>=punt6Comp)&& (fullComp==0 && pokerComp==0 && escaleraComp==0 && generalaComp ==0 )){
		maxPuntajeComp=punt1Comp;
		cout<<"El mayor puntaje es: "<<maxPuntajeComp<<endl;		
		
	}else if((punt2Comp>=punt1Comp && punt2Comp>=punt3Comp && punt2Comp>=punt4Comp && punt2Comp>=punt5Comp && punt2Comp>=punt6Comp)&& (fullComp==0 && pokerComp==0 && escaleraComp==0 && generalaComp ==0 )){
		maxPuntajeComp=punt2Comp;
		cout<<"El mayor puntaje es: "<<maxPuntajeComp<<endl;	
	}else if((punt3Comp>=punt1Comp && punt3Comp>=punt2Comp && punt3Comp>=punt4Comp && punt3Comp>=punt5Comp && punt3Comp>=punt6Comp)&& (fullComp==0 && pokerComp==0 && escaleraComp==0 && generalaComp ==0 )){
		maxPuntajeComp=punt3Comp;
		cout<<"El mayor puntaje es: "<<maxPuntajeComp<<endl;	
	}else if((punt4Comp>=punt1Comp && punt4Comp>=punt2Comp && punt4Comp>=punt3Comp && punt4Comp>=punt5Comp && punt4Comp>=punt6Comp)&& (fullComp==0 && pokerComp==0 && escaleraComp==0 && generalaComp==0 )){
		maxPuntajeComp=punt4Comp;
		cout<<"El mayor puntaje es: "<<maxPuntajeComp<<endl;	
	}else if((punt5Comp>=punt1Comp && punt5Comp>=punt2Comp && punt5Comp>=punt3Comp && punt5Comp>=punt4Comp && punt5Comp>=punt6Comp)&& (fullComp==0 && pokerComp==0 && escaleraComp==0 && generalaComp ==0 )){
		maxPuntajeComp=punt5Comp;
		cout<<"El mayor puntaje es: "<<maxPuntajeComp<<endl;	
	}else if((punt6Comp>=punt1Comp && punt6Comp>=punt2Comp && punt6Comp>=punt3Comp && punt6Comp>=punt4Comp && punt6Comp>=punt5Comp)&& (fullComp==0 && pokerComp==0 && escaleraComp==0 && generalaComp ==0 )){
		maxPuntajeComp=punt6Comp;
		cout<<"El mayor puntaje es: "<<maxPuntajeComp<<endl;	
	}
	
	if(fullComp!=0){
		maxPuntajeComp=fullComp;
		cout<<"Mayor puntaje:Full "<<maxPuntajeComp<<" puntos."<<endl;
	}else if(pokerComp!=0){
		maxPuntajeComp=pokerComp;
		cout<<"Mayor puntaje:Poker "<<maxPuntajeComp<<" puntos."<<endl;
	}else if(escaleraComp!=0){
		maxPuntajeComp=escaleraComp;
		cout<<"Mayor puntaje:Escalera "<<maxPuntajeComp<<" puntos."<<endl;
	}else if(generalaComp!=0){
		maxPuntajeComp=generalaComp;
		cout<<"Mayor puntaje:Generala "<<maxPuntajeComp<<" puntos."<<endl;
	}
	
	return maxPuntajeComp;
}

void ganador(int& maxPuntaje,int& maxPuntajeComp){//Verificando el ganador en base a los puntajes.
	
	if(maxPuntaje>maxPuntajeComp){
		cout<<endl<<"El ganador es el usuario con "<<maxPuntaje<<" puntos."<<endl;
	}else if(maxPuntajeComp>maxPuntaje){
		cout<<endl<<"El ganador es la compu con "<<maxPuntajeComp<<" puntos."<<endl;
	}else{
		cout<<endl<<"Empataron!!!."<<endl;
	}

}
	
	
