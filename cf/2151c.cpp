#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<ll> a(2*n);
        for(int i = 0; i < 2*n; i++) {
            cin >> a[i];
        }
        
        ll cnt = 0;
        vector<ll> ps(n), ms(n + 1);
        ps[0] = a[2*n-1] - a[0];
        for(int i = 1; i < n; i++) {
            ps[i] = ps[i-1] + a[2*n-1-i] - a[i];
        }
        for(int i = 0; i < 2*n; i+=2) {
            ms[0] += a[i+1] - a[i];
        }
        for(int i = 1; i < n; i++) {
            ms[i] = -ms[i-1] + a[2*n-i] - a[i-1];
        }
        
        for(int k = 1; k <= n; k++) {
            if(k == 1) cout << ms[k-1] << " ";
            else cout << ps[k-2] + ms[k-1] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
