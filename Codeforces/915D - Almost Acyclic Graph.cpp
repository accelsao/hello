#include <bits/stdc++.h>
#define LL long long
#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define Re(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
#define REP(I, N) for (int I = 0; I < (N); I++)
#define MID ((l+r)>>1)
#define lc (rt<<1)
#define rc (rt<<1|1)
#define ls lc,l,MID
#define rs rc,MID+1,r
#define st 1,1,n
#define PII pair<int,int>
#define PLL pair<LL,LL>
using namespace std;
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
const int N=500+1;
const int M=1e9+7;
int d[N],deg[N],vis[N];
vector<int>g[N];
void dfs(int u){
	vis[u]=1;
	for(auto v:g[u])if(!vis[v]&&(--deg[v])<=0)dfs(v);
}
int n,m;
int main(){Accel
	cin>>n>>m;
	int u,v;
	while(m--){
		cin>>u>>v;
		g[u].PB(v);
		d[v]++;
	}
	FOR(i,1,n){
		FOR(j,1,n)deg[j]=d[j],vis[j]=0;
		deg[i]--;
		FOR(j,1,n)
			if(deg[j]<=0&&!vis[j])dfs(j);
		int f=1;
		FOR(j,1,n)f&=vis[j];
		if(f)return cout<<"YES\n",0;
	}
	cout<<"NO\n";
}
