#include <iostream>

using namespace std;

/* 
int Bsearch(int arr[], int l, int r, int x)
{

    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] > x)
        {
            return Bsearch(arr, l, mid - l, x);
        }else{
            return Bsearch(arr,mid+l,r,x);
        }
    }

    return -1;
}
 */

int main()
{

    int m[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int arr[16];
    int x,fila;

    cin>> x;
    /* 
    for (int q = 0; q < 4; q++)
    {
        for (int t = 0; t < 4; t++)
        {
            arr[q * 4 + t] = m[q][t];
        }
    }
    

    for (int i=0;i<16;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cin>>x;

    cout<<Bsearch(arr,0,15,x)<<endl;

     */

    for (int i=0;i<4;i++){
        if (x>=m[i][0] && x<=m[i][3]){
            fila=i;
        }
    }

    for (int i=0;i<4;i++){
        if (x == m[fila][i]){
            cout<<"Encontrado en: "<<fila<<" "<<i<<endl;
        }
    }

    
}