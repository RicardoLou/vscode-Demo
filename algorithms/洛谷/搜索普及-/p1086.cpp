#include<bits/stdc++.h>
using namespace std;
const int N = 25;
const int M = 25;
int n, m, k;
struct point
{
	int x, y, value;
};
vector<point> points;

bool cmp(point& a, point& b) {
	return a.value > b.value;
}
int main() {
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			int x;
			cin >> x;
			if (x) {
				point p = {i, j, x};
				points.push_back(p);
			}
		}
	}
	// 按花生数量排序
	sort(points.begin(), points.end(), cmp);
	int time = points[0].x + 1;
	if (time + points[0].x > k) {
		cout << 0;
		return 0;
	}
	int ans = points[0].value; // 最多的直接走直线过去采摘
	for(int i = 0; i < points.size() - 1; i ++) {
		time += abs(points[i].x - points[i + 1].x) + abs(points[i].y - points[i + 1].y) + 1; // 曼哈顿距离 + 采摘时间
		if(time + points[i + 1].x > k)
			break;
		ans += points[i + 1].value; 
	}
	cout << ans;
}