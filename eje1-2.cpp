#include <iostream>

using namespace std;

//Prototipo funcion:
int mayorArr(int Arr[]);



int main(){
	
	int Arreglo[8]={2,4,5,3,8,3,95,12};
	
	mayorArr(Arreglo);
	
	
	
	return 0;
}
	
	//Declaracion de funcion:
	int mayorArr(int Arreglo[]){
		int mayor=0;
		for(int i=0;i<8;i++){
			if(Arreglo[i]>mayor){
				mayor=Arreglo[i];
			}
		}
		
		
		
		cout<<"El mayor del arreglo es: "<<mayor;
		return mayor;
	}
		
