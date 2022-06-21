/* 5- Dado un conjunto desordenado de valores enteros comprendidos entre 1 y 10, sin repetición, que
finaliza con cero, desarrollar un algoritmo que:
. Imprima un listado ordenado de aquellos valores enteros que se encuentran en el conjunto
. Imprima un listado ordenado de aquellos valores enteros que no se encuentran en el conjunto. */

#include <iostream>

using namespace std;

void cargarVectores(bool v[]);
void inicializarVector(bool v[],int t);
void mostrarListados(bool v[],bool valor,int t);

int main()
{
    const int CANT=10;
    bool vec[CANT];
    inicializarVector(vec,CANT);
    cargarVectores(vec);
    cout<<"Numeros ingresados: " << endl;
    mostrarListados(vec,true,CANT);
    cout << endl;
    cout<<"Numeros no ingresados: " << endl;
    mostrarListados(vec,false,CANT);
    return 0;
}

void inicializarVector(bool v[],int t)
{
    for(int i=0;i<t;i++)
        v[i]=false;
}

void cargarVectores(bool v[])
{
    int nro;
    cout << "Ingrese un numero: ";
    cin>>nro;
    while(nro!=0)
    {
        v[nro-1]=true;
        cout << "Ingrese un numero: ";
        cin>>nro;
    }
}

void mostrarListados(bool v[],bool valor,int t)
{
    for(int i=0;i<t;i++){
        if(v[i]==valor)
            cout<<i+1<< " ";
    }
}

// #include <iostream>

// using namespace std;

// int main()
// {
//   int num, i = 0, array[10], array1[10], array2[10];

//   do
//   {
//     cout << "Ingrese un valor entero comprendido entre 1 y 10: ";
//     cin >> num;
//     if (num != 0)
//     {
//       array[i] = num;
//       i++;
//     }
//   } while (num != 0);

//   for (int j = 0; j < i; j++)
//   {
//     if (array[j] >= 1 && array[j] <= 10)
//     {
//       array1[j] = array[j];
//       cout << "Aquellos valores enteros que se encuentran en el conjunto son: " << array1[j] << endl;
//     }
//     else
//     {
//       array2[j] = array[j];
//       cout << "Aquellos valores enteros que no se encuentran en el conjunto son: " << array2[j] << endl;
//     }
//   }

//   return 0;
// }