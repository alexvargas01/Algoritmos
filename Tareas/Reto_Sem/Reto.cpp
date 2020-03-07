#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool acomodar(pair<int, int> p1, pair<int, int> p2){
    if (p1.second < p2.second){
        return true;
    }
    return false;
}

int convertir(int iNum){
    int aux=0,iR=0;

    while(iNum != 0) {
        aux = iNum % 10;
        iNum /= 10;
        iR += aux;
    }
    return iR;
}



int main(){

    int OmpaNum, drinkNum;

    //Leer Datos
    cin>>OmpaNum>>drinkNum;

    int OmpaLompas[OmpaNum];
    int Drinks[drinkNum];

    for (int i=0;i<OmpaNum;i++){
        cin>>OmpaLompas[i];
    }

    for(int i=0;i<drinkNum;i++){
        cin>>Drinks[i];
    }

    //Acomodar
    vector< pair<int,int> > vec;


    for (int i=0;i<OmpaNum;i++){
        int x = convertir(OmpaLompas[i]);

        vec.push_back(pair<int, int>(OmpaLompas[i],x));
    }

    sort(vec.begin(), vec.end(), acomodar);
   

    for (int i=0;i<drinkNum;i++){
        //cout<<vec[i].first<<" "<<vec[i].second<<endl;
        for (int j=0;j<vec.size();j++){
            if (Drinks[i] == vec[j].first){
                cout<<j+1<<" ";
            }
        }

    }


    return 0;
}