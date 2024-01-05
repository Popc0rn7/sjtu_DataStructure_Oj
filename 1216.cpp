#include <iostream>
using namespace std;
class Stack{
    int top;
    char* head;

    public:
    Stack(int n){
        top=-1;
        head = new char[n+1];
    }
    ~Stack(){
        delete []head;
    }
    void pop(){
        if(top>=0) top--;
    }
    void push(char c){
        head[++top]=c;
    }
    int returntop(){
        return top;
    }
    char top_ch(){
        if(top<0) return 0;
        else return head[top];
    }

};
int main(){
    int n,m,top=-1;
    bool whether_match[1000001];
    char bracket[1000001];
    cin>>n;
    Stack match(n);
    while(n-->0){
        cin>>m;
        if(m==1){
            char temp;
            cin>>temp;
            bracket[++top]=temp;
            char tc =match.top_ch();
            if(temp==')'&&tc=='(') {match.pop();whether_match[top]=true;}
            else if(temp=='}'&&tc=='{') {match.pop();whether_match[top]=true;}
            else if(temp==']'&&tc=='[') {match.pop();whether_match[top]=true;}
            else {match.push(temp);whether_match[top]=false;}
        }
        else if(m==2){
            if(top>=0){
                if(whether_match[top]){
                    if(bracket[top]==')') match.push('(');
                    if(bracket[top]==']') match.push(']');
                    if(bracket[top]=='}') match.push('{');
                }
                else match.pop();
                top--;
            }
        }
        else if(m==3){
            if(top>=0) cout<<bracket[top]<<endl;
        }
        else if(m==4){
            if(match.returntop()<0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}