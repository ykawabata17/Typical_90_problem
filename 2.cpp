#include <bits/stdc++.h>
using namespace std;

#define rep(i,l,r)for(int i=(l);i<(r);i++)
#define PI 3.1415926535897932384626433832795028841971
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
    if (N%2 == 1) return 0;
    for (int bit = (1<<N); bit >= 0; --bit) {
        string bs = bitset<20>(bit).to_string();
        bs = bs.substr(20-N, N);
        int cnt_one = count(bs.begin(), bs.end(), '1');
        int cnt_zero = count(bs.begin(), bs.end(), '0');
        if (cnt_one != cnt_zero) continue;
        int num = 0;
        bool flag = true;
        rep(i, 0, N) {
            if (bs[i] == '1') num+=1;
            else num-=1;
            if (num < 0) flag = false;
        }
        if (flag) {
            rep(i, 0, N) {
                if (bs[i] == '1') cout << '(';
                else cout << ')';
            }
            cout << endl;
        }
    }
    return 0;
}