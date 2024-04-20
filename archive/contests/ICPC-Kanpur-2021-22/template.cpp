#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T> int sgn(T x) { return (x > T(0)) - (x < T(0)); }
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
  // abs() == dist()
  double dist() const { return sqrt((double)dist2()); }
  // angle to x-axis in interval [-pi, pi]
  double angle() const { return atan2(y, x); }
  P unit() const { return *this / dist(); } // makes dist()=1
  P perp() const { return P(-y, x); }
  // rotates +90 degrees
  P normal() const { return perp().unit(); }
  P translate(P v) { return P(x + v.x, y + v.y); }
  // scale an object by a certain ratio alpha around a
  // center c, we need to shorten or lengthen the vector
  // from c to every point by a factor alpha, while
  // conserving the direction
  P scale(P c, double factor) { return c + (*this - c) * factor; }
  // returns point rotated ’a’ radians ccw around the origin
  P rotate(double a) const {
    return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
  friend ostream &operator<<(ostream &os, P p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
  // Additional random shit
  bool isPerp(P p) { return P(x, y).dot(p) == 0; }
  double angle(P p) {
    double costheta = P(x, y).dot(p) / (*this).dist() / p.dist();
    return acos(fmax(-1.0, fmin(1.0, costheta)));
  }
  T orient(P b, P c) { return (b - *this).cross(c - *this); }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> w >> h;

    int n;
    cin >> n;

    int x1, x2, y1, y2;
    cin >> x1 >> x2;
    cin >> y1 >> y2;
    Point<double> p(x1, y1), q(x2, y2);


    
  }
}
