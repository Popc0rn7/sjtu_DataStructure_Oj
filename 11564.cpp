//
// Created by Administrator on 2023/12/31.
//
#include <iostream>
using namespace std;
int matrix[6][6];
int value[6][6];
struct node{
    int x=0;
    int y=0;
    int status=0;
    int value=0;
    node getSon(int type){
        int x_=x,y_=y,status_ = status%4+1;
        if(type == 1){
            x_ = x+1;
        }
        else if(type == 2){
            x_ = x -1;
        }
        else if(type == 3){
            y_ = y+1;
        }
        else if(type == 4){
            y_ = y-1;
        }
        node son ={x_,y_,status_,value+status*matrix[x_][y_]};
        return son;
    }
};
class SortHeap{
public:
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
    int returnlength() const { return length; }
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
    int length;
    node *heap;

};
bool isInsideGrid(int x, int y) {
    return (x >= 0 && x < 6 && y >= 0 && y < 6);
}
int solution(int x1,int y1,int x2,int y2){
    SortHeap heap(36);
    node tmp = {x1,y1,1,0};
    heap.enQueue(tmp);
    value[x1][y1] = 0;
    while(heap.returnlength()>0){
        tmp = heap.deQueue();
        if(isInsideGrid(tmp.x+1,tmp.y)){
            node son = tmp.getSon(1);
            if(value[son.x][son.y] > son.value){
                value[son.x][son.y] = son.value;
                heap.enQueue(son);
            }
        }
        if(isInsideGrid(tmp.x-1,tmp.y)){
            node son = tmp.getSon(2);
            if(value[son.x][son.y]>son.value){
                value[son.x][son.y] = son.value;
                heap.enQueue(son);
            }
        }
        if(isInsideGrid(tmp.x,tmp.y+1)){
            node son = tmp.getSon(3);
            if(value[son.x][son.y]>son.value){
                value[son.x][son.y]=son.value;
                heap.enQueue(son);
            }
        }
        if(isInsideGrid(tmp.x,tmp.y-1)){
            node son = tmp.getSon(4);
            if(value[son.x][son.y]>son.value){
                value[son.x][son.y]=son.value;
                heap.enQueue(son);
            }
        }
    }
    return value[x2][y2];
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
            }
        }
        cin>>x1>>y1>>x2>>y2;
        cout<<solution(x1,y1,x2,y2)<<endl;
    }
}
