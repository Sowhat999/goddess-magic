#include <algorithm>

int ldp[N];

int lis()
{
	int ans = 0;
	std::fill(ldp + 1, ldp + 1 + n, inf);
	for (int i = 0; i < n; ++i) {
		/* upper_bound for non-strict increase */
		int k = std::lower_bound(ldp + 1, ldp + n + 1, arr[i]) - ldp;
		ans = std::max(ans, k);
		ldp[k] = arr[i];
	}
	return ans;
}
