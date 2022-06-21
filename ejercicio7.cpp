/* 7-  Dado un número N (<20), y dos vectores A y B de N elementos que contenga valores entre 0..9
que representan números naturales muy largos
a) genere e informe un tercer vector SUMA de N+1 elementos que sea el resultante de la suma de
los dos números.
b) genere e informe un tercer vector RESTA de N elementos que sea el resultante de la resta de
los dos números */

#include <iostream>

using namespace std;

void cargarVectores(int v[], int cant);
void resta(int vA[], int vB[], int cant, int resta[]);
void suma(int vA[], int vB[], int cant, int suma[]);

int main()
{
    int N;

    do
    {
        cout << "Ingrese un numero mayor a 1 y menor a 20 ";
        cin >> N;
    } while (N <= 1 && N > 20);

    int A[N], B[N], SUMA[N + 1], RESTA[N];

    cout << "Valores del vector A" << endl;
    cargarVectores(A, N);
    cout << "Valores del vector B" << endl;
    cargarVectores(B, N);

    cout << "Vector resta" << endl;
    resta(A, B, N, RESTA);

    cout << "Vector suma" << endl;
    suma(A, B, N + 1, SUMA);

    return 0;
}

void cargarVectores(int v[], int cant)
{
    int nro, i = 0;
    do
    {
        cout << "Ingrese el valor " << i + 1 << " del vector: ";
        cin >> nro;
        v[i] = nro;
        i++;
    } while (i <= cant - 1);
}

void resta(int vA[], int vB[], int cant, int resta[])
{

    for (int i = 0; i < cant; i++)
        resta[i] = vA[i] - vB[i];

    for (int i = cant - 1; i >= 0; i--)
    {
        if (resta[i] < 0)
        {
            resta[i] = resta[i] + 10;
            if (i != 0)
                resta[i - 1] = resta[i - 1] - 1;
        }
        cout << resta[i] << " resta " << i + 1 << endl;
    }
}

void suma(int vA[], int vB[], int cant, int suma[])
{
    int i = cant - 2;
    int j = cant - 1;
    for (j; j >= 0; j--)
    {
        if (i != -1)
            suma[j] = vA[i] + vB[i];
        else
            suma[j] = 0;
        i--;
    }
    for (int k = cant - 1; k >= 0; k--)
    {
        if (suma[k] >= 10)
        {
            suma[k] = suma[k] - 10;
            if (k != 0)
                suma[k - 1] = suma[k - 1] + 1;
        }
        cout << suma[k] << " suma[k]" << endl;
    }
}

/* #include <iostream>
using namespace std;
void iniVec(int v[], int nro, int a);
void suma(int v1[], int v2[],int vSum[], int nro);
void resta(int v[],int v2[],int vRes[], int nro);
void iniCeros(int v[], int nro);
void imprimir (int v[],int);
int main()
{
    int nro,v1[10],v2[10];
    cout<<"Ingrese la cantidad de numeros que tienen sus vectores: "<<endl;
    cin>>nro;

    int vSuma[nro+1];
    int vResta[nro];

    iniVec(v1,nro,1);
    iniVec(v2,nro,2);
    iniCeros(vSuma,nro);

    suma(v1,v2,vSuma,nro);
    resta(v1,v2,vResta,nro);

    cout<<"|Vector Suma|"<<endl;
    imprimir(vSuma,nro+1);

    cout<<""<<endl;

    cout<<"|Vector Resta|"<<endl;
    imprimir(vResta,nro);

    return 0;
}
void iniVec(int v[], int nro, int a)
{
    for (int i = 0; i < nro; i++)
    {
        cout<<"Ingrese la "<<i+1<<" cifra de su "<<a<<" vector: "<<endl;
        cin>>v[i];
    }
}
void suma(int v1[], int v2[],int vSum[], int nro)
{
    int j=nro;
    int i=nro-1;
    for (i; i>=0; i--)
    {
        vSum[j]=v1[i]+v2[i];
        j--;
    }
    for (j=nro; j>=0; j--)
    {
        if (vSum[j]>=10)
        {
            vSum[j]=vSum[j]-10;
            vSum[j-1]=vSum[j-1]+1;
        }
    }
}

void resta(int v1[], int v2[],int vRes[], int nro)
{
    int resta;
    for (int i = nro; i>=0; i--)
    {
        vRes[i]=v1[i]-v2[i];
    }
    for (int i = nro-1; i>=0; i--)
    {
        if (vRes[i]<0)
        {
            vRes[i]=vRes[i]+10;
            vRes[i-1]=vRes[i-1]-1;
        }
    }
}
void iniCeros(int v[], int nro)
{
    for (int i = 0; i <nro ; i++)
    {
        v[i]=0;
    }

}
void imprimir (int v[],int a)
{
    for (int i = 0; i < a; i++)
    {
        cout<<"|"<<v[i]<<"|";
    }

} */