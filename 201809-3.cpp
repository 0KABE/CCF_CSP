#include <bits/stdc++.h>
using namespace std;
/*
11 5
html
..head
....title
..body
....h1
....p #subtitle
....div #main
......h2
......p #one
......div
........p #two
P
#subtitle
h3
diV p
div div p
*/

const int MAXN=1e2+5;

struct Node{
	string tag,subtitle;
	string info;
	int parent;
}tree[MAXN];

int n,m;

int main(){
	cin>>n>>m;
	getchar();
	stack<int>S;
	//input doc
	for(int i=1;i<=n;i++){
		string line;
		Node &node=tree[i];
		std::size_t start=0,end;
		int level=0;
		
		getline(cin,line);
		//get level
		end=line.find_last_of('.');
		if(end!=string::npos)level=(end+1)/2;
		//get tag
		start=line.find_first_not_of('.');
		end=line.find(' ');
        node.tag=line.substr(start,end-start);
        transform(node.tag.begin(),node.tag.end(),node.tag.begin(),::tolower);
		//get subtitle
		start=line.find('#');
		if(start!=string::npos)
		    node.subtitle=line.substr(start);
		//get info
		node.info=node.tag+" "+node.subtitle;		    
		while(level<S.size()){
			S.pop();
		}
		node.parent=S.empty()?0:S.top();
		S.push(i);
	}
	
	//test
	/*
	for(int i=1;i<=n;i++){
		cout<<"tag: \""<<tree[i].tag<<"\" subtitle: \""<<tree[i].subtitle<<"\" parent: "
		<<tree[i].parent<<endl;
	}
	*/
	
	//input 
	stack<string>selector_src,selector;
	for(int i=0;i<m;i++){
		selector_src=stack<string>();
		string line;
		getline(cin,line);
		std::size_t start=0,end=0;
		while((start=line.find_first_not_of(' ',end))!=string::npos){
			end=line.find(' ',start);
			string temp=line.substr(start,end-start);
			if(temp[0]!='#'){
				transform(temp.begin(),temp.end(),temp.begin(),::tolower);
			}
			selector_src.push(temp);
		}
		
		//search
		int cnt=0;
		vector<int>ans;
		for(int i=1;i<=n;i++){
			selector=selector_src;
			if(tree[i].info.find(selector.top())==string::npos){
				continue;
			}
			selector.pop();
			int l=tree[i].parent;
			while(l>0 && !selector.empty()){
				if(tree[l].info.find(selector.top())!=string::npos){
					selector.pop();
				}
				l=tree[l].parent;
			}
			if(selector.empty()){
				cnt++;
				ans.push_back(i);
			}
		}
		//output
		cout<<cnt<<" ";
		for(auto index:ans)cout<<index<<" ";
		cout<<endl;
	}
}

