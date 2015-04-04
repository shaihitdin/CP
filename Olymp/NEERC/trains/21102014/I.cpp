#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int problems,solved[301][301],rank[301],num[301],i,j,team;
string s;
double vainness,evenness,I[301],tmp,oversimplification,unsolvability;
int to_int(string t){
    int ret_val=0;
    for(int i=0;i<t.size();++i){
        if(t[i]==' '){
            break;
        }
        ret_val=ret_val*10+(t[i]-'0');
    }
    return ret_val;
}
int main(){
	freopen("ideal.in","r",stdin);
	freopen("ideal.out","w",stdout);
	while(getline(cin,s)){
		/*
		i=0;
		while(i<s.size() && s[i]==' ')	++i;
		*/
		if(s[0]=='T' && s[1]=='e' && s[2]=='a' && s[3]=='m'){
			i=4;
			while(s[i]!='='){
				if(s[i]==' '){
					++i;
					continue;
				}
				++problems;
				++i;
			}
			break;
		}
	}
	getline(cin,s);
	while(getline(cin,s)){
		i=s.size()-1;
		++team;
		while(s[i]==' '){
			--i;
		}
		while(s[i]!=' '){
			--i;
		}
		//rank
        rank[team]=to_int(s.substr(i+1));
		while(s[i]==' '){
			--i;
		}
		while(s[i]!=' '){
			--i;
		}
		//time
		while(s[i]==' '){
			--i;
		}
		while(s[i]!=' '){
			--i;
		}
		//num of solved
		//num[team]=to_int(s.substr(i+1,s.size()-i));
		for(int cnt=0;cnt!=problems;--i){
				if(s[i]=='+'){
					solved[team][problems-cnt]=1;
					++num[team];
					++cnt;
				}
				if(s[i]=='-'){
					solved[team][problems-cnt]=-1;
					++cnt;
				}
				if(s[i]=='.'){
					solved[team][problems-cnt]=-1;
					++cnt;
				}
		}
	}
	for(i=1;i<=team;++i){
		if(num[i]==0){
			vainness+=(1.0/(team*1.0));
		}
	}
	for(i=1;i<=team;++i){
		if(num[i]==problems){
			oversimplification+=(1.0/(team*1.0));
		}
	}
	for(i=2;i<=team;++i){
		if(num[i-1]-num[i]>1){	
			evenness+=((1.0/(problems*1.0))*1.0*(num[i-1]-num[i]-1));
		}
	}
	for(i=1;i<=problems;++i){
		for(j=1;j<=team;++j){
			if(solved[j][i]==1)
				break;
		}
		if(j>team){
			unsolvability+=(1.0/(problems*1.0));
		}
	}
	for(i=1;i<=problems;++i){
		int it=0;
		for(j=1;j<=team;++j){
			if(solved[j][i]==1){
				it=j;
			}	
		}
		if(it==0)
			continue;
		for(j=1;j<=team;++j){
			if(solved[j][i]==-1 && rank[j]<rank[it]){
				I[i]+=(1.0/(team*1.0));
			}
		}
	}
	cout.precision(3);
	cout<<"Vainness = "<<vainness<<"\nOversimplification = "<<oversimplification<<"\nEvenness = "<<evenness<<"\nUnsolvability = "<<unsolvability<<"\n";
	for(i=1;i<=problems;++i){
		cout<<"Instability "<<i<<" = "<<I[i]<<"\n";	
		tmp+=(I[i]);
	}
	cout<<"Negidealness = "<<(1.03*vainness+3.141*oversimplification+2.171*evenness+1.414*unsolvability+ ((problems!=0)?((tmp)/(problems*1.0)) : (0) ) );
	return 0;
}