#include <bitset>
#include <cstring>
#include <stack>
#include <vector>

#include "graph_llist.hpp"

int tmr;
int idx[N];
int low[N];
std::bitset<N> onst;
std::stack<int> st;

void tarjan_rec(int node)
{
	idx[node] = low[node] = ++tmr;
	st.push(node);
	onst[node] = true;
	for (int e = gbegin[node]; e; e = gedges[e].next) {
		int son = gedges[e].to;
		if (!idx[son]) {
			tarjan_rec(son);
			low[node] = std::min(low[node], low[son]);
		} else if (onst[son]) {
			low[node] = std::min(low[node], idx[son]);
		}
	}
	if (low[node] == idx[node]) {
		std::vector<int> ans;
		int nxt;
		do {
			nxt = st.top();
			st.pop();
			onst[nxt] = false;
			ans.push_back(nxt);
		} while (node != nxt);
		for (auto v : ans)
			std::cout << v << ' ';
		std::cout << std::endl;
	}
}

void tarjan()
{
	std::memset(idx, 0, sizeof(idx));
	std::memset(low, 0, sizeof(low));
	onst.reset();
	tmr = 0;
	for (int i = 1; i <= n; ++i) {
		if (!idx[i])
			tarjan_rec(i);
	}
}
