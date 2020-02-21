#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int iNum,one=0,zero=0,iR=0;
    string chain;

    cin>>iNum;
    cin>>chain;

    for(int i=0;i<chain.size();i++){
        (chain[i] == '1') ? one++:zero++;
    }

    iR = one-zero;

    cout<<abs(iR)<<endl;

    return 0;
}