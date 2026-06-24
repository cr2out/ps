#include <bits/stdc++.h>

using namespace std;

struct cell {
    int d, x, y;
};

inline bool cmp(const cell a, const cell b) {
    return a.d < b.d || (a.d == b.d && a.x < b.x) || (a.d == b.d && a.x == b.x && a.y < b.y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<cell> a;
    for(int i = 0; (i * i) < 1440000; i++) {
        for(int j = 0; (j * j) < 1440000; j++) {
            if(i % 3 == 2 && j % 3 == 2) {
                a.push_back({i + j + 2, i, j});
            }
            else if(i % 3 != 0 && j % 3 != 0){
                a.push_back({i + j, i, j});
            }
        } 
    }

    sort(a.begin(), a.end(), cmp);


    vector<vector<int> > v(1200, vector<int>(1200));

    int T;
    cin >> T; 
    while(T--) {
        int n;
        cin >> n;
        
        for(int i = 0; i * i < n * 4; i++) {
            for(int j = 0; j * j < n * 4; j++) {
                v[i][j] = 0;
            } 
        }   

        int p = 0, q = 0;

        for(int i = 0; i < n; i++) {
            int ok;
            cin >> ok;
            if(ok == 1) {
                while(a[p].x%3 == 1 && a[p].y%3 == 1 && v[a[p].x/3][a[p].y/3] == 1) p++;
                cout << a[p].x << " " << a[p].y << '\n';
                v[a[p].x/3][a[p].y/3] = 1;
                p++;
            }
            else {  
                while(v[a[q].x/3][a[q].y/3] == 1 && q < a.size()) q++;
                cout << a[q].x << " " << a[q].y << '\n';
                v[a[q].x/3][a[q].y/3] = 1;
                q++;
            }
        }

    }





    return 0;
}
