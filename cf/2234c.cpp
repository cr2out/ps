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
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> r(n), l(n);
        for(int i = 0; i < n; i++) {
            r[i] = 0, l[i] = 0;
            for(int j = 1; j < n; j++) {
                r[(i+j)%n] = max(r[(i+j-1)%n], a[(i+j-1)%n]);
            }
            for(int j = 1; j < n; j++) {
                l[(n+i-j)%n] = max(l[(n+i-j+1)%n], a[(n+i-j)%n]);
            }
            ll cnt = 0;
            for(int j = 0; j < n; j++) {
                cnt += min(r[j], l[j]);
            }
            cout << cnt << " ";
        }
        cout << '\n';
    }

    return 0;
}
