//
//  4557.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-9-6.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
char s1[10];
int pro;
vector< pair<int,string> > p;
bool visit[1111];
int main(){
    int t,num,n,total,tt=0;
    pair<int ,string > tmp;
    cin>>t;
    while(t--){
        int size=0;
        p.clear();
        total=0;
        cin>>n;
        cout<<"Case #"<<++tt<<":"<<endl;
        while(n--){
            scanf("%s",s1);
            if(s1[0]=='A'){
                cin>>tmp.second>>tmp.first;
                p.push_back(tmp);
                visit[size++]=false;
                total++;
                cout << total << endl;
            }else if(s1[0]=='F'){
                cin>>num;
                int zz=0x3f3f3f3f;
                int i=-1;
                int j=0;
                for(vector<pair<int,string> >::iterator it=p.begin();
                    it!=p.end();it++){
                    if((!visit[j])&&it->first>=num && it->first<zz){
                        zz=it->first;
                        i=j;
                    }
                    j++;
                }
                if(i==-1){
                    cout<<"WAIT..."<<endl;
                }else{
                    total--;
                    cout << p[i].second <<endl;
                    visit[i]=true;
                }
            }
        }
    }
}