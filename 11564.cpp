
#include "iostream"
using namespace std;

int dx[] = { 0,1,0,-1 },
        dy[] = { 1,0,-1,0 };
int matrix[6][6]={0};
bool visited[6][6]={0};
bool isInsideGrid(int x, int y) {
    return (x >= 0 && x < 6 && y >= 0 && y < 6);
}
int dfs(int fromx, int fromy, int tox, int toy, int status) {
    if (fromx == tox && fromy == toy)
        return 0;
    //深度优先搜索
    visited[fromx][fromy] = true;
    int minDis=100000;
    for (int i = 0; i < 4; i++) {
        if (isInsideGrid(fromx+dx[i],fromy+dy[i])&&!visited[fromx+dx[i]][fromy+dy[i]]) {
            int dis = matrix[fromx + dx[i]][fromy + dy[i]] * status,
                    ans = dfs(fromx + dx[i], fromy + dy[i], tox, toy, dis % 4 + 1)+dis;
            if (minDis > ans) minDis = ans;
        }
    }
    //回溯
    visited[fromx][fromy] = false;
    return minDis;
}

int main() {
    int n;
    cin >> n;

    for (; n > 0; n--) {

        int fromx, fromy, tox, toy;
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                cin >> matrix[i][j];
        cin >> fromx >> fromy >> tox >> toy;

        //深度优先搜索
        cout << dfs(fromx, fromy, tox, toy, 1) << endl;
    }

    return 0;
}