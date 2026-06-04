#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        ll p, q;
        cin >> p >> q;
        if(p >= q) {
            cout << "Alice" << '\n';
            continue;
        }
        ll d = q - p;
        if(p < d * 2 || q < d * 3) {
            cout << "Alice" << '\n';
        }
        else cout << "Bob" << '\n';
    }

    return 0;
}
