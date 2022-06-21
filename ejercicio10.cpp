/* 10- Dados los legajos y sueldos de los empleados de una empresa (máximo 100 empleados), se pide
determinar el/los empleados de máximo sueldo
a) Los números de legajo son números correlativos de 1 a 100
b) Los números de legajo son números no correlativos de 4 cifras.
 */

#include <iostream>

using namespace std;

void inicVec(int v[], int cant);

int main()
{
  const int cantEmple = 100;
  int sueldos[cantEmple], legajos[cantEmple];

  inicVec(sueldos, cantEmple);
  inicVec(legajos, cantEmple);

  return 0;
}

// void ingresoDeDatos(int sueldos[], int leg[],  )

void inicVec(int v[], int cant)
{
  for (int i = 0; i < cant; i++)
    v[i] = 0;
}