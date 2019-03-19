#include <bits/stdc++.h>
using namespace std;

const int MAXN=3e2+5;
vector<int>a,b(MAXN);
int n;

bool dfs(int i){
	if(i==n){
        if((b[n-2]+b[n-1])/2==a[n-1])return true;
		else return false;
	}
	for(int j=0;j<3;j++){
		b[i]=3*a[i-1]-b[i-2]-b[i-1]+j;
//		cout<<setw(i*5)<<b[i]<<endl;
		if(b[i]<=0)continue;
		if(dfs(i+1))return true;
	}
	return false;
}

int main(){
	scanf("%d",&n);
	for(int i=0,temp;i<n;i++){
		scanf("%d",&temp);
		a.push_back(temp);
	}
	for(int i=1;i<200;i++){
		b[0]=i;
//		cout<<setw(5)<<i<<endl;
		bool finish;
		for(int j=0;j<2;j++){
			b[1]=2*a[0]-b[0]+j;
//			cout<<setw(10)<<b[1]<<endl;
			if(b[1]<=0)continue;
			if((finish=dfs(2)))break;
		}
		if(finish)break;
	}
	
	for(int i=0;i<n;i++){
		cout<<b[i]<<" ";
	}
}
