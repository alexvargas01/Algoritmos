#include <iostream>
using namespace std;

int main(){
    int soldiers, balls;

    cin>>soldiers>>balls;

    int soldierSTR[soldiers], ballPWR[balls];

    for (int i=0;i<soldiers;i++){
        cin>>soldierSTR[i];
    }
    for (int i=0;i<balls;i++){
        cin>>ballPWR[i];
    }
    
    return 0;
}