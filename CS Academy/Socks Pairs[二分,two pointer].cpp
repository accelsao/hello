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
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define SZ(a) ((int)a.size())
//#pragma GCC optimize(2)
using namespace std;
const int N=1e6+1;
const int M=1e9+7;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//size() use int
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln() , log(x)/log(y)=log(y)-base-x
//watch out LL
int main(){Accel
    int n,k;
    int t=0,c=0;
    cin>>n>>k;
    priority_queue<int>q;
    FOR(i,1,n){
        int x;cin>>x;
        c++;
        if(x>1)q.push(x-1);
    }
    while(t<k){
        if(q.empty()){
            cout<<-1;return 0;
        }
        int x=q.top();q.pop();
        if(x==1){
            t++;c++;continue;
        }
        if(x==2){
            t++,c+=2;continue;
        }
        int d=min(k-t,(x-1)/2);
        t+=d;c+=2*d;
        x-=d*2;
        if(t==k)c--;
        if(x)q.push(x);
    }
    cout<<c<<endl;
}
