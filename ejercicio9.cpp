/* 9- Dado un vector de notas y un vector de números de documentos paralelo al vector de notas,
informar el dni de los alumnos que tienen la mayor nota y el dni de los alumnos que tienen la menor
nota. */

#include <iostream>

using namespace std;

void burbujeo(float v[], float v2[], unsigned t);
void ingresoDeValores(float vNot[], float vDoc[], int cant);
void mostrarMayorYMenorNota(float vNot[], float vDoc[], int cant);

int main()
{
  int cantAlumnos;

  cout << "Ingrese la cantidad de alumnos del curso: ";
  cin >> cantAlumnos;

  float vNotas[cantAlumnos], vDocumentos[cantAlumnos];

  ingresoDeValores(vNotas, vDocumentos, cantAlumnos);
  burbujeo(vNotas, vDocumentos, cantAlumnos);

  mostrarMayorYMenorNota(vNotas, vDocumentos, cantAlumnos);

  return 0;
}

void ingresoDeValores(float vNot[], float vDoc[], int cant)
{
  for (int i = 0; i < cant; i++)
  {
    cout << "Ingrese la nota del alumno " << i + 1 << ": ";
    cin >> vNot[i];
    cout << "Ingrese el DNI del alumno " << i + 1 << ": ";
    cin >> vDoc[i];
  }
}

void mostrarMayorYMenorNota(float vNot[], float vDoc[], int cant)
{
  for (int i = 0; i < cant; i++)
  {
    if (i == 0)
      cout << "El alumno con la mayor nota es aquel de DNI " << vDoc[i] << " y obtuvo una nota de " << vNot[i] << endl;
    else if (i == cant - 1)
      cout << "El alumno con la menor nota es aquel de DNI " << vDoc[i] << " y obtuvo una nota de " << vNot[i] << endl;
  }
}

void burbujeo(float v[], float v2[], unsigned t)
{
  unsigned i = 1, j;
  int aux, aux2;
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
        aux2 = v2[j];
        v2[j] = v2[j + 1];
        v2[j + 1] = aux2;
        cambio = true;
      }
    }
    i++;
  } while (i < t && cambio);
}