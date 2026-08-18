#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_compra_con_descuento() {
    Carrito carrito;
    carrito_init(&carrito);

    Producto pan = {"Pan", 200, 3};
    Producto leche = {"Leche", 350, 2};

    carrito_agregar(&carrito, pan);
    carrito_agregar(&carrito, leche);

    int total = carrito_total(&carrito);
    int precio_con_descuento = carrito_descuento(total, 10);

    ASSERT_IGUAL(total, 1300);
    ASSERT_IGUAL(precio_con_descuento, 1170);
}


/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_agregar_hasta_llenar() {
    Carrito carrito;
    carrito_init(&carrito);

    Producto producto = {"Producto", 100, 1};

    carrito_agregar(&carrito, producto);
    carrito_agregar(&carrito, producto);
    carrito_agregar(&carrito, producto);
    carrito_agregar(&carrito, producto);

    ASSERT_IGUAL(carrito_contar(&carrito), MAX_ITEMS);

    int resultado = carrito_agregar(&carrito, producto);

    ASSERT_IGUAL(resultado, 0);
    ASSERT_IGUAL(carrito_contar(&carrito), MAX_ITEMS);
}


int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
