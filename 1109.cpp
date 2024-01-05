#include <iostream>
using namespace std;
class binaryTree{
    struct node{
        string value;
        int time;
        node* left=NULL;
        node* right=NULL;
        node* parent;
        node(string x,node* y){
            time = 0;
            value = x;
            parent = y;
        }
    };
    node* base;

    int middle(node* root){
        if(root==NULL) return 0;//终点
        middle(root->left);
        cout<<root->value<<" ";
        middle(root->right);
        return 1;
    }
    int back(node* root){
        if(root==NULL) return 0;//终点
        back(root->left);
        back(root->right);
        cout<<root->value<<" ";
        return 1;
    }
    void deletenode(node* n){
        if(n->left) deletenode(n->left);
        if(n->right) deletenode(n->right);
        delete n;
    }
    public:
        void initialize(){
            string s;
            //防止空树
            cin>>s;
            base = new node(s,NULL);
            node* temp = base;
            while(cin>>s){
                if(s=="."){
                    if(temp->time==0) temp->time++;
                    else{
                        //挂满了重新找可挂节点
                        temp->time++;
                        while(true){
                            if(temp==NULL) break;//头结点挂满
                            int time = temp->time;
                            if(time==0||time==1) break; 
                            else if(time==2) temp=temp->parent;
                        }
                    }    
                }
                else{
                    node* new_node = new node(s,temp);
                    if(temp->time) temp->right = new_node;
                    else temp->left = new_node;
                    temp->time++;
                    temp = new_node;
                }
            }
        }
        ~binaryTree(){
            deletenode(base);
        }
        void middleTrav(){
            middle(base);
            cout<<endl;
        }
        void backTrav(){
            back(base);
            cout<<endl;
        }

};
int main(){
    binaryTree extree;
    extree.initialize();
    extree.middleTrav();
    extree.backTrav();
    return 0;
}