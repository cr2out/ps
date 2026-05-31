#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll x, ll y) {
    if(x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        ll n, m, a, b;
        cin >> n >> m >> a >> b;
        ll x = gcd(n, m), y = gcd(a, n), z = gcd(b, m);
        if(x <= 2 && y == 1 && z == 1) cout << "YES\n";
        else cout << "NO\n";

        
    }
    
    return 0;
}
