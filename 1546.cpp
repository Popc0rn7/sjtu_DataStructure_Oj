//
// Created by Administrator on 2023/12/21.
//
#include <iostream>
using namespace std;
class SortHeap{
public:
    SortHeap(){
        int n;
        cin>>n;
        length = n;
        size = n;
        heap = new int[n+1];
        for(int i=1;i<=n;i++){
            cin>>heap[i];
        }
        buildHeap();
    }
    void printHeap(){
        for(int i=1;i<=length;i++){
            cout<<heap[i]<<' ';
        }
        cout<<endl;
    }
    void sort(){
        while(length>0)
            heap[length]=deQueue();
        for(int i=1;i<=size;i++)
            cout<<heap[i]<<' ';
    }
private:
    int length;
    int size;
    int *heap;
    void buildHeap(){
        for(int i=length;i>=1;i--)
            perlocateDown(i);
    }
    void perlocateDown(int i){
        int hole = i,child;
        int value = heap[hole];
        while(hole*2<=length){
            child = hole*2;
            if(child<length && heap[child]<heap[child+1]) child++;
            if(heap[child]>value){
                heap[hole] = heap[child];
                hole = child;
            }
            else break;
        }
        heap[hole] = value;
    }
    int deQueue(){
        int toReturn = heap[1];
        heap[1] = heap[length--];
        perlocateDown(1);
        return toReturn;
    }
};
int main(){
    SortHeap myHeap;
    myHeap.printHeap();
    myHeap.sort();
}