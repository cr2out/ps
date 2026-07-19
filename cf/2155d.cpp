#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int flag = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n - i; j++) {
                cout << j << " " << i + j << endl;
                int x;
                cin >> x;
                if(x == 1) {
                    flag = 1;
                    break;
                }
                
            }
            if(flag) break;
        }
        
    }
    
    return 0;
}
