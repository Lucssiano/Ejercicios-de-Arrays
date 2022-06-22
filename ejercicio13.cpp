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

struct Alumno
{
  string nombre;
  float notaPrimerP, notaSegundoP;
};

Alumno ingresarAlum(int nroAlum, string p, string nomAlum);
void cargarVector(Alumno v[], Alumno v2[], int t);
void listadoOrdenado(Alumno v[], Alumno v2[], int t);
void burbujeo(Alumno v[], unsigned t);

int main()
{
  int cantAlumnos;

  cout << "Ingrese la cantidad de alumnos del curso: ";
  cin >> cantAlumnos;

  Alumno alumPrimerP[cantAlumnos], alumSegundoP[cantAlumnos], listado[cantAlumnos];
  cargarVector(alumPrimerP, alumSegundoP, cantAlumnos);
  burbujeo(alumPrimerP, cantAlumnos);
  burbujeo(alumSegundoP, cantAlumnos);
  listadoOrdenado(alumPrimerP, alumSegundoP, cantAlumnos);

  return 0;
}

void cargarVector(Alumno v[], Alumno v2[], int t)
{
  for (int i = 0; i < t; i++)
  {
    string nombreAlum;
    cout << "Ingrese el nombre del alumno " << i + 1 << ": ";
    cin >> nombreAlum;
    v[i] = ingresarAlum(i + 1, "primer parcial", nombreAlum);
    v2[i] = ingresarAlum(i + 1, "segundo parcial", nombreAlum);
  }
}

Alumno ingresarAlum(int nroAlum, string p, string nomAlum)
{
  Alumno alum;
  alum.nombre = nomAlum;
  if (p == "primer parcial")
  {
    cout << "Ingrese la nota del primer parcial del alumno " << nroAlum << ": ";
    cin >> alum.notaPrimerP;
  }
  else if (p == "segundo parcial")
  {
    cout << "Ingrese la nota del segundo parcial del alumno " << nroAlum << ": ";
    cin >> alum.notaSegundoP;
  }
  return alum;
}

void listadoOrdenado(Alumno v[], Alumno v2[], int t)
{
  for (int i = 0; i < t; i++)
  {
    if (v[i].notaPrimerP >= 8 && v2[i].notaSegundoP >= 8)
      cout << "El alumno " << v[i].nombre << " promociona con una nota de " << v[i].notaPrimerP << " en el primer parcial, y una nota de " << v2[i].notaSegundoP << " en el segundo parcial" << endl;
    else if (v[i].notaPrimerP >= 6 && v2[i].notaSegundoP >= 6)
      cout << "El alumno " << v[i].nombre << " rinde final con una nota de " << v[i].notaPrimerP << " en el primer parcial, y una nota de " << v2[i].notaSegundoP << " en el segundo parcial" << endl;
    else if (v[i].notaPrimerP < 6 || v2[i].notaSegundoP < 6)
      cout << "El alumno " << v[i].nombre << " recursa con una nota de " << v[i].notaPrimerP << " en el primer parcial, y una nota de " << v2[i].notaSegundoP << " en el segundo parcial" << endl;
  }
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

void burbujeo(Alumno v[], unsigned t)
{
  unsigned i = 1, j;
  string aux;
  bool cambio;
  do
  {
    cambio = false;
    for (j = 0; j < t - i; j++)
    {
      if (v[j].nombre > v[j + 1].nombre)
      {
        aux = v[j].nombre;
        v[j].nombre = v[j + 1].nombre;
        v[j + 1].nombre = aux;
        cambio = true;
      }
    }
    i++;
  } while (i < t && cambio);
}