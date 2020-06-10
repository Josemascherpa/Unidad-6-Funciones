/*Hacer una función que sume iguales al pasado por parámetro en un arreglo: El 2 en el arreglo
{2,7,1,2,5,3,2,1} dará 6.*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//prototipo funciones:
int ocurrencias(int,int);

int numero,Arreglo[10] = {2,2,2,5,5,3,4,6,7,6};
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
	cout<<contador*numero;
	return contador*numero;
}
		
