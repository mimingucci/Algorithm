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
# A[] is the original array
# ft[] is the fenwick tree maintaining the diffs initialized with 0
update(ft, p, v):
  for (; p <= N; p += p&(-p))
    ft[p] += v   

# Add v to A[a...b] 
update(a, b, v):    
  update(B1, a, v)  
  update(B1, b + 1, -v)     
  update(B2, a, v * (a-1))  
  update(B2, b + 1, -v * b)      

query(ft, b):   
  sum = 0   
  for(; b > 0; b -= b&(-b))
    sum += ft[b]
  return sum

# Return sum A[1...b]
query(b):
  return query(B1, b) * b - query(B2, b)

# Return sum A[a...b]
query(a, b):
  return query(b) - query(a-1)