#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

int a,b,c,d,ans;
int dir[8][2]={
    {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}
};
int v[8][8];

bool check(int x,int y){
    return (x>=0&&x<=7&&y>=0&&y<=7&&(!v[x][y]));
}

struct node{
    int x,y,id;
};

int bfs(int x,int y){
    if(x==c&&y==b) return 0;
    v[x][y]=1;
    int cnt=1;
    queue<node>q;
    q.push((node){x,y,0});
    while(!q.empty()){
        node tmp=q.front();
        q.pop();
        for(int i=0;i<=7;++i){
            int x1=tmp.x+dir[i][0],y1=tmp.y+dir[i][1];
            if(check(x1,y1)){
                if(x1==c&&y1==d) return tmp.id+1;
                v[x1][y1]=1;
                q.push((node){x1,y1,tmp.id+1});
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d%d%d%d",&a,&b,&c,&d);
    a--;b--;c--;d--;
    printf("%d\n",bfs(a,b));
    return 0;
}