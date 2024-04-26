#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<iomanip>
#include<sstream>
using namespace std;
const int maxn = 2e5 + 5; 
set<int> v[2][maxn];
int main() {
    int ROW,COL,n,row,col;
    cin >> ROW >> COL >> n;
    for(int i = 0;i < n;i++){
        cin >> row >> col;
        v[0][row].insert(col);
        v[1][col].insert(row);
    }
    v[0][ROW].insert(COL);
    v[1][COL].insert(ROW);
    int i = ROW,j = COL;
    // cout << i << ' ' <<j << '\n';
    while(i > 0 && j > 0){
        // cout << i << ' ' << j << '\n';
        if(v[0][i].find(j) != v[0][i].end()){
            i--;
            j--;
        }else if(v[0][i].upper_bound(j) != v[0][i].end()){
            i--;
        }else if(v[1][j].upper_bound(i) != v[1][j].end()){
            j--;
        }else {
            v[0][i].insert(j);
            v[1][j].insert(i);
            i--;
            j--;
        }
    }
    if(v[0][1].find(1) != v[0][1].end()||(v[0][1].empty() && v[1][1].empty())){
        cout << "Bhinneka" << '\n';
    }else {
        cout << "Chaneka" << '\n';
    }
    return 0;
}