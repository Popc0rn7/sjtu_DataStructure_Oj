#include <iostream>
//WRONG ANSWER!!
using namespace std;

int *p;
int k;

class uglyQueue{
private:
    struct node{
        int last_index=0;
        long long value=0;
    };
    node *ugly_heap;
    int heap_length;

    static void read(){
        for(int i=0;i<k;i++) {
            int temp,index = i;
            cin >> temp;
            //insert sort
            for(int j=i-1;j>=0;j--){
                if(temp<p[j]){
                    p[index]=p[j];
                    index=j;
                }
                else break;
            }
            p[index]=temp;
        }
        /*for(int i=0;i<k;i++){
            cout<<p[i]<<' ';
            cout<<endl;
        }*/
    }
    void percolateDown(const node &sub){
        int hole = 1;
        int child;
        long long newValue = sub.value*p[sub.last_index];
        for( ; hole * 2 <= heap_length; hole = child )
        {  child = hole * 2;
            if( child != heap_length && ugly_heap[ child + 1 ].value < ugly_heap[ child ].value )
                child++;
            if( ugly_heap[ child ].value < newValue )   ugly_heap[ hole ] = ugly_heap[ child ];
            else    break;
        }
        ugly_heap[hole] = {sub.last_index,newValue};
        //cout<<ugly_heap[hole].value<<' '<<hole<<endl;
    }
public:
    explicit uglyQueue(int n){
        read();
        ugly_heap = new node[2*n];
        heap_length = 1;
        ugly_heap[1]={0,p[0]};
        //cout<<ugly_heap[1].value<<" Successfully Initiallized!"<<endl;
    }
    long long deQueue(){
        node sub = ugly_heap[1];
        //substitute it with next time
        percolateDown(sub);
        //enQueue it with next digit and plus
        if(sub.last_index<k-1){
            enQueue(sub);
        }
        //for(int i=1;i<=heap_length;i++){ cout<<ugly_heap[i].value<<' ';}
        //cout<<endl;

        return sub.value;
    }
    void enQueue(const node &sub){
        int insert = ++heap_length;
        long long value = sub.value*p[sub.last_index+1]/p[sub.last_index];
        while(insert>1){
            if(ugly_heap[insert/2].value > value){
                ugly_heap[insert] = ugly_heap[insert/2];
                insert = insert/2;
            }
            else break;
        }
        ugly_heap[insert] = {sub.last_index+1,value};
        //cout<<ugly_heap[insert].value<<' '<<insert<<endl;
    }
    long long find_ugly(int n){
        long long value=0;
        for(int i=0;i<n;i++){
            value=deQueue();
            //cout<<"DeQueue "<<value<<endl;
        }
        //cout<<heap_length<<' ';
        return value;
    }
};
int main() {
    int n;
    cin>>k>>n;
    p = new int[k+1];
    uglyQueue u(n);
    cout<<u.find_ugly(n);
    return 0;
}