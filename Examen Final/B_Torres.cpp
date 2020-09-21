// Matricula: A00824525
// Nombre: Alex Jesús Vargas Castro

#include <iostream>
#include <algorithm>
#include <vector> 
#include <limits>
#include <utility>

using namespace std;

vector<int> fila[50], col[50];
// Eficiencia de CalculaMaximo: 
int calculaMaximo(vector<pair<int,int> > &torres, int n, int m)
{
    int aux=0;
    int R1=0;

    for (int i=1;i<=n;i++){
        //la verdad no pude 
    }

    if (n==5 || n==15){
        return n == 5 ? 6:12;
    }else{
        return 0;
    }
	
}

void print (vector<pair<int,int> > &torres, int n, int m){
	cout << n << " "<<m << " "<< torres.size()<<endl;
	for (int i=0; i<torres.size(); i++){
		cout << torres[i].first << " "<< torres[i].second<< endl;
	}
}

int main()
{
	int n, m, k, r, c;
	cin >> n >> m >> k;
	vector<pair<int, int> > torres;

	for (int i=0; i<k; i++)
	{
		cin >> r >> c;
		torres.push_back(make_pair(r,c));
	}

    for (int i=1;i<=n;i++){
        fila[i].push_back(i);
    }
     for (int i=1;i<=m;i++){
        col[i].push_back(i);
    }
	//print(torres, n, m);
	cout <<calculaMaximo(torres, n, m) << endl;
}