#include <iostream>
#include <ctime>

using namespace std;

//prototipo de funciones:
void concatenar(string,string);

string nombre, apellido;

int main(){
    cout<<"Escriba su nombre y apellido: ";cin>>nombre>>apellido;

    concatenar(nombre,apellido);







    return 0;
}

//definiciones de funciones:
void concatenar(string nombre1,string apellido1){
    cout<<nombre1<<apellido1<<endl;
}