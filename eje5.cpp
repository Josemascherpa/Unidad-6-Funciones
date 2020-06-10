/*Hacer una función que diga si un valor es múltiplo de N (dónde N se pasa por parámetro)*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//prototipo funciones:
int ocurrencias(int,int);

int numero,Arreglo[10] = {5,6,5,5,5,3,4,6,7,6};
int main(){
	
	cout<<"Ingrese numero que quiere ver si se repite: ";
	cin>>numero;
	
	ocurrencias(Arreglo[10],numero);
	
	return 0;
}
	
//declaracion de funcion: 
int ocurrencias(int,int numero){
	int contador=0;
	for(int i=0;i<10;i++){
		if(Arreglo[i]==numero){
			contador++;
		}
	}
	cout<<contador;
	return contador;
}
