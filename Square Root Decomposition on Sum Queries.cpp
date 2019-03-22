#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int n,m;
int block;
struct Query{
	int l,r,id;
	bool operator<(const Query &a)const{
		return l/block<a.l/block||(r<a.r);
	}
};

int main(){
	// input
	cin>>n>>m;
	vector<int>a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	vector<Query>q(m);
	vector<int>ans(m);
	for(int i=0;i<m;i++){
		cin>>q[i].l>>q[i].r;
		q[i].id=i;
	}
	// find answer
	block=sqrt(n);
	sort(q.begin(),q.end());
	int curL=0,curR=-1,curS=0;
	for(int i=0;i<m;i++){
		int L=q[i].l,R=q[i].r;
		while(curL<L){
			curS-=a[curL++];
		}
		while(curL>L){
			curS+=a[--curL];
		}
		while(curR<R){
			curS+=a[++curR];
		}
		while(curR>R){
			curS-=a[curR--];
		}
		cout<<curS<<endl;
		ans[q[i].id]=curS;
	}
	sort(q.begin(),q.end(),[](const Query &a,const Query &b){
		return a.id<b.id;
	}) ;
	for(int i=0;i<m;i++)
		printf("sum of [%d, %d] = %d\n",q[i].l,q[i].r,ans[q[i].id]);
}
/*
10 3
1 2 5 3 2 4 6 2 2 5
0 6
1 2
3 9

*/
