#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int flip[] = { 0, 1, 2, -1, -1, 5, 9, -1, 8, 6 };

int reverseDigits(int a)
{
    int ret = 0;
    while (a > 0) {
        int d = a % 10;
        if (flip[d] == -1)
            return -1;
        ret = flip[d] + ret * 10;
        a /= 10;
    }
    return ret;
}

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int n, s;
    cin>>n>>s;
    std::vector<int> a(n);
    std::vector<int> reverse_a(n);
    multiset<int> sett;
    multiset<int> reverse_sett;
    for(int i=0; i<n; i++){
       cin>>a[i];
       sett.insert(a[i]);
       reverse_a[i]=reverseDigits(a[i]);
       if(reverse_a[i]!=-1){
         reverse_sett.insert(reverse_a[i]);
       }
    }
    bool isOk=false;
    for(int i=0; i<n; i++){
        if(sett.count(s-a[i])>0){
            if(2*a[i]==s){
                if(sett.count(a[i])>1){
                    isOk=true;
                    break;
                }
            }else{
                isOk=true;
                break;
            }
        }
        if(reverse_sett.count(s-a[i])>0){
            if(a[i]+reverse_a[i]==s){
                if(reverse_sett.count(reverse_a[i])>1){
                    isOk=true;
                    break;
                }
            }else{
                isOk=true;
                break;
            }
        }
        if(reverse_sett.count(s-reverse_a[i])>0){
            if(2*reverse_a[i]==s){
                if(reverse_sett.count(reverse_a[i])>1){
                    isOk=true;
                    break;
                }
            }else{
                isOk=true;
                break;
            }
        }
    }
    if(isOk){
        cout<<"YES"<<'\n';
    }else{
        cout<<"NO"<<'\n';
    }
}


