// Link: https://community.topcoder.com/stat?c=problem_statement&pm=3038

#include <bits/stdc++.h>
using namespace std;
int n;

class BioScore
{
public:
	double maxAvg(string knownSet[]){
       int a[4][4];
       for(int i=0; i<4; i++){
       	memset(a[i], 0, sizeof(a[i]));
       }
       int cnt=0;
       int ans=0;
       for(int i=0; i<n; i++){
       	for(int j=i+1; j<n; j++){
       		for(int k=0; k<(int)knownSet[i].size(); k++){
       			if(knownSet[i][k]==knownSet[j][k]){
                   if(knownSet[i][k]=='A'){
                   	++a[0][0];
                   }
                   if(knownSet[i][k]=='C'){
                   	++a[1][1];
                   }
                   if(knownSet[i][k]=='G'){
                   	++a[2][2];
                   }
                   if(knownSet[i][k]=='T'){
                   	++a[3][3];
                   }
       			}else{
                   if(knownSet[i][k]=='A' && knownSet[j][k]=='C'){
                   	++a[0][1];
                   }
                   if(knownSet[i][k]=='C' && knownSet[j][k]=='A'){
                   	++a[1][0];
                   }
                   if(knownSet[i][k]=='A' && knownSet[j][k]=='G'){
                   	++a[0][2];
                   }
                   if(knownSet[i][k]=='G' && knownSet[j][k]=='A'){
                   	++a[2][0];
                   }
                   if(knownSet[i][k]=='A' && knownSet[j][k]=='T'){
                   	++a[0][3];
                   }
                   if(knownSet[i][k]=='T' && knownSet[j][k]=='A'){
                   	++a[3][0];
                   }
                   if(knownSet[i][k]=='C' && knownSet[j][k]=='G'){
                   	++a[1][2];
                   }
                   if(knownSet[i][k]=='G' && knownSet[j][k]=='C'){
                   	++a[2][1];
                   }
                   if(knownSet[i][k]=='C' && knownSet[j][k]=='T'){
                   	++a[1][3];
                   }
                   if(knownSet[i][k]=='T' && knownSet[j][k]=='C'){
                   	++a[3][1];
                   }
                   if(knownSet[i][k]=='G' && knownSet[j][k]=='T'){
                   	++a[2][3];
                   }
                   if(knownSet[i][k]=='T' && knownSet[j][k]=='G'){
                   	++a[3][2];
                   }
       			}
       		}
       	}
       }
       for(int i=0; i<4; i++){
       	for(int j=0; j<4; j++){
       		cnt+=a[i][j];
       	}
       }
       for(int i=0; i<4; i++){
       	for(int j=0; j<4; j++){
       		if(i<=j && a[i][j]){
       			if(i==j){
       				++ans;
       			}else{
       				ans+=2;
       			}
       		}
       	}
       }
       double best=-99999999;
       int s[6];
       s[0]=10;
       s[1]=10;
       s[3]=-10;
       s[4]=-10;
       s[5]=-10;
       std::vector<int> v;
       v.push_back(a[0][1]+a[1][0]);
       v.push_back(a[0][2]+a[2][0]);
       v.push_back(a[0][3]+a[3][0]);
       v.push_back(a[1][2]+a[2][1]);
       v.push_back(a[1][3]+a[3][1]);
       v.push_back(a[2][3]+a[3][2]);
       sort(begin(v), end(v));
       reverse(begin(v), end(v));
       for(int i=1; i<=10; i++){
       	for(int j=1; j<=10; j++){
       		for(int k=1; k<=10; k++){
       			for(int h=1; h<=10; h++){
       				if((i+j+k+h)%2==0){
                       s[2]=10-(i+j+k+h)/2;
                       int tmp=0;
                       for(int m=0; m<6; m++){
                       	tmp+=v[m]*s[m];
                       }
                       best=max(best,(double)(a[0][0]*i+a[1][1]*j+a[2][2]*k+a[3][3]*h+tmp));
       				}
       			}
       		}
       	}
       }
       return ((double)best/(double)cnt)*((double)ans);
	}
	
};

int main(){
	std::cin.tie(0)->sync_with_stdio(0);
	cin>>n;
    string knownSet[n];
    for(int i=0; i<n; i++){
    	cin>>knownSet[i];
    }
    BioScore x;
    cout << x.maxAvg(knownSet);
	return 0;
}
