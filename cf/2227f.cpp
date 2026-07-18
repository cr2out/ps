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
        vector<ll> a(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<ll> cnt(n + 1);
        for(int i = 1; i <= n; i++) {
            cnt[a[i]]++;
        }
        for(int i = n-1; i >= 1; i--) {
            cnt[i] += cnt[i+1];
        }
        ll d = 0;
        for(int i = 1; i <= n; i++) {
            d += (cnt[i]*(2*n-cnt[i]+1)/2)-(a[i]*i);
        }
        ll delta = 0;
        for(int i = 1; i <= n; i++) {
            delta = max(delta, cnt[a[i]]+i-n-1);
        }
        cout << d + delta << '\n';
    }

    return 0;
}
