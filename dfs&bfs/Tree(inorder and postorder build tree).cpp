#include<cstdio>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<string>
#include<iostream>
#define maxn 10010
using namespace std;
int in[maxn],post[maxn];
int lt[maxn],rt[maxn];
int ans=1000000000;
int res=1000000000;
int build(int l1,int r1,int l2,int r2)//l1,r1ÊÇÖÐÐò
{
    int root=post[r2];
    if(l1>r1) return 0;
    int cnt=0;
    while(in[l1+cnt]!=root)cnt++;
   // cout<<cnt<<endl;
    lt[root]=build(l1,l1+cnt-1,l2,l2+cnt-1);
    rt[root]=build(l1+cnt+1,r1,l2+cnt,r2-1);
    return root;
}
void dfs(int root,int sum)
{
    sum+=root;
    if(!lt[root]&&!rt[root]){
        if(sum<ans||(sum==ans&&root<res)){
            ans=sum;
            res=root;
        }
    }
    if(lt[root]){
        dfs(lt[root],sum);
        //sum-=tree[root*2];
    }
    if(rt[root]){
        dfs(rt[root],sum);
        //sum-=tree[root*2+1];
    }



}
int main()
{
    string line;
    int x,n=0;
    while(getline(cin,line)){
        ans=1000000000,res=1000000000;
        stringstream ss(line);
        while(ss>>x)
            in[n++]=x;
        n=0;
        line.clear();
        getline(cin,line);
        stringstream ss0(line);
        while(ss0>>x)
            post[n++]=x;
        //cout<<n<<endl;
        int root=build(0,n-1,0,n-1);
        //cout<<n<<endl;
        dfs(root,0);
        cout<<res<<endl;
        n=0;

    }
    return 0;
}
