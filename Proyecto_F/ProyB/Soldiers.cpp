/*
Nombre: Alex Jesús Vargas Castro
Matrícula: A00824525
*/

#include <iostream>
#include <vector>

using namespace std;

void solve(vector<long long int> STR, vector<long long int> PWR)
{
    vector<long long int>::iterator it;

    for (int i = 0; i < PWR.size(); i++)
    {
        it = upper_bound(STR.begin(), STR.end(), PWR[i]);

        int pos = it - STR.begin();

        if (STR.size() - pos == 0)
        {
            cout << STR.size() << endl;
        }
        else
        {
            cout << STR.size() - pos << endl;
        }
    }
}

int main()
{
    int soldiers, balls;

    cin >> soldiers >> balls;

    vector<long long int> soldierSTR(soldiers, 0), ballPWR(balls, 0);
    vector<long long int> STR(soldiers, 0), PWR(balls, 0);

    long long int acumulado1 = 0;
    long long int acumulado2 = 0;

    for (int i = 0; i < soldiers; i++)
    {
        cin >> soldierSTR[i];
        acumulado1 += soldierSTR[i];
        STR[i] = acumulado1;
    }

    for (int i = 0; i < balls; i++)
    {
        cin >> ballPWR[i];
        acumulado2 += ballPWR[i];
        PWR[i] = acumulado2;
        if (acumulado2 > STR[soldiers - 1])
        {
            acumulado2 = 0;
        }
    }

    solve(STR, PWR);

    return 0;
}
/*
5 5
1 2 1 2 1
3 10 1 1 1

3
5
4
4
3
*/