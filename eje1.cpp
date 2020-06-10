#include <iostream>
#include <ctime>

using namespace std;

//prototipo de la funcion:
int numRand(int);//numero random


int main(){
    
    int random;
   
    cout<<"Le toco la cara del dado: ";

    numRand(random);


    



    return 0;
}

//declaracion de la funcion:

int numRand(int a){

    srand(time(NULL));

    a=rand()%6+1;//elegir numero random del 1 al 6
    cout<<a;

    return a;
}