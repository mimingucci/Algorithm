#include <bits/stdc++.h>
using namespace std;

int countNumber(int a){
    int cnt=0;
    while(a>0){
        ++cnt;
        a/=10;
    }
    return cnt;
}

void solution(vector<int> &A, int K) {
    int maxx=*max_element(begin(A), end(A));
    int cnt=countNumber(maxx);
    int numberOfRow=(int)A.size()/K;
    int numberOfLastRow=(int)A.size()%K;
    if(numberOfRow>0){
      for(int i=0; i<numberOfRow; i++){
        int now=0;
        for(int j=0; j<K; j++){
            cout<<'+';
            for(int m=0; m<cnt; m++){
                cout<<'-';
            }
        }
        cout<<'+'<<'\n';
        for(int j=0; j<K; j++){
            cout<<'|';
            for(int m=0; m<=cnt-1-countNumber(A[K*i+now]); m++){
                cout<<' ';
            }
            cout<<A[K*i+now];
            ++now;
        }
        cout<<'|'<<'\n';
    }
    for(int j=0; j<K; j++){
            cout<<'+';
            for(int m=0; m<cnt; m++){
                cout<<'-';
            }
    }
    cout<<'+'<<'\n';
    if(numberOfLastRow==0){
        return;
    }else{
        int now=0;
        for(int j=0; j<numberOfLastRow; j++){
            cout<<'|';
            for(int m=0; m<=cnt-1-countNumber(A[K*numberOfRow+now]); m++){
                cout<<' ';
            }
            cout<<A[K*numberOfRow+now];
            ++now;
        }
        cout<<'|'<<'\n';
        for(int j=0; j<numberOfLastRow; j++){
            cout<<'+';
            for(int m=0; m<cnt; m++){
                cout<<'-';
            }
        }

        cout<<'+'<<'\n';
    }
    }else{
        for(int j=0; j<numberOfLastRow; j++){
            cout<<'+';
            for(int m=0; m<cnt; m++){
                cout<<'-';
            }
        }
        cout<<'+'<<'\n';
        int now=0;
        for(int j=0; j<numberOfLastRow; j++){
            cout<<'|';
            for(int m=0; m<=cnt-1-countNumber(A[K*numberOfRow+now]); m++){
                cout<<' ';
            }
            cout<<A[K*numberOfRow+now];
            ++now;
        }
        cout<<'|'<<'\n';
        for(int j=0; j<numberOfLastRow; j++){
            cout<<'+';
            for(int m=0; m<cnt; m++){
                cout<<'-';
            }
        }
        cout<<'+'<<'\n';
    }
    
}