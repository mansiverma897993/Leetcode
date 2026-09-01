class Solution {
public:
    int minMoves(vector<string>& a, int E) {
        int m = a.size(), n = a[0].size(), k = 0, sr, sc;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 'S') sr = i, sc = j;
                if (a[i][j] == 'L') id[i][j] = k++;
            }

        int full = (1 << k) - 1;
        vector<vector<int>> best(m * n, vector<int>(1 << k, -1));

        queue<array<int,4>> q;
        q.push({sr, sc, E, 0});
        best[sr * n + sc][0] = E;

        int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int ans = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r,c,e,mask] = q.front();
                q.pop();

                if (mask == full) return ans;
                if (!e) continue;

                for (auto [dr,dc] : d) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || x >= m || y < 0 || y >= n || a[x][y] == 'X')
                        continue;

                    int ne = e - 1, nm = mask;

                    if (a[x][y] == 'R') ne = E;
                    if (a[x][y] == 'L') nm |= 1 << id[x][y];

                    int p = x * n + y;
                    if (best[p][nm] >= ne) continue;

                    best[p][nm] = ne;
                    q.push({x,y,ne,nm});
                }
            }
            ans++;
        }

        return -1;
    }
};