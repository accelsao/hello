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
using namespace std;
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
const int N=1e5+1;
const int M=1e9+7;
int n,k,p[N],vis[N],ans;
int main(){
    cin>>n>>k;
    REP(i,n)cin>>p[i];
    REP(i,n){
        if(!vis[i]){
            vector<int>gp;
            gp.PB(p[i]);
            vis[i]=1;
            while(!vis[(i+k)%n]){
                vis[(i+k)%n]=1;
                i=(i+k)%n;
                gp.PB(p[i]);
            }
            sort(ALL(gp));
            int m=gp[gp.size()/2];
            for(auto x:gp)//cout<<x<<" ",
                ans+=abs(x-m);
            //cout<<endl;
        }
    }
    cout<<ans<<endl;
}
