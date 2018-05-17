#include<bits/stdc++.h>
#define S second
#define F first
using namespace std;
const int maxn=2e6+100;
int n,x,t;
int high[maxn],minn[maxn],maxx[maxn];
deque<pair<int,int> >que;
long long size() {
    long long ans=0;
    for(int i=1;i<=n;i++) {
        ans+=high[i]-maxx[i];
    }
    return ans;
}
long long times() {
    long long cnt=0,len=0;
    for(int i=1;i<=n;i++) {
        len++;
        if(maxx[i]!=maxx[i+1]) {
            cnt+=ceil((double)len/x);
            len=0;
        }	
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(0);
    cin>>n>>x;
    for(int i=1;i<=n;i++) {
        cin>>high[i];
        while(!que.empty()&&i-que.front().F>=x)que.pop_front();
        while(!que.empty()&&que.back().S>=high[i])que.pop_back();
        que.emplace_back(i,high[i]);
        if(i>=x)minn[i] = que.front().S;
    }
    que.clear();
    memset(maxx,-1,sizeof maxx);
    for(int i=1;i<=n+x-1;i++) {
        while((!que.empty())&&i-que.front().F>=x)que.pop_front();
        while((!que.empty())&&que.back().S<=minn[i])que.pop_back();
        que.emplace_back(i,minn[i]);
        if(0<=i-x+1)maxx[i-x+1]=que.front().S;
    }
    cin>>t;
    if(t==1)cout<<size();
    if(t==2)cout<<times();
    if(t==3)cout<<size()<<endl<<times();
    return 0;
}
