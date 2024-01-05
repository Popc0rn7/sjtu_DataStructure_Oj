#include <iostream>
using namespace std;
struct edge
{
    int v;//这条边终点
    int next;//下一条边储存下标
    int w = 0;//权值
};
edge edges[1000003];
int num = 0;
int head[1000003];
inline void add(int u, int m, int w){
    ++num;
    edges[num] = {m, head[u], w};
    head[u] = num;
}
struct node{
    int depth = 0;
    int total = 0;
};
node tree[1000003];
int ancestor[1000003][20];
// for(int i=head[u];i!=0;i=edges[i].next)   遍历以u为起点的边
void create(int root, int father){
    for (int j = head[root]; j!=0; j = edges[j].next)
    {
        const edge cur_edge = edges[j];
        const int cur_son = cur_edge.v;
        if (cur_son == father) { continue; }
        tree[cur_son] = {
                tree[root].depth + 1,
                tree[root].total + cur_edge.w,
        };
        ancestor[cur_son][0] = root;
        int ancestor_ = root;
        for (int i = 1; i < 20; i++)
        {
            ancestor_ = ancestor[ancestor_][i - 1];
            if (ancestor_ == 0)
            {break;}
            ancestor[cur_son][i] = ancestor_;
        }
        create(cur_son, root);
    }
}
int find(int x1, int x2){
    if (tree[x1].depth < tree[x2].depth)
    {
        swap(x1, x2);
    }
    int gap = tree[x1].depth - tree[x2].depth;
    for (int i = 0; gap; i++, gap >>= 1)
    {
        if (gap & 1)
        {
            x1 = ancestor[x1][i];
        }
    }
    if (x1 == x2){
        return x1;
    }
    for (int i = 20 - 1; i >= 0; i--){
        if (ancestor[x1][i] != ancestor[x2][i])
        {
            x1 = ancestor[x1][i];
            x2 = ancestor[x2][i];
        }
    }
    return ancestor[x1][0];
}
int cal(int x1, int x2){
    auto x3 = find(x1, x2);
    return tree[x1].total + tree[x2].total - tree[x3].total * 2;
}
int main(){   
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    create(1, 0);
    int m;
    cin >> m;
    while (m--){
        int u, v;
        cin >> u >> v;
        cout << cal(u, v) <<endl;
    }
}