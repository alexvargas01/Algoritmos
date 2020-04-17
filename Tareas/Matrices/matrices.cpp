#include <iostream>
#include <climits>

using namespace std;

#define MAX 51

void calcula(int D[MAX][MAX], int P[MAX][MAX], int d[MAX], int n)
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
            int menk=0, aux=0;
            for (int k = i; k < j; k++)
            {
                aux = D[i][k] + D[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (aux < men)
                {
                    men = aux;
                    menk = k;
                }
            }
            D[i][j] = men;
            P[i][j] = menk;
        }
    }
}

void recorre (int P[MAX][MAX], int ini, int fin){
    if (P[ini][fin] != 0){
        cout<<"(";
        recorre(P, ini, P[ini][fin]);
        cout<<")x(";
        recorre(P,P[ini][fin]+1, fin);
        cout<<")";
    }else{
        char ch = 'A'+ini-1;
        cout<<ch;
    }
}

void despliega(int P[MAX][MAX], int n){
    recorre(P, 1, n);
    cout<<endl;
}

int main()
{
    int d[MAX]; // las dimensiones de las matrices

    /*
    A = 20 x 2
    B = 2 x 30
    C = 30 x 12
    D = 12 x 8

    d = 20 2 30 12 8

    4
    20 2 30 12 8
    */

    int D[MAX][MAX], P[MAX][MAX];
    int n; //cantidad de matrices
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> d[i];
    }
    calcula(D, P, d, n);
    cout<<D[1][n]<<endl;
    despliega(P,n);
}