#include <iostream>
#include <string>
using namespace std;

int main(){

    string arr;
    int size;

    cin>>arr;
    size= arr.size();

    for (int i=0;i<size;){
        if (arr[i] != arr[i+1]){
            cout<<arr[i]<<endl;
            break;
        }else{
            i+=2;
        }
    }
    return 0;
}