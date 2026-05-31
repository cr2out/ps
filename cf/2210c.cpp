#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int gcd(int x, int y) {
    if(x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        int cnt = 0;
        
        for(int i = 0; i < n; i++) {
            int x = a[i];
            if(i > 0) {
               x /= gcd(a[i-1], x);
               if(i < n - 1) x *= gcd(a[i-1], a[i+1]);
            }
            if(i < n - 1) {
                x /= gcd(x, a[i+1]);
            }
            if(x != 1) cnt++;
            
        }
        cout << cnt << '\n';
        
    }
    
    return 0;
}
