#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int n, i;
        cin >> n;
        
        for(i = 1; i <= n - 1; i++) {
            cout << "? " << i*2-1 << " " << i*2 << endl;
            int ans;
            cin >> ans;
            if(ans==1) {
                cout << "! " << i*2-1 << endl;
                break;
            }   
            else if(ans==-1){
                return 0;
            }
        }
        if(i == n) {
            cout << "? " << 2*n-1 << " " << 2*n-2 << endl;
            int ans;
            cin >> ans;
            if(ans==1) {
                cout << "! " << 2*n-1 << endl;
            }
            else if(ans==-1){
                return 0;
            }
            else {
                cout << "? " << 2*n-1 << " " << 2*n-3 << endl;
                cin >> ans;
                if(ans==1) {
                    cout << "! " << 2*n-1 << endl;
                }
                else if(ans==-1){
                    return 0;
                }
                else {
                    cout << "! " << 2*n << endl;
                }
            }
        }
    }
    
    
    return 0;
}
