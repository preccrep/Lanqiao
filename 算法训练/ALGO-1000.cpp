#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <numeric>
using namespace std;

#define ll long long
ll n,m;
ll a[1000];
ll sum;

int main(){
    scanf("%lld%lld",&n,&m);
    for(ll i=0;i<n;++i)
        scanf("%lld",&a[i]);
    if(m>=n) m=n;
    sort(a,a+n,greater<int>());
    for(int i=0;i<m;++i)
        sum+=a[i];
    printf("%lld\n",sum);
    return 0;
}