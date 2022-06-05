// 3- Hacer un algoritmo que lea 4 edades de alumnos y muestre por pantalla las edades que superen a la edad promedio.

#include <iostream>

using namespace std;

int main()
{
  int edades[4], edad, i, sumaEdades = 0;
  float edadProm;

  while (i < 4)
  {
    cout << "Ingrese la edad del alumno ";
    cin >> edad;
    edades[i] = edad;
    sumaEdades += edad;
    i++;
  }

  edadProm = sumaEdades / 4;

  for (int j = 0; j < 4; j++)
  {
    if (edades[j] > edadProm)
      cout << "La edad " << edades[j] << " supera a la edad promedio " << edadProm << endl;
  }

  return 0;
}