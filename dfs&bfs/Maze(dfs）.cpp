#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int m,n;
char mp[25][25];
int vis[25][25];
int totalKey[10];
int dir[4][2]={1,0,-1,0,0,-1,0,1};
int flag=false;
int sx,sy;
void deal(char ch)
{
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mp[i][j]==ch)
                mp[i][j]='.';
        }
    }
    memset(vis,0,sizeof(vis));
}
void dfs(int x,int y)
{
    for(int i=0;i<4;i++){
        int newx=x+dir[i][0];
        int newy=y+dir[i][1];
 if(newx<0||newx>=m||newy<0||newy>=n||vis[newx][newy]||mp[newx][newy]=='X'||mp[newx][newy]>='A'&&mp[newx][newy]<='E')continue;

        if(mp[newx][newy]=='G'){flag=true;return;}

        if(mp[newx][newy]=='.'){
                vis[newx][newy]=1;
                dfs(newx,newy);
        }

        if(islower(mp[newx][newy])){
            totalKey[mp[newx][newy]-'a']--;
            if(totalKey[mp[newx][newy]-'a']){
                mp[newx][newy]='.';
                vis[newx][newy]=1;
                dfs(newx,newy);
            }else{
                deal(toupper(mp[newx][newy]));
                mp[sx][sy]='.';
                dfs(sx,sy);
            }


        }

    }
}
int main()
{
    while(~scanf("%d%d",&m,&n)&&m+n){
        flag=false;
        memset(vis,0,sizeof(vis));
        memset(totalKey,0,sizeof(totalKey));

        for(int i=0;i<m;i++){
            scanf("%s",mp[i]);
            for(int j=0;j<n;j++){
                if(mp[i][j]=='S')
                    sx=i,sy=j;
                else if(islower(mp[i][j]))
                    totalKey[mp[i][j]-'a']++;
            }
        }
        vis[sx][sy]=1;
        dfs(sx,sy);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
