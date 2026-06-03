#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int cs = a[0], cnt = 1;
        for(int i = 1; i < n; i++) {
            if(cs < a[i] && a[i-1] + 1 >= a[i]) {
                continue;
            }
            cs = a[i];
            cnt++;
            
        }
        cout << cnt << '\n';
        
    }
    
    
    return 0;
}
