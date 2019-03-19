#include <bits/stdc++.h>
using namespace std;

int main(){
	int cnt=0,ans=0,cur;
	while(1){
		cin>>cur;
		if(cur==0)break;
		if(cur==1){
			ans+=1;
			cnt=0;
		}else if(cur==2){
			ans+=++cnt*2;
		}
	}
	cout<<ans;
}
