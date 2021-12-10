#include <iostream>
#include <algorithm>
using namespace std;

#define N 33000
int n,ans;
int arr[N];

int main(){
    ans=INT_MIN;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>arr[1<<i];
    for(int i=0;i<(1<<n);++i){
        for(int j=0;j<n;++j){
            if((i&(1<<j))==0) continue;
            arr[i]=arr[i-(1<<j)]+arr[1<<j];
            break;
        }
    }
    for(int i=1;i<(1<<n);++i){
        int j=(1<<n)-i-1;
        for(int k=j;k>0;k=(k-1)&j){
            if(arr[k]==arr[i])
                ans=max(ans,arr[k]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
