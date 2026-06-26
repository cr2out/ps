#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(2 * n + 1), b, c;
        b.push_back(1);
        for(int i = 2; i <= 2 * n; i++) {
            cout << "? " << b.size() + 1 << " ";
            for(int j = 0; j < b.size(); j++) {
                cout << b[j] << " ";
            }
            cout << i << endl;
            int ans;
            cin >> ans;
            if(ans != 0) {
                a[i] = ans;
            }
            else {
                b.push_back(i);
            }
        }
        for(int i = 1; i <= 2 * n; i++) {
            if(a[i] != 0) c.push_back(i);
        }
        for(int i = 1; i <= 2 * n; i++) {
            if(a[i] != 0) continue;
            cout << "? " << c.size() + 1 << " ";
            for(int j = 0; j < c.size(); j++) {
                cout << c[j] << " ";
            }
            cout << i << endl;
            int ans;
            cin >> ans;
            a[i] = ans;
        }
        cout << "! ";
        for(int i = 1; i <= 2 * n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }


    return 0;
}
