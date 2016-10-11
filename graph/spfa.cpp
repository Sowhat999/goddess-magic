#include <algorithm>
#include <bitset>
#include <cstring>
#include <deque>
#include <tuple>
#include <vector>

#include "graph_llist.hpp"

BigInt dist[N];	// Distance
int prd[N];	// Pred
std::bitset<N> inq;	// In queue

// Return path (empty) or length of path (-1).
std::vector<int> /* BigInt */ spfa(int s, int t)
{
	std::memset(dist, -1, sizeof(dist));
	std::memset(prd, -1, sizeof(prd));
	inq.reset();
	std::deque<int> Q;
	dist[s] = 0;
	Q.push_back(s);
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop_front();
		inq[u] = false;
		for (int e = gbegin[u]; e; e = gedges[e].next) {
			int v = gedges[e].to;
			BigInt w = gedges[e].wei;
			BigInt du = dist[u];
			if (dist[v] == -1 || dist[v] > du + w) {
				prd[v] = u;
				dist[v] = du + w;
				if (!inq[v]) {
					if (Q.size() && dist[v] < dist[Q.front()])
						Q.push_front(v);
					else
						Q.push_back(v);
					inq[v] = true;
				}
			}
		}
	}
	// return dist[t];
	if (dist[t] == -1)
		return {};
	std::vector<int> path;
	int node = t;
	path.push_back(node);
	do {
		node = prd[node];
		path.push_back(node);
	} while (node != s);
	std::reverse(path.begin(), path.end());
	return path;
}
