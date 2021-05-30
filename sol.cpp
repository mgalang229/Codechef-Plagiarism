#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m, k;
		cin >> n >> m >> k;
		// add 'n' to 'm'
		m += n;
		vector<int> l(k);
		int limit = INT_MIN;
		for (int i = 0; i < k; i++) {
			cin >> l[i];
			// find the maximum number in the vector
			limit = max(limit, l[i]);
		}
		vector<int> counter(limit + 1, 0);
		set<int> disq;
		for (int i = 0; i < k; i++) {
			// check if the current number is in the range of [1, n] (inclusive)
			if (l[i] <= n) {
				// if yes, then mark its position
				if (counter[l[i]] == 0) {
					// if it's not yet marked, then mark it (visited)
					counter[l[i]] = 1;
				} else {
					// otherwise, insert it into the set (it means the user attempted more than once)
					disq.emplace(l[i]);
				}
			}
		}
		// print the size of the set
		cout << (int) disq.size() << " ";
		// print the elements in the set
		for (auto x : disq) {
			cout << x << " ";
		}
		cout << '\n';
	}
	return 0;
}
