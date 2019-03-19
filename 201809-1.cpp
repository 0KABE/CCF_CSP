#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int>v;
	int n;
	cin>>n;
	for(int i=0,temp;i<n;i++){
		cin>>temp;
		v.push_back(temp);
	}
	
	for(int i=0;i<n;i++){
		if(i==0){
			cout<<(v[0]+v[1])/2<<" ";
		}else if(i==n-1){
			cout<<(v[n-2]+v[n-1])/2<<" ";
		}else{
			cout<<(v[i-1]+v[i]+v[i+1])/3<<" ";
		}
	}
}
