#include <iostream>
#include <string>
using namespace std;

struct Libro {
    string titulo;
    string autor;
    int anio;
    bool disponible;
};

int main() {
    const int MAX_LIBROS = 100;
    Libro biblioteca[MAX_LIBROS];
    int totalLibros = 0;
    int opcion;

    do {
        cout << "\n===== MENU BIBLIOTECA =====\n";
        cout << "1. Agregar libro\n";
        cout << "2. Mostrar libros\n";
        cout << "3. Buscar libro por titulo\n";
        cout << "4. Marcar libro como prestado\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                if (totalLibros < MAX_LIBROS) {
                    cout << "\nIngrese el titulo: ";
                    getline(cin, biblioteca[totalLibros].titulo);
                    cout << "Ingrese el autor: ";
                    getline(cin, biblioteca[totalLibros].autor);
                    cout << "Ingrese el anio: ";
                    cin >> biblioteca[totalLibros].anio;
                    biblioteca[totalLibros].disponible = true;
                    totalLibros++;
                    cout << "Libro agregado con exito.\n";
                } else {
                    cout << "No hay espacio para mas libros.\n";
                }
                break;
            }
            case 2: {
                cout << "\nListado de libros:\n";
                for (int i = 0; i < totalLibros; i++) {
                    cout << i + 1 << ". " << biblioteca[i].titulo
                         << " - " << biblioteca[i].autor
                         << " (" << biblioteca[i].anio << ")";
                    if (biblioteca[i].disponible)
                        cout << " [Disponible]\n";
                    else
                        cout << " [Prestado]\n";
                }
                if (totalLibros == 0) cout << "No hay libros registrados.\n";
                break;
            }
            case 3: {
                string buscar;
                cout << "\nIngrese el titulo a buscar: ";
                getline(cin, buscar);
                bool encontrado = false;
                for (int i = 0; i < totalLibros; i++) {
                    if (biblioteca[i].titulo == buscar) {
                        cout << "Libro encontrado: " << biblioteca[i].titulo
                             << " - " << biblioteca[i].autor
                             << " (" << biblioteca[i].anio << ")";
                        if (biblioteca[i].disponible)
                            cout << " [Disponible]\n";
                        else
                            cout << " [Prestado]\n";
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) cout << "No se encontro el libro.\n";
                break;
            }
            case 4: {
                string prestar;
                cout << "\nIngrese el titulo del libro a marcar como prestado: ";
                getline(cin, prestar);
                bool encontrado = false;
                for (int i = 0; i < totalLibros; i++) {
                    if (biblioteca[i].titulo == prestar) {
                        biblioteca[i].disponible = false;
                        cout << "Libro marcado como prestado.\n";
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) cout << "No se encontro el libro.\n";
                break;
            }
            case 5:
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opcion no valida.\n";
        }
    } while (opcion != 5);

    return 0;
}
