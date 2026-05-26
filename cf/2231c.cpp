#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    vector<int> a(100003);
    
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        map<long long, long long> b, b2;
        
        long long m, cnt2 = 0;
        
        int tc = 0;
        
        for(int i = 0; i < n; i++) {
            tc = 0;
            m = a[i];
            b[1]++;
            if(m == 1) {
                b[2]++;
                b2[2]++;
            }
            while(m != 1) {
                if(i == 0 || b[m] != 0) {
                    b[m]++;
                    b2[m] += tc;
                }
                if(m % 2 == 0) m /= 2;
                else m++;
                cnt2++;
                tc++;
            }
            b2[1] += tc;
        }
        
        long long target = 1000000000, cnt = 0;
        
        for(map<long long, long long>::iterator it = b.begin(); it != b.end(); it++) {
            if((it->second) == n && b2[it->first] < target) {
                target = b2[it->first];
            }
        }
        
        cout << target << "\n";
        
        
    }
    return 0;
}
