#include <iostream>
#include <string>
using namespace std;

bool Es_par(int n){
    if (n%2==0){//comprobacion de si es par o no
        cout<<"El Numero "<<n<<" es Par"<<endl;
        //salida: El numero n es Par  
        return true;//devuelve true por si se usa en otra funcion
    }
    else{
        cout<<"El Numero "<<n<<" es Impar"<<endl;
        //salida: El numero n es Impar
        return false;//devuelve false por si se usa en otra funcion
    
    }    
}

int Largo(string Palabra){
    cout<<"La palabra tiene de largo: "<<Palabra.length()<<" Letras"<<endl;
    return 0;

}

int main(){
    int Numero;//inicializa datos para guardarse 
    string Palabra;
    cout<<"Ingrese un numero"<<endl;
    cin>>Numero;
    Es_par(Numero);//Prueba numero Ingresado 
    for (int i=1;i<=10;i++){
        Es_par(i);
    }
    //Prueba del 1 al 10 de la funcion
    //El numero 5 es Impar

    cout<<"Ingrese una Palabra"<<endl;
    cin>>Palabra;
    Largo(Palabra);
    //Largo(Hola)
    //La palabra tiene de largo: 4 Letras
    return 0;
}