#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> s_vector,f_vector;
int n,m,k;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);	
	cin >> n >> m >> k;
	s_vector=vector<pair<int,int>>(k,make_pair(0,0));
	f_vector=vector<pair<int,int>>(k,make_pair(0,0));
	for (int i=0;i<k;i++){
		cin >> s_vector[i].first >> s_vector[i].second;
	}
	for (int i=0;i<k;i++){
		cin >> f_vector[i].first >> f_vector[i].second;
	}
	
}