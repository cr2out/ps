#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T, cnt = 1;
    cin >> T;
    while(T--) {
        int n, flag = 0;
        cin >> n;
        vector<int> a(n), b(n);
        
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b.begin(), b.end());
        for(int i = 0; i < n; i++) {
            if(a[i] != b[i]) {
                flag = 1;
                break;
            }
        }
        if(!flag) {
            cout << "-1\n";
            continue;
        }
        
        int m = -1, tm;
        
        for(int i = 1; i < n - 1; i++) {
            if(a[i] == b[i]) continue;
            tm = min(max(abs(a[i]-b[0]), abs(a[i]-b[n-1])), max(abs(b[i]-b[0]), abs(b[i]-b[n-1])));
            if(m == -1 || tm < m) m = tm;
        }
        if(m == -1) {
            m = b[n-1] - b[0];
        }
        cout << m << '\n';
    }
    
    
    return 0;
}
