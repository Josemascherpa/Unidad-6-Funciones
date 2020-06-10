#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

//prototipos de la funciones:

float promedio(int);

int Valores[10] = {4,5,6,3,7,8,95,26,23,15};

int main(){
	
	promedio(Valores[10]);
	
	
	return 0;
}
	
	//declaraciones de las funciones:
	
float promedio(int){
	float contador = 0;
	int suma=0;
	float promedio=0;
	
	for(int i=0;i<10;i++){
	
	
	suma = suma + Valores[i];
	contador++;
	}
	
	promedio = suma / contador;
	cout<<"El promedio es: "<<promedio;
	
	return promedio;
}
