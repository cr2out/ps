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
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        map<int, int> p1, p2;
        for(int i = 0; i < n; i++) {
            int t = a[i], t2 = a[i] + 1;
            for(int j = 2; j * j <= t; j++) {
                if(t % j == 0) {
                    p1[j]++;
                    if(j != t / j) p1[t / j]++;
                }
            }
            if(t != 1) p1[t]++;
            for(int j = 2; j * j <= t2; j++) {
                if(t2 % j == 0) {
                    p2[j]++;
                    if(j != t2 / j) p2[t2 / j]++;
                }
            }
            if(t2 != 1) p2[t2]++;
        }
        int flag = 0;
        
        for(auto it = p1.begin(); it != p1.end(); it++) {
            if(it->second >= 2) {
                flag = 1;
                break;
            }
            else if(p2[it->first] >= 1) {
                flag = 2;
            }
        }
        if(flag == 1) {
            cout << "0\n";
        }
        else if(flag == 2) {
            cout << "1\n";
        }
        else cout << "2\n";
    }
    
    return 0;
}
