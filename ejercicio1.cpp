// 1- Hacer un algoritmo que lea 3 notas las cargue un vector y luego muestre la nota máxima

#include <iostream>

using namespace std;

int main()
{
  int i, nota[3], notaMax = 0;

  while (i < 3)
  {
    cout << "Ingrese una nota ";
    cin >> nota[i];
    if (notaMax < nota[i])
      notaMax = nota[i];
    i++;
  }

  cout << "La nota maxima es: " << notaMax;

  return 0;
}