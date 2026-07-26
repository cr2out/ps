#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const long long MOD = 998244353L;

ll power(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while(b > 0) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        ll su = 0;
        int flag = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            su += a[i];
            if(i > (n+1)/2 && a[i] != 0) flag = 1;
        }
        if(su != n || flag == 1) {
            cout << "0\n";
            continue;
        }
        ll selected = 0, ans = 1;
        for(int i = 0; i < (n+1)/2; i++) {
            ll o;
            if(n % 2 == 0) {
                o = i*2+2;
            }
            else o = i*2 + 1;
            if(a[(n+1)/2 - i] > o - selected) {
                flag = 1;
                break;
            }
            ll t = 1;
            for(int j = o-selected; j >= o-selected-a[(n+1)/2-i]+1; j--) {
                t *= j;
                t %= MOD;
            }
            ll t2 = 1;
            for(int j = a[(n+1)/2-i]; j >= 1; j--) {
                t2 *= j;
                t2 %= MOD;
            }
            ans = ans * (t * power(t2, MOD-2) % MOD);
            ans %= MOD;
            selected += a[(n+1)/2-i];
        }
        if(flag) {
            cout << "0\n";
        }
        else {
            cout << ans << '\n';
        }
    }

    return 0;
}
