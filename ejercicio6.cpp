/* 6- Escriba un programa que permita ingresar la tirada de un par de dados 50 veces y muestre una lista
donde se vea cuántas veces se dio cada uno de los resultados posibles. Por cada tirada se deberán
ingresar 2 valores, cada uno representa el valor de un dado. El formato de la salida debe ser el
siguiente:
2 salió ... veces
3 salió ... veces
.
.
12 salió ... veces */

#include <iostream>

using namespace std;

int main()
{
  int i, dado1, dado2, resultadosPosibles[5], veces;

  while (i < 5)
  {
    cout << "Ingrese el valor de los dados ";
    cin >> dado1 >> dado2;

    resultadosPosibles[i] = dado1 + dado2;

    i++;
  }

  for (int j = 2; j <= 12; j++)
  {
    veces = 0;
    for (int i = 0; i < 5; i++)
    {
      if (resultadosPosibles[i] == j)
        veces++;
    }
    cout << "El valor " << j << " salio " << veces << endl;
  }

  return 0;
}

// Recorre muchas veces el vector, la profe hizo una mejor forma