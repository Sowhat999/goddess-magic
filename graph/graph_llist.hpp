#ifndef _GRAPH_LLIST_HPP
#define _GRAPH_LLIST_HPP

constexpr int N = 1000;
constexpr int M = 3000 * 2;

using BigInt = long long;

struct Edge {
	int from;
	int to;
	BigInt wei;
	int next;
} gedges[M]; // 1-based

int gbegin[N];
int gm;

void initgraph()
{
	gm = 0;
	std::memset(gbegin, 0, sizeof(gbegin));
}

void adde(int from, int to, int wei)
{
	++gm;
	gedges[gm] = Edge{from, to, wei, gbegin[from]};
	gbegin[from] = gm;
}

#endif // _GRAPH_LLIST_HPP
