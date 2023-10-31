/* pseudo:
def add(b, idx, x):
    while idx <= N:
        b[idx] += x
        idx += idx & -idx

def range_add(l,r,x):
    add(B1, l, x)
    add(B1, r+1, -x)
    add(B2, l, x*(l-1))
    add(B2, r+1, -x*r)

def sum(b, idx):
    total = 0
    while idx > 0:
        total += b[idx]
        idx -= idx & -idx
    return total

def prefix_sum(idx):
    return sum(B1, idx)*idx -  sum(B2, idx)

def range_sum(l, r):
    return prefix_sum(r) - prefix_sum(l-1)
*/
std::vector<int> B1, B2;
void add(std::vector<int> a, int idx, int value){
    for(; idx<a.size(); idx+=(idx&(-idx))){
       a[idx]+=value;
    }
}
void range_add(int l, int r, int value){
    add(B1, l, value);
    add(B1, r+1, value);
    add(B2, l, value*(l-1));
    add(B2, r+1, -value*r);
}
int sum(std::vector<int> a, int idx){
    int res=0;
    for(; idx>0; idx-=(idx&(-idx))){
        res+=a[idx];
    }
    return res;
}
int prefix_sum(int idx){
    return sum(B1, idx)*idx-sum(B2, idx);
}
int range_sum(int l, int r){
    return prefix_sum(r)-prefix_sum(l-1);
}