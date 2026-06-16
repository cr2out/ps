#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T, ok = 0;
    cin >> T;
    while(T--) {
        ok++;
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        vector<ll> e(1);
        vector<ll> m1(n/2+1), m2(n/2+1);
        vector<int> idx1(n/2+1), idx2(n/2+1);
        
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(i % 2 == 0) e.push_back(a[i]);
        }
        
        
        
        if(n == 1) {
            cout << a[1] << '\n';
            continue;
        }
        for(int i = n/2; i >= 1; i--) {
            m1[i] = 2*e[i] + (i-1)*2+1;
            idx1[i] = i * 2;
        }
        for(int i = n/2-1; i >= 1; i--) {
            if(m1[i+1] >= m1[i]) {
                m1[i] = m1[i+1];
                idx1[i] = idx1[i+1];
            }
        }
        
        ll mx = 0;
        int n1 = 0, n2 = 0;
        for(int i = 1; i <= n - 1; i += 2) {
            if(m1[(i+1)/2]-2*a[i]-(i-1) > mx) {
                mx = m1[(i+1)/2]-2*a[i]-(i-1);
                n1 = i;
                n2 = idx1[(i+1)/2];
            }
        }
        
        for(int i = 1; i <= (n-1)/2; i++) {
            m2[i] = 2*e[i] + ((n-1)/2-i)*2+1;
            idx2[i] = i * 2;
        }
        for(int i = 2; i <= n/2; i++) {
            if(m2[i-1] >= m2[i]) {
                m2[i] = m2[i-1];
                idx2[i] = idx2[i-1];
            }
        }
        for(int i = ((n-1)/2)*2+1; i >= 3; i -= 2) {
            if(m2[(i-1)/2]-2*a[i]-(((n-1)/2)*2+1-i) > mx) {
                mx = m2[(i-1)/2]-2*a[i]-(((n-1)/2)*2+1-i);
                n1 = i;
                n2 = idx2[(i-1)/2];
            }
        }
        
        ll sum2 = 0;
        
        for(int i = 1; i <= n; i++) {
            if(i % 2 == 1) sum2 += a[i];
            else sum2 -= a[i];
        }
        
        
        cout << max(sum2 + mx, sum2 + ((n-1)/2)*2) << '\n';
    }



    return 0;
}
