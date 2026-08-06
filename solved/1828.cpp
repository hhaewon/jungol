#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Material {
    int start, end;
    bool operator<(const Material& right) const {
        if (end != right.end) {
            return end < right.end;
        }
        return start < right.start;
    }
};

int N;
Material materials[100];
vector<Material> used;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        Material material = {s, e};
        materials[i] = material;
    }
    sort(materials, materials + N);
    used.push_back(materials[0]);
    for (int i = 1; i < N; i++) {
        if (materials[i].start > used.back().end) {
            used.push_back(materials[i]);
        }
    }

    cout << used.size();
}