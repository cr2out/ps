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
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int B = 500;
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] >= 500) {
                for(int j = 1; i + j*a[i] < n; j++) {
                    if(a[i+j*a[i]] == j) cnt++;
                }
                for(int j = 1; i - j*a[i] >= 0; j++) {
                    if(a[i-j*a[i]] == j) cnt++;
                }
            }
            else {
                for(int j = 1; j < B && i+j*a[i] < n; j++) {
                    if(a[i+j*a[i]] == j) cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }



    return 0;
}
