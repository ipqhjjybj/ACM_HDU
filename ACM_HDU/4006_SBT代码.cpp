/*
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
const int maxn = 100010;
#define ls T[x].l
#define rs T[x].r
#define lls T[ls].l
#define lrs T[ls].r
#define rls T[rs].l
#define rrs T[rs].r
struct SBT{
    //左子树指针，右子树指针，大小，键值
    int l,r,sz,key;
    void init(){
        l=r=key=0;
        sz=1;
    }
}T[maxn];
int root,tot; //根的位置以及节点个数
//左旋转处理
void l_rot(int &x){
    int k=rs;
    rs=T[k].l;
    T[k].l=x;
    T[k].sz=T[x].sz;
    T[x].sz=T[ls].sz+T[rs].sz+1;
    x=k;
}
//右旋转处理
void r_rot(int &x){
    int k=ls;
    ls=T[k].r;
    T[k].r=x;
    T[k].sz=T[x].sz;
    T[x].sz=T[ls].sz+T[rs].sz+1;
    x=k;
}
//调整处理
void maintain(int &x,bool flag){
    if(flag){  //更新右子树
        if(T[rrs].sz>T[ls].sz)
            l_rot(x);
        else if(T[rls].sz>T[ls].sz){
            r_rot(rs);
            l_rot(x);
        }
        else
            return;
    }
    else{   //更新在左子树
        if(T[lls].sz>T[rs].sz)
            r_rot(x);
        else if(T[lrs].sz>T[rs].sz){
            l_rot(ls);
            r_rot(x);
        }
        else
            return;
    }
    //更新子树，然后再更新根，直到平衡为止
    maintain(ls,false);
    maintain(rs,true);
    maintain(x,false);
    maintain(x,true);
}
//插入新节点
void insert(int &r,int k){
    if(r==0){
        r=++tot;
        T[r].init();
        T[r].key=k;
    }
    else{
        T[r].sz++;
        if(k<T[r].key)
            insert(T[r].l,k);
        else
            insert(T[r].r,k);
        //插入后要调整，保证平衡
        maintain(r,k>=T[r].key);
    }
}
//删除结点，利用的是前驱替换
int remove(int &r,int k){
    int d_key;
    if(!r)
        return 0;
    T[r].sz--;
    //前者说明就是要删的节点，后两者说明不存在此节点
    if(T[r].key==k||(T[r].l==0&&k<T[r].key)||(T[r].r==0&&k>T[r].key)){
        d_key=T[r].key;
        if(T[r].l&&T[r].r)
            T[r].key=remove(T[r].l,k+1);
        else
            r=T[r].l+T[r].r;
        return d_key;
    }
    else return remove(k<T[r].key?T[r].l:T[r].r,k);
    
}
int get_pre(int &x,int y,int k) {
    if(x == 0) return y;
    if(k > T[x].key) return get_pre(rs,x,k);
    else return get_pre(ls,y,k);
}
int get_next(int &x,int y,int k) {
    if(x == 0) return y;
    if(k < T[x].key) return get_next(ls,x,k);
    else return get_next(rs,y,k);
}
//取得第K大的数
int get_max_Kth(int &x,int k){
    int t=T[rs].sz+1;
    if(t==k) return T[x].key;
    if(t<k) return get_max_Kth(ls,k-t);
    else return get_max_Kth(rs,k);
}
//取得第K小的数
int get_min_Kth(int &x,int k){
    int t=T[ls].sz+1;
    if(t==k) return T[x].key;
    if(t<k) return get_min_Kth(rs,k-t);
    else return get_max_Kth(ls,k);
}
//查找树中是否存在元素
int find(int &r,int k){
    if(!r) return 0;
    if(T[r].key==k) return 1;
    if(k<T[r].key) return find(T[r].l,k);
    else return find(T[r].r,k);
}
//获得结点的名次
int get_rank(int &x,int k) {
    if(k<T[x].key)
        return get_rank(ls,k);
    else if(k>T[x].key)
        return get_rank(rs,k)+T[ls].sz+1;
    else
        return T[ls].sz+1;
}
//排序
void inorder(int &x) {
    if(x == 0) return;
    inorder(ls);
    printf("%d\n",T[x].key);
    inorder(rs);
}
int n , k; char ch[11]; int p;
int main() {
    while(~scanf("%d%d",&n,&k)) {
        root = tot = 0;
        while(n--) {
            scanf("%s" , ch);
            if(ch[0] == 'I') {
                scanf("%d" , &p);
                insert(root , p);
            }
            else {
                int ans = get_max_Kth(root,k);
                printf("%d\n" , ans);
            }
        }
    }
    return 0;
}
*/