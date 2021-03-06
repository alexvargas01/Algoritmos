#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXOBJ 11
#define MAXMOCH 51

struct obj
{
    int valor, peso;
};

int mochDP(vector<obj> &datos, int N, int PESO)
{
    int mat[MAXOBJ][MAXMOCH];
    for (int i = 0; i <= N; i++)
    {
        mat[i][0] = 0;
    }
    for (int j = 0; j <= PESO; j++)
    {
        mat[0][j] = 0;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= PESO; j++)
        {
            if (datos[i - 1].peso > j)
            {
                //No cabe el objeto i en una mochila de tamaño j
                mat[i][j] = mat[i - 1][j];
            }
            else
            {
                //Ver si me conviene agregar o no el objeto i
                mat[i][j] = max(mat[i - 1][j], datos[i - 1].valor + mat[i - 1][j - datos[i - 1].peso]);
            }
        }
    }
    return mat[N][PESO];
}

int mochDyV(vector<obj> &datos, int N, int PESO)
{
    if (N == 0 || datos[N - 1].peso > PESO)
    {
        return 0;
    }
    return max(mochDyV(datos, N - 1, PESO), datos[N - 1].valor + mochDyV(datos, N - 1, PESO - datos[N - 1].peso));
}

int main()
{
    // N = Cantidad de Objetos
    // PESO = Peso que soporta la Mochila
    int v, p, N, PESO;
    cin >> N >> PESO;
    vector<obj> datos;

    for (int i = 1; i <= N; i++)
    {
        cin >> v >> p;
        obj misDatos;
        misDatos.valor = v;
        misDatos.peso = p;
        datos.push_back(misDatos);
    }
    cout << mochDP(datos, N, PESO) << endl;

    cout << mochDyV(datos, N, PESO) << endl;
}

/* 
4 16
10 5
40 2
50 10
30 5
*/