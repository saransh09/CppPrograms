#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<int,string> dir;
	map<pair<int,int>,string> codes = {make_pair<pair<int,int>,string>(make_pair(0,1),"U"),make_pair<pair<int,int>,string>(make_pair(0,-1),"D"),
									   make_pair<pair<int,int>,string>(make_pair(-1,0),"L"),make_pair<pair<int,int>,string>(make_pair(1,0),"R"),
									   make_pair<pair<int,int>,string>(make_pair(-1,-1),"LD"),make_pair<pair<int,int>,string>(make_pair(1,-1),"RD"),
									   make_pair<pair<int,int>,string>(make_pair(1,1),"RU"),make_pair<pair<int,int>,string>(make_pair(-1,1)),"LU"};
	dir[1] = ;
	dir[2] =  ;
	dir[3] = "L";
	dir[4] = "R";
	dir[5] = "LD";
	dir[6] = "RD";
	dir[7] =  "RU";
	dir[8] = "LU";
	string ip,op;
	cin>>ip>>op;
	int inpc,inpr,outc,outr;
	unordered_map<char,int> m;
	m['a'] = 0;
	m['b'] = 1;
	m['c'] = 2;
	m['d'] = 3;
	m['e'] = 4;
	m['f'] = 5;
	m['g'] = 6;
	m['h'] = 7;
	char temp = ip[0];
	inpc = m[temp];
	inpr = ip[1] - '0';
	temp = op[0];
	outc = m[temp];
	outr = op[1] - '0';
	vector<pair<int,int> > v;
	int ydiff = outc - inpc;
	int xdiff = outr - inpr;
	if(xdiff==0 && ydiff==0) cout<<0<<endl;
	else if(xdiff==0) {
		while(ydiff!=0){
			if(ydiff>0){
				v.push_back(make_pair(0,-1));
				ydiff--;
			}
			else{
				v.push_back(make_pair(0,1));
				ydiff++;
			}
		}
	}
	else if(ydiff==0){
		while(xdiff!=0) {
			if(xdiff > 0){
				v.push_back(make_pair(-1,0));
				xdiff--;
			}
			else {
				v.push_back(make_pair(-1,0));
				xdiff++;
			}
		}
	}
	else if(ydiff > 0 && xdiff > 0) {
		while(xdiff!=0 || ydiff!=0){
			v.push_back(make_pair(-1,-1));
			xdiff--;
			ydiff--;
		}
		if(xdiff==0 && ydiff==0){

		}
		else if(xdiff==0){
			if(ydiff>0){
				v.push_back(make_pair(0,-1));
				ydiff--;
			}
			else{
				v.push_back(make_pair(0,1));
				ydiff++;
			}
		}
		else{
			if(ydiff==0){
				if(xdiff>0){
					v.push_back(make_pair(-1,0));
					xdiff--;
				}
				else{
					v.push_back(make_pair(1,0));
					xdiff++;
				}
			}
		}
	}
	else if(ydiff > 0 && xdiff <0){
		while(xdiff!=0 || ydiff!=0){
			v.push_back(make_pair(1,-1));
			xdiff++;
			ydiff--;
		}
		if(xdiff==0){
			if(ydiff>0){
				v.push_back(make_pair(0,-1));
				ydiff--;
			}
			else{
				v.push_back(make_pair(0,1));
				ydiff++;
			}
		}
		else{
			if(ydiff==0){
				if(xdiff>0){
					v.push_back(make_pair(-1,0));
					xdiff--;
				}
				else{
					v.push_back(make_pair(1,0));
					xdiff++;
				}
			}
		}
	}
	else if(ydiff < 0 && xdiff < 0){
		while(xdiff!=0 || ydiff!=0){
			v.push_back(make_pair(1,1));
			xdiff++;
			ydiff++;
		}
		if(xdiff==0){
			if(ydiff>0){
				v.push_back(make_pair(0,-1));
				ydiff--;
			}
			else{
				v.push_back(make_pair(0,1));
				ydiff++;
			}
		}
		else{
			if(ydiff==0){
				if(xdiff>0){
					v.push_back(make_pair(-1,0));
					xdiff--;
				}
				else{
					v.push_back(make_pair(1,0));
					xdiff++;
				}
			}
		}
	}
	else if(ydiff < 0 && xdiff > 0){
		while(xdiff!=0 || ydiff!=0){
			v.push_back(make_pair(-1,1));
			xdiff--;
			ydiff++;	
		}
		if(xdiff==0){
			if(ydiff>0){
				v.push_back(make_pair(0,-1));
				ydiff--;
			}
			else{
				v.push_back(make_pair(0,1));
				ydiff++;
			}
		}
		else{
			if(ydiff==0){
				if(xdiff>0){
					v.push_back(make_pair(-1,0));
					xdiff--;
				}
				else{
					v.push_back(make_pair(1,0));
					xdiff++;
				}
			}
		}
	}
	cout<<v.size()<<endl;
	for(int i = 0 ; i < v.size() ; i++) cout<<dir[v[i]]<<endl;
 	return 0;
}