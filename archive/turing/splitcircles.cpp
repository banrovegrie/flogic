#include<bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
#define double long double
double x[2], y[2], rx[2], a[2], b[2];
double PI;

struct pt {
    double x, y;

    pt operator- (pt p) {
        pt res = { x-p.x, y-p.y };
        return res;
    }
};

struct circle : pt {
    double r;
};

struct line {
    double a, b, c;
};


double sqr (double a) {
    return a * a;
}


double ratxio(double r, double d)
{
    double theta = acosl(d/r);
    double A = r*r*0.5;
    double num = 2*theta*A - d*sqrtl(r*r-d*d);
    double dem = 2*(PI-theta)*A+d*sqrtl(r*r-d*d);
    // cout<<num<<" "<<dem<<" "<<r<<" "<<d<<"\n";
    return dem/num;
}
void tangents (pt c, double r1, double r2, vector<line> & ans) {
    double r = r2 - r1;
    double z = sqr(c.x) + sqr(c.y);
    double d = z - sqr(r);
    if (d < -EPS)  return;
    d = sqrt (abs (d));
    line l;
    l.a = (c.x * r + c.y * d) / z;
    l.b = (c.y * r - c.x * d) / z;
    l.c = r1;
    ans.push_back (l);
}

vector<line> tangents (circle a, circle b) {
    vector<line> ans;
    for (int i=-1; i<=1; i+=2)
        for (int j=-1; j<=1; j+=2)
            tangents (b-a, a.r*i, b.r*j, ans);
    for (size_t i=0; i<ans.size(); ++i)
        ans[i].c -= ans[i].a * a.x + ans[i].b * a.y;
    return ans;
}

void solve()
{
    for(int i=0;i<2;i++)
    {
        cin>>x[i]>>y[i]>>rx[i]>>a[i]>>b[i];
        double l=0, r=rx[i];
        double mid = (l+r)*0.5;
        while(r-l>=EPS)
        {
            double xd = ratxio(rx[i], mid);
            // cout<<xd<<"AS\n";
            if(xd>=(double)b[i]/(double)a[i])
            {
                r=mid;
            }
            else
                l=mid;
            mid=(l+r)*0.5;
        }
        rx[i] = mid;
    }
    
    // cout << rx[0] << " " << rx[1] << endl;
    circle c1, c2;
    c1.x = x[0], c1.y = y[0], c1.r = rx[0];
    c2.x = x[1], c2.y = y[1], c2.r = rx[1];

    vector<line> ts = tangents(c1, c2);

    if (ts.empty())
        cout << 0.0 << " " << 0.0 << " " << 0.0 << "\n";
    else
    {
        bool flag = false;

        for (auto i: ts)
        {
            // cout << i.a << ", " << i.b << ", " << i.c << "\n";
            int mul = (i.a * i.a + i.b * i.b);
            if (mul - 0.5 >= EPS)
            {
                flag = true;
                cout << i.a << " " << i.b << " " << i.c << "\n";
                break;
            }
            else
            {
                flag = true;
                cout << i.a * mul << " " << i.b * mul << " " << i.c * mul << endl;
                break;
            }
        }

        if (not flag)
            cout << 0.0 << " " << 0.0 << " " << 0.0 << "\n";
    }
    // double a= 2*(x[1]-x[0]);
    // double b= 2*(y[1]-y[0]);
    // double c= x[0]*x[0]+y[0]*y[0]-x[1]*x[1]-y[1]*y[1]-rx[0]*rx[0]+rx[1]*rx[1];
    // if(a==0 && b==0)
    //     c=0;
    // cout<<a<<" "<<b<<" "<<c<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<fixed<<setprecision(12);
    PI = 2*acosl(0.0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}