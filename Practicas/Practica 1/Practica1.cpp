#include <iostream>
using namespace std;

/*
int Rango(int inf,int sup){
    int cont=0;
    int arranque = inf + (inf%15==0 ? 0:15-inf%15);
    for (int i=arranque;i<=sup;i+=15){
        cont++;
    }
    return cont;
}
*/

int Rango(int inf,int sup){
    return sup/15 - inf/15+(inf%15 == 0 ? 1:0);
}

int main(){
    int inf,sup,iR=0;
    cin>>inf>>sup;
    iR = Rango(inf,sup);
    cout<<iR<<endl;
}