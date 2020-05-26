/*
Nombre: Alex Jesús Vargas Castro
Matrícula: A00824525
*/

#include <iostream>
#include <iomanip>

using namespace std;

double median(double arr[], int n)
{
    if (n % 2 == 0)
        return (arr[n / 2] + arr[n / 2 - 1]) / 2;
    else
        return arr[n / 2];
}

double solve(double a[], double b[], int n)
{
    if (n <= 0)
    {
        return -1;
    }

    if (n == 1)
    {
        return (a[0] + b[0]) / 2;
    }

    if (n == 2)
    {
        return (max(a[0], b[0]) + min(a[1], b[1])) / 2;
    }

    int m1 = median(a, n);
    int m2 = median(b, n);

    if (m1 == m2)
    {
        return m1;
    }

    if (m1 < m2)
    {
        if (n % 2 == 0)
        {
            return solve(a + n / 2 - 1, b, n - n / 2 + 1);
        }
        else
        {
            return solve(a + n / 2, b, n - n / 2);
        }
    }

    if (m1 > m2)
    {
        if (n % 2 == 0)
        {
            return solve(b + n / 2 - 1, a, n - n / 2 + 1);
        }
        else
        {
            return solve(b + n / 2, a, n - n / 2);
        }
    }

    return 0;
}

int main()
{
    int cases;
    int i = 1;

    // Read number of cases
    cin >> cases;

    //Read Arrays
    while (cases > 0)
    {
        int iSize = 0;

        cin >> iSize;

        double a[iSize], b[iSize];

        for (int i = 0; i < iSize; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < iSize; i++)
        {
            cin >> b[i];
        }

        //Solve problem
        cout << "Median case " << i << ": " << fixed << setprecision(2) << solve(a, b, iSize) << endl;

        //End cycle
        cases--;
        i++;
    }

    return 0;
}

/*
2
5
1
4
7
8
10
2
9
11
14
15
3
3
4
5
1
2
6 
*/