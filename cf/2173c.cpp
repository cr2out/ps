#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int n, k, i;
        cin >> n >> k;
        
        vector<int> a(n), chk(n);
        for(i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        
        vector<int> answer;
        for(i = 0; i < a.size(); i++) {
            if(chk[i] == 1) continue;
            int ex = a[i] * 2;
            for(int j = i; j < a.size(); j++) {
                if(ex > k) {
                    break;
                }
                if(a[j] == ex) {
                    ex += a[i];
                    chk[j] = 1;
                }
            }
            if(ex <= k) break;
            answer.push_back(a[i]);
        }
        if(i != a.size()) {
            cout << "-1\n";
        }
        else {
            cout << answer.size() << '\n';
            for(int i = 0; i < answer.size(); i++) {
                cout << answer[i] << " ";
            }
            cout << '\n';
        }
    }
    
    return 0;
}
