#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 2), p(k + 1);
        
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int i = 1; i <= k; i++) {
            cin >> p[i];
        }
        
        int ok = a[p[1]]^1;
        for(int i = 1; i <= n; i++) {
            a[i] ^= ok;
        }
        a[0] = 1;
        a[n + 1] = 1;
        
        int s = 0;
        int x = 0, mx = 0, j = 0;
        for(int i = 0; i <= n; i++) {
            if(j <= k && i == p[j]) {
                j++;
                x = 0;
            }
            if(a[i] != a[i + 1]) {
                s++;
                x++;
                mx = max(mx, x);
            }
        }
        
        cout << max(s / 2, mx) << '\n';
        
        
    } 
 
    return 0;
}
