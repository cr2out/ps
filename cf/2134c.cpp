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
        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<ll> dp(n);
        ll cnt = 0;
        for(int i = 0; i < n; i+=2) {
            ll d = 0;
            ll t = a[i];
            if(i > 0 && a[i-1] < a[i]) {
                d = a[i] - a[i-1];
                a[i] = a[i-1];
            }
            if(i < n - 1 && a[i+1] < t && d < t-a[i+1]) {
                d = t-a[i+1];
                a[i] = a[i+1];
            }
            cnt += d;
        }
        
        for(int i = 1; i < n - 1; i+=2) {
            if(a[i-1]+a[i+1]>a[i]) {
                cnt += a[i-1]+a[i+1]-a[i];
                a[i+1] = a[i]-a[i-1];
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}
