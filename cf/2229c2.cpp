#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        vector<ll> sum2(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            sum2[i] = sum2[i-1] + a[i];
        }
        vector<ll> sum(n + 1);
        for(int i = 1; i <= n; i++) {
            sum[i] = abs(a[i]) + sum[i-1];
        }
        ll m = sum2[n], mp = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] > 0) {
                if(sum[i-1] - a[i] + sum2[n] - sum2[i] > m) {
                    m = sum[i-1] - a[i] + sum2[n] - sum2[i];
                    mp = i;
                }
            }
        }
        vector<int> ans;
        int c = 0;
        for(int i = mp - 1; i >= 1; i--) {
            if((c % 2 == 0 && a[i] > 0) || (c % 2 == 1 && a[i] < 0)) {
                ans.push_back(i);
                c++;
            }
        }
        if(mp != 0) ans.push_back(mp);
        
        cout << ans.size() << '\n';
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}
