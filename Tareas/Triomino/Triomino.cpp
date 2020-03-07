#include <iostream>
using namespace std;


void triomino(int ri,int rf,int ci,int cf,int ro,int co,int mat[64][64],int &iCont){
    int rm=(ri+rf)/2;
    int cm=(ci+cf)/2;

    int r1=0,c1=0,r2=0,c2=0,r3=0,c3=0,r4=0,c4=0;

    r1=rm;
    c1=cm;

    r2=rm;
    c2=cm+1;

    r3=rm+1;
    c3=cm;

    r4=rm+1;
    c4=cm+1;

    //arriba Izq
    if (ro<=rm && co<=cm){

        r1=ro;
        c1=co;
        mat[r2][c2] = iCont;
        mat[r3][c3] = iCont;
        mat[r4][c4] = iCont;
        

        
        iCont++;
    }

    //arriba Der
    if (ro<=rm && co>cm){

        r2=ro;
        c2=co;
        mat[r1][c1] = iCont;
        mat[r3][c3] = iCont;
        mat[r4][c4] = iCont;
       
        
        iCont++;
    }

    //abajo Izq
    if (ro>rm && co<=cm){

        r3=ro;
        c3=co;
        mat[r1][c1] = iCont;
        mat[r2][c2] = iCont;
        mat[r4][c4] = iCont;

        
        iCont++;
    }

    //abajo Der
    if (ro>rm && co>cm){

        r4=ro;
        c4=co;
        mat[r1][c1] = iCont;
        mat[r2][c2] = iCont;
        mat[r3][c3] = iCont;
     
        
        iCont++;
    }

    if(ri+1 != rf){
    triomino(ri,rm,ci,cm,r1,c1,mat,iCont);
    triomino(ri,rm,cm+1,cf,r2,c2,mat,iCont);
    triomino(rm+1,rf,ci,cm,r3,c3,mat,iCont);
    triomino(rm+1,rf,cm+1,cf,r4,c4,mat,iCont);
    }
}

int main(){
    int N,ro,co,iCont=1;
    int mat[64][64];
    
    cin>>N;
    cin>>ro>>co;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            mat[i][j] = 0;
        }
    }

    mat[ro][co] = -1;


    triomino(0,N-1,0,N-1,ro,co,mat,iCont);

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }


    return 0;
}