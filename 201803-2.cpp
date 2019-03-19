#include <bits/stdc++.h>
using namespace std;

struct Node{
	int direct,pos;
	int order;//save input order
	friend bool operator<(const Node &a,const Node &b){
		return a.pos<b.pos;
	}
};

vector<Node>V;
int n,L,t;

bool cmp(const Node &a,const Node &b){
	return a.order<b.order;
}

int main(){
	cin>>n>>L>>t;
	for(int i=0,p;i<n;i++){
		cin>>p;
		V.push_back(Node{1,p,i});
	}
	sort(V.begin(),V.end());
	
	for(int i=0;i<t;i++){
		//check the direction
		for(int j=0;j<n;j++){
			if(V[j].pos==0 || V[j].pos==L || (j>0 && V[j-1].pos==V[j].pos) ||
			(j<n-1 && V[j+1].pos==V[j].pos)){
				V[j].direct*=-1;
			}
		}
		//move one step
		for(int j=0;j<n;j++){
			V[j].pos+=V[j].direct;
		}
	}
	sort(V.begin(),V.end(),cmp);
	
	//output
	for(int i=0;i<n;i++){
		cout<<V[i].pos<<" ";
	}
}
