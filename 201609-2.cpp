#include <bits/stdc++.h>
using namespace std;

int sets[20][6];

int main(){
	int n;
	cin>>n;
	
	
	while(n--){
		int num;
		cin>>num;
		int i;
		for(i=0;i<20;i++){
			if(5-sets[i][0]>=num){
				
				for(int j=1;j<=num;j++){
					sets[i][j+sets[i][0]]=1;
					cout<<i*5+j+sets[i][0]<<" ";
				}
				
				sets[i][0]+=num;
				break;
			}
		}
		if(i<20){
			putchar('\n');
			continue;
		}
		
		for(int i=0;i<20;i++){
			for(int j=1;j<=5;j++){
				if(sets[i][j]==0){
					sets[i][j]=1;
					sets[i][0]++;
					num--;
					cout<<i*5+j<<" ";
				}
				if(num==0)break;
			}
			if(num==0)break;
		}
		
		putchar('\n');
	}
} 
