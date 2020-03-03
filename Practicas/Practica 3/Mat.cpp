#include <iostream>
using namespace std;

int contar(int matriz[3][3],int x,int y,int n){
    int returnvalue = 0;
    if (matriz[x][y] > 100){
        returnvalue = 1;
    }
    y++;
    if(y==n){
        y=0;
        x++;
    }
    if(x==n){
        return returnvalue;
    }else{
        return contar(matriz,x,y,n)+returnvalue;
    }
}

int contar(int matriz[3][3],int n){
    return contar(matriz,0,0,n);
}


int main(){
    int matriz[3][3] = {{37,22,138},{24,250,277},{500,2,1}};

    int cont = contar(matriz,3);

    cout<<cont<<endl;



}