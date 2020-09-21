#include <iostream>

using namespace std;

int main()
{
    int mat[10][10];

    for (int i = 0; i < 10; i++)
    {
        mat[i][i] = i;
        for (int j = i + 1; j < 10; j++)
        {
            mat[j][i] = mat[i][j] = mat[i][j - 1] + j;
        }
    }
}