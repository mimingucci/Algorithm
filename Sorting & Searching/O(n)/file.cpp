// sorting in case n is large, nlog(n) is not enough, base * base > n
// For all values less than base^2 (base = 2^15), the time complexity comes out to be O(n + base), 2 * n(2 for loops of n) + base(memory definition and prefix array). you can choose base depending on max value of array, N and memory.
// For n > base it starts becoming faster and faster than cpp sort.
void sortit(vector<int> &arr, int base = 1 << 15) {
    int n = arr.size();
    
    vector<vector<int>> grps(base);
    vector<int> cnts(base + 1), live(base);
    for (int i = 0; i < n; i++) {
        int z = arr[i] / base;
        grps[arr[i] % base].push_back(z);   //adding each element in respective group
        cnts[z + 1]++;  //increasing count
    }
    for (int i = 1; i < base; i++) cnts[i] += cnts[i - 1]; //making prefix array
    
    for (int i = 0; i < base; i++) {
        for (int &x : grps[i]) arr[cnts[x] + live[x]++] = x * base + i;
    }
}