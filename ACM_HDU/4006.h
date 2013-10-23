//
//  4006.h
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-8-25.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//

#ifndef __ACM_HDU___006__
#define __ACM_HDU___006__

#include <iostream>

#endif /* defined(__ACM_HDU___006__) */

struct SBT{
    //左子树指针，右子树指针，大小，键值
    int l,r,sz,key;
    void init(){
        l=r=key=0;
        sz=1;
    }
}p[maxn];


bool find(int &t,int val){
    if(!t) return false;
    if(val==p[t].key) return true;
    else if(val<p[t].key) return find(p[t].l,val);
    else return find(p[t].r,val);
}
//SBT 删除 前驱替换
//是保证点存在下的删除,请先使用find操作
//如果没有对应节点,它会删除最靠近这个值的一个节点，慎用！
int remove(int &t,int val){
    if(!t) return 0;
    p[t].size--;
    if(val==p[t].key||p[t].l==0&&p[t].key>val||p[t].r==0&&p[t].val<val){
        int key_rm=p[t].key;
        if(p[t].l&&p[t].r){
            p[t].key=remove(p[t].l,val+1);
        }else t=p[t].l+p[t].r;
        return key_rm;
    }else{
        return remove(p[t].key<val?p[t].r:p[t].l,val);
    }
}