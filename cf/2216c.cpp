#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int n, k, p, q;
        cin >> n >> k >> p >> q;
        vector<ll> a(n + 1), mp(n + 1), mqp(n + 1), mm(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            mp[i] = a[i] % p;
            mqp[i] = (a[i] % q) % p;
            mm[i] = min(mp[i], mqp[i]);
        }
        vector<ll> amp(n + 1), amqp(n + 1), amm(n + 1);
        for(int i = 1; i <= n; i++) {
            amp[i] = mp[i] + amp[i-1];
            amqp[i] = mqp[i] + amqp[i-1]; 
            amm[i] = mm[i] + amm[i-1];
        }
        
        ll mini = min(amp[n], amqp[n]);
        
        for(int i = 1; i <= n-k+1; i++) {
            ll x = min(amp[i+k-1] - amp[i-1], amqp[i+k-1] - amqp[i-1]);
            mini = min(mini, x + amm[i-1] + amm[n] - amm[i+k-1]);
        }
        
        
        cout << mini << '\n';
        
        
    }

}
