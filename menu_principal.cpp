#include<iostream>
#include<string.h>
#include<vector>
#include<list>
#include<queue>
#include<stack>

using namespace std;

//Prototipo de funciones
void agorden();

struct dato_usuario{
    string nombreusu, nombremed2;
    int cantidad2;
    float precio2;
    float total;
};
typedef dato_usuario usuario;
usuario datos2;

struct datos_medicamento {
    string nombremedi, descripcion;
    int cantidad;
    float precio;
};
///////////////// MEDICAMENTOS///////////////////////////////
typedef struct datos_medicamento medicamento; ////para no escribir siempre el tipo "struct datos_medicamento" lo hemos nombrado "medicamento"
vector<medicamento> vmedicamentos; //// nombre de tipo VECTOR donde se almacenaran los medicamentos
medicamento datos; ////nombre de la estructura con la que pediremos y llamaremos los datos
///////////////////////////////////////////////////////////////////////////////

queue<medicamento>med;

///////////Agregando datos al vector/////////////////////////

void nuevomedicamento() {
    cout << "Ingresa nombre del medicamento:";
    getline(cin, datos.nombremedi);
    cout << "Ingresa cantidad del medicamento: ";
    cin >> datos.cantidad;
    cout << "Ingresa Precio del medicamento (en $): ";
    cin >> datos.precio;
    cin.ignore();
    cout << "Agrega una descripcion del medicamento: ";
    getline(cin, datos.descripcion);
    vmedicamentos.insert(vmedicamentos.end(), datos);
}
/////////////////////////////////////////////////////////////////////////////

//////////// CONSULTANDO vector vmedicamentos/////////////////////////////////////////
void ver_medicamentos() {
    for (int i = 0; i < vmedicamentos.size(); i++) {
        cout << "Nombre del medicamento: " << vmedicamentos[i].nombremedi << endl;
        cout << "Cantidad: " << vmedicamentos[i].cantidad << "\t" << "Precio: " << vmedicamentos[i].precio << " $" << endl;
        cout << "Descripcion: " << vmedicamentos[i].descripcion << endl;
        cout<<"********************************************************************************************"<<endl;
    }
}

void agregar_stock(){
    string nombreedit;
    int val=0;
    cout<<"Ingrega nombre del medicamento a agregar: ";
    getline(cin,nombreedit);
     bool encontrado = false;
    for (auto & vmedicamentos2 : vmedicamentos) {
        if (vmedicamentos2.nombremedi == nombreedit) {
            cout << "Nombre: " << vmedicamentos2.nombremedi << endl;
            cout << "Cantidad: " << vmedicamentos2.cantidad << "\t" << "Precio: " << vmedicamentos2.precio << " $" << endl;
          cout << "Escribe cantidad de medicamento: "; cin>>val;
          vmedicamentos2.cantidad+=val;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "El medicamento no existe";
    }
}

void menu_admin() {
    int opcion;
    bool continuar = true;
    do {
        cout << "1. Agregar nuevo medicamento" << endl; ////agregando nuevo medicamneto
        cout << "2. Agregar al stock" << endl; ////agregamos mas medicamentos
        cout << "3. Ver medicamentos" << endl; ////consultando vector que contiene los medicamentos
        cout << "4. Ver ordenes pendientes" << endl; ////viendo ordenes pendientes
        cout << "5. Ver ganancias" << endl; ////las ordenes ya canceladas sumando todos los totales
        cout << "6. Bucar medicamento" << endl;
        cout << "7. Volver" << endl;
        cout << "Opcion: ";
        cin>>opcion;
        cin.ignore();
        switch (opcion) {
            case 1:
                nuevomedicamento();
                break;
            case 2:
                agregar_stock();
                break;
            case 3:
                ver_medicamentos();
                break;
            case 4:
                break;
            case 5:
                break;
            case 7: cout << "salir" << endl;
                continuar = false;
                break;
            default: cout << "Error al ingresar datos" << endl;
        }

    } while (continuar);

    return;
}

/////////////////MENU DE EMPLEADO/////////////////////////
void menu_empleado(){
 int opcion;
    bool continuar=true;
    do{
        cout<<"\n1. Agregar orden"<<endl;
        cout<<"2. Consultar pedidos"<<endl;
        cout<<"3. Despachar clientes"<<endl;
        cout<<"4. Opcion-> salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        cin.ignore();
        switch(opcion){
            case 1: agorden(); break;
            case 2: cout<<"Eligio opcion 2"<<endl; break;
            case 3: cout<<"Eligio opcion 3"<<endl; break;
            case 4: cout<<"salir"<<endl; continuar=false; break;
            default: cout<<"Error al ingresar datos"<<endl;
        }

    }while(continuar);
}
int main() {
    int opcion;
    bool continuar = true;
    do {
        cout << "1. Menu Administrador" << endl;
        cout << "2. Menu Empleado" << endl;
        cout << "3. Apagar" << endl;
        cout << "Opcion: ";
        cin>>opcion;
        cin.ignore();
        switch (opcion) {
            case 1: menu_admin();
                break;
            case 2: menu_empleado();
                break;
            case 3: cout << "salir" << endl;
                continuar = false;
                break;
            default: cout << "Error al ingresar datos" << endl;
        }
    } while (continuar);
    return 0;
}

void agorden()
{
    int x;
    int cantidadx;
    char opc;
    char opc2[]="s";

    cout<<"Ingrese el nombre del cliente: "; getline(cin,datos2.nombreusu);
    ver_medicamentos(); //Mostrar los medicamentos en el stock;
    cout<<"\Ingrese el medicamemnto a elegir:"; cin>>x;
    cout<<"Ingrese la cantidad:"; cin>> cantidadx;

    for (int i=0;i<vmedicamentos.size();i++)
    {
        if (i=x){
            datos.nombremedi == vmedicamentos[i].nombremedi;
            vmedicamentos[i].cantidad -= cantidadx;
            datos.cantidad == cantidadx;
            datos.precio == vmedicamentos[i].precio;
            med.push(datos);
        }
    }

    cout<<"\nDesea adquirir otro producto?: "; cin>>opc;

    if (strcmp(opc,opc2)==0){
        void agorden();
    }else{
        return;
    }

}
