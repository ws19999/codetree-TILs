#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;
vector<pair<int,int>> road[2001];
int dist[2001];
unordered_map<int,pair<int, int>> items;
priority_queue<pair<int, int>> pq;
int Q, n, m,start=0;
void dijkstra()
{
	for (int i = 0; i < n; i++)dist[i] = INT_MAX;
	dist[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		int weight = -pq.top().first;
		int land = pq.top().second;
		pq.pop();
		if (weight > dist[land])continue;
		for (auto t : road[land])
		{
			if (dist[t.first] > t.second + weight)
			{
				dist[t.first] = t.second + weight;
				pq.push(make_pair(-dist[t.first], t.first));
			}
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> Q;
	for (int query = 1; query <= Q; query++)
	{
		int q;
		cin >> q;
		if (q == 100)
		{
			cin >> n >> m;
			for (int i = 0; i < m; i++)
			{
				int v, u, w;
				cin >> v >> u >> w;
				road[v].push_back(make_pair(u, w));
				road[u].push_back(make_pair(v, w));
			}
			dijkstra();
		}
		else if (q == 200)
		{
			int id, revenue, d;
			cin >> id >> revenue >> d;
			items[id] = make_pair(revenue, d);
			if (dist[d] < INT_MAX && revenue - dist[d] >= 0)pq.push(make_pair(revenue - dist[d], -id));
		}
		else if (q == 300)
		{
			int id;
			cin >> id;
			items.erase(id);
		}
		else if (q == 400)
		{
			bool find = false;
			while (!pq.empty())
			{
				int id = -pq.top().second;
				if (items[id].first == 0)
				{
					pq.pop();
					continue;
				}
				find = true;
				cout << id << "\n";
				items.erase(id);
				pq.pop();
				break;
			}
			if (!find)cout << "-1\n";
		}
		else if (q == 500)
		{
			cin >> start;
			while (!pq.empty())pq.pop();
			dijkstra();
			for (auto i : items)
			{
				if (dist[i.second.second] < INT_MAX && i.second.first - dist[i.second.second] >= 0)pq.push(make_pair(i.second.first - dist[i.second.second], -i.first));
			}
		}
	}
	return 0;
}