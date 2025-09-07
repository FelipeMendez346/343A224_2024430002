#include <iostream>
#include <iostream>
using namespace std;

struct Pacientes{
    string Nombre;//nombre 
    int Edad;//edad en años
    double Peso;//peso en KG
    double Altura;//altura en Metros
};
//crea un paciente a partir de datos dados 
Pacientes Crear_paciente(string nombre,int edad, double peso, double altura){
    Pacientes Nuevo_paciente;//crea nuevo paciente
    Nuevo_paciente.Nombre=nombre;//le pone el nombre dada
    Nuevo_paciente.Edad=edad;//le pone la edad dada
    Nuevo_paciente.Peso=peso;//le pone el peso dada
    Nuevo_paciente.Altura=altura;//le pone la altura dada
    return Nuevo_paciente;//retorna el paciente con los datos puestos
}
//escribe caracteristicas de los pacientes por salida estandar
void printear(Pacientes p){
    cout<< "Nombre: "<<p.Nombre<<endl;
    cout<< "Edad: "<<p.Edad<<" años"<<endl;
    cout<< "Peso: "<<p.Peso<<" kg"<<endl;
    cout<< "Altura: "<<p.Altura <<" m"<<endl;
    cout << "------------------"<<endl;
}

int main(){
    Pacientes paciente1=Crear_paciente("Maria",30,60.2,1.77);
    Pacientes paciente2=Crear_paciente("Pedro",20,70,1.54);
    Pacientes paciente3=Crear_paciente("Camilo",22,100,1.83);
    printear(paciente1);
    printear(paciente2);
    printear(paciente3);
    return 0;
}

