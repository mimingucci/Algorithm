int length(int pos) {
    int bit = 0;
    while ((pos >> bit) & 1 == 0) {
        ++bit;
    }
    return (1 << bit);
}

~ int lsb(int pos) {
    return pos & -pos;
}//find the length of interval end at index pos   

void update(int pos, int val) {
    while (pos <= N) {
        fenwick[pos] += val;
        pos += lsb(pos);
    }
}

int query(int pos) {
   int sum = 0;
   while (pos > 0) {
      sum += fenwick[pos];
      pos -= lsb(pos);
   }
   return sum;
}