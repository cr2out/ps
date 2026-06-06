#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T, cnt = 1;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        if(n % 2 == 0) {
            a[0] = n;
            for(int i = 0; i < (n - 2) / 2; i++) {
                a[i*2+1] = 2*i+3;
                a[i*2+2] = 2*i+2;
            }
            a[n-1] = 1;
            int st = 1;
            while(st * 2 <= n) st *= 2;
            if(st == n) {
                cout << -1 << '\n';
                continue;
            }
            else {
                swap(a[0], a[n-st]);
            }
            for(int i = 0; i < n; i++) {
                cout << a[i] << ' ';
            }
            cout << '\n';
        }
        else {
            cout << n-1 << " ";
            for(int i = 0; i < (n - 3) / 2; i++) {
                cout << 2*i+3 << " " << 2*i+2 << " ";
            }
            cout << 1 << " " << n << "\n";
        }
        
    }
    
    
    return 0;
}
