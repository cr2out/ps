#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        vector<int> answer; 
        int j = 0;
        for(int i = n - 1; i > j; i--) {
            if(str[i] == '1') continue;
            while(str[j] == '0' && i > j) {
                j++;
            }
            if(j >= i) break;
            answer.push_back(i + 1);
            answer.push_back(j + 1);
            j++;
        }
        sort(answer.begin(), answer.end());
        
        if(answer.size() > 0) {
            cout << "Alice" << '\n' << answer.size() << '\n';
            for(int i = 0; i < answer.size(); i++) {
                cout << answer[i] << " ";
            }
            cout << '\n';
        }
        else {
            cout << "Bob" << '\n';
        }
        
    }
    return 0;
}
