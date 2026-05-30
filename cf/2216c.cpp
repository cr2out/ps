#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int p, q;
        cin >> p >> q;
        ll sg = p + q * 2;
        int n = 1, m = 1000000000, flag = 0;
        while(n <= (m = (sg - n) / (2 * n + 1))) {
            if((sg - n) % (2 * n + 1) != 0 || (sg - p) % 2 == 1 || q > n * m + n) {
                n++;
                continue;
            }
            cout << n << " " << m << "\n";
            break;
        }
        if(n > m) cout << "-1" << '\n';
    }

}
