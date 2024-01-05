#include <iostream>
using namespace std;
struct LinkedList {
    // todo: some variables here
    struct Node{
        int data;
        Node* next=NULL;
        Node(const int &x){
            data = x;next = NULL;
        }
    };
    Node* head = new Node(-1);
    int length;

    void initialize() {
        int n;
        Node* temp = head;
        cin>>n;
        length = n;
        int *a = new int[n];
        for(int i = 0; i < n; i++) cin>>a[i];
        for(int i=0;i<n;i++){
            Node* p = new Node(a[i]);
            temp->next = p;
            temp = p;
        }
        delete[] a;
    }

    Node* move(int i){
        Node* p=head;
        while(--i>=0) p=p->next;
        return p;
    }
    void insert(int i, int x) {
        // todo
        Node* p = new Node(x);
        Node* temp = move(i);
        p->next = temp->next;
        temp->next = p;
        length++;
    }

    void erase(int i) {
        // todo
        Node* temp = move(i-1);
        Node* p = temp->next;
        temp->next = p->next;
        delete p;
        length--;
    }

    void swap() {
        // todo
        Node* p1 = head;
        Node* p2 = p1->next;

        while(p2 != NULL&&p2->next != NULL){
            p1->next = p2->next;
            p2->next = p2->next->next;
            p1->next->next = p2;
            p1=p2;
            p2=p2->next;
        }
    }

    void moveback(int i, int x) {
        // todo
        Node* p = move(i+x);
        Node* q = move(i+1);
        move(i)->next =p->next;
        p->next = head->next;
        head->next = q;
    }

    int query(int i) {
        // todo
        return move(i)->data;
    }

    void printAll() {
        // todo
        Node* p = head->next;
        while(p!=NULL){
            cout<<p->data<<' ';
            p = p->next;
        }
        cout<<'\n';
    }

    void ClearMemory() {
        // todo
        Node* p = head->next;
        Node* temp = NULL;
        if (length>0) temp = p->next;
        while(p!=NULL){
            delete p;
            p= temp;
            if(temp!=NULL) temp = temp->next;
        }
    }
};

int main() {
    LinkedList List;
    int m, op, i, x;
    List.initialize();
    cin>>m;
    while(m--) {
        cin>>op;
        if(op == 1) {
            cin>>i>>x;
            List.insert(i, x);
        }
        else if(op == 2) {
            cin>>i;
            List.erase(i);
        }
        else if(op == 3) {
            List.swap();
        }
        else if(op == 4) {
            cin>>i>>x;
            List.moveback(i, x);
        }
        else if(op == 5) {
            cin>>i;
            cout<<List.query(i)<<'\n';
        }
        else if(op == 6) {
            List.printAll();
        }
    }
    List.ClearMemory();
    return 0;
}