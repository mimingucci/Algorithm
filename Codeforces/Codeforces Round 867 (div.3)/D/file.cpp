#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii int64_t
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		ii n;
		cin>>n;
		bool isOk=true;
		ii a[n];
		a[0]=n;
		ii sum=n;
		vector<bool> used(n+1, false);
		used[n]=true;
		ii l=1;
		ii r=1;
		for(ii i=1; i<n; i++){
          if(i%2!=0){
          	ii du=sum%n;
            if(du==n-l){
              isOk=false;
              break;
            }else{
            	if(du>n-l){
            		ii inc=n-du+n-l;
            		if(used[inc]){
            			isOk=false;
            			break;
            		}else{
            			a[i]=inc;
            			
            			used[inc]=true;
            		}
            	}else{
            		ii des=n-l-du;
            		if(used[des]){
            			isOk=false;
            			break;
            		}else{
            			a[i]=des;

            			used[des]=true;
            		}
            	}
            }
            sum+=a[i];
            ++l;
            
          }else{
            ii du=sum%n;
            if(du==r){
              isOk=false;
              break;
            }else{
            	if(du>r){
            		ii inc=n-du+r;
            		if(used[inc]){
            			isOk=false;
            			break;
            		}else{
            			a[i]=inc;
            			used[inc]=true;
            		}
            	}else{
            		ii des=r-du;
            		if(used[des]){
            			isOk=false;
            			break;
            		}else{
            			a[i]=des;
            			used[des]=true;
            		}
            	}
            }
            sum+=a[i];
            ++r;
          }
		}
		if(isOk){
			for(ii i : a){
				cout<<i<<" ";
			}
			cout<<'\n';
		}else{
			cout<<-1<<'\n';
		}
	}
	return 0;
}