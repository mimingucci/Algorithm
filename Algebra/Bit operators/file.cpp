#include <bits/stdc++.h>
using namespace std;
bool is_set(int n, int x){
	return (n>>x)&1;
}

bool isPowerOfTwo(unsigned int n){
	return n && !(n & (n-1));
}

//Brian Kernighan's algorithm
int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	int x;
    //set x-th bit of n
    n = n | (1<<x);

    //flip x-th bit of n
    n= n ^ (1<<x);

    // clear x-th of n
    n= n & ~(1<<x);

    //clear most-right set bit
    n= n & (n-1);

    //de lai moi bit cuoi duoc set tu trai qua
    n= n & -n;

    //set last cleared bit 001001->001011
    n= n | (n+1);

    //clears all trailing ones
    n= n & (n+1);

    //check power of two: has_single_bit
    //bit_ceil / bit_floor: round up/down to the next power of two
    //rotl / rotr: rotate the bits in the number
    //countl_zero / countr_zero / countl_one / countr_one: count the leading/trailing zeros/ones
    //popcount: count the number of set bits
	return 0;
}