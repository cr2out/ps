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
        
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        vector<ll> s(n), su(n);
        s[0] = a[0];
        
        for(int i = 1; i < n; i++) {
            s[i] = a[i] + ((s[i-1]>0)?s[i-1]:0);
        }
        
        if(k%2==0) {
            ll m = -1000000001;
            for(int i = 0; i < n; i++) {
                if(s[i] > m) m = s[i];
            }
            cout << m << '\n';
        }
        else {
            su[0] = s[0] + b[0];
            for(int i = 1; i < n; i++) {
                su[i] = max(s[i]+b[i], su[i-1]+a[i]);
            }
            ll m = -1000000001;
            for(int i = 0; i < n; i++) {
                if(su[i] > m) m = su[i];
            }
            cout << m << '\n';
        }
        
        
    }
    
    return 0;
}
