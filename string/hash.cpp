#include <iostream>
#include <string>

const int N = 1000010;

using ull = unsigned long long;

ull hsh_[N];
ull *hsh = hsh_ + 1;
const ull base = SOME_PRIME;
ull basen[N];

int matchhash(const char *s, int n, ull hs, int m)
{
	hsh[-1] = 0;
	ull cnt = 0;
	for (int i = 0; i < n; ++i) {
		hsh[i] = hsh[i - 1] * base + s[i];
		if (i + 1 >= m && hsh[i] - hsh[i - m] * basen[m] == hs)
			++cnt;
	}
	return cnt;
}

void inithash()
{
	basen[0] = 1;
	for (int i = 1; i < N; ++i) {
		basen[i] = basen[i - 1] * base;
	}
}

ull gethash(const char *s, int n)
{
	ull hs = 0;
	for (int i = 0; i < n; ++i) {
		hs = hs * base + s[i];
	}
	return hs;
}

int main()
{
	std::string needle;
	std::string text;
	std::getline(std::cin, needle);
	std::getline(std::cin, text);
	int m = needle.size();
	int n = text.size();

	inithash();
	ull hs = gethash(needle.c_str(), m);
	ull ans = matchhash(text.c_str(), n, hs, m);

	std::cout << ans << std::endl;
}
