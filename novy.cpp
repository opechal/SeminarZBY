#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

//Dalimil Hajek
using namespace std;

int toi(string g){
	return g[0]-'A';
}
int main(){
	int m; scanf("%d", &m);
	vector<vector<pair<int, int> > > g(30, vector<pair<int, int> >(30));
	for(int i=0;i<m;i++){
		char a[5], b[5];
		int c; scanf("%s %s %d", a, b, &c);
		string A = a, B = b;
		g[toi(A)].push_back(make_pair(toi(B), c));
		g[toi(B)].push_back(make_pair(toi(A), c));
		cout << A <<"  " << B << " " << c << endl;
	}
	go(0);

}
