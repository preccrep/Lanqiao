#include <iostream>
#include <cstdio>
using namespace std;

#define MOD 1000000007
int n,m;
int board[110][110];
int v[110][110];
int d[4][2]={{-2,-1},{-1,-2},{-1,2},{-2,1}};

int getval(int x1,int y1){
    if(v[x1][y1]){
        // cout<<x1<<" "<<y1<<endl;
        return 0;
    }
    for(int i=0;i<4;++i){
        int tx=x1+d[i][0],ty=y1+d[i][1];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&(!v[tx][ty])){
            if(!board[tx][ty]) board[x1][y1]=(board[x1][y1]+getval(tx,ty))%MOD;
            else board[x1][y1]=(board[x1][y1]+board[tx][ty])%MOD;
        }
    }
    if(!board[x1][y1]){
        v[x1][y1]=1;
        // cout<<x1<<" "<<y1<<endl;
    }
    return board[x1][y1]%MOD;
}

int main(){
    scanf("%d%d",&n,&m);
    board[1][1]=1;
    printf("%d\n",getval(n,m));
    return 0;
}