#include <iostream>
using namespace std;
class CutTree{
private:
    struct Node {
        int value = 0;
        int left = 0;
        int right = 0;
        void initialize(int v,int l,int r){
            value=v;left=l;right=r;
        }
    };
    Node tree[60000];
    bool flag = false;
    int input=0,index=0;

public:
    int buildTree(int root){
        if(flag) return -1;
        cin>>input;
        if(input == -1) return -1;
        if(input == -2){
            flag = true;
            return -1;
        }

        else{
            int value=input;

            int left = buildTree(++index);
            int right = buildTree(++index);
            tree[root].initialize(value,left,right);

            if(left==-1&&right==-1&&value==0) return -1;
            else return root;
        }
    }
    void preOrder(int root){
        cout<<tree[root].value<<' ';
        if(tree[root].left != -1) preOrder(tree[root].left);
        else cout<<-1<<' ';
        if(tree[root].right != -1) preOrder(tree[root].right);
        else cout<<-1<<' ';
    }

};

int main() {
    CutTree cutTree;
    cutTree.buildTree(0);
    cutTree.preOrder(0);
    return 0;
}