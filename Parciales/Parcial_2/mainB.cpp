#include <iostream>
#include <algorithm>
// Robot
// Matricula: A00824525
// Nombre: Alex Jesús Vargas Castro

using namespace std;
#define MAX 100

int robot(int mat[MAX][MAX], int n, int m)
{
    int iR = mat[0][0] + mat[n - 1][m - 1];
    int col = 0;

    for (int i = 0; i < n;)
    {
        iR += min(mat[i][col + 1], mat[i + 1][col]);
        if (mat[i][col + 1] < mat[i + 1][col])
        {
            if (col == m - 1)
            {
                i++;
            }
            else
            {
                col++;
            }
        }
        else
        {
            i++;
        }
    }

    return iR;
}

void print(int mat[MAX][MAX], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    int mat[MAX][MAX];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    //	print(mat, n, m);
    cout << robot(mat, n, m) << endl;
}

/*
5 4
2  2 15  1
5  1 15  1
5  3 10  1
5  2  1  1
8 13  2 15

Resp 27
*/