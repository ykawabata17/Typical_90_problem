#include <bits/stdc++.h>
using namespace std;

#define rep(i,l,r)for(int i=(l);i<(r);i++)
#define PI 3.1415926535897932384626433832795028841971
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using Graph = vector<vector<int>>;
const long long INF = (1LL << 60);
const int ddx[4] = {1, 0, -1, 0};
const int ddy[4] = {0, 1, 0, -1};

template <class T> bool chmin(T& a, const T& b) { return a > b ? a = b, true : false; }
template <class T> bool chmax(T& a, const T& b) { return a < b ? a = b, true : false; }


template <class T>
void printVector(const vector<T>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}


int main() {
    int N; cin >> N;
    vector<ll> A, B;
    rep(i, 0, N) {
        int a; cin >> a;
        A.push_back(a);
    }
    rep(i, 0, N) {
        int b; cin >> b;
        B.push_back(b);
    }
    // AとBを昇順ソートする
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    ll ans = 0;
    rep(i, 0, N) {
        ans += abs(A[i]-B[i]);
    }
    cout << ans << endl;
    return 0;
}
