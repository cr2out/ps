#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int n, m = 0;
        cin >> n;
        vector<vector<int> > a(n, vector<int>()), at(n, vector<int>());
        for(int i = 0; i < n; i++) {
            int l;
            cin >> l;
            unordered_map<int, int> ch;
            for(int j = 0; j < l; j++) {
                int x;
                cin >> x;
                at[i].push_back(x);
                if(x > m) m = x;
            }
            reverse(at[i].begin(), at[i].end());
            for(int j = 0; j < l; j++) {
                if(ch.count(at[i][j]) == 0) {
                    a[i].push_back(at[i][j]);
                    ch[at[i][j]] = 1;
                }
            }
        }
        vector<int> chk(m + 1);
        vector<int> bye(n + 1);
        
        while(1) {
            int mp = -1;
            for(int i = 0; i < n; i++) {
                if(mp == -1 && !bye[i]) {
                    mp = i;
                    continue;
                }
                if(mp == -1 || bye[i]) continue;
                vector<int> tmp1, tmp2;
                for(int k: a[i]) {
                    if(!chk[k]) tmp1.push_back(k);
                }
                for(int k: a[mp]) {
                    if(!chk[k]) tmp2.push_back(k);
                }
                if(tmp1 < tmp2) mp = i;
            }            
            if(mp == -1) break;
            for(int k: a[mp]) {
                if(!chk[k]) cout << k << " ";
                chk[k] = 1;
            }
            bye[mp] = 1;
        }
        cout << '\n';
        
    }
    
    
    return 0;
}
