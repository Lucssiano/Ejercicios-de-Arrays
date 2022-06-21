/* 8- Dado un vector de códigos de productos y un vector paralelo de precios correspondiente a los
productos, se pide:
a) Informar código y precio de todos los productos ordenados de mayor a menor por precio.
b) Dado un código de producto informar su precio. */

#include <iostream>

using namespace std;

void burbujeo(float v[], unsigned t);
int binaria(float v[], unsigned t, int bus);
void inicVector(float v[], int cant);
void ingresoDeDatos(float vP[], float vCod[], int cant);
void productoPorCod(float vP[], float vCod[], int cant);

int main()
{
  const int cantProd = 4;
  float vPrecios[cantProd], vCod[cantProd];

  inicVector(vCod, cantProd);

  ingresoDeDatos(vPrecios, vCod, cantProd);

  cout << "PRODUCTOS: " << endl;
  burbujeo(vPrecios, cantProd);
  for (int i = 0; i < cantProd; i++)
    cout << "El producto " << vCod[i] << " tiene un precio de $" << vPrecios[i] << endl;

  productoPorCod(vPrecios, vCod, cantProd);

  return 0;
}

void inicVector(float v[], int cant)
{
  for (int i = 0; i < cant; i++)
    v[i] = 0;
}

void ingresoDeDatos(float vP[], float vCod[], int cant)
{
  for (int i = 0; i < cant; i++)
  {
    // int codigo, j;
    cout << "Ingrese el codigo del producto: ";
    cin >> vCod[i];

    // for (j = 1; j < cant; j++)
    // {
    //   codigo = vCod[i];
    //   while (vCod[j] == codigo)
    //   {
    //     cout << "Ese codigo de producto ya existe" << endl;
    //     cout << "Ingrese el codigo del producto: ";
    //     cin >> codigo;
    //   }
    // }

    cout << "Ingrese el precio del producto: ";
    cin >> vP[i];
  }
}

void productoPorCod(float vP[], float vCod[], int cant)
{
  int cod;
  cout << "Ingrese un codigo de algun producto para saber su precio: ";
  cin >> cod;

  cout << "El producto de codigo " << cod << " tiene un precio de $" << vP[binaria(vCod, cant, cod)];
}

void burbujeo(float v[], unsigned t)
{
  unsigned i = 1, j;
  int aux;
  bool cambio;
  do
  {
    cambio = false;
    for (j = 0; j < t - i; j++)
    {
      if (v[j] < v[j + 1])
      {
        aux = v[j];
        v[j] = v[j + 1];
        v[j + 1] = aux;
        cambio = true;
      }
    }
    i++;
  } while (i < t && cambio);
}

int binaria(float v[], unsigned t, int bus)
{
  int desde = 0, hasta = t - 1, medio;
  do
  {
    medio = (desde + hasta) / 2;

    if (bus < v[medio])
      hasta = medio - 1;
    else
      desde = medio + 1;

  } while (desde <= hasta && v[medio] != bus);
  if (v[medio] == bus)
    return medio;
  else
    return -1;
}
