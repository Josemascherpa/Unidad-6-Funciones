#include <iostream>
#include <ctime>
#include <string.h>

using namespace std;


//Prototipo de funciones:
void vocales(string,int,int,int,int,int,int);


int main(){
	string palabra;
	int contA=0,contE=0,contI=0,contO=0,contU=0;
	cout<<"Ingrese una palabra: "<<endl;
	cin>>palabra;
	int tamanio=palabra.length();
	
	
	
	vocales(palabra,tamanio,contA,contE,contI,contO,contU);
	
	
	return 0;
}
	
	//Declaracion de funciones:
	void vocales(string palabra,int tamanio,int contA,int contE,int contI,int contO,int contU){
		for(int i=0;i<tamanio;i++){
			switch(palabra[i]){
			case 'a':contA++;break;
			case 'e':contE++;break;
			case 'i':contI++;break;
			case 'o':contO++;break;
			case 'u':contU++;break;
			default:break;				
			}
		}
		
		
		cout<<"A:"<<contA<<" E:"<<contE<<" I:"<<contI<<" O:"<<contO<<" U:"<<contU<<endl;
		
	}

