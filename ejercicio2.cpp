// 2- Hacer un algoritmo que lea 4 números y los muestre en orden inverso

#include <iostream>

using namespace std;

int main()
{
  int i, num[4];

  while (i < 4)
  {
    cout << "Ingrese un numero ";
    cin >> num[i];
    i++;
  }

  for (int j = 3; j >= 0; j--)
  {
    cout << num[j] << " ";
  }

  return 0;
}