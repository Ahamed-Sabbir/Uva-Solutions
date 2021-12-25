#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int l;
#define loop(a, b) for(int i = a; i < b; i++)

int main()
{
    l ts;
    while(cin>>ts && ts){
        l ts2; cin>>ts2;
        l ara[ts]; loop(0, ts) cin>>ara[i];
        l ara1[ts2]; loop(0, ts2) cin>>ara1[i];
        vector<double> v;
        for(l i = 0; i < ts; i++){
            for(l j = 0; j < ts2; j++){
                double p = ((double)(ara1[j])/(double)(ara[i]));
                v.push_back(p);
            }
        }
        sort(v.begin(), v.end());
        double ans = -1;
        l sz = v.size();
        for(l i = 0; i < sz-1; i++){
            ans = max(ans, v[i+1]/v[i]);
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
