// http://lx.lanqiao.cn/problem.page?gpid=T3002http://lx.lanqiao.cn/problem.page?gpid=T3002

#include <cstdio>

float dp[21][21];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    if(m<n) printf("%.4f\n",0.0);
    else{
        //dp[i][j]表示买到第i个印章时,已经有的i个印章中共有j种类型的概率
        //dp[i+1][j]=dp[i][j]*(j/n), 第i+1个买到了已经有的j种类型中的1个
        //dp[i+1][j+1]=dp[i][j]*(1-(j-1)/n), 第i+1个买到了新的类型,即剩下n-(j-1)个中的1个,概率为[n-(j-1)]/n=1-(j-1)/n
        //1<=i<=m,1<=j<=n
        dp[0][0]=1.0;
        for(int i=1;i<=m;i++)
            dp[0][i]=0.0;
        for(int i=1;i<=n;i++)
            dp[i][0]=0.0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i>=j){
                    float factor1=1.0*j/n,factor2=1.0-(j-1.0)/n;
                    dp[i][j]=dp[i-1][j]*factor1+dp[i-1][j-1]*factor2;
                }
            }
        }
        printf("%.4f",dp[m][n]);
    }
    return 0;
}