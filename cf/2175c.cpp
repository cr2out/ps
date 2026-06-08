#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        string s, t;
        cin >> s;
        cin >> t;
        
        vector<int> alpha(26);
        for(int i = 0; i < t.length(); i++) {
            alpha[t[i]-'a']++;
        }
        
        int flag = 0;
        for(int i = 0; i < s.length(); i++) {
            alpha[s[i]-'a']--;
            if(alpha[s[i]-'a'] < 0) {
                cout << "Impossible\n";
                flag = 1;
                break;
            }
        }
        
        if(flag) continue;
        
        int p = 0;
        for(int i = 0; i < 26; i++) {
            while(p < s.length() && s[p] - 'a' <= i) {
                cout << s[p];
                p++;
            }
            for(int j = 0; j < alpha[i]; j++) {
                cout << (char)(i+'a');
            }
        }
        cout << '\n';
    }
    
    return 0;
}
