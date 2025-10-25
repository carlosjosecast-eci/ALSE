#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
protected:
    string marca;
    string modelo;
    string placa;
    bool disponible;

public:
    Vehiculo(string m, string mod, string p)
        : marca(m), modelo(mod), placa(p), disponible(true) {}

    virtual void mostrarInformacion() {
        cout << "Marca: " << marca << " | Modelo: " << modelo << " | Placa: " << placa;
        cout << (disponible ? " [Disponible]" : " [Alquilado]") << endl;
    }

    bool estaDisponible() { return disponible; }
    void alquilar() { disponible = false; }
    void devolver() { disponible = true; }
    string getPlaca() { return placa; }
    virtual ~Vehiculo() {}
};

class Auto : public Vehiculo {
private:
    int capacidadPasajeros;

public:
    Auto(string m, string mod, string p, int cap)
        : Vehiculo(m, mod, p), capacidadPasajeros(cap) {}

    void mostrarInformacion() override {
        cout << "[AUTO] ";
        Vehiculo::mostrarInformacion();
        cout << "Capacidad: " << capacidadPasajeros << " pasajeros\n";
    }
};

class Bicicleta : public Vehiculo {
private:
    string tipo;

public:
    Bicicleta(string m, string mod, string p, string t)
        : Vehiculo(m, mod, p), tipo(t) {}

    void mostrarInformacion() override {
        cout << "[BICICLETA] ";
        Vehiculo::mostrarInformacion();
        cout << "Tipo: " << tipo << endl;
    }
};

class SistemaAlquiler {
private:
    Vehiculo* vehiculos[50];
    int totalVehiculos;

public:
    SistemaAlquiler() { totalVehiculos = 0; }

    void registrarVehiculo(Vehiculo* v) {
        if (totalVehiculos < 50) {
            vehiculos[totalVehiculos++] = v;
            cout << "Vehiculo registrado correctamente.\n";
        } else {
            cout << "No se pueden registrar más vehículos.\n";
        }
    }

    void mostrarDisponibles() {
        cout << "\n--- Vehículos disponibles ---\n";
        for (int i = 0; i < totalVehiculos; i++) {
            if (vehiculos[i]->estaDisponible())
                vehiculos[i]->mostrarInformacion();
        }
    }

    void alquilarVehiculo(string placa) {
        for (int i = 0; i < totalVehiculos; i++) {
            if (vehiculos[i]->getPlaca() == placa) {
                if (vehiculos[i]->estaDisponible()) {
                    vehiculos[i]->alquilar();
                    cout << "Vehículo alquilado con éxito.\n";
                } else {
                    cout << "El vehículo ya está alquilado.\n";
                }
                return;
            }
        }
        cout << "No se encontró un vehículo con esa placa.\n";
    }

    void devolverVehiculo(string placa) {
        for (int i = 0; i < totalVehiculos; i++) {
            if (vehiculos[i]->getPlaca() == placa) {
                if (!vehiculos[i]->estaDisponible()) {
                    vehiculos[i]->devolver();
                    cout << "Vehículo devuelto correctamente.\n";
                } else {
                    cout << "El vehículo ya estaba disponible.\n";
                }
                return;
            }
        }
        cout << "No se encontró un vehículo con esa placa.\n";
    }
};

int main() {
    SistemaAlquiler sistema;
    int opcion;

    do {
        cout << "\n===== MENU ALQUILER DE VEHICULOS =====\n";
        cout << "1. Registrar vehículo\n";
        cout << "2. Mostrar vehículos disponibles\n";
        cout << "3. Alquilar vehículo\n";
        cout << "4. Devolver vehículo\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                int tipo;
                cout << "1. Auto\n2. Bicicleta\nSeleccione tipo: ";
                cin >> tipo;
                cin.ignore();
                string marca, modelo, placa;
                cout << "Marca: "; getline(cin, marca);
                cout << "Modelo: "; getline(cin, modelo);
                cout << "Placa: "; getline(cin, placa);

                if (tipo == 1) {
                    int capacidad;
                    cout << "Capacidad de pasajeros: ";
                    cin >> capacidad;
                    cin.ignore();
                    sistema.registrarVehiculo(new Auto(marca, modelo, placa, capacidad));
                } else {
                    string tipoBici;
                    cout << "Tipo de bicicleta (montaña, ruta, etc.): ";
                    getline(cin, tipoBici);
                    sistema.registrarVehiculo(new Bicicleta(marca, modelo, placa, tipoBici));
                }
                break;
            }
            case 2:
                sistema.mostrarDisponibles();
                break;
            case 3: {
                string placa;
                cout << "Ingrese la placa del vehículo a alquilar: ";
                getline(cin, placa);
                sistema.alquilarVehiculo(placa);
                break;
            }
            case 4: {
                string placa;
                cout << "Ingrese la placa del vehículo a devolver: ";
                getline(cin, placa);
                sistema.devolverVehiculo(placa);
                break;
            }
            case 5:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opción no válida.\n";
        }
    } while (opcion != 5);

    return 0;
}
