#include <bits/stdc++.h>

using namespace std;

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
        if(n == 1) {
            cout << 0 << '\n';
            continue;
        }
        int x = 0;
        for(int i = 0; i < n; i++) {
            x ^= a[i];
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if((x ^ a[i]) <= a[i]) cnt++;
        }
        if(x == 0) cout << 1 << '\n';
        else cout << cnt << '\n';
    }

    return 0;
}
