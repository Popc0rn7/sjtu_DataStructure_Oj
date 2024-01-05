#include <iostream>
using namespace std;
class binaryTree{
    private:
    struct node{
        int left;
        int right;
        void initialize(int l,int r){
            left=l;
            right=r;
        }
        void swap(){
            int temp = left;
            left = right;
            right = temp;
        }
    };
    node profile[1025];
    int root=1,swap_level=0;

    struct son{
            int num=0;
            son* bro=NULL;
            son(int n):num(n){}
        };

    void middle(int root,int level){
        if(root==-1) return;//жу╣Ц
        if(level%swap_level==0){
            profile[root].swap();
        }
        middle(profile[root].left,level+1);
        cout<<root<<" ";
        middle(profile[root].right,level+1);
    }

    public:
    void read(int i,int a,int b){
        profile[i].initialize(a,b);
    }
    void midTraverse(int k){
        swap_level=k;
        middle(root,1);
        cout<<endl;
    }
    
};
int main(){
    int n,a,b,k;
    cin>>n;
    binaryTree tree;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        tree.read(i+1,a,b);
    }
    cin>>n;
    while(n-->0){
        cin>>k;
        tree.midTraverse(k);
    }
    
}