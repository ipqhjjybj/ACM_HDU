//
//  1004.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-9-14.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int calc(string s) {
    int ret = 0;
    for (int i = 0; i < s.size(); ++i) {
        int cur = 1;
        for (int j = 1; i - j >= 0 && i + j < s.size(); ++j) {
            if (s[i - j] == s[i + j])
                cur += 2;
            else
                break;
        }
        ret = max(ret, cur);
    }
    for (int i = 0; i + 1 < s.size(); ++i) {
        int cur = 0;
        for (int j = 0; i - j >= 0 && i + 1 + j < s.size(); ++j) {
            if (s[i - j] == s[i + 1 + j])
                cur += 2;
            else
                break;
        }
        ret = max(ret, cur);
    }
    return ret;
}

string ans;
int ret;

bool check(string t) {
    for (int i = 0, j = t.size() - 1; i < j; i++, j--)
        if (t[i] != t[j])
            return false;
    return true;
}

void dfs(int rem, string s) {
    if (s.size() >= 6 && check(s.substr(s.size() - 6)))
        return;
    if (s.size() >= 5 && check(s.substr(s.size() - 5)))
        return;
    if (rem == 0) {
        int cur = calc(s);
        if (cur < ret) {
            ret = cur;
            ans = s;
        }
        return;
    }
    dfs(rem - 1, s + "a");
    dfs(rem - 1, s + "b");
}

void dfs2(int rem, string s) {
    if (rem == 0) {
        int cur = calc(s);
        if (cur < ret) {
            ret = cur;
            ans = s;
        }
        return;
    }
    dfs(rem - 1, s + "a");
    dfs(rem - 1, s + "b");
}
string solve(int n, int L) {
    if (n == 1) {
        string ret = "";
        for (int i = 0; i < L; ++i) {
            ret += "a";
        }
        return ret;
    }
    if (n == 2) {
        //aaaabababbbb
        string R = "aaaababbaababbaababb";
        if (L <= 20) {
            ret = 1000;
            dfs2(L, "");
            return ans;
            //            return R.substr(0, L);
        }
        string T = "aababb";
        int cur = 0;
        int i = 20;
        for (int j = 0; j < (L - 20) / 6; ++j) {
            R += T;
        }
        int rem = (L - 20) % 6;
        if (rem <= 4)
            R += string("aaaa").substr(0, rem);
        else
            R += T.substr(0, rem);
        return R;
    }
    if (n >= 3) {
        string t = "abc", R = "";
        for (int i = 0; i < L; ++i) {
            R.push_back(t[i % 3]);
        }
        return R;
    }
}

int main() {
    //    cout << calc("AABABBAABABB") << endl;
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d: ", i);
        int n, L;
        cin >> n >> L;
        cout << solve(n, L) << endl;
    }
}