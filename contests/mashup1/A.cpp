#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define int long long
pair<int, int> d[(int)1e5 + 5];
pair<int, int> s, e;
int n;
string str;

int f(int mid) {
    int q = mid / n, rem = mid % n;
    return abs(
        s.x + q * d[n].x + d[rem].x - e.x
    ) + abs(
        s.y + q * d[n].y + d[rem].y - e.y
    );
}

string moves = "UDLR";
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

signed main() {
    cin >> s.x >> s.y;
    cin >> e.x >> e.y;
    cin >> n >> str;

    for (int i = 0; i < n; i++) {
		int k = -1;
		for (int j = 0; j < 4; j++)
			if (moves[j] == str[i])
				k = j;
		d[i + 1] = {d[i].x + dx[k], d[i].y + dy[k]};
	}

    int l = 0, r = (int)1e18, mid;
	int q, rem;
    while (r - l > 1) {
		mid = (l + r) / 2;
		if (f(mid) <= mid)
			r = mid;
		else
			l = mid;	
	} 

	if (r >= (int)1e17) 
        cout << -1 << endl;
    else
	    cout << r << endl;
}