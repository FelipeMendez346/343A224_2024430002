#include <iostream>
#include <string>
using namespace std;

int tamaño_arreglo=10;

//Funciones a usar del ejercio 0
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
    
void agregar_paciente(Pacientes arreglo[] ,Pacientes a){
    int i=0;
    while(arreglo[i].Nombre!=""){//busca el primer espacio vacio en el arreglo
        i++;
    }
    if (i<tamaño_arreglo){// verifica que no se pase del tamaño maximo
        arreglo[i]=a;// coloca a nuevo paciente en el arreglo
        cout<<"se agrego el paciente: "<<endl;
        printear(a);//describe al paciente agregado
    }else{
        cout<<"lista llena,no se ha agregado el paciente"<<endl;  
    }
}

void Escribir_arreglo(Pacientes arreglo[]){
    int i=0;
    cout<<"___________________________________________"<<endl;
    cout<<"La lista Competa seria:"<<endl;
    while(arreglo[i].Nombre!=""){//recorre cada arreglo para imprimirlo
        printear(arreglo[i]);
        i++;
    }
}

void eliminar_paciente(Pacientes arreglo[],int n){  //n es la posiciojn que quiere eliminar
    for (int i=n;i<tamaño_arreglo;i++){
        arreglo[i]=arreglo[i+1];
    }
    
}

int main(){
    //crea arrego y pacientes
    Pacientes pacientes[tamaño_arreglo];
    Pacientes paciente1=Crear_paciente("Maria",30,60.2,1.77);
    Pacientes paciente2=Crear_paciente("Pedro",20,70,1.54);
    Pacientes paciente3=Crear_paciente("Camilo",22,100,1.83);
    // Agregar pacientes al arreglo
    agregar_paciente(pacientes,paciente1);
    agregar_paciente(pacientes,paciente2);
    agregar_paciente(pacientes,paciente3);
    //muestra el arreglo final de pacientes
    Escribir_arreglo(pacientes);
    //elimina a pedro
    eliminar_paciente(pacientes,1);
    //muestra el arreglo eliminando a pedro
    Escribir_arreglo(pacientes);
    return 0; 
}