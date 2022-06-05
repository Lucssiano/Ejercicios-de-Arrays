/* 4) Desarrollar un programa que permita:
- Cargar un vector de 5 valores enteros
- Mostrar por pantalla el contenido del vector
- Obtener el mayor valor entero contenido en el vector y su posición en el mismo
- Obtener el menor valor entero contenido en el vector y su posición en el mismo.
Analizar y describir los cambios necesarios para resolver el mismo problema considerando a lo
sumo 5 valores enteros. */

// No entendí el ultimo item

#include <iostream>

using namespace std;

int main()
{
  int num[5], i, mayor, posicionMayor, menor, posicionMenor;

  while (i < 5)
  {
    cout << "Ingrese un valor entero para agregar al vector: ";
    cin >> num[i];
    i++;
  }

  mayor = num[0];
  menor = num[0];

  for (int j = 0; j < 5; j++)
  {
    cout << "El contenido del vector es: ";
    cout << num[j] << endl;
    if (mayor < num[j])
    {
      mayor = num[j];
      posicionMayor = j;
    }
    if (menor > num[j])
    {
      menor = num[j];
      posicionMenor = j;
    }
  }

  cout << "El mayor valor entero contenido en el vector es: " << mayor << " y se encuentra en la posicion " << posicionMayor << endl;
  cout << "El menor valor entero contenido en el vector es: " << menor << " y se encuentra en la posicion " << posicionMenor << endl;

  return 0;
}