#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n, d;
        cin >> n >> d;
        vector<ll> a(n), sum(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sum[0] = a[0];
        for(int i = 1; i < n; i++) {
            sum[i] = sum[i-1] + a[i];
        }
        ll cnt = 0;
        for(int i = 0; i < n; i++) {
            ll x = a[i] * 2 * d;
            if(i + d >= n) {
                x -= sum[n-1] - sum[i];
                x -= sum[i + d - n];
            }
            else {
                x -= sum[i + d] - sum[i];
            }
            if(i - d < 0) {
                if(i > 0) x -= sum[i-1];
                x -= sum[n-1] - sum[n+(i-d)-1];
            }
            else {
                x -= sum[i-1];
                if(i - d > 0) x += sum[i-d-1];
            }
            if(x > 0) cnt += x; 
        }
        cout << cnt << '\n';

    }




    return 0;
}
