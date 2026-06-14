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
        if(n == 1) {
            cout << "2\n";
            continue;
        }
        //l : 1, r: -1
        
        vector<int> b(n);
        int cnt = 0, t, flag = 0, ok = 0;
        
        //b[0] == 1
        b[0] = 1;
        for(int i = 1; i < n; i++) {
            int d = a[i]-a[i-1];
            if(d == 1) {
                if(b[i-1] == -1) {
                    ok = 1;
                    break;
                }
                b[i] = 1;
            }   
            else if(d == -1) {
                if(b[i-1] == 1) {
                    ok = 1;
                    break;
                }
                b[i] = -1;
            }
            else if(d == 0) {
                b[i] = -b[i-1];
            }
            else {
                flag = 1;
                break;
            }
        }
        
        t = 1;
        for(int i = 1; i < n; i++) {
            if(b[i] == -1) t++;
        }
        
        if(ok == 0 && t == a[0]) cnt++;
        
        //b[0] == -1
        ok = 0, b[0] = -1;
        for(int i = 1; i < n; i++) {
            int d = a[i]-a[i-1];
            if(d == 1) {
                if(b[i-1] == -1) {
                    ok = 1;
                    break;
                }
                b[i] = 1;
            }   
            else if(d == -1) {
                if(b[i-1] == 1) {
                    ok = 1;
                    break;
                }
                b[i] = -1;
            }
            else if(d == 0) {
                b[i] = -b[i-1];
            }
            else {
                flag = 1;
                break;
            }
        }
        
        t = 1;
        for(int i = 1; i < n; i++) {
            if(b[i] == -1) t++;
        }
        
        if(ok == 0 && t == a[0]) cnt++;
        
        if(flag == 1) {
            cout << "0\n";
            continue;
        }
        cout << cnt << '\n';
        
    }
    
    
    return 0;
}
