#include <iostream>
using namespace std;

 
int menor(int arr[], int ini, int fin){
    int m = (ini+fin)/2;
    int izq,der;

    if (ini != fin){
        izq = menor(arr,ini,m);
        der = menor(arr,m+1,fin);

        return (izq<der) ? izq:der;
    }

    return arr[fin];
}



int matr(int mat[4][4], int fi, int ff, int ci, int cf){
    int fm = (fi+ff)/2;
    int cm = (ci+cf)/2;

    int c1,c2,c3,c4;

    if (ci != cf){
        c1 = matr(mat, fi, fm, ci,cm);
        c2 = matr(mat,fi,fm,cm+1,cf);
        c3 = matr(mat,fm+1,ff,ci,cm);
        c4 = matr(mat,fm+1,ff,cm+1,cf);

        if (c1 < c2 && c1<c3 && c1<c4){
            return c1;
        }else if (c2<c3 && c2<c4){
            return c2;
        }else if(c3<c4){
            return c3;
        }else{
            return c4;
        }
    }

    return mat[fi][ci];
    
}
 

int main(){

    int arr[8] = {5,78,23,67,45,0,34,23};
    int m[4][4] = {{4, 2, 4567, 4}, {5, -4, 7, 8}, {-9, 10, 11, 12}, {13, -56, 15, -986}};

    //cout<<menor(arr,0,7)<<endl;

    cout<<matr(m,0,3,0,3)<<endl;


    return 0;
}