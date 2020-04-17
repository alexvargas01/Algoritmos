// Matricula: A00824525
// Nombre: Alex Vargas

#include <iostream>
#include <vector>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

int num1=0;
int num2=0;

int treeOne(TreeNode *r1){
    if (r1!=NULL){
        if(r1->left == NULL && r1->right == NULL){
            num1++;
        }else{
            treeOne(r1->left);
            treeOne(r1->right);
        }
    }
    return num1;
}

int treeTwo(TreeNode *r2){
    if (r2!=NULL){
        if(r2->left == NULL && r2->right == NULL){
            num2++;
        }else{
            treeTwo(r2->left);
            treeTwo(r2->right);
        }
    }
    return num2;
}

bool check(TreeNode *r1, TreeNode *r2){
    if (treeOne(r1) == treeTwo(r2)){
        return true;
    }else{
        return false;
    }
}


TreeNode* load(vector<int> &v, int n){
	if (v[n] != -1){
		TreeNode *r = new TreeNode(v[n]);
		if (n*2 < v.size()){
			r->left = load(v,n*2);
		}
		if (n*2+1 < v.size()){
			r->right = load(v,n*2+1);
		}
		return r;
	}
	return NULL;
}

int main(){
	TreeNode *r1, *r2;
	int n;
	cin >> n;
	vector<int> v1(n+1);
	for (int i=1; i<n; i++){
		cin >> v1[i];
	}
	r1 = load(v1,1);
	cin >> n;
	vector<int> v2(n+1);
	for (int i=1; i<n; i++){
		cin >> v2[i];
	}
	r2 = load(v2,1);
	if (check(r1,r2)){
		cout << "EQUALS"<<endl;
	}
	else{
		cout << "NOT EQUALS"<<endl;
	}
}
/*
Example 1
8
4 8 3 -1 5 10 -1
16
10 -1 5 -1 -1 7 3 -1 -1 -1 -1 1 2 3 4
Answer "NOT EQUALS"

Example 2
4
1 2 3
8
1 2 -1 4 5 -1 -1
Answer "EQUALS"
*/