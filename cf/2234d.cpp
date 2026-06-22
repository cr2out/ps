#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int n, k;
        cin >> n >> k;
        string s, z, xo;
        cin >> s >> z;

        for(int i = 0; i < n; i++) {
            if(s[i] == z[i]) xo += "0";
            else xo += "1";
        }

        ll ac = 0, bc = 0, cc = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') ac++;
            if(z[i] == '1') bc++;
            if(xo[i] == '1') cc++;
        }

        ll a = ac * (n-ac), b = bc * (n-bc), c = cc * (n-cc);
        int m = (1 << k) + 1;
 
        if(m % 3 == 0) {
            cout << (a + b + c) * (m / 3) << '\n';
        }
        else if(m % 3 == 2) {
            cout << (a + b + c) * (m / 3) + a + b << '\n';
        }
        else {
            cout << "what";
        }
        
    }
    


    return 0;
}
