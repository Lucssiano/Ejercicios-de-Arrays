/* 13- Se tiene un vector de notas (cada elemento tiene nombre del alumno y nota obtenida)
correspondientes al primer parcial y otro vector del mismo tipo del anterior con las notas
correspondientes al segundo parcial, ambos vectores están ordenados alfabéticamente por nombre.
Se pide hacer un listado ordenado por nombre con la condición obtenida por el alumno en la
materia, según lo siguiente:
- Primer y segundo parcial con nota mayor o igual a 8: PROMOCIÓN
- Primer y segundo parcial con nota mayor o igual a 6: RINDE FINAL
- Primer o segundo parcial con nota menor a 6: RECURSA */

#include <iostream>

using namespace std;

int main()
{
  int cantAlumnos;

  cout << "Ingrese la cantidad de alumnos del curso: ";
  cin >> cantAlumnos;

  float notas[cantAlumnos];

  return 0;
}