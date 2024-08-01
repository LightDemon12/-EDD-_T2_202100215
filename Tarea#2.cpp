
#include <iostream> // Para entrada y salida estándar
#include <string> // Para el manejo de cadenas de texto
#include <locale> // Para configurar la consola con UTF-8
#include <limits> // Para el uso de std::numeric_limits
#include <algorithm> // Para transformar cadenas a minúsculas
#include <cstdlib> // Para limpiar la consola


// Definición de la estructura Nodo
struct Nodo {
    std::string nombre;
    std::string apellido;
    int edad;
    std::string direccion;
    std::string carrera;
    std::string materia;
    std::string estado;
    Nodo* siguiente;
};

// Función para agregar un nodo a la lista
void agregarNodo(Nodo*& cabeza, 
const std::string& nombre, 
const std::string& apellido,  
int edad, 
const std::string& direccion, 
const std::string& carrera, 
const std::string& Curso, 
const std::string& estado) {
    // Crear un nuevo nodo
    Nodo* nuevoNodo = new Nodo{nombre, apellido, edad, direccion, carrera, Curso, estado, nullptr};
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    } else {
        // Recorrer la lista para agregar el nuevo nodo al final
        Nodo* temp = cabeza;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

// Función para mostrar la lista
void mostrarLista(Nodo* cabeza) {
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Nombre: " << temp->nombre << " " << temp->apellido << std::endl;
        std::cout << "Edad: " << temp->edad << std::endl;
        std::cout << "Dirección: " << temp->direccion << std::endl;
        std::cout << "Carrera: " << temp->carrera << std::endl;
        std::cout << "Materia: " << temp->materia << std::endl;
        std::cout << "Estado: " << temp->estado << std::endl;
        std::cout << "-----------------------------" << std::endl;
        temp = temp->siguiente;
    }
}



void mostrarDatosEstudiante(Nodo* cabeza) {
    if (cabeza == nullptr) {
        // si la lista está vacía
        std::cout << "No hay estudiantes en la lista.\n";
        return;
    }

    // Mostrar nombres y apellidos de todos los estudiantes
    std::cout << "Lista de estudiantes:\n";
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        // Mostrar el nombre y apellido del estudiante
        std::cout << "Nombre: " << actual->nombre << ", Apellido: " << actual->apellido << "\n";
        actual = actual->siguiente;
    }

    // Solicitar el nombre del estudiante para mostrar sus datos completos
    std::string nombre;
    std::cout << "Ingrese el nombre del estudiante para ver sus datos completos: ";
    std::cin.ignore(); // Ignorar el carácter de nueva línea pendiente
    std::getline(std::cin, nombre);
    // Buscar el estudiante por nombre
    actual = cabeza;
    while (actual != nullptr) {
        if (actual->nombre == nombre) {
            std::cout << "Nombre: " << actual->nombre << "\n";
            std::cout << "Apellido: " << actual->apellido << "\n";
            std::cout << "Edad: " << actual->edad << "\n";
            std::cout << "Dirección: " << actual->direccion << "\n";
            std::cout << "Carrera: " << actual->carrera << "\n";
            std::cout << "Materia: " << actual->materia << "\n";
            std::cout << "Estado: " << actual->estado << "\n";
            return;
        }
        actual = actual->siguiente;
    }

    std::cout << "Estudiante no encontrado.\n";
}
// Función para actualizar los datos de un estudiante
void actualizarDatos(Nodo* cabeza) {
    if (cabeza == nullptr) {
        std::cout << "No hay estudiantes en la lista.\n";
        return;
    }
    //  Mostrar nombres y apellidos de todos los estudiantes
    Nodo* actual = cabeza;
    int index = 1;
    while (actual != nullptr) {
        std::cout << index << ". " << actual->nombre << " " << actual->apellido << "\n";
        actual = actual->siguiente;
        index++;
    }
    // Solicitar el nombre del estudiante a actualizar
    std::string nombre;
    std::cout << "Ingrese el nombre del estudiante a actualizar: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);

    actual = cabeza;
    while (actual != nullptr) {
        if (actual->nombre == nombre) { // Encontrar el estudiante por nombre
            // Mostrar los datos actuales del estudiante
            std::cout << "Actualizando datos para " << actual->nombre << " " << actual->apellido << "\n";
            // Solicitar los nuevos datos
            std::cout << "Ingrese nueva dirección: ";
            std::getline(std::cin, actual->direccion);
            std::cout << "Ingrese nueva carrera: ";
            std::getline(std::cin, actual->carrera);
            std::cout << "Ingrese nueva materia: ";
            std::getline(std::cin, actual->materia);
            std::cout << "Ingrese nuevo estado (activo/inactivo): ";
            std::getline(std::cin, actual->estado);
            // Convertir el estado a minúsculas
            std::transform(actual->estado.begin(), actual->estado.end(), actual->estado.begin(), ::tolower);
            return;
        }
        actual = actual->siguiente;
    }

    std::cout << "Estudiante no encontrado.\n";
}


int main() {
    // Configurar la consola para usar UTF-8
    std::setlocale(LC_ALL, "en_US.UTF-8");

    // Imprimir datos decorados
    std::cout << "*******************************" << std::endl;
    std::cout << "* Angel Guillermo de Jesús    *" << std::endl;
    std::cout << "*       Pérez Jiménez         *" << std::endl;
    std::cout << "*******************************" << std::endl;
    std::cout << "*         202100215           *" << std::endl;
    std::cout << "*******************************" << std::endl;
    std::cout << "*     Estructura de datos     *" << std::endl;
    std::cout << "*          Sección: B         *" << std::endl;
    std::cout << "*           Tarea #2          *" << std::endl;
    std::cout << "*******************************" << std::endl;

    // Crear la lista enlazada
    Nodo* cabeza = nullptr;
    // Menú principal
    char opcion;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Agregar estudiante\n";
        std::cout << "2. Actualizar datos\n";
        std::cout << "3. Mostrar lista de estudiantes\n";
        std::cout << "F. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        // Limpiar el buffer de entrada
        if (opcion == '1') {
            system("cls");
            std::string nombre, apellido, direccion, carrera, materia, estado;
            int edad;
            // Solicitar los datos del estudiante
            std::cout << "Ingrese nombre: ";
            std::cin >> nombre;
            std::cout << "Ingrese apellido: ";
            std::cin >> apellido;
            while (true) {
                std::cout << "Ingrese edad: ";
                std::cin >> edad;
                if (std::cin.fail()) {
                    std::cin.clear(); // limpiar el estado de error
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpiar el buffer de entrada
                    std::cout << "Por favor, ingrese un número válido para la edad.\n";
                } else {
                    break;
                }
            }
            std::cout << "Ingrese dirección: ";
            std::cin.ignore(); // Limpiar el buffer de entrada
            std::getline(std::cin, direccion);
            std::cout << "Ingrese carrera: ";
            std::getline(std::cin, carrera);
            std::cout << "Ingrese materia: ";
            std::getline(std::cin, materia);
            // Solicitar el estado del estudiante
            while (true) {
                std::cout << "Ingrese estado (activo/inactivo): ";
                std::getline(std::cin, estado); // Leer la línea completa
                std::transform(estado.begin(), estado.end(), estado.begin(), ::tolower); // Convertir a minúsculas
                if (estado == "activo" || estado == "inactivo") { // Verificar si el estado es válido
                    break;
                } else {
                    std::cout << "Por favor, ingrese un estado válido (activo/inactivo).\n";
                }
            }
            // Agregar el estudiante a la lista
            agregarNodo(cabeza, nombre, apellido, edad, direccion, carrera, materia, estado);
        } else if (opcion == '2') {
            system("cls");
            actualizarDatos(cabeza);
        } else if (opcion == '3') {
            system("cls");
            mostrarLista(cabeza);
        } else if (opcion == 'F' || opcion == 'f') {
            std::cout << "Saliendo...\n";
        } else {
            std::cout << "Opción no válida.\n";
        }
    // Limpiar el buffer de entrada
    } while (opcion != 'F' && opcion != 'f');
    // Liberar la memoria de los nodos
    return 0;
}