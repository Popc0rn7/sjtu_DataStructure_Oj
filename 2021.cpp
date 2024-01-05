#include <iostream>
using namespace std;
void bubble(int* & group,int size){

}
bool check_1(int* group,int size){
    bubble(group,size);
}
bool check_2(int* group,int size){
    bubble(group,size);
    int i=0;
    while(i<size){
        group
    }
}
bool check(int* group1,int* group2,int* group3,int size_1,int size_2){

}
int main(){
    int num[14];
    char ch[14];
    char c;
    int A[10],B[10],C[10];
    int size_a=0,size_b=0,size_c=0;
    for (int i=0;i<14;i++){
        cin>>num[i];
        cin>>c;
        ch[i]=c;
        if(c=='A') A[size_a++]=i;
        else if(c=='B') B[size_b++]=i;
        else C[size_c++]=i;
    }
    
    if(size_a/3==2&&size_b==0){
        if(check_1(A,size_a)){
            if(check_2(B,size_b)){
                if(check_2(C,size_c)){
                    return 1;
                }
                else return 0;
            }
            else return 0;
        }
        else return 0;
    }
    else if (size_b/3==2&&size_a==0){
        if(check_1(B,size_a)){
            if(check_2(A,size_b)){
                if(check_2(C,size_c)){
                    return 1;
                }
                else return 0;
            }
            else return 0;
        }
        else return 0;
    }
    else if (size_c/3==2&&size_b==0){
        if(check_1(C,size_a)){
            if(check_2(B,size_b)){
                if(check_2(A,size_c)){
                    return 1;
                }
                else return 0;
            }
            else return 0;
        }
        else return 0;
    }
    else return 0;
}