#include <bits/stdc++.h>
using namespace std;

template <typename T>
void find_shortest_distance(T start, vector<T> &dist, const vector<vector<T>> &graph, const T &edge) {
    const T INF = (1 << 30);// caution!
    for (T i = 0; i < edge; i++) dist[i] = INF;

    queue<T> que;
    que.push(start);
    dist[start] = 0;

    while (!que.empty()) {
        T pos = que.front(); que.pop();
        for (T to : graph[pos]) {
            if (dist[to] == INF) {
                dist[to] = dist[pos] + 1;
                que.push(to);
            }
        }
    }
}
