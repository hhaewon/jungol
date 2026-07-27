#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct Person {
    int age;
    double height;

    bool operator<(const Person& right) const {
        if (age != right.age) {
            return age > right.age;
        }
        return height > right.height;
    }
} Person;

bool comp(Person& a, Person& b) {
    if (a.height != b.height) {
        return a.height < b.height;
    }
    return a.age < b.age;
}

int N;
Person A[100000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i].age >> A[i].height;
    }
    sort(A, A + N);
    cout << std::fixed;
    cout.precision(1);
    for (int i = 0; i < N; i++) {
        cout << A[i].age << " " << A[i].height << "\n";
    }
    sort(A, A + N, comp);
    cout << "\n";
    for (int i = 0; i < N; i++) {
        cout << A[i].age << " " << A[i].height << "\n";
    }
}