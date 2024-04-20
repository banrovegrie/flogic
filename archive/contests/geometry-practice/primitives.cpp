#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }

/**
 * DEFINITION OF A POINT
 */
template <class T> struct Point {
  typedef Point P;
  T x, y;
  explicit Point(T x = 0, T y = 0) : x(x), y(y) {}

  bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }

  P operator+(P p) const { return P(x + p.x, y + p.y); }
  P operator-(P p) const { return P(x - p.x, y - p.y); }
  P operator*(T d) const { return P(x * d, y * d); }
  P operator/(T d) const { return P(x / d, y / d); }

  T dot(P p) const { return x * p.x + y * p.y; }
  T cross(P p) const { return x * p.y - y * p.x; }
  T cross(P a, P b) const { return (a - *this).cross(b - *this); }
  T dist2() const { return x * x + y * y; }
  double dist() const { return sqrt((double)dist2()); }

  // angle to x-axis in interval [-pi, pi]
  double angle() const { return atan2(y, x); }

  // makes dist() = 1
  P unit() const { return *this / dist(); }
  // rotates +90 degrees
  P perp() const { return P(-y, x); }
  P normal() const { return perp().unit(); }
  // returns point rotated ’a’ radians ccw around the origin
  P rotate(double a) const {
    return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
  friend ostream &operator<<(ostream &os, P p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};

/**
 * LINE DISTANCE
 */
template <class P> double lineDist(const P &a, const P &b, const P &p) {
  return (double)(b - a).cross(p - a) / (b - a).dist();
}

int main() {
  // freopen("sample.in", "r", stdin);
  // freopen("sample.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  Point<double> p1(0, 3);
  Point<double> p2(1, 2);
  Point<double> p3(2, 5);
  cout << p1.cross(p2) << endl;
  cout << sgn('3') << endl;

  cout << lineDist(p1, p2, p3) << endl;
}
