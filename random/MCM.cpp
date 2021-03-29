#include <bits/stdc++.h>
using namespace std;

int static t[1001][1001];

int MCM(int a[], int i, int j) {
	if(i >= j) return 0;
	if(t[i][j] != -1) return t[i][j];
	int mn = INT_MAX;
	for(int k = i; k < j; k++) {
		int temp = MCM(a, i, k) + MCM(a, k+1, j) + (a[i-1]*a[k]*a[j]);
		mn = min(mn, temp);
	}
	return t[i][j] = mn;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(t, -1, sizeof(t));
	cout << MCM(a, 1, n-1) << endl;
}
