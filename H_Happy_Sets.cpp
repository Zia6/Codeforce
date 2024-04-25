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
using ll = long long;
const int maxn = 2e5 + 5;
const int mod = 998244353;
ll pre[maxn],inv[maxn];
long long bit_pow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
void init(){
    pre[0] = 1;
    for(int i = 1;i < maxn;i++){
        pre[i] = pre[i - 1] * i % mod;
    }
}
int main() {
    int n,k;
    init();
    ll ans = 0;
    cin >> n >> k;
    for(int i = 0;i <= n;i++){
        ll tmp = 1;
        if(n - i > k ){
            continue;
        }
        tmp = tmp * pre[n - i + 1] % mod;
        tmp = tmp * bit_pow(n - i + 1,k - n + i)% mod;
        tmp = tmp - pre[n - i] * bit_pow(n - i,k - n + i + 1) % mod; 
        tmp = (tmp + mod) % mod;
        // cout << tmp << ' ' << pre[i] << ' ';
        tmp = tmp * pre[n] % mod;
        tmp = tmp * bit_pow(pre[i],mod - 2) % mod;
        // cout << tmp << '\n';
        ans += tmp;
        ans %= mod;
    }   
    cout << ans << '\n';
    return 0;
}