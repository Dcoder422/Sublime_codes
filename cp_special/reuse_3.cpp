#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
	    long int n, a;
	    cin >> n >> a;
	    long int c[n+1], d[n+1], pf[n+1] = {0};
	    for (int i = 1; i <= n; ++i) {
	        cin >> c[i] >> d[i];
	        pf[i] = c[i] + pf[i-1];
	    }
	    int result = 0;
	    for (int i = 1; i <= n; ++i) {
	    	long int dmax = INT_MIN;
	    	long int dmin = INT_MAX;
	    	for (int j = i; j <= n; ++j) {
	    		dmax = max(dmax, d[j]);
                dmin = min(dmin, d[j]);
                int gap = (dmax - dmin)*(dmax - dmin);
                int profit = a * (j-i+1) - (pf[j] - pf[i-1]) - gap;
                result = max(result, profit);
                cout << result<< endl;
	    	}
	    }
	    cout << result << endl;
	}
	return 0;
}