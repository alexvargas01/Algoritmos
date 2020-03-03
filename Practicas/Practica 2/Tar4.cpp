#include <iostream>
using namespace std;

/*
int sumas(int arr[]){
    int i=0, iR=0;
    if (arr[i]%2 != 0){
        iR = iR + sumas(arr[i]);
    }else{
        i++;
    }
    return iR;
}
*/

int main(){
    int n,iSuma=0;
    cin>>n;
    int arr[n];

    for (int i=0;i<n;i++){
        cin>>arr[i];
    }

    for (int i=0;i<n;i++){
        if (arr[i] % 2 != 0){
            iSuma+=arr[i];
        }
    }

    cout<<iSuma<<endl;
}
