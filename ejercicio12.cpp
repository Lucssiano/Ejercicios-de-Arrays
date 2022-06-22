// 12- Rehacer el ejercicio 9 con un vector de struct.
/* 9- Dado un vector de notas y un vector de números de documentos paralelo al vector de notas,
informar el dni de los alumnos que tienen la mayor nota y el dni de los alumnos que tienen la menor
nota. */

#include <iostream>

using namespace std;

struct Alumno
{
  int dni;
  float nota;
};

void burbujeo(Alumno v[], unsigned t);
void cargarVector(Alumno v[], int t);
Alumno ingresarAlum(int nroAlum);
void mostrarMayorYMenorNota(Alumno v[], int cant);

int main()
{
  int cantAlumnos;

  cout << "Ingrese la cantidad de alumnos del curso: ";
  cin >> cantAlumnos;

  Alumno vecAlumnos[cantAlumnos];

  cargarVector(vecAlumnos, cantAlumnos);
  burbujeo(vecAlumnos, cantAlumnos);
  mostrarMayorYMenorNota(vecAlumnos, cantAlumnos);

  // for (int i = 0; i < cantAlumnos; i++)
  //   cout << "alumno dni " << vecAlumnos[i].dni << " alumno nota " << vecAlumnos[i].nota << endl;

  return 0;
}

void cargarVector(Alumno v[], int t)
{
  for (int i = 0; i < t; i++)
    v[i] = ingresarAlum(i + 1);
}

Alumno ingresarAlum(int nroAlum)
{
  Alumno alum;
  cout << "Ingrese la nota del alumno " << nroAlum << ": ";
  cin >> alum.nota;
  cout << "Ingrese el dni del alumno " << nroAlum << ": ";
  cin >> alum.dni;
  return alum;
}

void mostrarMayorYMenorNota(Alumno v[], int cant)
{
  int j = 0;
  int k = cant - 1;
  while (v[0].nota == v[j].nota)
  {
    cout << "El alumno con la mayor nota es aquel de DNI " << v[j].dni << " y obtuvo una nota de " << v[j].nota << endl;
    j++;
  }
  while (v[cant - 1].nota == v[k].nota)
  {
    cout << "El alumno con la menor nota es aquel de DNI " << v[k].dni << " y obtuvo una nota de " << v[k].nota << endl;
    k--;
  }
}

void burbujeo(Alumno v[], unsigned t)
{
  unsigned i = 1, j;
  int aux, aux2;
  bool cambio;
  do
  {
    cambio = false;
    for (j = 0; j < t - i; j++)
    {
      if (v[j].nota < v[j + 1].nota)
      {
        aux = v[j].nota;
        v[j].nota = v[j + 1].nota;
        v[j + 1].nota = aux;
        aux2 = v[j].dni;
        v[j].dni = v[j + 1].dni;
        v[j + 1].dni = aux2;
      }
    }
    i++;
  } while (i < t && cambio);
}