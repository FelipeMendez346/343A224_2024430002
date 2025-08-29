#include <iostream>
#include <string>
using namespace std;

string Dar_vuelta(string Secuenciaa){
    string Secuencia_alreves;
    for (int i=Secuenciaa.length()-1;i>=0;i--){
        string a_temp;
        a_temp=Secuenciaa[i];
        Secuencia_alreves.append(a_temp);
    }
    return Secuencia_alreves;
} 

bool Es_Palindromo(string Secuencia){
    if(Secuencia==Dar_vuelta(Secuencia)){
        cout<<"La secuencia "<<Secuencia<<" es Palindroma."<<endl;
        return true;
    }else{
        cout<<"La secuencia "<<Secuencia<<" no es Palindroma."<<endl;
        return false;
    }
}

int main(){
    string S;
    cout<<"Escriba Una cadena de Nucleotidos"<<endl;
    cin>>S;
    Es_Palindromo(S);
}