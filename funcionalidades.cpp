#include <iostream>
#include <fstream>

using namespace std;

// Estructura de datos
struct Nodo
{
    int id;
    string nombre;
    Nodo *izq;
    Nodo *der;
};

// Prototipos
void menu();
void insertar(Nodo *&arbol, int id, string nombre);
void preorden(Nodo *arbol);
void buscar(Nodo *arbol, int id);
void eliminar(Nodo *&arbol, int id);
void guardar(Nodo *arbol, ofstream &archivo);
void cargar(Nodo *&arbol, ifstream &archivo);

// Programa principal
int main()
{
    menu();
    return 0;
}

// Funciones
void menu()
{
    // Variables
    Nodo *arbol = NULL;    
    int opcion;
    string nombre;

    // Archivo
    ifstream archivo;
    string nombreArchivo;

    cout << "Ingrese el nombre del archivo: ";
    cin >> nombreArchivo;
    archivo.open(nombreArchivo.c_str());
    if (archivo.fail())
    {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    // Cargar el arbol
    cargar(arbol, archivo);

    // Menu
    do
    {
        cout << "1. Insertar" << endl;
        cout << "2. Recorrido preorden" << endl;
        cout << "3. Buscar" << endl;
        cout << "4. Eliminar" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            int id;
            cout << "Ingrese el ID: ";
            cin >> id;
            cout << "Ingrese el nombre: ";
            cin >> nombre;
            insertar(arbol, id, nombre);
            break;
        case 2:
            preorden(arbol);
            cout << endl;
            break;
        case 3:
            int id2;
            cout << "Ingrese el ID: ";
            cin >> id2;
            buscar(arbol, id2);
            cout << endl;
            break;
        case 4:
            int id3;
            cout << "Ingrese el ID: ";
            cin >> id3;
            eliminar(arbol, id3);
            cout << endl;
            break;
        case 5:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }
    } while (opcion != 5);
}

void insertar(Nodo *&arbol, int id, string nombre)
{
    if (arbol == NULL)
    {
        arbol = new Nodo;
        arbol->id = id;
        arbol->nombre = nombre;
        arbol->izq = NULL;
        arbol->der = NULL;
    }
    else
    {
        if (id < arbol->id)
        {
            insertar(arbol->izq, id, nombre);
        }
        else
        {
            insertar(arbol->der, id, nombre);
        }
    }
}

void preorden(Nodo *arbol)
{
    if (arbol != NULL)
    {
        cout << arbol->id << " ";
        preorden(arbol->izq);
        preorden(arbol->der);
    }
}

void buscar(Nodo *arbol, int id)
{
    if (arbol != NULL)
    {
        if (arbol->id == id)
        {
            cout << "El ID " << id << " se encuentra en el arbol" << endl;
            cout << "Nombre: " << arbol->nombre << endl;
        }
        else
        {
            if (id < arbol->id)
            {
                buscar(arbol->izq, id);
            }
            else
            {
                buscar(arbol->der, id);
            }
        }
    }
    else
    {
        cout << "El ID " << id << " no se encuentra en el arbol" << endl;
    }
}

void eliminar(Nodo *&arbol, int id)
{
    if (arbol != NULL)
    {
        if (arbol->id == id)
        {
            if (arbol->izq == NULL && arbol->der == NULL)
            {
                delete arbol;
                arbol = NULL;
            }
            else
            {
                if (arbol->izq == NULL)
                {
                    Nodo *aux = arbol;
                    arbol = arbol->der;
                    delete aux;
                }
                else
                {
                    if (arbol->der == NULL)
                    {
                        Nodo *aux = arbol;
                        arbol = arbol->izq;
                        delete aux;
                    }
                    else
                    {
                        Nodo *aux = arbol->der;
                        while (aux->izq != NULL)
                        {
                            aux = aux->izq;
                        }
                        arbol->id = aux->id;
                        arbol->nombre = aux->nombre;
                        eliminar(arbol->der, aux->id);
                    }
                }
            }
        }
        else
        {
            if (id < arbol->id)
            {
                eliminar(arbol->izq, id);
            }
            else
            {
                eliminar(arbol->der, id);
            }
        }
    else
    {
        cout << "El ID " << id3 << " no se encuentra en el arbol" << endl;
    }
    }
}

void guardar(Nodo *arbol, ofstream &archivo)
{
    if (arbol != NULL)
    {
        archivo << arbol->id << "," << arbol->nombre << endl;
        guardar(arbol->izq, archivo);
        guardar(arbol->der, archivo);
    }
}

void cargar(Nodo *&arbol, ifstream &archivo)
{
    string linea;
    getline(archivo, linea);
    if (linea != "")
    {
        string id, nombre;
        int pos = linea.find(",");
        id = linea.substr(0, pos);
        nombre = linea.substr(pos + 1, linea.length());
        insertar(arbol, stoi(id), nombre);
        cargar(arbol, archivo);
    }
}

