//http://lx.lanqiao.cn/problem.page?gpid=T2995
#include <cstdio>
#include <algorithm>

#define ll long long
ll len,sum;
ll combi[10];
int a[10];

ll combinatorial(ll n,ll m){
    ll ans=1,tmp=1;;
    for(ll i=n;i>=n-m+1;i--)
        ans*=i;
    for(ll i=m;i>=1;i--)
        tmp*=i;
    return ans/tmp;
}

int main() {
    scanf("%lld%lld",&len,&sum);
    for(int i=0;i<len;i++)
        combi[i]=combinatorial(len-1,i);
    ll ans=0;
    for(int i=0;i<len;i++)
        a[i]=i+1;
    do{
        ll cnt=0;
        for(int i=0;i<len;i++)
            cnt+=combi[i]*a[i];
        if(cnt==sum){
            for(int i=0;i<len-1;i++)
                printf("%d ",a[i]);
            printf("%d\n",a[len-1]);
            break;
        }
    }while(std::next_permutation(a,a+len));
    return 0;
}