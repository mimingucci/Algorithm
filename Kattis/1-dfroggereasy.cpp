#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF=1e9+7;

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int n, s, value;
    cin>>n>>s>>value;
    std::vector<int> a(n+1);
    for(int i=1; i<=n; i++)cin>>a[i];
    std::vector<int> next(n+1);
    std::vector<bool> visited(n+1, false);
    for(int i=1; i<=n; i++){
        if(i+a[i]>n){
            next[i]=INF;
        }else{
            if(i+a[i]<1){
                next[i]=-1;
            }else{
                next[i]=i+a[i];
            }
        }
    }
    int h=0;
    int now=s;
    if(a[now]==value){
        cout<<"magic"<<'\n';
        cout<<0<<'\n';
    }else{
        visited[now]=true;
        while((now>=1 && now<=n) && a[now]!=value){
           now=next[now];
           ++h;
           if(now<1 || now>n)break;
           if(visited[now]){
            break;
           }else{
            visited[now]=true;
           }
        }
        if(now<1){
           cout<<"left"<<'\n';
           cout<<h<<'\n';
        }else{
            if(now>n){
                cout<<"right"<<'\n';
                cout<<h<<'\n';
            }else{
                if(a[now]==value){
                    cout<<"magic"<<'\n';
                    cout<<h<<'\n';
                }else{
                    cout<<"cycle"<<'\n';
                    cout<<h<<'\n';
                }
            }
        }
    }
}


