#include <bits/stdc++.h>
using namespace std;

int static t[1001][1001];

string lcs(string a, string b, int n, int m) {
	for(int i = 0; i < n+1; i++) {
		t[i][0] = 0;
	}
	for(int i = 0; i < m+1; i++) {
		t[0][i] = 0;
	}
	for(int i = 1; i < n+1; i++)
		for(int j = 1; j < m+1; j++) {
			if(a[i-1] == b[j-1]) 
				t[i][j] = 1+t[i-1][j-1];
			else
				t[i][j] = max(t[i-1][j], t[i][j-1]);
		}
	int i = n, j = m;
	string s = "";
	while(i > 0 && j > 0) {
		if(a[i-1] == b[j-1]) {
			s = s + a[i-1];
			i--;
			j--;
		}
		else if(t[i-1][j] >= t[i][j-1]) 
			i--;
		else 
			j--;
	}	
	reverse(s.begin(), s.end());
	return s;
} 
int lcs2(string a, string b, int n, int m) {
	if(n == 0 || m == 0) return 0;
	if(t[n][m] != -1) {
		return t[n][m];
	}
	if(a[n-1] == b[m-1]) {
		return t[n][m] = 1+lcs2(a, b, n-1, m-1);
	}
	else {
		return t[n][m] = max(lcs2(a, b, n-1, m), lcs2(a, b, n, m-1));
	}
}

int main() {
	string a, b;
	cin >> a >> b;
	memset(t, -1, sizeof(t));
	cout << lcs(a, b, a.size(), b.size()) << endl;
	for(int i = 0; i < a.size()+1; i ++) {
		for(int j = 0; j < b.size()+1; j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
}
