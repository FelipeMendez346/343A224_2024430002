#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
};

// Crear un nuevo nodo
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->info = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
//busca un nodo que tenga la data que se busca
Node* Buscar_nodo(Node* node, int N) {
    if (node == nullptr || node->info == N) {
        return node;
    }
    Node* left = Buscar_nodo(node->left, N);
    if (left != nullptr) {
        return left;
    }
    return Buscar_nodo(node->right, N);
}

bool esta_en_nodo(Node* nodo,int numero){
    if(Buscar_nodo(nodo,numero)==nullptr){
        return true;
    }else{
        return false;
    }
}

void crear_txt(Node* node, ofstream& fp) {
    if (node != nullptr) {
        if (node->left != nullptr) {
            fp << node->info << "->" << node->left->info << ";" << endl;
        } else {
            string cadena = "\"" + to_string(node->info) + "i\"";  // Convertir el entero a string y concatenar "i"
            fp << cadena << "[shape=point];" << endl;
            fp << node->info << "->" << cadena << ";" << endl;
        }

        if (node->right != nullptr) {
            fp << node->info << "->" << node->right->info << ";" << endl;
        } else {
            string cadena = "\"" + to_string(node->info) + "d\"";  // Convertir el entero a string y concatenar "d"
            fp << cadena << "[shape=point];" << endl;
            fp << node->info << "->" << cadena << ";" << endl;
        }

        crear_txt(node->left, fp);  // Llamada recursiva
        crear_txt(node->right, fp); // Llamada recursiva
    }
}

// Generar y mostrar la visualización del árbol
void visualize(Node* root) {
    ofstream fp("arbol.txt");

    if (!fp.is_open()) {
        cerr << "Error al abrir el archivo arbol.txt" << endl;
        return;
    }

    fp << "digraph G {" << endl;
    fp << "node [style=filled fillcolor=yellow];" << endl;

    // Llamada a la función 'crear_txt' para escribir la representación en el archivo
    crear_txt(root, fp);

    fp << "}" << endl;

    fp.close();

    // Generar y mostrar la imagen del árbol
    system("dot -Tpng -o arbol.png arbol.txt");
    system("eog arbol.png");
}


// Funcion recursiva para construir el arbol manualmente
void crea_arbol(Node* &apnodo) {
    if (apnodo == nullptr) {
        int valor;
        cout << "Ingrese valor para el nodo: ";
        cin >> valor;
        apnodo = createNode(valor);
    }

    char resp;

    // Preguntar por hijo izquierdo
    cout << "¿Existe nodo por izquierda de " << apnodo->info << "? (s/n): ";
    cin >> resp;
    if (resp == 's' || resp == 'S') {
        apnodo->left = nullptr; // inicializar
        crea_arbol(apnodo->left); // llamada recursiva
    } else {
        apnodo->left = nullptr;
    }

    // Preguntar por hijo derecho
    cout << "¿Existe nodo por derecha de " << apnodo->info << "? (s/n): ";
    cin >> resp;
    if (resp == 's' || resp == 'S') {
        apnodo->right = nullptr;
        crea_arbol(apnodo->right); // llamada recursiva
    } else {
        apnodo->right = nullptr;
    }
}

//Agrega un nodo nuevo con un numero dado a la izquierda del arbol
void Agregar_Nodo(Node* node,int n){
    if (esta_en_nodo(node,n)){    
        if (node==nullptr){
            node=createNode(n);
        }else{
            if (node->left==nullptr){
                node->left=createNode(n);
            }else if(node->right==nullptr){
                node->right=createNode(n);
            }else{
                Agregar_Nodo(node->left,n);
            }
        }
    }else{
        cout<<"error, existe un nodo con el numero ingresado\n";
    }    
}
Node* Eliminar_Nodo(Node* node, int n) {
    Node* nodo = Buscar_nodo(node, n);
    if (nodo == nullptr) {
        cout << "No existe el nodo\n";
        return node;
    }
    if (nodo->left != nullptr) {
        nodo = nodo->left;
        Eliminar_Nodo(nodo->left, n);
    }else if (nodo->right != nullptr) {
        nodo = nodo->right;
        Eliminar_Nodo(nodo->right, n);
    }else{
        nodo = nullptr;
    }

    return node;
}

void cambiar_nodo(Node* node,int n_a_cambiar,int n_a_reemplazar){
    if (esta_en_nodo(node,n_a_reemplazar)){ 
        Node* nodo_cambiado=Buscar_nodo(node,n_a_cambiar);
        if (node!=nullptr){
            node->info=n_a_reemplazar;
        }else{
            cout<<"El nodo a reemplazar no existe\n";
        }
    }else{
        cout<<"error, existe un nodo con el numero ingresado\n";
    }    

}

// Funcion recursiva para imprimir el arbol en preorden
void printPreOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->info << " - ";   // Imprimir el dato del nodo actual
    printPreOrder(node->left);   // Recorrer el subarbol izquierdo
    printPreOrder(node->right);  // Recorrer el subarbol derecho
}
// Funcion recursiva para imprimir el arbol en Inorden
void printInOrder(Node* node){
    if (node==nullptr){
        return;
    }
    printInOrder(node->left);
    cout<<node->info <<" - ";
    printInOrder(node->right);
}
// Funcion recursiva para imprimir el arbol Posorden
void printPosOrder(Node* node){
    if (node==nullptr){
        return;
    }
    printPosOrder(node->left);
    printPosOrder(node->right);
    cout<<node->info<<" - ";
}

int main() {
    int opcion;
    Node* root = nullptr;

    cout << "Construccion interactiva del arbol binario:\n";
    crea_arbol(root);
    do {
        cout << "----- Menú -----\n";
        cout << "1.Insertar numero\n";
        cout << "2.Eliminar numero\n";
        cout << "3.Modificar numero\n";
        cout << "4.Mostrar orden\n";
        cout << "5.Imprimir grafico\n";
        cout << "6.Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // Switch para manejar las opciones
        switch (opcion) {
            case 1:
                int nuevo_numero;
                cout << "Escribi el numero que quieres agregar\n";
                cin>>nuevo_numero;
                Agregar_Nodo(root,nuevo_numero);
                break;
            case 2:
                int n_a_eliminar;
                cout << "ingrese el numero del nodo que quiere elimnar\n";
                cin>>n_a_eliminar;
                Eliminar_Nodo(root,n_a_eliminar);
                break;
            case 3:
                int n_a_cambiar;
                int n_nuevo;
                cout << "ingrese numero a reemplazar\n";
                cin>>n_a_cambiar;
                cout << "ingrese nuevo valor\n";
                cin>>n_nuevo;
                cambiar_nodo(root,n_a_cambiar,n_nuevo);
                break;
            case 4:
                cout<<"Preorden:\n";
                printPreOrder(root);
                cout<<"\n";
                cout<<"Inorden:\n";
                printInOrder(root);
                cout<<"\n";
                cout<<"Posorden:\n";
                printPosOrder(root);
                cout<<"\n";
                break;
            case 5:
                visualize(root);
                break;
            case 6:
                break;
            default:
                cout << "Opción no válida. Por favor, intente de nuevo\n";
        }
    } while (opcion != 6);

    return 0;
}

