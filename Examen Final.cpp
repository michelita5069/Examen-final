#include <iostream>
#include <string>
using namespace std;

// Estructuras para manejar la información de los viajeros, ingresos, y salidas
struct Viajero {
    int id;
    string nombre;
    string direccion;
    string nacionalidad;
    string pasaporte;
    string fechaNacimiento;
};

struct Ingreso {
    int idViajero;
    string fechaIngreso;
    string lugarIngreso;
};

struct Salida {
    int idViajero;
    string fechaSalida;
    string lugarSalida;
};

// Declaración de variables globales
const int MAX_VIAJEROS = 100;
Viajero viajeros[MAX_VIAJEROS];
Ingreso ingresos[MAX_VIAJEROS];
Salida salidas[MAX_VIAJEROS];
int numeroViajeros = 0;
int numeroIngresos = 0;
int numeroSalidas = 0;

// Función para agregar un nuevo viajero
void agregarViajero() {
    if (numeroViajeros >= MAX_VIAJEROS) {
        cout << "No se pueden agregar mas viajeros.\n";
        return;
    }
    
    Viajero v;
    cout << "Ingrese ID del viajero: ";
    cin >> v.id;
    cin.ignore();
    cout << "Ingrese nombre del viajero: ";
    getline(cin, v.nombre);
    cout << "Ingrese direccion del viajero: ";
    getline(cin, v.direccion);
    cout << "Ingrese nacionalidad del viajero: ";
    getline(cin, v.nacionalidad);
    cout << "Ingrese numero de pasaporte del viajero: ";
    getline(cin, v.pasaporte);
    cout << "Ingrese fecha de nacimiento del viajero (DD/MM/AAAA): ";
    getline(cin, v.fechaNacimiento);
    viajeros[numeroViajeros++] = v;
    cout << "Viajero agregado exitosamente.\n";
}

// Función para registrar el ingreso de un viajero
void registrarIngreso() {
    if (numeroIngresos >= MAX_VIAJEROS) {
        cout << "No se pueden registrar mas ingresos.\n";
        return;
    }
    
    Ingreso ing;
    cout << "Ingrese ID del viajero: ";
    cin >> ing.idViajero;
    cin.ignore();
    cout << "Ingrese fecha de ingreso (DD/MM/AAAA): ";
    getline(cin, ing.fechaIngreso);
    cout << "Ingrese lugar de ingreso: ";
    getline(cin, ing.lugarIngreso);
    
    ingresos[numeroIngresos++] = ing;
    cout << "Ingreso registrado exitosamente.\n";
}

// Función para registrar la salida de un viajero
void registrarSalida() {
    if (numeroSalidas >= MAX_VIAJEROS) {
        cout << "No se pueden registrar más salidas.\n";
        return;
    }
    
    Salida sal;
    cout << "Ingrese ID del viajero: ";
    cin >> sal.idViajero;
    cin.ignore();
    cout << "Ingrese fecha de salida (DD/MM/AAAA): ";
    getline(cin, sal.fechaSalida);
    cout << "Ingrese lugar de salida: ";
    getline(cin, sal.lugarSalida);
    
    salidas[numeroSalidas++] = sal;
    cout << "Salida registrada exitosamente.\n";
}

// Función para consultar la información de un viajero
void consultarViajero() {
    int id;
    cout << "Ingrese ID del viajero a consultar: ";
    cin >> id;
    
    for (int i = 0; i < numeroViajeros; ++i) {
        if (viajeros[i].id == id) {
            cout << "ID: " << viajeros[i].id << "\nNombre: " << viajeros[i].nombre << "\nDireccion: " << viajeros[i].direccion 
                 << "\nNacionalidad: " << viajeros[i].nacionalidad << "\nPasaporte: " << viajeros[i].pasaporte 
                 << "\nFecha de Nacimiento: " << viajeros[i].fechaNacimiento << "\n";
            return;
        }
    }
    cout << "Viajero no encontrado.\n";
}

// Función para borrar los registros de un viajero
void borrarViajero() {
    int id;
    cout << "Ingrese ID del viajero a borrar: ";
    cin >> id;
    
    for (int i = 0; i < numeroViajeros; ++i) {
        if (viajeros[i].id == id) {
            viajeros[i] = viajeros[--numeroViajeros]; 
            cout << "Viajero borrado exitosamente.\n";
            return;
        }
    }
    cout << "Viajero no encontrado.\n";
}

// Función para generar reportes de todos los viajeros, ingresos y salidas
void generarReportes() {
    cout << "\nReporte de Viajeros:\n";
    for (int i = 0; i < numeroViajeros; ++i) {
        cout << "ID: " << viajeros[i].id << ", Nombre: " << viajeros[i].nombre << ", Direccion: " << viajeros[i].direccion << "\n";
    }
    
    cout << "\nReporte de Ingresos:\n";
    for (int i = 0; i < numeroIngresos; ++i) {
        cout << "ID Viajero: " << ingresos[i].idViajero << ", Fecha Ingreso: " << ingresos[i].fechaIngreso << ", Lugar Ingreso: " << ingresos[i].lugarIngreso << "\n";
    }
    
    cout << "\nReporte de Salidas:\n";
    for (int i = 0; i < numeroSalidas; ++i) {
        cout << "ID Viajero: " << salidas[i].idViajero << ", Fecha Salida: " << salidas[i].fechaSalida << ", Lugar Salida: " << salidas[i].lugarSalida << "\n";
    }
}


void menu() { // Menú principal para interactuar con el sistema
    int opcion;
    do {
        cout << "\nMenu de Sistema de Control de Migracion\n";
        cout << "1. Agregar Viajero\n";
        cout << "2. Registrar Ingreso\n";
        cout << "3. Registrar Salida\n";
        cout << "4. Consultar Viajero\n";
        cout << "5. Generar Reportes\n";
        cout << "6. Borrar Viajero\n";
        cout << "7. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: agregarViajero(); break;
            case 2: registrarIngreso(); break;
            case 3: registrarSalida(); break;
            case 4: consultarViajero(); break;
            case 5: generarReportes(); break;
            case 6: borrarViajero(); break;
            case 7: cout << "Saliendo del sistema...\n"; break;
            default: cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 7);
}

// Función principal
int main() {
    menu();
    return 0;
}

