#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


struct NodoRes {
    string resn;   
    string resid;   
    NodoRes* sig;
};

// agrega el nuevo nodo al final 
void insertarFinal(NodoRes*& cabeza, const string& resn, const string& resid) {
    NodoRes* nuevo = new NodoRes{resn, resid, nullptr};
    if (!cabeza) { cabeza = nuevo; return; }
    NodoRes* cur = cabeza;
    while (cur->sig) cur = cur->sig;
    cur->sig = nuevo;
}
// muestra la lista
void mostrar(NodoRes* cabeza) {
    if (!cabeza) { cout << "Lista vacia.\n"; return; }
    int i = 1;
    while (cabeza) {
        cout << i++ << ") " << cabeza->resn << cabeza->resid << "\n";
        cabeza = cabeza->sig;
    }
}
//elimina espacios
void rtrim(string& s) { // quita espacios/blancos finales (maneja '\r')
    while (!s.empty()) {
        char c = s[s.size()-1];
        if (c==' ' || c=='\t' || c=='\r' || c=='\n') s.erase(s.size()-1);
        else break;
    }
}
// exportar .dot
bool exportarDOT(NodoRes* cabeza, const string& filenameDot) {
    ofstream out(filenameDot.c_str());
    if (!out) { cout << "No se pudo abrir: " << filenameDot << "\n"; return false; }

    out << "digraph G {\n";
    out << "rankdir=LR;\n";
    out << "node [style=filled, fillcolor=yellow];\n";

    if (!cabeza) {
        out << "}\n";
        cout << "DOT exportado (lista vacia): " << filenameDot << "\n";
        return true;
    }

    NodoRes* cur = cabeza;
    while (cur && cur->sig) {
        out << "\"" <<cur->resn << cur->resid << "->"
            << cur->sig->resn << cur->sig->resid << "\";\n";
        cur = cur->sig;
    }
    // Asegurar que el último nodo se muestre
    out << cur->resn << cur->resid << ";\n";

    out << "}\n";
    cout << "DOT exportado en: " << filenameDot << "\n";
    return true;
}

string sugerirPNG(const string& dotFile) {
    if (dotFile.size() >= 4) {
        size_t n = dotFile.size();
        if (dotFile[n-4]=='.' && dotFile[n-3]=='d' && dotFile[n-2]=='o' && dotFile[n-1]=='t')
            return dotFile.substr(0, n-4) + ".png";
    }
    return dotFile + ".png";
}

bool generarPNG(const string& dotFile, const string& pngFile) {
    string cmd = "dot -Tpng \"" + dotFile + "\" -o \"" + pngFile + "\"";
    int ret = system(cmd.c_str());
    if (ret != 0) {
        cout << "Fallo al ejecutar Graphviz. Asegurate de tener 'dot' en el PATH.\n";
        return false;
    }
    cout << "PNG generado: " << pngFile << "\n";
    return true;
}

// cargar archivo
bool cargarDesdeFormat(const string& formatFile, NodoRes*& cabeza) {
    ifstream in(formatFile.c_str());
    if (!in) {
        cout << "No se pudo abrir: " << formatFile << "\n";
        return false;
    }

    string line;
    int insertados = 0;
    while (getline(in, line)) {
        if (line.size() < 4) continue;   
        string resn  = line.substr(0, 3);     
        string resid = line.substr(3);
        if (resid.empty()) continue;

        insertarFinal(cabeza, resn, resid);
        insertados++;
    }
    in.close();

    cout << "Cargados " << insertados 
         << " residuos desde " << formatFile << ".\n";
    return insertados > 0;
}

//main
int main() {
    NodoRes* cabeza = nullptr;
    string Archivo="4l40_Resids_ChainA_Format_Uniq.pdb";
    string dotPath  = "4l40.dot";
    string pngPath  = "4l40.png";
    cargarDesdeFormat(Archivo, cabeza);
    // Exportar .dot
    cout << "Nombre de salida .dot (ENTER para '" << dotPath << "'): ";
    string inDot; getline(cin, inDot);
    if (!inDot.empty()) dotPath = inDot;
    if (exportarDOT(cabeza, dotPath)) {
        // Generar .png
        cout << "Nombre de salida .png (ENTER para sugerido '" 
                << sugerirPNG(dotPath) << "'): ";
        string inPng; getline(cin, inPng);
        pngPath = inPng.empty() ? sugerirPNG(dotPath) : inPng;
        generarPNG(dotPath, pngPath);
    }
}