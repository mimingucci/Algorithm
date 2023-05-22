#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    std::map<int, int> mapp;
    int ans=1;
    mapp[A[0]+A[1]]++;
    bool isOk=true;
    for(int i=2; i<(int)A.size(); i++){
        if(A[i-2]!=A[i]){
            mapp[A[i]+A[i-1]]++;
            ans=max(ans, mapp[A[i]+A[i-1]]);
            isOk=true;
        }else{
            if(isOk==false){
                mapp[A[i]+A[i-1]]++;
                ans=max(ans, mapp[A[i]+A[i-1]]);
                isOk=true;
            }else{
                isOk=false;
            }
        }
    }
    return ans;
}