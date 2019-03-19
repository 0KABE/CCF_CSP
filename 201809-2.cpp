#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e6+5;
bool t[MAXN][2];
int n;

int main(){
	scanf("%d",&n);
	for(int i=0,a,b;i<n;i++){
	    scanf("%d%d",&a,&b);
	    for(int j=a;j<b;j++){
	    	t[j][0]=true;
	    }
	}
	
	for(int i=0,a,b;i<n;i++){
	    scanf("%d%d",&a,&b);
	    for(int j=a;j<b;j++){
	    	t[j][1]=true;
	    }
	}
	
	int cnt=0;
	for(int i=0;i<MAXN;i++){
		if(t[i][0] && t[i][1])cnt++;
	}
	
	printf("%d",cnt);
}
