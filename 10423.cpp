#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct go {
	int x;
	int y;
	int z;
};

typedef pair<int, pair<int, int> > pa;
int n, m, k;
int visit[1010];

vector<int> elc;
vector<go> v;
int parent[1010];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y)
		parent[x] = y;
}

bool com(go a, go b) {
	if (a.z < b.z) return true;
	return false;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);
		elc.push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	priority_queue<pa, vector<pa>, greater<>> q;

	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		v.push_back({ x,y,z });
	}

	for (int i = 0; i < k - 1; i++) {
		int now = elc[i];
		int next = elc[i + 1];
		Union(now, next);
	}
	int ans = 0;
	sort(v.begin(), v.end(), com);

	for (int i = 0; i < v.size(); i++) {
		int now = v[i].x;
		int next = v[i].y;
		int dist = v[i].z;
		if (Find(now) != Find(next)) {
			ans += dist;
			Union(now, next);
			k++;
		}
		if (k == n) break;
	}

	cout << ans << endl;

	return 0;
}