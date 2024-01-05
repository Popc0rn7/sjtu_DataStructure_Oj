/*
#include <iostream>
#include <vector>

using namespace std;

bool isInsideGrid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool isFourConnected(vector<vector<char>>& grid, int x, int y, int n, int m) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    visited[x][y] = true;
    int connected = 1;

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isInsideGrid(newX, newY, n, m) && !visited[newX][newY] && grid[newX][newY] == '.') {
            visited[newX][newY] = true;
            connected++;
        }
    }

    return (connected == 4);
}

void dfs(vector<vector<char>>& grid, int x, int y, int n, int m) {
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    if (!isInsideGrid(x, y, n, m) || grid[x][y] != '?') {
        return;
    }

    grid[x][y] = '.';

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        dfs(grid, newX, newY, n, m);
    }
}

string solve(vector<vector<char>>& grid, int n, int m) {
    bool ambiguous = false;
    bool hasUnknown = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '?') {
                grid[i][j] = '.';
                dfs(grid, i, j, n, m);

                if (!isFourConnected(grid, i, j, n, m)) {
                    return "Impossible";
                }

                ambiguous |= (grid[i][j] == '?');
                hasUnknown = true;
            }
        }
    }

    if (ambiguous) {
        return "Ambiguous";
    } else if (hasUnknown) {
        return "Impossible";
    } else {
        return "Possible";
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    string result = solve(grid, n, m);

    if (result == "Ambiguous" || result == "Impossible") {
        cout << result << endl;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
*/

// Created by Administrator on 2023/12/29.
//
#include <iostream>
using namespace std;
struct cd{
    int row = 0;
    int column = 0;
};
class Graph{
public:
    Graph(){
        cin>>n>>m;
        land_num = 0;
        unct_num = 0;

        graph = new char*[n];
        isVisited = new bool*[n];
        for(int i=0;i<n;i++){
            graph[i]= new char[m];
            isVisited[i] = new bool[m];
            for(int j=0;j<m;j++){
                cin>>graph[i][j];
                isVisited[i][j] = false;
                if(graph[i][j]=='.'){
                    land_num++;
                    start_land = {i,j};
                }
            }
        }
    }
    void check_possible(){
        int land_touched =0;
        int row = start_land.row;
        int column = start_land.column;

        cd Stack[3000];
        int top = 0;
        Stack[top]= {row,column};

        while(top>=0){
            row = Stack[top].row;
            column = Stack[top].column;
            top--;
            if(isVisited[row][column]) continue;

            isVisited[row][column]=true;
            if(graph[row][column]=='.') land_touched++;
            else unct[unct_num++] = {row,column};
            if(isConnect(row+1,column)) Stack[++top] = {row+1,column};
            if(isConnect(row-1,column)) Stack[++top] = {row-1,column};
            if(isConnect(row,column+1)) Stack[++top] = {row,column+1};
            if(isConnect(row,column-1)) Stack[++top] = {row,column-1};
        }
        if(land_touched==land_num){
            if(check_ambiguous()) cout<<"Ambiguous"<<endl;
            else{
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(isVisited[i][j]) cout<<'.'<<' ';
                        else cout<<'#'<<' ';
                    }
                    cout<<endl;
                }
            }
        }
        else cout<<"Impossible"<<endl;
    }
private:
    int n,m;
    char **graph;
    bool **isVisited;
    cd unct[2000];
    int unct_num;
    int land_num;
    cd start_land;

    bool isInsideGrid(int x, int y) const {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    bool isConnect(int x,int y){
        if(!isInsideGrid(x,y)) return false;
        if(graph[x][y]=='.'||graph[x][y]=='?') { return true; }
        return false;
    }

    bool check_ambiguous(){

        while(unct_num>=0){

            cd Stack[3000];
            int top = 0;
            Stack[top]= {start_land.row,start_land.column};
            int land_touched =0;

            bool **Visited = new bool*[n];
            for(int i=0;i<n;i++){
                Visited[i] = new bool[m];
                for(int j=0;j<m;j++) Visited[i][j] = false;
            }
            Visited[unct[unct_num].row][unct[unct_num].column] = true;
            unct_num--;

            while(top>=0){
                int row = Stack[top].row;
                int column = Stack[top].column;
                if(Visited[row][column]){top--;continue;}
                Visited[row][column]=true;
                if(graph[row][column]=='.') land_touched++;
                top--;

                if(isConnect(row+1,column)) Stack[++top] = {row+1,column};
                if(isConnect(row-1,column)) Stack[++top] = {row-1,column};
                if(isConnect(row,column+1)) Stack[++top] = {row,column+1};
                if(isConnect(row,column-1)) Stack[++top] = {row,column-1};
            }
            if(land_touched==land_num) return true;
        }
        return false;
    }
};



int main(){
    Graph graph;
    graph.check_possible();
    return 0;
}