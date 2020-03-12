/*
  Matricula: A00824525
  Nombre: ALEX JESÚS VARGAS CASTRO
*/

#include <iostream>
#include <vector>

using namespace std;

bool llega(vector<int> &d)
{
    if (d.size() == 1)
    {
        return true;
    }

    int curr = 0;

    for (int i = 0; i < d.size();)
    {
        int salto = d[i];
        curr = i;
        i = i + salto;
        if (d[curr] == 0)
        {
            if (d[curr - 1] >= 2)
            {
                i = d[curr - 1] + curr;
            }
            else if (d[curr - 2] == 3)
            {
                i = d[curr - 2] + curr;
            }
            else
            {
                return false;
                break;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> datos(n);
    for (int i = 0; i < n; i++)
    {
        cin >> datos[i];
    }
    cout << (llega(datos) ? "YES" : "NO") << endl;
}

/*
Ejemplo 1
4
1 2 3 1

Ejemplo 2
5
1 2 0 1 2

Ejemplo 3
5
1 1 0 1 2

*/