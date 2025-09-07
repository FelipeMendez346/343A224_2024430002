#include <iostream>
#include <string>
using namespace std;
#include <cmath>

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
    cout<< "IMC: "<<p.Peso/pow(p.Altura, 2)<<endl;
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

void eliminar_paciente(Pacientes arreglo[],int n){  //n es la posicion que quiere eliminar
    for (int i=n;i<tamaño_arreglo;i++){//mueve todo el arreglo a un espacio a la izquierda quietando e numero a elegir
        arreglo[i]=arreglo[i+1];
    }

}

void Promedios(Pacientes arreglo[]){
    int Pr_Edad=0;
    int Pr_peso=0;
    int i=0;
    while(arreglo[i].Nombre!=""){//busca el largo de pacientes
        i++;
    }
    for (int a=0;a<i;a++){//dependiendo del largo va sumando
        Pr_Edad+=arreglo[a].Edad;
        Pr_peso+=arreglo[a].Peso;   
    }
    Pr_Edad/=i;
    Pr_peso/=i;
    cout<<"Promedio de Edad: "<<Pr_Edad<<" años"<<endl;
    cout<<"Promedio de Peso: "<<Pr_peso<<" Kg"<<endl;


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
    Promedios(pacientes);

    return 0; 
}