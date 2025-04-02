//Link: https://codeforces.com/problemset/problem/492/B
#include<bits/stdc++.h>
#define V(all) v.begin(),v.end()
using namespace std;

int main(){
    int n, l, a;
    cin >> n >> l;
    vector<int> v;
    while(n--){
        cin >> a;
        v.push_back(a);
    }

    double dis = 0, temp = 0;
    sort(V(all));

    if(v.size()==1){
        if(v[0] == 0){
            dis = l;
        }
        else{
            dis = max(v[0], l-v[0]);
        }
    }
    else if(v[0]!=0){
        dis = v[0];
        for(int i = 0; i < v.size()-1; i++){
            temp = (double)(v[i+1]-v[i])/2;
            if(temp > dis){
                dis = temp;
            }
        }
    }
    else if(v[0]==0){
        dis = (double)v[1]/2;
        for(int i = 1; i < v.size()-1; i++){
            temp = (double)(v[i+1]-v[i])/2;
            if(temp > dis){
                dis = temp;
            }
        }
    }
    


    if(v[v.size()-1] < l){
        temp = l - v[v.size()-1];
        if(temp > dis){
            dis = temp;
        }
    }
    
    cout << fixed << setprecision(10) << dis << endl;
    return 0;
}

//Shorter Version:
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int n;
	double l;
	cin>>n>>l;
	double a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	
	sort(a,a+n);
	
	double res=max(a[0],l-a[n-1]);
	for(int i=1;i<n;i++)
	{
		res=max(res,(a[i]-a[i-1])/2);
	}
	cout<<fixed<<setprecision(10)<<res<<endl;
}
*/