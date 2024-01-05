#include <iostream>
using namespace std;
int matrix[6][6];
int value[6][6];
int value_[6][6];
int dx[] = { 0,1,0,-1 },
    dy[] = { 1,0,-1,0 };
struct node{
    int x=0;
    int y=0;
    int status=0;
    int value=0;
};
class SortHeap{
public:
    int length;

    SortHeap(int n){
        length = 0;
        heap = new node[4*n];
    }
    void printHeap(){
        for(int i=1;i<=length;i++){
            cout<<heap[i].value<<' ';
        }
        cout<<endl;
    }
    void enQueue(node newN){
        int insert = ++length;
        while(insert>1){
            if(heap[insert/2].value>newN.value) break;
            heap[insert] = heap[insert/2];
            insert = insert/2;
        }
        heap[insert] = newN;
    }
    node deQueue(){
        node toReturn = heap[1];
        node sub = heap[length--];
        int hole = 1,child;
        while(hole*2<=length){
            child = hole*2;
            if(child<length && heap[child].value<heap[child+1].value) child++;
            if(heap[child].value>sub.value){
                heap[hole] = heap[child];
                hole = child;
            }
            else break;
        }
        heap[hole] = sub;
        return toReturn;
    }
private:
    node *heap;

};
bool isInsideGrid(int x, int y) {
    return (x >= 0 && x < 6 && y >= 0 && y < 6);
}
struct Stack{
    int top;
    node* stack;
    Stack(int n){
        stack = new node[4*n];
        top=-1;
    }
    node pop(){
        return stack[top--];
    }
    void push(node n){
        stack[++top] = n;
    }
};
int solution(int x1,int y1,int x2,int y2){
    SortHeap heap(100);
    node tmp = {x1,y1,1,0};
    heap.enQueue(tmp);
    value[x1][y1] = 0;
    while(heap.length>0){
        tmp = heap.deQueue();
        for(int i=0;i<4;i++){
            int x_ = tmp.x+dx[i],y_ = tmp.y+dy[i];
            if(isInsideGrid(x_,y_)){
                node son = {x_,y_,(tmp.status%4+1),tmp.status*matrix[x_][y_]};
                if(son.status==1||son.status==2){
                    if(value[son.x][son.y] > son.value){
                        value[son.x][son.y] = son.value;
                        heap.enQueue(son);
                    }
                }
                else{
                    if(value_[son.x][son.y] > son.value){
                        value_[son.x][son.y] = son.value;
                        heap.enQueue(son);
                    }
                }
            }
        }
    }
    return (value[x2][y2] <= value_[x2][y2])?value[x2][y2]:value_[x2][y2];
}
int main(){
    int time;
    cin>>time;
    int x1,y1,x2,y2;
    while(time-->0){
        for(int i = 0;i<6;i++){
            for(int j=0;j<6;j++){
                cin>>matrix[i][j];
                value[i][j]=100000;
                value_[i][j]=100000;
            }
        }
        cin>>x1>>y1>>x2>>y2;
        cout<<solution(x1,y1,x2,y2)<<endl;
    }
}