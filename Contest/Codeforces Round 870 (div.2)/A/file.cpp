#include <bits/stdc++.h>
using namespace std;
int main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)cin>>a[i];
        int ans=-1;
        for(int i=0; i<n; i++){
            int maylie=0;
            for(int j=0; j<n; j++){

                if(a[j]>a[i]){
                    ++maylie;
                }
            }
            int truelie=0;
            for(int j=0; j<n; j++){
                if(a[j]>maylie){
                    ++truelie;
                }
            }
            if(truelie==maylie && truelie>=a[i]){
                ans=truelie;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;    
}