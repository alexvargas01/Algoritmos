#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int iSize;
    int iR=0;

    cin>>iSize;

    int arr[iSize];

    for (int i=0;i<iSize;i++){
        cin>>arr[i];
    }

    int j=1;
    int sup = iSize-1;

    for (int i=0;i<iSize;){

        iR += min(arr[i],arr[sup])*j;

        if (sup == i){
            break;
        }

        if (min(arr[i],arr[sup]) == arr[sup]){
            sup--;
        }else if (min(arr[i],arr[sup]) == arr[i]){
            i++;
        }
        j++;
    }

    cout<<iR<<endl;

    return 0;
}

/*
5
2 1 5 3 4
*/