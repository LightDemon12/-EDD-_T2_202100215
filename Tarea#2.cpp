#include <iostream>
#include <string>
#include <locale>
#include <limits>
#include <algorithm>
#include <cstdlib>


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
    Nodo* nuevoNodo = new Nodo{nombre, apellido, edad, direccion, carrera, Curso, estado, nullptr};
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    } else {
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
void inicializarEstudiantes(Nodo*& cabeza) {
    Nodo* estudiante1 = new Nodo{"Juan", "Perez", 20, "Calle 123", "Ingeniería", "Matemáticas", "Activo", nullptr};
    Nodo* estudiante2 = new Nodo{"Maria", "Gomez", 22, "Avenida 456", "Medicina", "Biología", "Activo", nullptr};
    Nodo* estudiante3 = new Nodo{"Carlos", "Lopez", 21, "Boulevard 789", "Derecho", "Historia", "Activo", nullptr};

    estudiante1->siguiente = estudiante2;
    estudiante2->siguiente = estudiante3;
    cabeza = estudiante1;
}


void mostrarDatosEstudiante(Nodo* cabeza) {
    if (cabeza == nullptr) {
        std::cout << "No hay estudiantes en la lista.\n";
        return;
    }

    // Mostrar nombres y apellidos de todos los estudiantes
    std::cout << "Lista de estudiantes:\n";
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        std::cout << "Nombre: " << actual->nombre << ", Apellido: " << actual->apellido << "\n";
        actual = actual->siguiente;
    }

    // Solicitar el nombre del estudiante para mostrar sus datos completos
    std::string nombre;
    std::cout << "Ingrese el nombre del estudiante para ver sus datos completos: ";
    std::cin.ignore(); // Ignorar el carácter de nueva línea pendiente
    std::getline(std::cin, nombre);

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

void actualizarDatos(Nodo* cabeza) {
    if (cabeza == nullptr) {
        std::cout << "No hay estudiantes en la lista.\n";
        return;
    }

    Nodo* actual = cabeza;
    int index = 1;
    while (actual != nullptr) {
        std::cout << index << ". " << actual->nombre << " " << actual->apellido << "\n";
        actual = actual->siguiente;
        index++;
    }

    std::string nombre;
    std::cout << "Ingrese el nombre del estudiante a actualizar: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);

    actual = cabeza;
    while (actual != nullptr) {
        if (actual->nombre == nombre) {
            // Aquí puedes agregar el código para actualizar los datos del estudiante
            std::cout << "Actualizando datos para " << actual->nombre << " " << actual->apellido << "\n";
            // Ejemplo de actualización
            std::cout << "Ingrese nueva dirección: ";
            std::getline(std::cin, actual->direccion);
            std::cout << "Ingrese nueva carrera: ";
            std::getline(std::cin, actual->carrera);
            std::cout << "Ingrese nueva materia: ";
            std::getline(std::cin, actual->materia);
            std::cout << "Ingrese nuevo estado (activo/inactivo): ";
            std::getline(std::cin, actual->estado);
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

    char opcion;
    do {
        inicializarEstudiantes(cabeza);
        std::cout << "Menu:\n";
        std::cout << "1. Agregar estudiante\n";
        std::cout << "2. Actualizar datos\n";
        std::cout << "3. Mostrar lista de estudiantes\n";
        std::cout << "F. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        if (opcion == '1') {
            system("cls");
            std::string nombre, apellido, direccion, carrera, materia, estado;
            int edad;

            std::cout << "Ingrese nombre: ";

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

            while (true) {
                std::cout << "Ingrese estado (activo/inactivo): ";
                std::getline(std::cin, estado);
                std::transform(estado.begin(), estado.end(), estado.begin(), ::tolower); // Convertir a minúsculas
                if (estado == "activo" || estado == "inactivo") {
                    break;
                } else {
                    std::cout << "Por favor, ingrese un estado válido (activo/inactivo).\n";
                }
            }

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


    } while (opcion != 'F' && opcion != 'f');

    return 0;
}