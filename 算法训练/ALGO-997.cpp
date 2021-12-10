#include <bits/stdc++.h>
using namespace std;

#define ll long long
int n,m,cnt,tmp;
ll len[10],small[10],sum,a,max_len,min_len;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",&len[i]);
        sum+=len[i];
    }
    //m=1可以特判，答案是0
    a=sum/m;
    int index=0;
    max_len=INT_MIN,min_len=INT_MAX;
    for(int i=1;i<=n;++i){
        if(len[i]>=a){
            cnt++;
            max_len=max(max_len,len[i]);
            min_len=min(min_len,len[i]);
        }else small[++index]=len[i];
    }
    if(m==cnt) printf("0\n");
    else{
        cnt=m-cnt;
        if(index==cnt){
            for(int i=1;i<=index;++i){
                max_len=max(max_len,small[i]);
                min_len=min(min_len,small[i]);
            }
            printf("%lld\n",max_len-min_len);
        }else{
            sort(small+1,small+1+index);
            tmp=index-cnt;
            int i1=tmp+1,i2=tmp;
            while(i2>=1){
                if(i1+1>index) small[i1]+=small[i2--];
                else{
                    while(small[i1]<=small[i1+1]&&i1+1<=index&&i2>=1){
                        small[i1]+=small[i2--];
                    }
                }
                sort(small+1+tmp,small+1+index);
                i1=tmp+1;
            }
            for(int i=tmp+1;i<=index;++i){
                max_len=max(max_len,small[i]);
                min_len=min(min_len,small[i]);
            }
            printf("%lld\n",max_len-min_len);
        }
    }
    return 0;
}