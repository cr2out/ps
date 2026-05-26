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
        string a, b;
        cin >> a >> b;
        
        int da = 0, db = 0, d = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] != b[i]) {
                if(d % 2 == 0) {
                    a[i] = '(';
                    b[i] = ')';
                }
                else {
                    a[i] = ')';
                    b[i] = '(';
                }
                d++;
            }
        }
        
        int flag = 0;
        for(int i = 0; i < n; i++) {
            da += (a[i] == '(') ? 1 : -1;
            db += (b[i] == '(') ? 1 : -1;
            if(da < 0 || db < 0) {
                flag = 1;
                break;
            }
        }
        if(!flag && da == 0 && db == 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
