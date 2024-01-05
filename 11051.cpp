//
// Created by Administrator on 2023/12/21.
//
#include <iostream>
using namespace std;
struct node{
    long value=0;
    int nxt=-1;
};
int main(){
    int n,m,count=0;
    long input;
    cin>>n;
    node list[10001];
    int head = -1;
    for(int i=0;i<n;i++){
        cin>>input;
        if(!i) head=0;
        else list[i-1].nxt = i;
        list[i].value = input;
    }
    cin>>m;
    while(m-->0){
        cin>>input;
        int cur = head;
        int front = -1;
        while(cur!=-1){
            if(list[cur].value==input){
                if(cur != head){
                    list[front].nxt = list[cur].nxt;
                    list[cur].nxt = head;
                    head = cur;
                }
                count++;
                break;
            }
            front = cur;
            cur = list[cur].nxt;
            count++;
        }
    }
    cout<<count;
}