#include <iostream>
#include <string>
using namespace std;

string Dar_vuelta(string Secuenciaa){
    //Funcion para crear variable de una palabra pero al reves
    string Secuencia_alreves;
    for (int i=Secuenciaa.length()-1;i>=0;i--){
        string a_temp;//Creacion de un temporal para cada letra a dar vuelta
        a_temp=Secuenciaa[i];
        Secuencia_alreves.append(a_temp);
    }
    return Secuencia_alreves;
} //salida:hola>>a+l+o+h>>aloh

void Es_Palindromo(string Secuencia){
    if(Secuencia==Dar_vuelta(Secuencia)){
        cout<<"La secuencia "<<Secuencia<<" es Palindroma."<<endl;
    //si es palindroma, se escribe que es
    }else{
        cout<<"La secuencia "<<Secuencia<<" no es Palindroma."<<endl;
    }
    //si no, escribe que no es
}

int main(){
    string S;
    cout<<"Escriba Una cadena de Nucleotidos"<<endl;
    cin>>S;
    Es_Palindromo(S);
}
//funcion main
//Entrada: HOOH
//salida: La secuencia HOOH es Palindroma