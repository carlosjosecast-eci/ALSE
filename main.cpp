#include "Producto.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    vector<Producto> productos = {
        Producto("Laptop", 3500.0, 5, 10),
        Producto("Mouse", 150.0, 20, 5),
        Producto("Teclado", 250.0, 10, 0)
    };

    // Simular operaciones
    productos[0].vender(1);
    productos[1].actualizarPrecio(120.0);
    productos[2].reabastecer(5);

    // Mostrar resumen
    cout << "\n--- INVENTARIO FINAL ---\n";
    float totalInventario = 0;
    for (auto &p : productos) {
        p.resumenProducto();
        totalInventario += p.consultarValorInventario();
    }
    cout << "Valor total del inventario: $" << totalInventario << endl;

    // BONO: generar reporte .txt
    ofstream reporte("reporte_inventario.txt");
    for (auto &p : productos) {
        reporte << "Producto: " << p.consultarValorInventario() << endl;
    }
    reporte.close();

    cout << "\nReporte generado en 'reporte_inventario.txt'\n";
    return 0;
}