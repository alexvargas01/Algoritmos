#include <iostream>

using namespace std;

int solve(string s1, string s2, int iSize1, int iSize2)
{
    int arr[iSize1 + 1][iSize2 + 1];
    int i, j;

    for (i = 0; i <= iSize1; i++)
    {
        for (j = 0; j <= iSize2; j++)
        {
            if (i == 0 || j == 0)
            {
                arr[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                arr[i][j] = arr[i - 1][j - 1] + 1;
            }
            else
            {
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
    }
    return arr[iSize1][iSize2];
}

int main()
{
    int cases;
    int i = 1;

    //Read number of cases
    cin >> cases;

    while (cases > 0)
    {
        string s1, s2;

        //Read strings
        cin >> s1;
        cin >> s2;

        //Solve and print test cases
        cout << "case " << i << ": " << solve(s1, s2, s1.length(), s2.length()) << endl;

        i++;
        cases--;
    }

    return 0;
}