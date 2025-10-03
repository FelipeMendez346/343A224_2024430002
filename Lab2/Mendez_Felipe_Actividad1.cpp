#include <iostream>
#include <string>
using namespace std;

struct Pila {
    int MAX;          // Capacidad lógica (<= 100)
    int TOPE;         // 0 => vacía; 1..MAX => elementos
    bool BAND;        // Bandera de estado
    string dato[100]; // Arreglo estático (índices 1..MAX)

    bool Pila_vacia(int TOPE, bool &BAND) {   
        if (TOPE == 0)
            BAND = true;
        else
            BAND = false;
        return BAND;
    }

    bool Pila_llena(int TOPE, int MAX, bool &BAND) {   
        if (TOPE == MAX)
            BAND = true;
        else
            BAND = false;
        return BAND;
    }   

    void Push(bool &BAND, int &TOPE, int MAX, string dato[], string DATO) { 
        Pila_llena(TOPE, MAX, BAND);
        if (BAND == true) {
            cout << "Desbordamiento, pila llena\n";
        } else if (BAND == false) {
            TOPE = TOPE + 1;
            dato[TOPE] = DATO;
            cout << "Agregado: \"" << DATO << "\"\n";
        }
    }

    string Pop(string dato[], int &TOPE, bool &BAND) { 
        Pila_vacia(TOPE, BAND);
        if (BAND == true) {
            cout << "Subdesbordamiento, pila vacia\n";
            return "";
        } else if (BAND == false) {
            string DATO = dato[TOPE];
            TOPE = TOPE - 1;
            cout << "Retirado: \"" << DATO << "\"\n";
            return DATO;
        }
        return ""; 
    }

    void Mostrar(string dato[], int TOPE) {
        if (TOPE == 0) {
            cout << "La pila está vacía.\n";
        } else {
            cout << "Contenido de la pila:\n";
            for (int i = TOPE; i >= 1; i--) {
                cout << "- " << dato[i] << "\n";
            }
        }
    }
};

int main() {
    Pila pila;
    pila.MAX = 100;
    pila.TOPE = 0;
    pila.BAND = false;

    int opcion;
    string titulo;
    do {
        cout << "\nMenu:\n";
        cout << "Agregar/Push [1]. \n";
        cout << "Remover/pop [2].\n";
        cout << "Mostrar [3].\n";
        cout << "Salir [4].\n";
        cout << "-------------------\n";
        cout << "Seleccione una opcion: \n";
        cin >> opcion;

        while (opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=-1){
            cin.ignore(1000,'\n');
            cin.clear();
            cout<<"Numero incorrecto, ingrese un nuevo valor: \n";
            opcion=-1;
        }
        cin.ignore();

        switch (opcion) {
            case -1:
                break;
            case 1:
                cout << "Ingrese el dato a agregar: ";
                cin.ignore(); // Limpiar buffer
                getline(cin, titulo);
                pila.Push(pila.BAND, pila.TOPE, pila.MAX, pila.dato, titulo);
                break;
            case 2:
                pila.Pop(pila.dato, pila.TOPE, pila.BAND);
                break;
            case 3:
                pila.Mostrar(pila.dato, pila.TOPE);
                break;
            case 4:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}
