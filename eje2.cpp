#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//Declaracion funciones:
void SalidaEnPantalla(string);

string nombre;

int main(){

	cout<<"Escriba su nombre: ";
	cin>>nombre;
	SalidaEnPantalla(nombre);
	
	
	return 0;
}
	
//prototipo de funcion: 
void SalidaEnPantalla(string nombre1){
	cout<<"Hola "<<nombre1<<" como estas? "<<endl;
	
}
