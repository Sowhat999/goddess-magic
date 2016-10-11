// This code only identifies flush. It does not compare suits.
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

int card[5];
char suit[5];

int fucker[5] = {14, 5, 4, 3, 2};
int royal[5] = {14, 13, 12, 11, 10};

int ch2num(char ch)
{
	if (ch == 'T')
		return 10;
	if (ch == 'J')
		return 11;
	if (ch == 'Q')
		return 12;
	if (ch == 'K')
		return 13;
	if (ch == 'A')
		return 14;
	return ch - '0';
}

void work()
{
	for (int i = 0; i < 5; ++i) {
		char num, st;
		std::cin >> num >> st;
		card[i] = ch2num(num);
		suit[i] = st;
	}
	bool isflush = std::unique(suit, suit + 5) - suit == 1;
	std::map<int, int> mp;
	for (int i = 0; i < 5; ++i)
		++mp[card[i]];
	using pii = std::pair<int, int>;
	std::vector<pii> vct;
	for (auto& p : mp)
		vct.emplace_back(p.second, p.first);
	std::sort(vct.begin(), vct.end(), std::greater<pii>());
	int p = 0;
	for (int i = 0; i < (int) vct.size(); ++i) {
		std::pair<int, int>& q = vct[i];
		for (int i = 0; i < q.first; ++i) {
			card[p++] = q.second;
		}
	}

	// test straight
	bool straight = true;
	for (int i = 1; i < 5; ++i) {
		if (card[i - 1] != card[i] + 1)
			straight = false;
	}
	if (std::memcmp(fucker, card, sizeof(fucker)) == 0)
		straight = true;

	// royal flush
	if (isflush && std::memcmp(royal, card, sizeof(royal)) == 0) {
		std::cout << "royal flush\n";
		return;
	}

	// straight flush
	if (isflush && straight) {
		std::cout << "straight flush\n";
		return;
	}

	// four of a kind
	if (vct.front().first == 4) {
		std::cout << "four of a kind\n";
		return;
	}

	// full house
	if (vct[0].first == 3 && vct[1].first == 2) {
		std::cout << "full house\n";
		return;
	}

	// flush
	if (isflush) {
		std::cout << "flush\n";
		return;
	}

	// straight
	if (straight) {
		std::cout << "straight\n";
		return;
	}

	// three of a kind
	if (vct.front().first == 3) {
		std::cout << "three of a kind\n";
		return;
	}

	// two pairs
	if (vct[0].first == 2 && vct[1].first == 2) {
		std::cout << "two pairs\n";
		return;
	}

	// pair
	if (vct[0].first == 2) {
		std::cout << "pair\n";
		return;
	}

	// high card
	std::cout << "high card\n";
	return;
}
