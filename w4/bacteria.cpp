#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int computeMinTime(int si, int sj, int n, int m) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> room(n, vector<int>(m, 0));

    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;

    vector<pair<int, int>> d = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
    };

    int maxTime = 0;

    while (!q.empty()) {
        pair<int, int> cell = q.front();
        q.pop();

        int ui = cell.first;
        int uj = cell.second;

        for (int i=0; i < d.size(); ++i) {
            int vi = ui + d[i].first;
            int vj = uj + d[i].second;

            if ((vi >= 0 && vi < n) && (vj >= 0 && vj < m) && !visited[vi][vj]) {
                visited[vi][vj] = true;
                q.push({vi, vj});
                room[vi][vj] = room[ui][uj] + 1;

                maxTime = max(maxTime, room[vi][vj]);
            }
        }

    }

    for (int i=0; i < n; ++i) {
        for (int j=0; j < m; ++j) {
            cout << room[i][j] << " ";
        }
        cout << endl;
    }

    return maxTime;
}

int main() {
    int n=4, m=6;
    int si=2, sj=4;

    int minTime = computeMinTime(si, sj, n, m);

    cout << minTime << endl;

    return 0;
}