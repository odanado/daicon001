#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <array>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const int SIZE = 30;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
using Vector = array<int, SIZE>;
using Matrix = array<Vector, SIZE>;
using Graph = array<vector<int>, SIZE * SIZE>;

#ifndef COEFFICIENT1
#define COEFFICIENT1 0.3
#endif
#ifndef COEFFICIENT2
#define COEFFICIENT2 0.1
#endif

std::ostream &operator<<(std::ostream &os, const P &p) {
    os << p.first + 1 << " " << p.second + 1;
    return os;
}
void input(Matrix &A) { rep(i, SIZE) rep(j, SIZE) cin >> A[i][j]; }

void breakStone(Matrix &A, const P &p) { --A[p.first][p.second]; }

int toVertex(int i, int j) { return i * SIZE + j; }

P toPoint(int v) { return P(v / SIZE, v % SIZE); }

int getStoneCount(const Matrix &A, int v) {
    auto p = toPoint(v);
    return A[p.first][p.second];
}

struct State {
    vector<int> vec;
    int root;
    void push_back(int v) { vec.push_back(v); }
    void pop_back() { vec.pop_back(); }
    void clear() {
        vec.clear();
        root = -1;
    }
    double eval(const Matrix &A) {
        if (root == -1) return 0;
        return COEFFICIENT1 * getStoneCount(A, root) +
               COEFFICIENT2 * vec.size();
    }
};

Graph makeGraph(const Matrix &mat) {
    Graph G;
    rep(i, SIZE) rep(j, SIZE) rep(k, 4) {
        if (mat[i][j] == 1) continue;
        int ny = i + dy[k];
        int nx = j + dx[k];
        if (nx < 0 || ny < 0) continue;
        if (nx >= SIZE || ny >= SIZE) continue;
        if (mat[i][j] - 1 == mat[ny][nx])
            G[toVertex(i, j)].push_back(toVertex(ny, nx));
    }
    return std::move(G);
}
void printGraph(const Graph &G) {
    rep(i, SIZE * SIZE) {
        if (G[i].empty()) continue;
        cout << i << " -> " << endl;
        for (auto u : G[i]) cout << "\t" << u << endl;
    }
}
void dfs(const Matrix &A, const Graph &G, int v, State &cur, State &ret) {
    if (G[v].empty()) {
        if (cur.eval(A) > ret.eval(A)) ret = cur;
        return;
    }
    for (auto &u : G[v]) {
        cur.push_back(u);
        dfs(A, G, u, cur, ret);
        cur.pop_back();
    }
}
bool finish(const Matrix &A) {
    bool ret = true;
    rep(i, SIZE) rep(j, SIZE) ret &= A[i][j] == 0;
    return ret;
}
Graph G;
Matrix A;

int main() {
    int cnt = 0;
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    input(A);
    State cur, ret;
    ret.root = -1;
    while (!finish(A)) {
        cnt++;
        auto G = makeGraph(A);
        rep(i, SIZE) rep(j, SIZE) {
            if (A[i][j] == 0) continue;
            int v = toVertex(i, j);
            cur.clear();
            cur.push_back(v);
            cur.root = v;
            dfs(A, G, v, cur, ret);
        }
        for (auto &e : ret.vec) {
            auto p = toPoint(e);
            breakStone(A, p);
            cout << p << endl;
        }
        cur.clear();
        ret.clear();
    }
    cerr << cnt << endl;
    return 0;
}
