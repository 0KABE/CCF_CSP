#include <bits/stdc++.h>
using namespace std;

int main(){
	int ans=0;
	int cur;
	int n;
	cin>>n>>cur;
	while(--n){
		int temp;
		cin>>temp;
		ans=max(ans,abs(cur-temp));
		cur=temp;
	}	
	cout<<ans;
}
