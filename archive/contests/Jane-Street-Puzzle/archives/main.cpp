#include <bits/stdc++.h>
using namespace std;

class PentagonCenter {
public:
    short dx1, dx2, dy1, dy2, dy3;
    bool orientation;

    PentagonCenter(short x1, short x2, short y1, short y2, short y3, bool o) : 
        dx1(x1), dx2(x2), dy1(y1), dy2(y2), dy3(y3), orientation(o) {
    }

    PentagonCenter get_neighbor(char side_id) {
        int o = orientation ? +1 : -1;
        switch (side_id) {
            case 'A':
                return PentagonCenter(dx1, dx2, dy1, dy2, dy3 - o, !orientation);
            case 'B':
                return PentagonCenter(dx1, dx2 - 1, dy1, dy2 - o, dy3, !orientation);
            case 'C':
                return PentagonCenter(dx1 - 1, dx2, dy1 + o, dy2, dy3, !orientation);
            case 'D':
                return PentagonCenter(dx1 + 1, dx2, dy1 + o, dy2, dy3, !orientation);
            case 'E':
                return PentagonCenter(dx1, dx2 + 1, dy1, dy2 - o, dy3, !orientation);
            default:
                cout << "Invalid side name" << endl;
                exit(1);
        }
    }

    pair<double, double> center_position() {
        double tan54 = tan(3 * M_PI / 10);
        double cos36 = cos(M_PI / 5);
        double sin36 = sin(M_PI / 5);
        return {
            dx1 * cos(M_PI / 5),
            dy1 * tan54 * sin36 + dy2 * tan54 *  + dy3 * tan54
        };
    }

    tuple<int, int, int, int, int, bool> as_tuple() {
        return {dx1, dx2, dy1, dy2, dy3, orientation};
    }

    friend bool operator<(const Pentagon& p1, const Pentagon& p2) {
        return p1.as_tuple() < p2.as_tuple();
    }
};

void find_centres() {
    
}

int main()
{
    return 0;   
}