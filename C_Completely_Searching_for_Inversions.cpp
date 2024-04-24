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
const int mod = 998244353;
vector<int> s[maxn],w[maxn];
int vis[maxn];
long long ans = 0,sum = 0,cnt[maxn][2],ss[maxn];
long long sum1 = 0,sum0 = 0,z = 0;
void dfs(int x){
    if(vis[x]){
        return;
    }
    vis[x] = 1;
    for(int i = 0;i < s[x].size();i++){
        cnt[x][w[x][i]]++;
        dfs(s[x][i]);
        ss[x] += cnt[x][1] * cnt[s[x][i]][0]; 
        ss[x] += (w[x][i] ^ 1) * cnt[x][1];
        ss[x] %= mod;
        cnt[x][0] += cnt[s[x][i]][0];
        cnt[x][0] %= mod;
        cnt[x][1] += cnt[s[x][i]][1];
        cnt[x][1] %= mod;
        ss[x] += ss[s[x][i]];
        ss[x] %= mod;
    }
}
int main() {
    int n,t1,t2,t;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> t;
        for(int j = 0;j < t;j++){
            cin >> t1 >> t2;
            s[i].push_back(t1);
            w[i].push_back(t2);
        }
    }
    dfs(1);
    cout << ss[1] << '\n';
    return 0;
}