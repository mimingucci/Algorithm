#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> &D, int X) {
    int cnt=1;
    int minn=D.front();
    int maxx=D.front();
    for(int i=1; i<(int)D.size(); i++){
       if(abs(D[i]-minn)<=X && abs(D[i]-maxx)<=X){
        minn=min(minn, D[i]);
        maxx=max(maxx, D[i]);
       }else{
        ++cnt;
        minn=D[i];
        maxx=D[i];
       }
    }
    return cnt;
}