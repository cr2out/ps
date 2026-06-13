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
        vector<int> a(n + 1);
        int ma = 1, mi = 1;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(a[i] > a[ma]) ma = i;
            if(a[i] < a[mi]) mi = i;
        }
        string t;
        cin >> t;
        t = " " + t;
        if(t[1] == '1' || t[n] == '1' || t[ma] == '1' || t[mi] == '1') {
            cout << "-1\n";
            continue;
        }
        
        cout << "5\n1 " << ma << "\n1 " << mi << '\n';
        cout << ma << " " << n << "\n" << mi << " " << n << '\n';
        cout << min(ma,mi) << " " << max(ma,mi) << '\n';
        
    }
    
    return 0;
}
