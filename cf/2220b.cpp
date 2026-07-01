#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int flag = 0, cnt = 1;
        for(int i = 1; i < n; i++) {
            if(a[i] == a[i-1]) {
                cnt++;
            }
            else {
                cnt = 1;
            }
            if(cnt >= m) flag = 1;
        }
        if(flag) {
            cout << "NO" << '\n';
        }
        else {
            cout << "YES" << '\n';
        }
    }
    
    return 0;
}
