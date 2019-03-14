#include <bits/stdc++.h>
using namespace std;

struct Node{
	int attack,health;
};

bool player;
vector<Node>V[2];

void summon(int pos,int attack,int health){
	V[player].insert(V[player].begin()+pos,Node{attack,health}); 
//	printf("player %d, index: %d summon created, attack: %d health: %d\n",
//				   player,pos,V[player][pos].attack,V[player][pos].health);
}

bool attackSummon(int attack,int defender){
	V[player][attack].health-=V[!player][defender].attack;
	V[!player][defender].health-=V[player][attack].attack;
	
	if(V[player][attack].health<=0){
		V[player].erase(V[player].begin()+attack);
//		printf("player %d, index: %d summon dead\n",player,attack);
	}
       
	if(V[!player][defender].health<=0){
		if(defender==0)return true;
		V[!player].erase(V[!player].begin()+defender);
//		printf("player %d, index: %d summon dead\n",!player,defender);
	}
	return false;
}

void changePlayer(){
	player=!player;
}

int main(){
	//initialize
	V[0].push_back(Node{0,30});
	V[1].push_back(Node{0,30});
	//
	int n,status=0;
	cin>>n;
	while(n--){
		string order;
		cin>>order;
		if(order=="summon"){
			int pos,attack,health;
			cin>>pos>>attack>>health;
			summon(pos,attack,health);
		}else if(order=="attack"){
			int attack,health;
			cin>>attack>>health;
			bool win=attackSummon(attack,health);
			if(win){
				status=player?1:-1;
				getchar();
				while(n--){
					getline(cin,order);
				}
				break;
			}
		}else{
			changePlayer();
		}
	}
	
	//output
	cout<<status<<endl;
	cout<<V[0][0].health<<endl<<V[0].size()-1<<" ";
	for(int i=1;i<V[0].size();i++){
		cout<<V[0][i].health<<" ";
	}
	putchar('\n');
	cout<<V[1][0].health<<endl<<V[1].size()-1<<" ";
	for(int i=1;i<V[1].size();i++){
		cout<<V[1][i].health<<" ";
	}
	putchar('\n');
}
