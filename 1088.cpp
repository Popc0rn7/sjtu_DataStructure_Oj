#include <iostream>
using namespace std;

int solution(int n,int m,int cord,int d){
    int x = 0,k = 0;
    if (n==1) return 0;
    else {
        if (d==1){
            x = cord+m-1;
        }
        else{
            x = n-1-cord+m-1;
        }
        if (x/(n-1)%2) d=-d;

        if (d==1) k = x%(n-1);
        else k = n-1-(x%(n-1));

        if (d==-1) cord=k-1;
        else cord = k;

        int ans = solution(n-1,m,cord,d);//递归更新cord、d以及数列
        return (ans>=k)?ans+1:ans;
    }
}
int main(){
    int m,n,d=1,cord = 0;
    cin>>n>>m;
    cout<<solution(n,m,cord,d)+1;
    return 0;
}
