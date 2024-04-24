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

int main() {
    int n ,t,ans;
    cin >> n;
    ans = 1e9 + 5;
    for(int i = 0;i < n;i++){
        cin >> t;
        ans = min(ans,abs(t));
    }
    cout << ans << '\n';
    return 0;
}