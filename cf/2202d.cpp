#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        int m = 2*n - 1;
        if(k < n || k > m) {
            cout << "NO\n";
            continue;
        }
        
        cout << "YES\n";
        if(n == 1) {
            cout << "1 1\n";
            continue;
        }
        if(n == k) {
            for(int i = 1; i <= n; i++) {
                cout << i << " " << i << " ";
            }
        }
        else {
            cout << "1 2 ";
            for(int i = 3; i <= n - (m-k); i++) {
                cout << i << " " << i - 2 << " ";
            }
            cout << n - (m-k) - 1 << " " << n - (m-k) << " ";
            for(int i = n - (m-k) + 1; i <= n; i++) {
                cout << i << " " << i << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}
