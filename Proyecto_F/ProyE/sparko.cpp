/*
Nombre: Alex Jesús Vargas Castro
Matrícula: A00824525
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void leeArcos(int mat[20][20], int m){
    char cha,chb;
    int a=0,b=0,c=0;

    for(int i=0;i<m;i++){
        for (int j=0;j<m;j++){
            mat[i][j] =0;
        }
    }

    for (int i=1;i<=m;i++){
        cin>>cha>>chb>>c;
        a=cha-'A';
        b=chb-'A';
        mat[a][b] = mat[b][a] = c;
    }
}

void solve(int graph[20][20], vector<bool>& v, int Pos, int n, int iCont, int dist, int& ans) 
{ 
    if (iCont == n && graph[Pos][0]) { 
        ans = min(ans, dist + graph[Pos][0]); 
        return; 
    } 
  
    for (int i = 0; i < n; i++) { 
        if (!v[i] && graph[Pos][i]) { 
            v[i] = true; 
            solve(graph, v, i, n, iCont + 1, dist + graph[Pos][i], ans); 
            v[i] = false; 
        } 
    } 
}; 
  

int main() 
{ 
    int graph[20][20];
	int n, m;

    cin >> n >> m;
	leeArcos(graph, m);
  
    vector<bool> v(n); 
    for (int i = 0; i < n; i++){
        v[i] = false; 
    }
  
    v[0] = true; 
    int ans = INT_MAX; 
  
   
    solve(graph, v, 0, n, 1, 0, ans); 

    if (ans == INT_MAX){
        cout<<"INF"<<endl;
    }else{
        cout<<ans<<endl;
    }

    return 0; 
} 

/*
4 5
A B 5
A C 10
A D 8
B C 2
C D 1

5 7
A B 4
A C 8
A D 2
B C 7
B D 2
C D 1
D E 3

7 11
A B 2
A C 4
A D 6
B C 2
B E 6
C D 1
C E 3
D E 2
D F 3
E G 5
F G 4

5 10
A B 4
A C 8
A D 5
A E 3
B C 7
B D 2
B E 2
C D 1
C E 4
D E 3
*/