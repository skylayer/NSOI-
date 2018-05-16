#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+50;

int head[maxn],p;
struct edge {
	int from,to,next;
}e[maxn];
void add(int from,int to) {
	e[++p]=(edge){from,to,head[from]};
	head[from]=p;
}

int num[maxn],dfn[maxn],low[maxn],clck,cnt,stacks[maxn],top,belong[maxn];
bool inst[maxn];
int tarjan(int now) {
	low[now]=dfn[now]=++clck;
	stacks[++top]=now,inst[now]=true;
	for(int i=head[now];i;i=e[i].next) {
		int to=e[i].to;
		if(inst[to])low[now]=min(low[now],low[to]);
		else if(!dfn[to]) {
			tarjan(to);
			low[now]=min(low[now],low[to]);
		}
	}
	if(low[now]==dfn[now]) {
		cnt++;
		while(stacks[top+1]!=now) {
			num[cnt]++;
			belong[stacks[top]]=cnt;
			inst[stacks[top]]=false;
			top--;
		}
	}
	return 0;
}

int avi[maxn];
int dfs(int now) {
	for(int i=head[now];i;i=e[i].next) {
		int to=e[i].to;
		if(avi[to]==-1)dfs(to);
		if(avi[to]==1)return avi[now]=1;
	}
	return avi[now]=0;
}

int n,m;
int main() {
	freopen("train.in","r",stdin);
	freopen("train.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(avi,-1,sizeof avi);
	for(int i=1,f,t;i<=m;i++) {
		scanf("%d%d",&f,&t);
		if(f!=t)
		add(f,t);
		else
		avi[f]=1;
	}
	for(int i=1;i<=n;i++) {
		if(!dfn[i])tarjan(i);
		if(num[belong[i]]>1)avi[i]=true;
	}
	for(int i=1;i<=n;i++) {
		if(avi[i]==-1)dfs(i);
		printf("%d\n",avi[i]);
	}
	return 0;
}
