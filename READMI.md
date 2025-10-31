Proyecto: Gestión de Inventario con Clase Producto

Descripción general

En este trabajo se desarrolló un programa en C++ para manejar un inventario simple usando Programación Orientada a Objetos.
La clase Producto tiene funciones que permiten vender, actualizar precios, reabastecer y calcular el valor total del inventario.
También se genera un reporte en un archivo de texto con el resumen final.

Archivos del proyecto
	•	Producto.h: declaración de la clase y métodos.
	•	Producto.cpp: implementación de la clase.
	•	main.cpp: programa principal que crea los productos y prueba las funciones.

Funcionalidades
	1.	Crear productos con su nombre, precio, cantidad y descuento.
	2.	Vender unidades y disminuir el stock.
	3.	Cambiar precios y reabastecer productos.
	4.	Consultar el valor total del inventario.
	5.	Generar un reporte llamado reporte_inventario.txt.

Ejecución del programa

Compilación:
g++ main.cpp Producto.cpp -o inventario
Ejecución:
./inventario
Salida esperada:
--- INVENTARIO FINAL ---
Nombre: Laptop | Precio: $3500 | Stock: 4 | Descuento: 10%
Nombre: Mouse | Precio: $120 | Stock: 20 | Descuento: 5%
Nombre: Teclado | Precio: $250 | Stock: 15 | Descuento: 0%
Valor total del inventario: $20800
Reporte generado en 'reporte_inventario.txt'
Conceptos aplicados
	•	Clases, objetos y encapsulamiento.
	•	Uso de vectores (std::vector).
	•	Entrada/salida estándar y manejo de archivos.
	•	Programación orientada a objetos en C++.

Resumen

El programa demuestra cómo aplicar los principios de POO en un caso sencillo.
Se usaron clases, vectores y archivos para representar un inventario real.
Es una práctica del curso ALSE sobre Programación Orientada a Objetos en C++.

