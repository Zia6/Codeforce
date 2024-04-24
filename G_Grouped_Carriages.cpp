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
#include<cstring>
using namespace std;
#define int long long
const int maxn = 2e5 + 5;
const int inf = 1e9 + 5;
struct seg{
    int l,r,value;
    bool operator < (const seg& s) const {
        return r > s.r;
    }
}s[maxn];
bool cmp(seg& s1,seg& s2){
    return s1.l < s2.l;
}
int a[maxn];
priority_queue<seg> q;
bool check(int x,int n){
    while(!q.empty()){
        q.pop();
    }
    for(int i = 0,j = 0;i < n;i++){
        a[i] = 0;
        while(j < n && s[j].l <= i){
            q.push(s[j]);
            j++;
        }
        // cout << j << '\n';
        while(a[i] <= x){
            if(q.empty()) break;
            seg now = q.top();
            // cout << now.l << ' ' << now.r << ' ' << now.value << '\n';
            // cout << a[i] << ' ' << x << '\n';
            q.pop();
            if(now.r >= i){
                if(x - a[i] >= now.value){
                    a[i] += now.value;
                    now.value = 0;
                }else {
                    now.value -= (x - a[i]);
                    a[i] = x;
                    q.push(now);
                }
            }else {
                return false;
            }
            if(a[i] == x) break;
        }
    }
    if(q.empty()) return true;
    return false;
}
signed main() {
    int n;
    cin >> n;
    for(int i = 0 ;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        s[i].l = max((long long)0,i - x);
        s[i].r = min(i + x,n - 1);
        s[i].value = a[i];
    }
    sort(s,s + n,cmp);
    int l = 0,r = inf;
    while(l < r){
        int mid = (r + l) >> 1;
        if(check(mid,n)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
    return 0;
}