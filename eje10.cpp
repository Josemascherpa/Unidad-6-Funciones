#include <iostream>
#include <ctime>
#include <string.h>

using namespace std;


//Prototipo de funciones:
void vocales(string,int);


int main(){
	string palabra;
	cout<<"Ingrese una palabra: "<<endl;
	cin>>palabra;
	int tamanio=palabra.size();
	
	
	
	vocales(palabra,tamanio);
	
	
	return 0;
}
	
	//Declaracion de funciones:
	void vocales(string palabra,int tamanio){
		int contA=0,contE=0,contI=0,contO=0,contU=0;
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
		
		
		cout<<"A: "<<contA<<" E: "<<contE<<" I: "<<contI<<" O: "<<contO<<" U: "<<contU<<endl;
		
	}
		
		
