
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
        tmpVisited = new bool*[n];
        for(int i=0;i<n;i++){
            graph[i]= new char[m];
            isVisited[i] = new bool[m];
            tmpVisited[i] = new bool[m];
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
            else unct[++unct_num] = {row,column};
            if(isConnect(row+1,column)) Stack[++top] = {row+1,column};
            if(isConnect(row-1,column)) Stack[++top] = {row-1,column};
            if(isConnect(row,column+1)) Stack[++top] = {row,column+1};
            if(isConnect(row,column-1)) Stack[++top] = {row,column-1};
        }
        if(land_touched==land_num){
            //cout<<"Possible"<<endl;
            if(check_ambiguous()) cout<<"Ambiguous"<<endl;
            else{
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(isVisited[i][j]) cout<<'.';
                        else cout<<'#';
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
    bool **tmpVisited;
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

        while(unct_num>0){
            //cout<<unct_num<<' ';
            cd Stack[3000];
            int top = 0;
            Stack[top]= {start_land.row,start_land.column};
            int land_touched =0;

            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++) tmpVisited[i][j] = false;

            tmpVisited[unct[unct_num].row][unct[unct_num].column] = true;
            unct_num--;
            //cout<<"About to loop"<<endl;
            while(top>=0){
                int row = Stack[top].row;
                int column = Stack[top].column;
                if(tmpVisited[row][column]) {top--;continue;}

                tmpVisited[row][column]=true;
                if(graph[row][column]=='.') land_touched++;
                top--;

                if(isConnect(row+1,column)) Stack[++top] = {row+1,column};
                if(isConnect(row-1,column)) Stack[++top] = {row-1,column};
                if(isConnect(row,column+1)) Stack[++top] = {row,column+1};
                if(isConnect(row,column-1)) Stack[++top] = {row,column-1};
            }
            //cout<<"check feasible"<<endl;
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