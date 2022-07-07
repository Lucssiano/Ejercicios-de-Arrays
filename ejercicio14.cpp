/* 14- Se tiene un vector de productos (cada elemento tiene código, descripción y stock) y otro vector con
los productos recibidos de los proveedores (código, cantidad recibida), ambos ordenados por código
de producto. Se pide actualizar el stock del vector de productos.*/

#include <iostream>

using namespace std;

struct Producto
{
  int codigo, stock;
  string descripcion;
};

struct ProductoProovedores
{
  int codigo, cantRecibida;
};

void burbujeo(Producto v[], ProductoProovedores v2[], unsigned t);
void cargarVecProd(Producto v[], int t);
void cargarVecProdProveedores(Producto v[], ProductoProovedores v2[], int t);

int main()
{
  const int cantProd = 5;
  Producto productos[cantProd];
  ProductoProovedores productosProovedores[cantProd];

  cargarVecProd(productos, cantProd);
  cargarVecProdProveedores(productos, productosProovedores, cantProd);
  burbujeo(productos, productosProovedores, cantProd);

  cout << "------------------------------------------" << endl;

  for (int i = 0; i < cantProd; i++)
  {
    cout << "Producto " << i + 1 << endl;
    cout << "Codigo: " << productos[i].codigo << endl;
    cout << "Descripcion: " << productos[i].descripcion << endl;
    cout << "Stock: " << productos[i].stock << endl;
    cout << endl;
  }

  cout << "------------------------------------------" << endl;

  for (int i = 0; i < cantProd; i++)
  {
    cout << "Producto proov " << i + 1 << endl;
    cout << "Codigo: " << productosProovedores[i].codigo << endl;
    cout << "Cantidad recibida: " << productosProovedores[i].cantRecibida << endl;
    cout << endl;
  }

  return 0;
}

void cargarVecProd(Producto v[], int t)
{
  for (int i = 0; i < t; i++)
  {
    cout << "Ingrese el codigo del producto " << i + 1 << ": ";
    cin >> v[i].codigo;

    cout << "Ingrese una descripcion del producto " << i + 1 << ": ";
    cin >> v[i].descripcion;

    cout << "Ingrese el stock del producto " << i + 1 << ": ";
    cin >> v[i].stock;
  }
}

void cargarVecProdProveedores(Producto v[], ProductoProovedores v2[], int t)
{
  for (int i = 0; i < t; i++)
  {
    cout << "Ingrese la cantidad recibida del producto " << i + 1 << " por parte del proovedor: "; // asociarlo con el otro vector y poner la cantidad del producto i
    cin >> v2[i].cantRecibida;

    v2[i].codigo = v[i].codigo;
    v[i].stock += v2[i].cantRecibida;
  }
}

void burbujeo(Producto v[], ProductoProovedores v2[], unsigned t)
{
  unsigned i = 1, j;
  int aux, aux2, aux4, aux5;
  string aux3;
  bool cambio;
  do
  {
    cambio = false;
    for (j = 0; j < t - i; j++)
    {
      if (v[j].codigo > v[j + 1].codigo)
      {
        aux = v[j].codigo;
        v[j].codigo = v[j + 1].codigo;
        v[j + 1].codigo = aux;
        aux2 = v[j].stock;
        v[j].stock = v[j + 1].stock;
        v[j + 1].stock = aux2;
        aux3 = v[j].descripcion;
        v[j].descripcion = v[j + 1].descripcion;
        v[j + 1].descripcion = aux3;
        aux4 = v2[j].codigo;
        v2[j].codigo = v2[j + 1].codigo;
        v2[j + 1].codigo = aux;
        aux5 = v2[j].cantRecibida;
        v2[j].cantRecibida = v2[j + 1].cantRecibida;
        v2[j + 1].cantRecibida = aux5;
      }
    }
    i++;
  } while (i < t && cambio);
}