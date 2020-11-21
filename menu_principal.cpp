#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<stack>

using namespace std;

struct datos_medicamento {
    string nombremedi, descripcion;
    int cantidad;
    float precio;
};

struct pedido_cliente {
    string nombre_pedido, nombre_medi;
    int cantidad;
    float precio_pedido;
};
///////////////////////PEDIDO DE MEDICNAS/////////////////////////////
typedef struct pedido_cliente detalle_pedido;
vector<detalle_pedido> vpedidos;
queue<string>cpedido;
detalle_pedido pedido;
//////////////////////////////////////////////////////////////////////
///////////////// MEDICAMENTOS///////////////////////////////
typedef struct datos_medicamento medicamento; ////para no escrivir siempre el tipo "struct datos_medicamento" lo hemos nombrado "medicamento"
vector<medicamento> vmedicamentos; //// nombre de tipo VECTOR donde se almacenaran los medicamentos
medicamento datos; ////nombre de la estructura con la que pediremos y llamaremos los datos
///////////////////////////////////////////////////////////////////////////////
stack<float>pganancia; ////guardando el total al despachar
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
    cout << "**********************************************************************************************" << endl;
    for (int i = 0; i < vmedicamentos.size(); i++) {
        cout << "Nombre del medicamento: " << vmedicamentos[i].nombremedi << endl;
        cout << "Cantidad: " << vmedicamentos[i].cantidad << "\t" << "Precio: " << vmedicamentos[i].precio << " $" << endl;
        cout << "Descripcion: " << vmedicamentos[i].descripcion << endl;
        cout << "**********************************************************************************************" << endl;
    }
}
///////////////////////////////EDITANDO(agregando al stock exitente)//////////////////////////////////////////////////////

void agregar_stock() {
    string nombreedit;
    int val = 0;
    cout << "Ingrega nombre del medicamento a agregar: ";
    getline(cin, nombreedit);
    bool encontrado = false;
    for (auto & vmedicamentos2 : vmedicamentos) {
        if (vmedicamentos2.nombremedi == nombreedit) {
            cout << "Nombre: " << vmedicamentos2.nombremedi << endl;
            cout << "Cantidad: " << vmedicamentos2.cantidad << "\t" << "Precio: " << vmedicamentos2.precio << " $" << endl;
            cout << "Escribe cantidad de medicamento: ";
            cin>>val;
            vmedicamentos2.cantidad += val;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "El medicamento no existe";
    }
}

void buscar() {
    string val;
    cout << "Nombre del medicamento: ";
    getline(cin, val);

    for (int i = 0; i < vmedicamentos.size(); i++) {
        if (vmedicamentos[i].nombremedi == val) {
            cout << "**********************************************************************************************" << endl;
            cout << "Nombre del medicamento: " << vmedicamentos[i].nombremedi << endl;
            cout << "Cantidad: " << vmedicamentos[i].cantidad << "\t" << "Precio: " << vmedicamentos[i].precio << " $" << endl;
            cout << "Descripcion: " << vmedicamentos[i].descripcion << endl;
            cout << "**********************************************************************************************" << endl;
            break;
        } else {
            cout << "El medicamento no existe" << endl;
        }
    }
}

void agregar_pedido() {
    ///////////////variables a usar y guardar valores//////////////
    string nom_pedido, nom_medi;
    char decicion;
    int existentes, cant_pedido;
    float precio_prod;
    cout << "Ingrega nombre del cliente: ";
    getline(cin, pedido.nombre_pedido);
    nom_pedido = pedido.nombre_pedido; /////guardamos nombre en una variable
    do {///preguntar si quiere continuar usando "do while"
        ver_medicamentos();
        cout << "Ingresa nombre del medicamento: ";
        getline(cin, nom_medi); ////////////guardamos nombre del medicamento a ingregar en una variable
        bool encontrado = false;
        for (int i = 0; i < vmedicamentos.size(); i++) {//////////////buscamos si existe el medicamento recorriendo todo el vector de medicamentos
            if (vmedicamentos[i].nombremedi == nom_medi) {
                existentes = vmedicamentos[i].cantidad; //// si existe el medicamento, guardamos la cantidad en una variable
                precio_prod = vmedicamentos[i].precio; ////////////guardamos valor en variable
                encontrado = true;
                break;
            }
        }
        if (encontrado) {
            pedido.nombre_medi = nom_medi;
            cout << "Ingresa cantidad a llevar: ";
            cin>>cant_pedido; ////////guardando en una variable la cantidad
            cin.ignore();
            if (existentes >= cant_pedido && cant_pedido > 0) {////validando
                existentes -= cant_pedido; ////operando los valores existentes con los que llevara el cliente
                bool encontrado = false;
                for (auto & vmedicamentos2 : vmedicamentos) {
                    if (vmedicamentos2.nombremedi == nom_medi) {
                        vmedicamentos2.cantidad = existentes; ///guardando en el vector de medicamentos
                        encontrado = true;
                        break;
                    }
                }
                pedido.cantidad = cant_pedido; ///guardando en la structura de cliente
                pedido.precio_pedido = cant_pedido*precio_prod; ///guardando en la structura de cliente
                vpedidos.insert(vpedidos.end(), pedido); ////guardando en el vector
                cout << "Quieres ingresar mas Medicamentos(S/N): ";
                cin>>decicion;
                cin.ignore();
                if (decicion == 'n' || decicion == 'N' || decicion == 'S' || decicion == 's') {///validando
                } else {
                    cout << "Error al ingresar datos" << endl << "Cerrando pedido" << endl;
                    decicion = 'n';
                }
            }
        } else {
            cout << "El medicamento no existe";
        }
    } while (decicion == 's' || decicion == 'S');
    cpedido.push(nom_pedido); //////cola
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    /********FACTURA************/
    float suma = 0;
    cout << "****************************************************************" << endl;
    cout << "Nombre del pedido: " << nom_pedido << endl;
    for (int i = 0; i < vpedidos.size(); i++) {
        if (vpedidos[i].nombre_pedido == nom_pedido) {
            cout << "Medicamento: " << vpedidos[i].nombre_medi << endl;
            cout << "Cantidad: " << vpedidos[i].cantidad << endl;
            //cout<<"total pedido: "<<vpedidos[i].precio_pedido<<endl;
            suma += vpedidos[i].precio_pedido;
        }
    }
    cout << "Total: " << suma << endl;
    cout << "****************************************************************" << endl;
}

void ver_pedidos() {
    queue<string>clon;
    cout << "****************************************************************" << endl;
    for (int i = 0; i = cpedido.size(); i++) {
        clon.push(cpedido.front());
        cout << "*" << cpedido.front() << endl;
        cpedido.pop();
    }
    for (int i = 0; i = clon.size(); i++) {
        cpedido.push(clon.front());
        clon.pop();
    }
    cout << "****************************************************************" << endl;
}

/***************DESPACHANDO cola de clientes*******************************/
void despachar() {
    string despacho;
    float suma;
    despacho = cpedido.front();
     cout << "****************************************************************" << endl;
    cout << "Nombre del pedido: " << despacho << endl;
    for (int i = 0; i < vmedicamentos.size(); i++) {
        if (vpedidos[i].nombre_pedido == despacho) {
            cout << "Medicamento: " << vpedidos[i].nombre_medi << endl;
            cout << "Cantidad: " << vpedidos[i].cantidad << endl;
            suma += vpedidos[i].precio_pedido;
        }
    }
    cout << "****************************************************************" << endl;
    cout << "Total: " << suma << endl;
    cout << "****************************************************************" << endl;
    pganancia.push(suma);
    for (auto iter = vpedidos.begin(); iter != vpedidos.end(); ++iter) {
        if (iter->nombre_pedido == despacho) {
            iter = vpedidos.erase(iter);
            cout << "Despachado Exitosamente.\n";

        }
    }
    cpedido.pop();
}

void ver_ganancias() {
    float suma = 0;
    for(int i=0;i<pganancia.size();i++){
        suma+=pganancia.top();
    }
    cout<<"La ganancia total es: "<<suma<<endl;
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
                ver_pedidos();
                break;
            case 5:
                ver_ganancias();
                break;
            case 6:
                buscar();
                break;
            case 7: cout << "salir" << endl;
                continuar = false;
                break;
            default: cout << "Error al ingresar datos" << endl;
        }

    } while (continuar);
}

/////////////////MENU DE EMPLEADO/////////////////////////

void menu_empleado() {
    int opcion;
    bool continuar = true;
    do {
        cout << "1. Agregar orden" << endl;
        cout << "2. Consultar pedidos" << endl;
        cout << "3. Buscar medicamento" << endl;
        cout << "4. Despachar clientes" << endl;
        cout << "5. Volver" << endl;
        cout << "Opcion: ";
        cin>>opcion;
        cin.ignore();
        switch (opcion) {
            case 1:agregar_pedido();
                break;
            case 2: ver_pedidos();
                break;
            case 3: buscar();
                break;
            case 4:
                despachar();
                break;
            case 5: cout << "salir" << endl;
                continuar = false;
                break;
            default: cout << "Error al ingresar datos" << endl;
        }

    } while (continuar);
}

int main() {
    int opcion;
    bool continuar = true;
    do {
        cout << "1. Menu Administrador" << endl;
        cout << "2. Munu Empleado" << endl;
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

