/*
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
const int MAXN = 100100;
int c[2*MAXN][2];
int tree[MAXN][2];
map<int,int>mp;
vector<int>vv[MAXN];
int num[2*MAXN];
int w[MAXN];
bool vis[MAXN],judge[MAXN];
int tot;
struct query
{
    int x,u;
    int a,b;
}q[MAXN];
int lowbit(int x)
{
    return x&(-x);
}
void updata(int x,int p,int d)
{
    for(;x<=tot;x+=lowbit(x)) c[x][p]+=d;
}
int sum(int x,int p)
{
    int res=0;
    for(;x>0;x-=lowbit(x)) res+=c[x][p];
    return res;
}
void dfs(int u)
{
    int siz=(int)vv[u].size();
    for(int i=0;i<siz;i++)
    {
        int it=vv[u][i];
        int t=mp[q[it].x];
        
        printf("sum t-1 %d 0 = %d\n",t-1,sum(t-1,0));
        printf("sum t %d 0 = %d\n",t,sum(t,0));
        printf("sum t-1 %d 1 = %d\n",t-1,sum(t-1,1));
        printf("sum t   %d 1 = %d\n",t,sum(t,1));
        
        printf("tot %d 0 sum=%d\n",tot,sum(tot,0));
        printf("tot %d 1 sum=%d\n",tot,sum(tot,1));
        printf("\n");
        if(sum(t,0)-sum(t-1,0)||sum(t,1)-sum(t-1,1))
        {
            q[it].a=-1;
            q[it].b=-1;
            continue;
        }

        q[it].a=sum(t-1,1);
        q[it].b=sum(t-1,0)*3+(sum(tot,0)-sum(t,0))+sum(t-1,1)*3+(sum(tot,1)-sum(t,1));
        
    }
    if(tree[u][0])
    {
        int t=mp[w[u]];
        vis[t]=1;
        printf("add t=%d\n",t);
        updata(t,0,1);
        dfs(tree[u][0]);
        updata(t,0,-1);
        printf("delete t=%d\n",t);
        
        printf("add t=%d\n",t);
        updata(t,1,1);
        dfs(tree[u][1]);
        updata(t,1,-1);
        printf("delete t=%d\n",t);
        vis[t]=0;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        mp.clear();
        memset(c,0,sizeof(c));
        memset(tree,0,sizeof(tree));
        memset(vis,0,sizeof(vis));
        memset(judge,0,sizeof(judge));
        int n,m,Q;
        scanf("%d",&n);
        for(int i=0;i<=n;i++) vv[i].clear();
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&w[i]);
            num[cnt++]=w[i];
        }
        scanf("%d",&m);
        while(m--)
        {
            int u,a,b;
            scanf("%d%d%d",&u,&a,&b);
            tree[u][0]=a;
            tree[u][1]=b;
            vis[a]=1;
            vis[b]=1;
        }
        
        scanf("%d",&Q);
        tot=0;
        for(int i=1;i<=Q;i++)
        {
            //int v,x;
            scanf("%d%d",&q[i].u,&q[i].x);
            vv[q[i].u].push_back(i);
            num[cnt++]=q[i].x;
        }
        sort(num,num+cnt);
        for(int i=0;i<cnt;i++)
        {
            if(mp[num[i]]) continue;
            mp[num[i]]=++tot;
        }
        int u;
        for(int i=1;i<=n;i++) if(!vis[i])
        {
            u=i;
            break;
        }
        memset(vis,0,sizeof(vis));
        dfs(u);
        for(int i=1;i<=Q;i++)
        {
            if(q[i].a==-1&&q[i].b==-1) puts("0");
            else
            {
                printf("%d %d\n",q[i].a,q[i].b);
            }
        }
    }  
}
*/