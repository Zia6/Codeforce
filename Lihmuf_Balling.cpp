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
using i64 = long long;

int main() {
    int n, k, m,ans = 1;
    i64 sum = 0,max_s = 0;
    cin >> n >> m;
    for(int k = 2;k <= m;k++){
        sum = 0;
        int g = __gcd(k,n);
        for(int i = 0;i < k;i++){
            i64 l = max((1ll * i * n + k - 1) / k,1ll * n * i/(k - 1) + 1), r = min(1ll * n / g - 1,(1ll * (i + 1) * n - 1) / k);
            if(l <= r){
                sum +=1ll * (r - l + 1) * (r + l) / 2 * k;
                sum -= 1ll * (r - l + 1) * i * n;
            }
        }
        if(g > 1) sum += n;
        if(sum > max_s){
            ans = k;
            max_s = sum;
        }
    }
    cout << ans << '\n';
    return 0;
}