#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int k, n; // mistake, should swap k and n
        cin >> k >> n;
        vector<string> str(n);
        for(int i = 0; i < n; i++) {
            cin >> str[i];
        }
        int flag = 0;
        for(int i = 1; i <= k / 2; i++) {
            if(k % i != 0) continue;
            string answer;
            for(int x = 0; x < i; x++) {
                vector<int> alp(26), tmp(26);
                for(int j = 0; j < k / i; j++) {
                    int y = i * j + x;
                    for(int z = 0; z < n; z++) {
                        if(alp[str[z][y]-'a'] == tmp[str[z][y]-'a']) alp[str[z][y]-'a']++;
                    }
                    for(int z = 0; z < 26; z++) {
                        tmp[z] = alp[z];
                    }
                }
                for(int j = 0; j < 26; j++) {
                    if(alp[j] == k / i) {
                        answer += (char)(j + 'a');
                        break;
                    }
                }
            }
            if(answer.length() == i) {
                for(int j = 0; j < k / i; j++) {
                    cout << answer;
                }
                cout << '\n';
                flag = 1;
                break;
            }
        }
        if(!flag) {
            cout << str[0] << '\n';
        }
    }

    return 0;
}
