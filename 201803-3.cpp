#include <bits/stdc++.h>
using namespace std;

struct Rule{
	string name;
	vector<string>p;
};
vector<Rule>rule;
int n,m;

vector<string> separate(string r){
	vector<string> temp;
	std::size_t start=0,end;
		while(start!=string::npos){
			temp.push_back("/");
			end=r.find('/',start+1);
			if(start+1==r.size())break;
			temp.push_back(r.substr(start+1,end-start-1));
			start=end;
		}
	return temp;
}

bool CheckRule(Rule &r,vector<string> &check){
	bool isMatch=true;
	int check_index=0;
	vector<string>output;
	for(auto i:r.p){
		if(check_index==check.size()){
			isMatch=false;
			break;
		}
		if(i=="<str>"){
			output.push_back(check[check_index++]);
		}else if(i=="<int>"){
			for(auto c:check[check_index]){
				if(!isdigit(c)){
					isMatch=false;
					break;
				}
			}
			char temp[1000];
			output.push_back(itoa(atoi(check[check_index++].c_str()),temp,10));
		}else if(i=="<path>"){
			string temp=check[check_index++];
			while(check_index<check.size()){
				temp+=check[check_index++];
			}
			output.push_back(temp);
		}else{
			if(i!=check[check_index++]){
				isMatch=false;
				break;
			}
		}
		
		if(!isMatch)break;
	}
	
	if(!isMatch || check_index<check.size())return false;
	
	cout<<r.name<<" ";
	for(auto i:output)cout<<i<<" ";
	cout<<endl;
	return true;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		Rule R;
		string r;
		cin>>r>>R.name;
		R.p=separate(r);
		rule.push_back(R);
	}
	
	//test
//	for(int i=0;i<n;i++){
//		cout<<"Rule name: \""<<rule[i].name<<"\"\n";
//		for(auto it:rule[i].p)cout<<"\""<<it<<"\"\n";
//		cout<<endl;
//	}
	
	
	for(int i=0;i<m;i++){
		string r;
		cin>>r;
		vector<string>check=separate(r);
		bool isMatch=true;
		for(auto j:rule){
			if((isMatch=CheckRule(j,check)))break;
		}
		if(!isMatch)cout<<"404"<<endl;
	}
	

}
