#include <algorithm>
#include <bitset>
#include <cstring>
#include <queue>
#include <tuple>
#include <vector>

#include "graph_llist.hpp"

BigInt dist[N];	// Distance
int prd[N];	// Pred
std::bitset<N> vis;	// Visited

// Return path (empty) or length of path (-1).
std::vector<int> /* BigInt */ dijkstra(int s, int t)
{
	std::memset(dist, -1, sizeof(dist));
	std::memset(prd, -1, sizeof(prd));
	vis.reset();
	using pii = std::pair<BigInt, int>;
	std::priority_queue<pii, std::vector<pii>, std::greater<pii> > pq;
	dist[s] = 0;
	pq.emplace(0L, s);
	while (!pq.empty()) {
		int u;
		BigInt du;
		std::tie(du, u) = pq.top();
		pq.pop();
		if (vis[u])
			continue;
		vis[u] = true;
		if (u == t)
			break;
		for (int e = gbegin[u]; e; e = gedges[e].next) {
			int v = gedges[e].to;
			BigInt w = gedges[e].wei;
			if (!vis[v] && (dist[v] == -1 || dist[v] > du + w)) {
				prd[v] = u;
				dist[v] = du + w;
				pq.emplace(dist[v], v);
			}
		}
	}
	// return dist[t];
	if (!vis[t])
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
