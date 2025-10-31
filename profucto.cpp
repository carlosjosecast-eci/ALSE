#include "Producto.h"
#include <iostream>
using namespace std;

Producto::Producto(string nombre, float precio, int stock, int descuento)
    : nombre(nombre), precio(precio), stock(stock), descuento(descuento) {}

void Producto::actualizarPrecio(float nuevoPrecio) {
    precio = nuevoPrecio;
}

void Producto::resumenProducto() const {
    cout << "Nombre: " << nombre
         << " | Precio: $" << precio
         << " | Stock: " << stock
         << " | Descuento: " << descuento << "%" << endl;
}

float Producto::vender(int cantidad) {
    if (cantidad <= stock) {
        stock -= cantidad;
        float precioFinal = precio - (precio * descuento / 100.0);
        return precioFinal * cantidad;
    } else {
        cout << "No hay suficiente stock." << endl;
        return 0.0;
    }
}

void Producto::reabastecer(int cantidad) {
    stock += cantidad;
}

float Producto::consultarValorInventario() const {
    return precio * stock;
}