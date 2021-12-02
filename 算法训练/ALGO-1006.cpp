//http://lx.lanqiao.cn/problem.page?gpid=T3000
#include <cstdio>
#include <algorithm>

int n,x;
int dp[2][1001];

int main() {
    x=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            scanf("%d",&dp[x][j]);
        for(int j=1;j<=n;j++)
            dp[x][j]+=std::max(dp[x][j-1],dp[!x][j]);
        x=!x;
    }
    printf("%d\n",dp[!x][n]);
    return 0;
}