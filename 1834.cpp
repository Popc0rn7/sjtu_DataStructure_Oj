//
// Created by Administrator on 2023/12/8.
//

#include <iostream>
using namespace std;

struct Student{
    int charm;
    Student *nxt= nullptr;
    Student(int c):charm(c){}
};

class Group{
private:
    bool checkEmpty(){
        if(head == nullptr) return true;
        return false;
    }

public:
    Student *head;

    Group(){
        head = nullptr;
    }

    void addStudent(int c){
        Student *newStudent = new Student(c);
        //insert
        Student *cur=head,*front = nullptr;
        while(cur!= nullptr){
            if(cur->charm >= c) break;

            front = cur;
            cur = cur->nxt;
        }
        if(!front) head = newStudent;
        else front->nxt = newStudent;
        newStudent->nxt = cur;
        //cout<<"Add "<<c<<" Successfully!"<<endl;
    }

    void combine(Group &g){
        Student *bHead = g.head;

        if(!head) { head = g.head;return; }
        if(!g.head) return;

        Student *newHead = nullptr,*tail = nullptr;
        while(head&&bHead){
            if(head->charm > bHead->charm) {
                if(!newHead) newHead=bHead;
                else tail->nxt = bHead;
                tail = bHead;
                bHead = bHead->nxt;
            }
            else{
                if(!newHead) newHead=head;
                else tail->nxt = head;
                tail = head;
                head = head->nxt;
            }
        }
        if(!head) tail->nxt = bHead;
        else tail->nxt = head;
        head = newHead;


        //cout<<"Combine Successfully!"<<endl;
    }

    int kickStudent(){
        if(checkEmpty()) return -1;
        Student *temp = head;
        int charm = temp->charm;
        head = head->nxt;
        delete temp;
        return charm;
    }

};

int main(){
    //cout<<"what's wrong"<<endl;
    int n,m,input;
    cin>>n>>m;
    Group *group = new Group[n];
    //cout<<"Initialize Successfully!"<<endl;
    for(int i=0;i<n;i++){
        cin>>input;
        group[i].addStudent(input);
    }
    while(m-->0){
        int a,b;
        cin>>input;
        if(input == 0){
            cin>>a>>b;
            group[a].combine(group[b]);
        }
        else if(input == 1){
            cin>>a;
            cout<<group[a].kickStudent()<<endl;
        }
        else if(input == 2){
            cin>>a>>b;
            group[a].addStudent(b);
        }
    }
}