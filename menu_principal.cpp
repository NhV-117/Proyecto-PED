#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct datos_medicamento {
    string nombremedi, descripcion;
    int cantidad;
    float precio;
};

//ORDENAMIENTO//

bool compNombre(datos_medicamento a, datos_medicamento b) {
    return a.nombremedi < b.nombremedi;
};

struct pedido_cliente {
    string nombre_pedido, nombre_medi;
    int cantidad;
    float precio_pedido;
};
//PEDIDO DE MEDICINAS//
typedef struct pedido_cliente detalle_pedido;
vector<detalle_pedido> vpedidos;
queue<string>cpedido;
detalle_pedido pedido;
list <detalle_pedido> lhistorial;
//usando para ver consultar los pedidos//

// MEDICAMENTOS//
typedef struct datos_medicamento medicamento; ////para no escrivir siempre el tipo "struct datos_medicamento" lo hemos nombrado "medicamento"
vector<medicamento> vmedicamentos; //// nombre de tipo VECTOR donde se almacenaran los medicamentos
medicamento datos; ////nombre de la estructura con la que pediremos y llamaremos los datos//
stack<float>pganancia; ////guardando el total al despachar
///////////Agregando datos al vector/////////////////////////

//PROTOTIPO DE FUNCIONES//
void eliminar_med();

bool medi_validacion(string nombre) {
    bool encontrado = true;
    for (int i = 0; i < vmedicamentos.size(); i++) {
        if (vmedicamentos[i].nombremedi == nombre) {
            encontrado = false;
            break;
        }
    }

    if (encontrado) {
        return encontrado;
    } else {
        return encontrado;
    }
}
//AGREGAR NUEVO MEDICAMENTO//

void nuevomedicamento() {
    cin.ignore();
    string nom;
    bool existe, eldato = false;
    bool eldato2 = false;

    while (!eldato) {
        cout << "Ingrese nombre del medicamento: ";
        getline(cin, datos.nombremedi);

        for (int i = 0; i < datos.nombremedi.length(); i++) {
            datos.nombremedi[i] = toupper(datos.nombremedi[i]);
        }

        if (datos.nombremedi.empty()) {
            cout << "Por favor ingrese un dato" << endl;
        } else {
            eldato = true;
        }
    }

    do {
        cout << "Ingrese cantidad del medicamento: ";
        while (!(cin >> datos.cantidad)) {
            cout << "¡Ingrese una cantidad por favor: ";
            cin.clear();
            cin.ignore(132, '\n');
        };
    } while (datos.cantidad <= 0);
    cin.ignore();

    do {
        cout << "Ingrese Precio del medicamento: $ ";
        while (!(cin >> datos.precio)) {
            cout << "Ingrese una cantidad por favor: ";
            cin.clear();
            cin.ignore(132, '\n');
        };
    } while (datos.precio <= 0);

    cin.ignore();
    while (!eldato2) {
        cout << "Agrega una descripcion del medicamento: ";
        getline(cin, datos.descripcion);

        if (datos.descripcion.empty()) {
            cout << "Por favor ingrese un dato" << endl;
        } else {
            eldato2 = true;
        }

    }

    nom = datos.nombremedi;
    existe = medi_validacion(nom);
    if (existe == true) {
        vmedicamentos.insert(vmedicamentos.end(), datos);
        system("clear");
    } else {
        system("clear");
        cout << "El medicamento ya existe" << endl;
    }

}

//AGREGAR MEDICAMENTOS AL STOCK//

void agregar_stock() {
    cin.ignore();
    string nombreedit;
    int val = 0;
    bool eldato3 = false;

    while (!eldato3) {
        cout << "\nNombre del medicamento a agregar: ";
        getline(cin, nombreedit);

        if (nombreedit.empty()) {
            cout << "Por favor ingrese un dato" << endl;
        } else {
            eldato3 = true;
        }

    }

    for (int i = 0; i < nombreedit.length(); i++) {
        nombreedit[i] = toupper(nombreedit[i]);
    }

    bool encontrado = false;
    for (auto & vmedicamentos2 : vmedicamentos) {
        if (vmedicamentos2.nombremedi == nombreedit) {
            cout << "Nombre: " << vmedicamentos2.nombremedi << endl;
            cout << "Cantidad: " << vmedicamentos2.cantidad << "\t" << endl;
            cout << "Precio: $ " << vmedicamentos2.precio << endl;
            do {
                cout << "Cantidad a agregar: ";
                while (!(cin >> val)) {
                    cout << "¡Error:Ingrese un dato valido: ";
                    cin.clear();
                    cin.ignore(132, '\n');
                };

            } while (val <= 0);

            vmedicamentos2.cantidad += val;
            encontrado = true;
            cout << "Medicamento agregado al stock" << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "¡El medicamento no existe!" << endl;
    }
}

//VER MEDICAMENTOS DISPONIBLES//

void ver_medicamentos() {
    cout << "     *** INICIO DE LISTA ***" << endl << endl;
    cout << "********************************" << endl;
    sort(vmedicamentos.begin(), vmedicamentos.end(), compNombre);

    for (int i = 0; i < vmedicamentos.size(); i++) {
        cout << "Nombre del medicamento: " << vmedicamentos[i].nombremedi << endl;
        cout << "Cantidad: " << vmedicamentos[i].cantidad << "\t" << endl;
        cout << "Precio: $ " << vmedicamentos[i].precio << endl;
        cout << "Descripcion: " << vmedicamentos[i].descripcion << "\n" << endl;
        cout << "********************************" << endl;
    }

    cout << "      *** FIN DE LISTA ***" << endl << endl;

}

//VER COLA DE PEDIDOS//

void ver_pedidos() {
    queue<string>clon;
    cout << "*******************************" << endl;
    for (int i = 0; i = cpedido.size(); i++) {
        clon.push(cpedido.front());
        cout << "*" << cpedido.front() << endl;
        cpedido.pop();
    }

    for (int i = 0; i = clon.size(); i++) {
        cpedido.push(clon.front());
        clon.pop();
    }
    cout << "*******************************" << endl << endl;
}

//VER GANANCIAS OBTENIDAS//

void ver_ganancias() {
    float suma = 0;
    stack<float>clon;
    for (int i = 0; i = pganancia.size(); i++) {
        suma += pganancia.top();
        clon.push(pganancia.top());
        pganancia.pop();
    }
    cout << "*******************************" << endl;
    cout << "La ganancia total es: $ " << suma << endl;
    cout << "*******************************" << endl << endl;
    for (int i = 0; i < clon.size(); i++) {
        pganancia.push(clon.top());
        clon.pop();
    }
}

//BUSCAR MEDICAMENTOS EN STOCK//

void buscar() {
    cin.ignore();
    string val;
    bool existe = false;
    bool eldato4 = false;

    while (!eldato4) {
        cout << "Nombre del medicamento: ";
        getline(cin, val);

        if (val.empty()) {
            cout << "Por favor ingrese un dato" << endl;
        } else {
            eldato4 = true;
        }

    }

    for (int i = 0; i < val.length(); i++) {
        val[i] = toupper(val[i]);
    }

    for (int i = 0; i < vmedicamentos.size(); i++) {
        if (vmedicamentos[i].nombremedi == val) {
            cout << "*******************************" << endl;
            cout << "Nombre del medicamento: " << vmedicamentos[i].nombremedi << endl;
            cout << "Cantidad: " << vmedicamentos[i].cantidad << "\t" << endl;
            cout << "Precio: $ " << vmedicamentos[i].precio << endl;
            cout << "Descripcion: " << vmedicamentos[i].descripcion << endl;
            cout << "*******************************" << endl;
            existe = true;
            break;
        }

    }
    if (existe == false) {
        cout << "El medicamento no existe!" << endl;
    }
}

bool id_pedido(string nombre) {
    bool encontrado = true;
    for (int i = 0; i < vpedidos.size(); i++) {
        if (vpedidos[i].nombre_pedido == nombre) {
            encontrado = false;
            break;
        }
    }

    if (encontrado) {
        return encontrado;
    } else {
        return encontrado;
    }
}

//HISTORIAL DE VENTAS REALIZADAS//

void historial_ventas() {
    cout << "*******************************" << endl;
    for (struct pedido_cliente i : lhistorial) {
        cout << "Nombre del pedido: " << i.nombre_pedido << endl;
        cout << "Medicamento: " << i.nombre_medi << " Cantidad: " << i.cantidad << endl;
    }
    cout << "*******************************" << endl;
    char letra;

    cout << "Desea limpiar historial?(S/N) ";
    cin>>letra;

    if (letra == 's' || letra == 'S') {
        lhistorial.clear();
    } else if (letra == 'n' || letra == 'N') {
    } else {
        cout << "¡Error al ingresar datos!" << endl << endl;
    }
}

//ELIMINAR MEDICAMENTO//

void eliminar_med() {
    cin.ignore();
    string borrar;
    bool eldato5 = false;

    while (!eldato5) {
        cout << "Digite el medicamento a eliminar: ";
        getline(cin, borrar);

        if (borrar.empty()) {
            cout << "Por favor ingrese un dato" << endl;
        } else {
            eldato5 = true;
        }
    }

    for (int i = 0; i < borrar.length(); i++) {
        borrar[i] = toupper(borrar[i]);
    }

    for (auto iter = vmedicamentos.begin(); iter != vmedicamentos.end(); ++iter) {
        if (iter->nombremedi == borrar) {
            system("clear");
            iter = vmedicamentos.erase(iter);
            cout << "*******************************" << endl;
            cout << "Elemento eliminado exitosamente!" << endl;
            cout << "*******************************" << endl;
            break;
        } else {
            cout << "¡El medicamento no existe!" << endl << endl;
        }
    }
}

//REALIZAR PEDIDO//

void agregar_pedido() {
    ///////////////variables a usar y guardar valores//////////////
    string nom_pedido, nom_medi;
    char decicion;
    bool eldato6 = false;
    bool id;
    int existentes, cant_pedido;
    float precio_prod;

    while (!eldato6) {
        cout << "Ingrese nombre del cliente: ";
        getline(cin, pedido.nombre_pedido);

        if (pedido.nombre_pedido.empty()) {
            cout << "Por favor ingrese un dato" << endl;
        } else {
            eldato6 = true;
        }

    }

    for (int i = 0; i < pedido.nombre_pedido.length(); i++) {
        pedido.nombre_pedido[i] = toupper(pedido.nombre_pedido[i]);
    }

    nom_pedido = pedido.nombre_pedido; //guardamos nombre en una variable
    id = id_pedido(nom_pedido);
    if (id == true) {
        do ///preguntar si quiere continuar usando "do while"
        {
            ver_medicamentos();
            cout << "Ingrese nombre del medicamento: ";
            getline(cin, nom_medi); //guardamos nombre del medicamento a ingregar en una variable

            for (int i = 0; i < nom_medi.length(); i++) {
                nom_medi[i] = toupper(nom_medi[i]);
            }

            bool encontrado = false;
            for (int i = 0; i < vmedicamentos.size(); i++) //buscamos si existe el medicamento recorriendo todo el vector de medicamentos
            {
                if (vmedicamentos[i].nombremedi == nom_medi) {
                    existentes = vmedicamentos[i].cantidad; // si existe el medicamento, guardamos la cantidad en una variable
                    precio_prod = vmedicamentos[i].precio; //guardamos valor en variable
                    encontrado = true;
                    break;
                }
            }

            if (encontrado) {
                pedido.nombre_medi = nom_medi;
                do {
                    cout << "Ingresa cantidad a llevar: ";
                    while (!(cin >> cant_pedido)) //guardando en una variable la cantidad
                    {
                        cout << "¡Error, ingrese un dato valido!" << endl;
                        cin.clear();
                        cin.ignore(132, '\n');
                    }
                } while (cant_pedido <= 0);
                cin.ignore();

                if (existentes >= cant_pedido && cant_pedido > 0) //validando
                {
                    existentes -= cant_pedido; //operando los valores existentes con los que llevara el cliente
                    bool encontrado = false;
                    for (auto & vmedicamentos2 : vmedicamentos) {
                        if (vmedicamentos2.nombremedi == nom_medi) {
                            vmedicamentos2.cantidad = existentes; //guardando en el vector de medicamentos
                            encontrado = true;
                            break;
                        }
                    }
                    pedido.cantidad = cant_pedido; //guardando en la structura de cliente
                    pedido.precio_pedido = cant_pedido*precio_prod; //guardando en la structura de cliente
                    vpedidos.insert(vpedidos.begin(), pedido); //guardando en el vector
                    cout << "Quieres ingresar mas Medicamentos(S/N): ";
                    cin>>decicion;
                    cin.ignore();

                    if (decicion == 'n' || decicion == 'N' || decicion == 'S' || decicion == 's') //validando
                    {
                    } else {
                        cout << "¡Error al ingresar datos!" << endl << "¡Cerrando pedido!" << endl;
                        decicion = 'n';
                    }
                }
            } else {
                cout << "\n¡El medicamento no existe!";
            }
        } while (decicion == 's' || decicion == 'S');
        cpedido.push(nom_pedido); //cola

        system("clear");

        //FACTURA CLIENTE//
        float suma = 0;
        cout << "\n*******************************" << endl;
        cout << "Nombre del pedido: " << nom_pedido << endl;
        for (int i = 0; i < vpedidos.size(); i++) {
            if (vpedidos[i].nombre_pedido == nom_pedido) {
                cout << "Medicamento: " << vpedidos[i].nombre_medi << endl;
                cout << "Cantidad: " << vpedidos[i].cantidad << endl;
                //cout<<"total pedido: "<<vpedidos[i].precio_pedido<<endl;
                suma += vpedidos[i].precio_pedido;
            }
        }
        cout << "Total: $" << suma << endl;
        cout << "*******************************" << endl;
    } else {
        cout << "¡El cliente ya existe, ingresa otro nombre!" << endl;
    }
}


//DESPACHAR CLIENTE//

void despachar() {
     string despacho;
    float suma = 0, solo_uno = 0;
    despacho = cpedido.front();
    cout << "\n*******************************" << endl;
    cout << "Nombre del pedido: " << despacho << endl;
    for (int i = 0; i < vpedidos.size(); i++) {
        if (vpedidos[i].nombre_pedido == despacho) {
            cout << "Medicamento: " << vpedidos[i].nombre_medi << endl;
            cout << "Cantidad: " << vpedidos[i].cantidad << endl;
            suma += vpedidos[i].precio_pedido;
            lhistorial.insert(lhistorial.end(), vpedidos[i]);
            solo_uno++;
        }
    }
    pganancia.push(suma);
    cout << "*******************************" << endl;
    cout << "Total: " << suma << endl;
    cout << "*******************************" << endl;

    for (int i = 0; i < solo_uno; i++) {
        vpedidos.erase(vpedidos.end() - 1);
    }

    cout << "Despachado Exitosamente.\n" << endl;
    cpedido.pop();
}


//MENU DE ADMINISTRADOR//

void menu_admin() {
    int opcion;
    bool continuar = true;
    do {
        cout << "      .: ADMINISTRADOR :." << endl;
        cout << "1. Agregar nuevo medicamento" << endl;
        cout << "2. Agregar al stock" << endl;
        cout << "3. Ver medicamentos" << endl;
        cout << "4. Ver cola de pedidos" << endl;
        cout << "5. Ver ganancias" << endl;
        cout << "6. Bucar medicamento" << endl;
        cout << "7. Historial de ventas" << endl;
        cout << "8. Eliminar medicamento" << endl;
        cout << "9. Volver" << endl;
        cout << "Opcion: ";

        while (!(cin >> opcion)) {
            cout << "Error:Ingrese un caracter valido: ";
            cin.clear();
            cin.ignore(132, '\n');
        };

        switch (opcion) {
            case 1:
                system("clear");
                nuevomedicamento();
                break;
            case 2:
                system("clear");
                agregar_stock();
                break;
            case 3:
                system("clear");
                ver_medicamentos();
                break;
            case 4:
                system("clear");
                ver_pedidos();
                break;
            case 5:
                system("clear");
                ver_ganancias();
                break;
            case 6:
                system("clear");
                buscar();
                break;
            case 7:
                system("clear");
                historial_ventas();
                break;
            case 8:
                system("clear");
                eliminar_med();
                break;
            case 9:
                continuar = false;
                system("clear");
                break;
            default: cout << "¡Error al ingresar datos!" << endl;
        }

    } while (continuar);
}

//MENU DE EMPLEADO//

void menu_empleado() {
    int opcion;
    bool continuar = true;
    do {
        cout << "     .: EMPLEADO :." << endl;
        cout << "1. Agregar orden" << endl;
        cout << "2. Consultar pedidos" << endl;
        cout << "3. Buscar medicamento" << endl;
        cout << "4. Despachar cliente" << endl;
        cout << "5. Volver" << endl;
        cout << "Opcion: ";

        while(!(cin>>opcion)){
            cout<<"Error: ingrese un caracter valido: ";
            cin.clear();
            cin.ignore(132,'\n');
        }

        switch (opcion) {
            case 1:
                system("clear");
                agregar_pedido();
                break;
            case 2:
                system("clear");
                ver_pedidos();
                break;
            case 3:
                system("clear");
                buscar();
                break;
            case 4:
                system("clear");
                despachar();
                break;
            case 5:
                continuar = false;
                break;
            default: cout << "\n¡Error al ingresar datos!" << endl << endl;
        }

    } while (continuar);

    system("clear");
}

//MENU PRINCIPAL//

int main() {
    int opcion;
    bool continuar = true;
    do {
        cout << "      .: INICIO :." << endl;
        cout << "1. Menu Administrador" << endl;
        cout << "2. Menu Empleado" << endl;
        cout << "3. Apagar" << endl;
        cout << "Opcion: ";

        while (!(cin >> opcion)) {
            cout << "Error:Ingrese un caracter valido: ";
            cin.clear();
            cin.ignore(132, '\n');
        };

        switch (opcion) {
            case 1:
                system("clear");
                menu_admin();
                break;
            case 2:
                system("clear");
                menu_empleado();
                break;
            case 3:
                cout << "\nAPAGANDO..." << endl;
                continuar = false;
                break;
            default: cout << "¡Error al ingresar datos!" << endl;
        }

    } while (continuar);
    return 0;
}
