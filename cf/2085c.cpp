#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        ll x, y;
        cin >> x >> y;
        
        ll d = 1, ans = 0;
        if(x == y) {
            cout << -1 << '\n';
            continue;
        }

        if(y > x) swap(x, y);
        while(d < x) d *= 2;
        cout << d - x << '\n';
    }


    return 0;
}
