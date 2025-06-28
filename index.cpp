// src/seg_tree.cpp
#include <vector>
using ll = long long;

struct SegTree {
    int n;
    std::vector<ll> tree;
    SegTree(int size): n(size), tree(4*size, 0) {}
    void update(int idx, ll val, int v, int tl, int tr) {
        if (tl == tr) tree[v] = val;
        else {
            int tm = (tl + tr) / 2;
            if (idx <= tm) update(idx, val, v*2, tl, tm);
            else update(idx, val, v*2+1, tm+1, tr);
            tree[v] = tree[v*2] + tree[v*2+1];
        }
    }
    ll query(int l, int r, int v, int tl, int tr) {
        if (l > r) return 0;
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr)/2;
        return query(l, min(r, tm), v*2, tl, tm)
             + query(max(l, tm+1), r, v*2+1, tm+1, tr);
    }
};
