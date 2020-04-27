/*
Alex Jesús Vargas Castro
A00824525
*/

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int casos;
    int n;

    cin >> casos;

    while (casos > 0)
    {
        cin >> n;
        int mat[n][n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j <= i)
                {
                    cin >> mat[i][j];
                }
                else
                {
                    mat[i][j] = 0;
                }
            }
        }

        for (int i = n - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                mat[i - 1][j] = mat[i - 1][j] + max(mat[i][j], mat[i][j + 1]);
            }
        }

        cout << mat[0][0] << endl;

        casos--;
    }
}

/* 
2
3
1
2 1
1 2 3
4
1
1 2
4 1 2
2 3 1 1

5
9
*/