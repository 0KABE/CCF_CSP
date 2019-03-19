#include <bits/stdc++.h>
using namespace std;

int T;
int board[3][3];

int check(bool isAlice){
	//count
	int cnt=1;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[i][j]==0)cnt++;
		}
	}
	//row
	for(int i=0;i<3;i++){
		if(board[i][0] && board[i][0]==board[i][1] && board[i][1]==board[i][2]){
			return isAlice?1*cnt:-1*cnt;
		}
	}
	//column
	for(int j=0;j<3;j++){
		if(board[0][j] && board[0][j]==board[1][j] && board[1][j]==board[2][j]){
			return isAlice?1*cnt:-1*cnt;
		}
	}
	//gradient
	if(board[1][1] && board[0][0]==board[1][1] && board[1][1]==board[2][2]){
		return isAlice?1*cnt:-1*cnt;
	}
	if(board[1][1] && board[2][0]==board[1][1] && board[1][1]==board[0][2]){
		return isAlice?1*cnt:-1*cnt;
	}
	return 0;
}

int dfs(bool isAlice){
	int ans=check(!isAlice);
	if(ans)return ans;
	ans=isAlice?INT_MIN:INT_MAX;
	bool full=true;
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(!board[i][j]){
				full=false;
				board[i][j]=isAlice?1:2;
				ans=isAlice?max(ans,dfs(!isAlice)):min(ans,dfs(!isAlice));
				board[i][j]=0;
			}
		}
	}
	return full?0:ans;
}

int main(){
	scanf("%d",&T);
	
	while(T--){
		memset(board,0,sizeof(board));
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				scanf("%d",&board[i][j]);
			}
		}
		int ans=dfs(true);
		printf("%d\n",ans);
	}
}
