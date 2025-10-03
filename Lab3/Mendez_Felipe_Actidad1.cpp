#include <iostream>
#include <string>
using namespace std;

struct Nodo {
    string nombre;
    string carrera;
    float  promedio;
    Nodo*  sig;
};

// agrega al final
void agregar(Nodo*& primero, const string& nombre, const string& carrera, float promedio) {
    Nodo* nuevo = new Nodo{nombre, carrera, promedio, nullptr};
    if (!primero) { primero = nuevo; return; }
    Nodo* cur = primero;
    while (cur->sig) cur = cur->sig;
    cur->sig = nuevo;
}

//eliminar el primer dato 
bool eliminar(Nodo*& primero) {
    if (!primero) return false;
    Nodo* aux = primero;
    primero = primero->sig;
    cout << "Se elimino: " << aux->nombre << " (" << aux->carrera
         << "), Promedio: " << aux->promedio << "\n";
    return true;
}

void mostrar(Nodo* primero) {
    if (!primero) { cout << "La cola esta vacia.\n"; return; }
    cout << "Cola:\n";
    int i = 1;
    while (primero) {
        cout << i++ << ") " << primero->nombre << " | " << primero->carrera
             << " | Promedio: " << primero->promedio << "\n";
        primero = primero->sig;
    }
}

int main() {
    Nodo* primero = nullptr;
    int opcion = -1;

    do {
        cout << "\n====== COLA ======\n"
             << "1) Agregar\n"
             << "2) Eliminar primero\n"
             << "3) Mostrar cola\n"
             << "4) Salir\n"
             << "Opcion: ";
        cin >> opcion; cin.ignore();

        if (opcion == 1) {
            string nombre, carrera; float prom;
            cout << "Nombre: ";  getline(cin, nombre);
            cout << "Carrera: "; getline(cin, carrera);
            cout << "Promedio: "; cin >> prom; cin.ignore();
            agregar(primero, nombre, carrera, prom);
        } else if (opcion == 2) {
            if (!eliminar(primero)) cout << "La cola esta vacia.\n";
        } else if (opcion == 3) {
            mostrar(primero);
        } else if (opcion == 4) {
            cout << "Saliendo...\n";
        } else {
            cout << "Opcion invalida.\n";
        }
    } while (opcion != 4);
    return 0;
}