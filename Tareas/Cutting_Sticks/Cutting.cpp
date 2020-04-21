/* 
Alex Vargas 
A00824525
*/

#include <iostream>
#include <climits>

using namespace std;

#define MAX 51

void cortar(int D[MAX][MAX], int d[MAX], int n)
{
    for (int i = 1; i <= n; i++)
    {
        D[i][i] = 0;
    }
    for (int diag = 1; diag <= n - 1; diag++)
    {
        for (int i = 1; i <= n - diag; i++)
        {
            int j = i + diag;
            int men = INT_MAX;
            int menk = 0, aux = 0;
            for (int k = i; k < j; k++)
            {
                aux = D[i][k] + D[k + 1][j] + d[j] - d[i - 1];
                if (aux < men)
                {
                    men = aux;
                    menk = k;
                }
            }
            D[i][j] = men;
        }
    }
}

int main()
{
    int d[MAX];
    int D[MAX][MAX], P[MAX][MAX];
    int n, iSize;
    bool check = true;

    d[0] = 0;

    while (check != false)
    {
        cin >> iSize;
        if (iSize == 0)
        {
            check = false;
        }
        else
        {
            cin >> n;
            int i;
            for (i = 1; i <= n; i++)
            {
                cin >> d[i];
            }
            d[i] = iSize;
            cortar(D, d, n+1);
            cout << "The minimum cutting is " <<  D[1][n+1]<<"." << endl;
        }
    }
}

/* 
100
3
25 50 75
10
4
4 5 7 8
0
*/