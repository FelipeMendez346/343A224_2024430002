#include <iostream>
#include <string>
using namespace std;
#include <cmath>
#include <fstream>
#include <sstream>
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
    for (int i=n;i<tamaño_arreglo && arreglo[i].Nombre!="";i++){//mueve todo el arreglo a un espacio a la izquierda quietando e numero a elegir
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
    cout<<"-------------------------------------------";
}

void cargar_desde_csv(Pacientes arreglo[], string nombre_archivo){
    string linea;
    ifstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        cout << "no se pudo abrir el archivo" << endl;
        return;
    }
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nombre, edadStr, pesoStr, alturaStr;

        getline(ss,nombre,',');
        getline(ss,edadStr,',');
        getline(ss,pesoStr,',');
        getline(ss,alturaStr,',');

        if (nombre != "") {
            Pacientes p_temp;
            p_temp = Crear_paciente(nombre, stoi(edadStr), stod(pesoStr), stod(alturaStr));
            agregar_paciente(arreglo,p_temp);
        }
    }

    archivo.close();
}

int main() {
    Pacientes pacientes[tamaño_arreglo];
    int opcion;

    do {
        cout<<"1.Agregar paciente"<<endl;
        cout<<"2.Ver lista de pacientes"<<endl;
        cout<<"3.Eliminar paciente"<<endl;;
        cout<<"4.Calcular promedios"<<endl;
        cout<<"5.Cargar desde archivo CSV"<<endl;
        cout<<"0.Salir"<<endl;
        cout<<"Seleccione una opcion:"<<endl;
        cin >> opcion;

        if (opcion==1){
            string nombre;
            int edad;
            double peso;
            double altura;
            cout<<"Ingrese nombre:"<<endl;
            cin >> nombre;
            cout<<"Ingrese edad:"<<endl;
            cin >> edad;
            cout<<"Ingrese peso (kg):"<<endl;
            cin >> peso;
            cout<<"Ingrese altura (m):"<<endl;
            cin >> altura;
            Pacientes nuevo_paciente=Crear_paciente(nombre, edad, peso, altura);
            agregar_paciente(pacientes,nuevo_paciente);

        } else if(opcion==2){
            Escribir_arreglo(pacientes);

        } else if(opcion==3){
            int n;
            cout<<"Ingrese la posicion a eliminar (empezando en 0): ";
            cin>>n;
            eliminar_paciente(pacientes,n);

        } else if(opcion==4){
            Promedios(pacientes);

        } else if(opcion==5){
            string archivo;
            cout << "Ingrese nombre del CSV:"<<endl;
            cin >> archivo;
            cargar_desde_csv(pacientes, archivo);
        }

    } while (opcion != 0);

    return 0;
}