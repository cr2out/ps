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
        if(n % 2 == 0) {
            cout << n << " ";
            for(int i = 0; i < (n - 2) / 2; i++) {
                cout << 2*i+3 << " " << 2*i+2 << " ";
            }
            cout << 1 << '\n';
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
