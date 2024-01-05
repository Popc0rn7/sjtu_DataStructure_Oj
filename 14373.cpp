#include <iostream>
using namespace std;
class CQueue{
    private:
        int* base;
        int head=0,rear=0;
        int length;
        bool checkempty(){
            if(head==rear) return true;
            else return false;
        }
    public:
        CQueue(int s){
            base = new int[s+1];
            length = s+1;
        }
        ~CQueue(){
            delete base;
        }
        void enQueue(int x){
            base[rear++]=x;
            rear %= length;
            cout<<rear<<' '<<(rear-head)%length<<endl;
        }
        void deQueue(){
            if(!checkempty()) head = (head+1)%length;
            cout<<head<<' '<<(rear-head)%length<<endl;
        }
        /*int getHead(){
            return head;
        }*/
};
int main(){
    int m,n,x,s;
    cin>>s>>m;
    CQueue queue(s);
    while(m-->0){
        cin>>n;
        if(!n){
            cin>>x;
            queue.enQueue(x);
        }
        else queue.deQueue();
    }
    return 0;
}