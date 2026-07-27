#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct Rect {
    int width, height;
    Rect operator+(const Rect& right) const {
        return (Rect){width + right.width, height + right.height};
    }
    bool operator<(const Rect& right) const {
        return width * height < right.width * right.height;
    }
    bool operator==(const Rect& right) const {
        return width * height == right.width * right.height;
    }
} Rect;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Rect a, b, c, d;
    cin >> a.width >> a.height;
    cin >> b.width >> b.height;
    cin >> c.width >> c.height;
    cin >> d.width >> d.height;

    Rect r1, r2;
    r1 = a + b;
    r2 = c + d;
    if (r1 == r2) {
        cout << "Same";
    } else if (r1 < r2) {
        cout << "Left Small";
    } else {
        cout << "Right Small";
    }
}