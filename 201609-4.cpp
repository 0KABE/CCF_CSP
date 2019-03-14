/*
AC
*/
#include<bits/stdc++.h>
using namespace std;
/*
6 9
1 2 6
3 1 3
6 1 4
6 3 5
4 3 6
4 5 1
2 3 2
5 2 3
3 5 7
*/
struct Node{
	int index,dis;
};
const int MAXN=1e4+5;
vector<Node>G[MAXN];
int vis[MAXN];
int edge[MAXN];
queue<int>Q;
int n,m;


int main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++){
		edge[i]=vis[i]=0x7ffffff;
	}
	
	for(int i=0,a,b,c;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		G[a].push_back(Node{b,c});
		G[b].push_back(Node{a,c});
	}
	
	
	Q.push(1);
	while(!Q.empty()){
		int index=Q.front();
		Q.pop();
		for(auto w:G[index]){
			if(vis[w.index]>vis[index]+w.dis||vis[w.index]==vis[index]+w.dis && edge[w.index]>w.dis){
				Q.push(w.index);
				vis[w.index]=vis[index]+w.dis;
				edge[w.index]=w.dis;
			}
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=edge[i];
	}
	printf("%d",ans);
}
