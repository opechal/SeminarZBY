#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

//Dalimil Hajek
using namespace std;


vector<vector<pair<int, int> > > g(30, vector<pair<int, int> >(30, pair<int,int>(-1, -1)));

int toi(string g){
	return g[0]-'A';
}
char ito(int ind){
	return 'A'+ind;
}

int go(int v, int fuel){
	bool end = true;
	for(int i=0;i<30;i++){
		if(g[v][i].first != -1 && g[v][i].first <= fuel && g[v][i].second == 0){ //exists, have fuel, not visited
			end = false;
			g[v][i].second = g[i][v].second = 1;
			go(i, fuel-g[v][i].first);
			g[v][i].second = g[i][v].second = 0;
		}
	}
	if(end){
		//vytiskni celou cestu
	}//cout << "->"<<ito(v) << endl;
}
			
int main(){
	int m; scanf("%d", &m);
	
	for(int i=0;i<m;i++){
		char a[5], b[5];
		int c; scanf("%s %s %d", a, b, &c);
		string A = a, B = b;
		g[toi(A)][toi(B)] = make_pair(c, 0);
		g[toi(B)][toi(A)] = make_pair(c, 0);
		//cout << A <<"  " << B << " " << c << endl;
	}
	go(0, 5);
	go(0, 8);
	go(0, 16);

}
//pokus
