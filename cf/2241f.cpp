#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = " " + s;
        int l, r;
        for(l = 1; l <= n; l++) {
            if(s[l] == '1') break;
        }
        for(r = n; r >= 1; r--) {
            if(s[r] == '0') break;
        }
        int flag = 0, cnt = 0;
        for(int i = l; i <= r; i++) {
            if(s[i] == '1') {
                cnt++;
            }
            if(s[i] == '0') {
                if(cnt % 2 == 1) {
                    flag = 1;
                    break;
                }
                cnt = 0;
            }
        }
        cnt = 0;
        for(int i = r; i >= l; i--) {
            if(s[i] == '0') {
                cnt++;
            }
            if(s[i] == '1') {
                if(cnt % 2 == 1) {
                    flag = 1;
                    break;
                }
                cnt = 0;
            }
        }
        if(flag) cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}
