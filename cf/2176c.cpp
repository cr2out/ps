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
        vector<int> o, e;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(x % 2 == 0) e.push_back(x);
            else o.push_back(x);
        }
        
        sort(e.begin(), e.end());
        sort(o.begin(), o.end());
        
        vector<ll> so(o.size() + 1), se(e.size() + 1);
        
        for(int i = 1; i <= o.size(); i++) {
            so[i] = o[i-1] + so[i-1];
        }
        
        for(int i = 1; i <= e.size(); i++) {
            se[i] = e[i-1] + se[i-1];
        }
        
        for(int k = 1; k <= n; k++) {
            if(o.size() == 0) {
                cout << "0 ";
                continue;
            }
            ll cnt = o[o.size()-1];
            if(k <= e.size() + 1) {
                cnt += se[e.size()] - se[e.size() - k + 1];
                cout << cnt << " ";
            }
            else if((k-(e.size()+1)) % 2 == 0) {
                cnt += se[e.size()];
                cout << cnt << " ";
            }
            else {
                cnt += se[e.size()]-se[1];
                if(e.size() == 0 || o.size() == 2 ||(k == n)) cnt = 0;
                 
                cout << cnt << " ";
            }
        }
        cout << '\n';
    }
    
    return 0;
}
