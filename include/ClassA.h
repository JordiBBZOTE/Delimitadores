#ifndef CLASSA_H
#define CLASSA_H
#include <cstdlib>

using namespace std;

class ClassA
{
    private:
        string cadena;
        int entero;
        int arreglo[4];
    public:
        ClassA();
        ClassA(string lectura);
        ClassA(int entero, string cadena, int arreglo[4]);
        void setCad(string cad);
        void setEntero(int key);
        void setArreglo(int arreglo[]);
        int getEntero();
        string getCadena();
        string tostring();
        string toFile();

};

#endif // CLASSA_H
