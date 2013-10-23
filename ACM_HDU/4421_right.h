#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define Maxn 1010
#define Maxm Maxn*Maxn
using namespace std;
int vi[Maxn],head[Maxn],dfn[Maxn],low[Maxn],e,n,lab,top,num,m,id[Maxn],Stack[Maxn],B[510][510];
struct Edge{
    int u,v,next;
}edge[Maxm];
void init()//初始化
{
    memset(vi,0,sizeof(vi));
    memset(head,-1,sizeof(head));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(id,0,sizeof(id));
    e=lab=top=num=0;
}
void add(int u,int v)//加边
{
    edge[e].u=u,edge[e].v=v,edge[e].next=head[u],head[u]=e++;
}
void Tarjan(int u)//找出强连通分支
{
    int i,j,v;
    //cout<<u<<endl;
    dfn[u]=low[u]=++lab;
    Stack[top++]=u;
    vi[u]=1;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(!dfn[v])
        {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        if(vi[v])
            low[u]=min(low[u],dfn[v]);
        
    }
    if(low[u]==dfn[u])
    {
        ++num;
        do{
            i=Stack[--top];
            vi[i]=0;
            id[i]=num;
        }while(i!=u);
    }
}
int Ok()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
            if(i==j&&(B[i][j]!=0||B[j][i]!=0))
                return 0;
            if(B[i][j]!=B[j][i])
                return 0;
        }
    return 1;
}
void buildGraphic(int k)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        {
            if(i%2==1&&j%2==1)
            {
                temp=(1<<k);
                if(B[i][j]&temp)
                {
                    add(i,j+n);
                    add(j,i+n);
                }
                else
                {
                    add(i+n,j);
                    add(j+n,i);
                    add(i,j);
                    add(j,i);
                    add(i+n,j+n);
                    add(j+n,i+n);
                }
            }
            else
                if(i%2==0&&j%2==0)
                {
                    temp=(1<<k);
                    if(B[i][j]&temp)
                    {
                        add(i,j+n);
                        add(j,i+n);
                        add(i,j);
                        add(j,i);
                        add(i+n,j+n);
                        add(j+n,i+n);
                    }
                    else
                    {
                        add(i+n,j);
                        add(j+n,i);
                    }
                }
                else
                {
                    temp=(1<<k);
                    if(B[i][j]&temp)
                    {
                        add(i,j+n);
                        add(j,i+n);
                        add(i+n,j);
                        add(j+n,i);
                    }
                    else
                    {
                        add(i,j);
                        add(j,i);
                        add(i+n,j+n);
                        add(j+n,i+n);
                    }
                }
        }
}
int solve(int k)
{
    int i,j;
    buildGraphic(k);
    for(i=0;i<2*n;i++)
    {
        if(!dfn[i])
            Tarjan(i);
    }
    for(i=0;i<n;i++)
    {
        if(id[i]==id[i+n])
            return 0;
    }
    return 1;
}
int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&B[i][j]);
        if(!Ok())
        {
            printf("NO\n");
            continue;
        }
        int k;
        for(k=0;k<=31;k++)//每次取出一个二进制位，进行2-SAT判定
        {
            init();
            if(!solve(k))
                break;
        }
        if(k<=31)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}