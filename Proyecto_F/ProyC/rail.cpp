/*
Nombre: Alex Jesús Vargas Castro
Matrícula: A00824525
*/

#include <iostream>
#include <string>

using namespace std;

long long int N1, N2, train1[1000], train2[1000], departure[2000];

bool solve(int pos1, int pos2, int i)
{
    if (i == N1 + N2 + 1)
    {
        return true;
    }
    if (train1[pos1] == departure[i] && pos1 <= N1 && solve(pos1 + 1, pos2, i + 1))
    {
        return true;
    }
    if (train2[pos2] == departure[i] && pos2 <= N2 && solve(pos1, pos2 + 1, i + 1))
    {
        return true;
    }
    return false;
}

int main()
{
    bool input = true;

    while (input == true)
    {
        cin >> N1 >> N2;
        if (N1 == 0 && N2 == 0)
        {
            input = false;
        }
        else
        {
            for (int i = 0; i < N1; i++)
            {
                cin >> train1[i];
            }
            for (int i = 0; i < N2; i++)
            {
                cin >> train2[i];
            }
            for (int i = 0 ; i < N1 + N2; i++)
            {
                cin >> departure[i];
            }

            if (solve(0, 0, 1) == true){
                cout<<"possible"<<endl;
            }else{
                cout<<"not possible"<<endl;
            }

            memset(train1, 0, sizeof(train1));
            memset(train2, 0, sizeof(train2));
            memset(departure, 0, sizeof(departure));
        }
    }
    return 0;
}

/*
3 3
1 2 1
2 1 1
1 2 1 1 2 1
3 3
1 2 1
2 1 2
1 1 1 2 2 2
0 0

3 3
1 2 1
2 1 1
1 2 1 1 2 1
3 3
1 2 1
2 1 2
1 1 1 2 2 2
3 3
1 2 1
2 1 1
1 2 1 1 2 1
3 3
1 2 1
2 1 2
1 1 1 2 2 2
0 0
*/