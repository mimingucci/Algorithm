void add(int idx, int val) {
    for (++idx; idx < n; idx += idx & -idx)
        bit[idx] += val;
}

void range_add(int l, int r, int val) {
    add(l, val);
    add(r + 1, -val);
}

int point_query(int idx) {
    int res = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
        res += bit[idx];
    return res;
}