#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

int main(){
    vector<int> v,v2;
    int iR=0,iR2=0;

    stack <int> s,s2;

    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);

    v2.push_back(4);
    v2.push_back(3);
    v2.push_back(2);

    reverse(v.begin(),v.end());
    reverse(v2.begin(),v2.end());

    for (int i=0;i<5;i++){
        iR+=v[i];
        s.push(iR);
        iR2+=v2[i];
        s2.push(iR2);    }

    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    while (!s2.empty()){
        cout<<s2.top()<<" ";
        s2.pop();
    }
    cout<<endl;


}