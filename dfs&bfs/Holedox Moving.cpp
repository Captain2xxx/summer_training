#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>
int n,m,l;
using namespace std;
struct Snake{
    int x,y;
    int zt;
    int num;
}snake;
int mp[21][21];
int vis[21][21][1<<14];
int dir[4][2]={1,0,-1,0,0,-1,0,1};
queue<Snake> q;
bool check(Snake now,int nx,int ny)
{
    int t;
    int sx=now.x,sy=now.y;
    for(int i=1;i<l;i++){
        t=(now.zt>>((l-1-i)*2))&3;
        if(t==0) sx-=1;
        if(t==1) sx+=1;
        if(t==2) sy+=1;
        if(t==3) sy-=1;
        if(sx==nx&&sy==ny)
            return true;

    }
    return false;
}
int bfs()
{
    while(!q.empty())q.pop();
    q.push(snake);
    vis[snake.x][snake.y][snake.zt]=1;

    while(!q.empty()){
        Snake now=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            Snake next=now;
            next.x+=dir[i][0];
            next.y+=dir[i][1];
            next.zt>>=2;
            next.num++;
            if(dir[i][0]==1 && dir[i][1]==0) next.zt+=(0<<(l-2)*2);
            if(dir[i][0]==-1 && dir[i][1]==0) next.zt+=(1<<((l-2)*2));
            if(dir[i][0]==0 && dir[i][1]==-1) next.zt+=(2<<((l-2)*2));
            if(dir[i][0]==0 && dir[i][1]==1)  next.zt+=(3<<((l-2)*2));


            if(next.x<=0||next.x>n||next.y<=0||next.y>m||mp[next.x][next.y]||vis[next.x][next.y][next.zt])
                continue;
            if(check(now,next.x,next.y))
                continue;


            if(next.x==1&&next.y==1)
                return next.num;
            vis[next.x][next.y][next.zt]=1;
            q.push(next);

        }
}
    return -1;


}
int main()
{
    int cnt=0;
    while(~scanf("%d%d%d",&n,&m,&l)&&n+m+l){

        memset(vis,0,sizeof(vis));
        memset(mp,0,sizeof(mp));

        scanf("%d%d",&snake.x,&snake.y);
        snake.zt=0,snake.num=0;
        int tx=snake.x,ty=snake.y;
        for(int i = 1; i < l; i++){
            int x,y;
            scanf("%d%d",&x,&y);
            int dx = tx - x;
            int dy = ty - y;
            tx=x,ty=y;
            if(dx == 1 && dy == 0) snake.zt += 0;
            if(dx == -1 && dy == 0) snake.zt += 1;
            if(dx == 0 && dy == -1) snake.zt += 2;
            if(dx == 0 && dy == 1) snake.zt += 3;

            if(i!=l-1)
            snake.zt<<=2;
        }
int k;
        scanf("%d",&k);
        for(int i = 0; i < k; i++){
            int x,y;
            scanf("%d%d",&x,&y);
            mp[x][y]=1;
        }


        if(snake.x==1&&snake.y==1)
            printf("Case %d: %d\n",++cnt,0);
        else
            printf("Case %d: %d\n",++cnt,bfs());
    }
    return 0;
}
