#include <iostream>
using namespace std;

#define ll long long
ll n,a,ans,sum;

int main(){
    cin>>n;
    for(ll i=1;i<=n;++i){
        cin>>a;
        if(sum+a>0) sum+=a;
        else sum=0;
        ans=ans>sum?ans:sum;
    }
    cout<<ans<<endl;
    return 0;
}