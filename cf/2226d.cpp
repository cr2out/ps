#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; 
    cin >> T;
    while(T--){
        int n; 
        cin >> n;
        vector<int> a(n);
        int mn[2] = {INT_MAX, INT_MAX}, mx[2] = {INT_MIN, INT_MIN};
        for(int &x : a){ cin >> x; mn[x&1] = min(mn[x&1], x); mx[x&1] = max(mx[x&1], x); }

        int flag = 0;
        for(int p = 0; p < 2; p++){
            int q = p^1, pre = INT_MIN;
            for(int x : a){
                if((x&1) != p) continue;
                if(x < pre && mx[q] < pre && mn[q] > x) {
                    flag = 1;
                    break;
                }
                pre = max(pre, x);
            }
        }
        cout << (flag ? "NO\n" : "YES\n");
    }
    return 0;
}
