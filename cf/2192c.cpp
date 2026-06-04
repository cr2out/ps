#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int n, h, k;
        cin >> n >> h >> k;
        vector<int> a(n + 1);
        vector<ll> s(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            s[i] = s[i - 1] + a[i];
        }
        
        
        ll answer = (ll) (k + n) * (h / s[n]);
        if(h % s[n] == 0) {
            answer -= k;
            cout << answer << '\n';
            continue;
        }
        h %= s[n];
        
        int p = 0;
        for(int i = 1; i <= n; i++) {
            if(s[i] >= h) {
                p = i;
                break;
            }            
        }
        int mp = std::max_element(a.begin() + p, a.end()) - a.begin();
        
        int fmp = p;
        for(int i = 1; i <= p - 1; i++) {
            int d = a[mp] - a[i];
            int tmp = lower_bound(s.begin() + i, s.begin() + p, h - d) - s.begin();
            if(tmp < fmp) {
               fmp = tmp; 
            }
        }
        answer += fmp;
        
        cout << answer << '\n';
        
    }
    
    return 0;
}
