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
const int maxn = 1e5 + 5;
int a[11][maxn];
long long d[maxn];
int main() {
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            for(int p = i + 1;p >= max(1,i + 2 - k);p--){
                d[p] = max(d[p],d[p - 1] + a[j][i]);
            }
        }
    }
    cout << d[m - k + 1] << '\n';
    return 0;
}