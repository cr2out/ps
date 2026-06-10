#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        ll a;
        int n;
        cin >> a >> n;
        vector<int> d(10);
        int mind, maxd;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(i == 0) mind = x;
            if(i == n-1) maxd = x;
            d[x] = 1;
        }
        
        
        ll st = 1;
        while(st * 10 <= a) {
            st *= 10;
        }
        
        ll t = a, m = 100000000000000000L, sum = 0;
        
        ll ok = 10, y = 0;
        int mind2 = mind;
        if(mind2 == 0) {
            for(int i = 1; i <= 9; i++) {
                if(d[i] == 1) {
                    mind2 = i;
                    break;
                }
            }
        }
        y += mind2;
        while(ok <= st * 10) {
            y = y * 10 + mind;
            ok *= 10;
        }
        
        m = abs(a-y);
        
        while(st > 0) {
            int i = t / st;
            int j = i;
            while(j <= 9) {
                if(d[j] == 1) {
                    ll x = sum + j * st;
                    ll tst = st / 10;
                    while(tst >= 1) {
                        x += tst * mind;
                        tst /= 10;
                    }
                    if(abs(a - x) < m) m = abs(a - x);
                }
                j++;
            }
            j = i;
            while(j >= 0) {
                if(d[j] == 1 || (j == 0 && t == a && st != 1)) {
                    ll x = sum + j * st;
                    ll tst = st / 10;
                    while(tst >= 1) {
                        x += tst * maxd;
                        tst /= 10;
                    }
                    if(abs(a - x) < m) m = abs(a - x);
                }
                j--;
            }
            
            if(d[i] != 1) {
                break;
            }
            sum += (t / st) * st;
            t %= st;
            st /= 10;
        }
        
        cout << m << '\n';
    }
 
    return 0;
}
