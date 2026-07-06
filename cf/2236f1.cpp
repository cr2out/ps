#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        map<int, int> pc;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            for(int j = 2; j * j <= a[i]; j++) {
                while(a[i] % j == 0) {
                    a[i] /= j;
                    pc[j]++;
                }
            }
            if(a[i] > 1) {
                pc[a[i]]++;
            }
        }
        ll ans = 1;
        for(auto it = pc.begin(); it != pc.end(); it++) {
            ans *= (it->second+1)%MOD;
            ans %= MOD;
        }
        cout << ans << '\n';
    }
	
    return 0;
}
