#include <iostream>
#include <cstdio>
using namespace std;

#define ll long long
ll n,ans,tmp,tmp1;

ll calc(int a){
	ll b=n-a+1ll,cnt=1ll,cnt1=1ll;
	for(ll i=n;i>=b;--i){
		cnt*=i;
	}
	for(ll i=1;i<=a;++i){
		cnt1*=i;
	}
	return cnt/cnt1;
}

int main() {
	scanf("%lld",&n);
	ans=1ll+n*n;
	for(ll i=2;i<=n;++i){
		tmp=n,tmp1=n;
		for(ll j=1;j<i;++j){
			tmp*=(--tmp1);
		}
		ans+=tmp*calc(i);
	}
	printf("%d\n",ans);
	return 0;
}