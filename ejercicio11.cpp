// 11- Rehacer el ejercicio 8 con un vector de struct.
/* 8- Dado un vector de códigos de productos y un vector paralelo de precios correspondiente a los
productos, se pide:
a) Informar código y precio de todos los productos ordenados de mayor a menor por precio.
b) Dado un código de producto informar su precio. */

#include <iostream>

using namespace std;

struct Producto
{
  int codigo;
  float precio;
};

void burbujeo(Producto v[], unsigned t);
int binaria(Producto v[], unsigned t, int bus);
Producto ingresarProd();
void cargarVector(Producto v[], int t);
Producto productoPorCod(Producto vP[], int cant);

int main()
{
  const int TAMAÑO = 4;

  Producto vecProductos[TAMAÑO];
  cargarVector(vecProductos, TAMAÑO);
  burbujeo(vecProductos, TAMAÑO);

  for (int i = 0; i < TAMAÑO; i++)
    cout << "El producto " << vecProductos[i].codigo << " tiene un precio de $" << vecProductos[i].precio << endl;

  productoPorCod(vecProductos, TAMAÑO);

  return 0;
}

void cargarVector(Producto v[], int t)
{
  for (int i = 0; i < t; i++)
    v[i] = ingresarProd();
}

Producto ingresarProd()
{
  Producto prod;
  cout << "Ingrese el codigo del producto: ";
  cin >> prod.codigo;
  cout << "Ingrese el precio del producto: ";
  cin >> prod.precio;
  return prod;
}

Producto productoPorCod(Producto vP[], int cant)
{
  Producto prod;
  cout << "Ingrese un codigo de algun producto para saber su precio: ";
  cin >> prod.codigo;

  cout << "El producto de codigo " << prod.codigo << " tiene un precio de $" << vP[binaria(vP, cant, prod.codigo)].precio;
}

void burbujeo(Producto v[], unsigned t)
{
  unsigned i = 1, j;
  int aux, aux2;
  bool cambio;
  do
  {
    cambio = false;
    for (j = 0; j < t - i; j++)
    {
      if (v[j].precio < v[j + 1].precio)
      {
        aux = v[j].precio;
        v[j].precio = v[j + 1].precio;
        v[j + 1].precio = aux;
        aux2 = v[j].codigo;
        v[j].codigo = v[j + 1].codigo;
        v[j + 1].codigo = aux2;
        cambio = true;
      }
    }
    i++;
  } while (i < t && cambio);
}

int binaria(Producto v[], unsigned t, int bus)
{
  int desde = 0, hasta = t - 1, medio;
  do
  {
    medio = (desde + hasta) / 2;

    if (bus < v[medio].codigo)
      hasta = medio - 1;
    else
      desde = medio + 1;

  } while (desde <= hasta && v[medio].codigo != bus);
  if (v[medio].codigo == bus)
    return medio;
  else
    return -1;
}