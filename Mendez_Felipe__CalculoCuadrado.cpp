#include <iostream>
using namespace std;

int square (double x){
    double cuadrado=0;//variable para guardar el cuadrado temporal
    cuadrado=x*x;//asigna valor
    cout<<"El cuadrado de "<<x<<" es "<<cuadrado<<endl;//Escritura del resultdo
    return 0;
}
int main(){
    square(2);//print:El cuadrado de 2 es 4
    square(79);//print:El cuadrado de 79 es 6241
    square(1.24);//print:El cuadrado de 1.24 es 1.5376
    square(72.164);//print:El cuadrado de 72.164 es 5207.64
}
