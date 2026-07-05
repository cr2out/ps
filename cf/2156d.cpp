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
        int st = 1, d = 0;
        while(st <= n) {
            st *= 2;
            d++;
        }
        int k = 0, t = 1, b = 0, now = 0, ans = 0;
        vector<int> use(n + 1);
        vector<int> q(n + 1);
        for(k = 0; k < d; k++) {
            now = 0, b = 0;
            for(int i = 1; i <= n; i++) {
                if((k == 0 || (i & ((1<<k)-1)) == ans) && (i & t) != 0) {
                    b++;
                }
            }
            for(int i = 1; i <= n - 1; i++) {
                if(use[i]) continue;
                cout << "? " << i << " " << t << endl;
                int ok;
                cin >> ok;
                if(ok == 1) {
                    now++;   
                    q[i] = 1;
                }
                else {
                    q[i] = 0;
                }
            }
            if(now != b) {
                ans += t;
            }
            
            for(int i = 1; i <= n - 1; i++) {
                if(use[i]) continue;
                if(now != b && q[i] == 0) use[i] = 1;
                else if(now == b && q[i] == 1) use[i] = 1;
            }    
            t *= 2;
        }
        cout << "! " << ans << endl;
        
    }
    return 0;
}
