#include <algorithm>
#include <cstring>

constexpr int N = 100000;
constexpr int M = 10000;

char text[N];
char pattern[M];
int n; // strlen of text
int m; // strlen of pattern
int fail[M];

void initkmp()
{
	fail[0] = -1;
	int j = -1;
	for (int i = 1; i < m; ++i) {
		while (~j && pattern[i] != pattern[j + 1])
			j = fail[j];
		if (pattern[i] == pattern[j + 1])
			++j;
		fail[i] = j;
	}
}

// start matching from startpos
// quit when pos of first char >= endpos
int kmp(/* int startpos, int endpos */)
{
	int ans = 0;
	int j = -1;
	for (int i = 0 /* startpos */;
			i < n /* std::min(n, endpos + m - 1) */; ++i) {
		while (~j && text[i] != pattern[j + 1])
			j = fail[j];
		if (text[i] == pattern[j + 1])
			++j;
		if (j == m - 1) {
			// return i - m + 1;
			++ans;
			j = fail[j];
		}
	}
	return ans;
}
