#include <iostream>
#include<sstream>
#include<cstdlib>
#include "ClassA.h"
#include<fstream>
#define N 100

using namespace std;

//FUNCIONES DEL MENU
void agregar();
void Modifica();
void Elimina();

//FUNCIONES SECUNDARIAS
void insertaFinal();
void insertaInicio();
bool valida(int key);
void MuestraTodo();

int main()
{
    int opc;
    do
    {
        system("cls");
        cout<<"\n\tMenu Principal DELIMITADORES"<<endl;
        cout<<"\n\t1.- Agregar: "<<endl;
        cout<<"\t2.- Eliminar: "<<endl;
        cout<<"\t3.- Modificar: "<<endl;
        cout<<"\t4.- Mostrar Todos los Registros: "<<endl;
        cout<<"\t5.- Salir: "<<endl<<endl;
        cout<<"\tTeclee una opcion desde el teclado:\t";
        cin>>opc;

        switch(opc)
        {
        case 1:
            agregar();
            break;
        case 2:
            Elimina();
            break;
        case 3:
            Modifica();
            break;
        case 4:
            MuestraTodo();
            break;
        case 5:
            system("cls");
            cout<<"\n\n\t\tFin del programa"<<endl;
            break;
        case 6:
        {
            int a = 4;
            valida(a);
        }
        default:
            cout<<"\tSeleccione una opcion valida"<<endl;
            system("Pause");
            break;
        }
    }
    while(opc != 5);

    return 0;
}
void agregar()
{
    system("cls");
    int rpt;
    cout<<"\n\tQUE METODO DESEAS UTILIZAR?: "<<endl;
    cout<<"\t1. Insertar Al Final: "<<endl;
    cout<<"\t2. Insertar Al Inicio: "<<endl;
    cout<<"\t3. Regresar: "<<endl;
    cout<<"\tSeleccione una opcion: \t";
    cin>>rpt;
    switch(rpt)
    {
    case 1:
        insertaFinal();
        break;
    case 2:
        insertaInicio();
        break;
    case 3:
        break;
    default:
        cout<<"\tSeleccione una opcion valida"<<endl;
        system("pause");
    }
}
void insertaFinal()
{
    int key;
    string cad,ss;

    cout<<"\t\nINSERTA AL FINAL"<<endl<<endl;
    cout<<"\tIngrese la llave primaria: ";
    cin>>key;
    cout<<"\n\tIngrese la cadena: ";
    cin.ignore();
    getline(cin, cad);

    ClassA obj;

    if(valida(key)==true)
    {
        cout<<"EL ENTERO YA EXISTENTE"<<endl<<endl;
        system("pause");
        return;
    }

    obj.setEntero(key);
    obj.setCad(cad);

    ofstream archivo;
    archivo.open("Archivo.txt", ios::app);

    archivo<<obj.toFile()<<endl;

    archivo.close();
}
void insertaInicio()
{
    int key;
    string cad, respaldo;

    cout<<"\t\nINSERTA AL INICIO"<<endl<<endl;
    cout<<"\tIngrese la llave primaria: ";
    cin>>key;
    cout<<"\n\tIngrese la cadena: ";
    cin.ignore();
    getline(cin, cad);

    ClassA obj;

    if(valida(key)==true)
    {
        cout<<"ENTERO YA EXISTENTE"<<endl<<endl;
        system("pause");
        return;
    }
    obj.setEntero(key);
    obj.setCad(cad);

    ofstream aux;
    aux.open("auxiliar.txt",ios::app);

    aux<<obj.toFile()<<endl;

    ifstream archivo;
    archivo.open("Archivo.txt", ios::app);

    while(!archivo.eof())
    {
        getline(archivo, respaldo);
        aux<<respaldo;
        if(!archivo.eof())
            aux<<'\n';
    }

    aux.close();
    archivo.close();

    remove("Archivo.txt");
    rename("auxiliar.txt","Archivo.txt");
}
void Modifica()
{
    string cadena;
    int nuevoentero;
    string nuevacadena;

    ifstream fin;
    ofstream fout;
    fin.open("Archivo.txt",ios::app);
    fin >> cadena;

    int key;

    system("cls");
    cout<<"\n\tMODIFICAR"<<endl<<endl;
    cout<<"\tIngrese la llave primaria: ";
    cin>>key;

    if(valida(key)!=true)
    {
        cout<<"NO SE ENCONTRO LA LLAVE"<<endl<<endl;
        system("pause");
        return;
    }
    fout.open("auxiliar.txt",ios::out);
    while(!fin.eof())
    {
        ClassA obj(cadena);
        if (obj.getEntero()!=key)
        {
            fout<<obj.toFile()<<endl;
            //fin >> cadena;
        }

        else
        {
            int opc;
            system("cls");
            cout<<"\n\tMODIFICA"<<endl<<endl;
            cout<<"1.- Modificar Entero: "<<endl;
            cout<<"2.- Modificar Cadena: "<<endl;
            cin>>opc;
            if(opc>2)
                opc = 2;
            else if(opc<1)
                opc = 1;

            if(opc==1)
            {
                cout<<"Ingrese el nuevo entero: ";
                cin>>nuevoentero;
                if(valida(nuevoentero)==true)
                {
                    cout<<"EL ENTERO YA EXISTENTE"<<endl<<endl;
                    system("pause");
                    return;
                }
                else
                {
                    obj.setEntero(nuevoentero);
                    fout<<obj.toFile()<<endl;

                }
            }
            else if(opc==2)
            {
                cout<<"Ingrese la nueva cadena: ";
                cin>>nuevacadena;

                obj.setCad(nuevacadena);
                fout<<obj.toFile()<<endl;

            }
        }
        fin >> cadena;
    }

    fin.close();
    fout.close();

    remove("Archivo.txt");
    rename("auxiliar.txt","Archivo.txt");
    system("pause");
}
void Elimina()
{
    int key;
    string cadena;
    ifstream fin;
    ofstream fout;
    fin.open("Archivo.txt",ios::app);
    fout.open("auxiliar.txt", ios::app);
    fin >> cadena;

    system("cls");
    cout<<"\tELIMINAR"<<endl<<endl;
    cout<<"\tIngrese la llave primaria: ";
    cin>>key;

    while(!fin.eof())
    {
        ClassA obj(cadena);
        if (obj.getEntero()!=key)
        {
            fout<<obj.toFile()<<endl;
            fin >> cadena;
        }

        else
        {
            cout<<"EL ELEMENTO "<<obj.tostring()<<" SE ELIMINO"<<endl;
            fin >> cadena;
        }
    }
    system("pause");

    fin.close();
    fout.close();

    remove("Archivo.txt");
    rename("auxiliar.txt","Archivo.txt");
}
bool valida(int key)
{
    string cadena;
    ifstream fin;

    fin.open("Archivo.txt");
    fin >> cadena;

    while(!fin.eof())
    {
        ClassA obj(cadena);
        if (obj.getEntero()==key)
        {
            fin.close();
            return true;
        }
        else
            fin >> cadena;
    }
    fin.close();
    return false;
}
void MuestraTodo()
{
    int i = 0;
    string cadena;
    ClassA lista[N];
    ifstream fin;
    fin.open("Archivo.txt", ios::app);
    fin >> cadena;
    system("cls");
    cout<<"\n\tREGISTROS ARCHIVO.TXT\n\n";
    while(!fin.eof())
    {
        ClassA obj(cadena);
        lista[i++] = obj;
        fin >> cadena;
    }
    for(int j = 0; j < i; j++)
        cout<<lista[j].tostring()<<endl;
    fin.close();
    system("pause");
}


