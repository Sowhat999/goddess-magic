#include <algorithm>
#include <bitset>
#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

#include "graph_llist.hpp"

long dist[N];	// Distance
int prd[N];	// Pred
std::bitset<N> vis;	// Visited

// Return path (empty) or length of path (-1).
std::vector<int> /* long */ dijkstra(int s, int t)
{
	std::memset(dist, -1, sizeof(dist));
	std::memset(prd, -1, sizeof(prd));
	vis.reset();
	using pii = std::pair<long, int>;
	std::priority_queue<pii, std::vector<pii>, std::greater<pii> > pq;
	dist[s] = 0;
	pq.emplace(0L, s);
	while (!pq.empty()) {
		int node;
		long cdst;
		std::tie(cdst, node) = pq.top();
		pq.pop();
		if (vis[node])
			continue;
		vis[node] = true;
		if (node == t)
			break;
		for (int e = gbegin[node]; e; e = gedges[e].next) {
			int to = gedges[e].to;
			long wei = gedges[e].wei;
			if (!vis[to] && (!~dist[to] || dist[to] > cdst + wei)) {
				prd[to] = node;
				dist[to] = cdst + wei;
				pq.emplace(dist[to], to);
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
