#include <bits/stdc++.h>
using namespace std;
typedef int l;
typedef long long ll;
void run(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output8.txt", "w", stdout);
#else
#endif
}

l p = 1;
void solve(){
    //cout << "green\n";
    if(p != 1) printf("\n");
    l x;cin>>x;l d = x;
    set<double> s;
    vector<double> vt;
    set<double> ::iterator it;
    vector<pair<pair<double, double>, double> > v;
    while(x--){
        double a1,a2,a3,a4,a5;cin>>a1>>a2>>a3>>a4>>a5;
        s.insert(a1);s.insert(a3);
        v.push_back({{a1, a3}, a5});
    }
    for(l i = 0; i < d; i++){
        if(v[i].first.first > v[i].first.second){
            swap(v[i].first.first, v[i].first.second);
        }
    }
    sort(v.begin(), v.end());
    for(it = s.begin(); it != s.end(); it++) vt.push_back(*it);
    vector<pair<pair<double, double>, double> > result;
    l sz = vt.size();
    l sz1 = v.size();
    for(l i = 0; i < sz-1; i++){
        double res = 1.000;
        for(l j = 0; j < sz1; j++){
            if(vt[i] >= v[j].first.first && vt[i+1] <= v[j].first.second){
                res *= (v[j].second+0.000);
            }
        }
        result.push_back({{vt[i], vt[i+1]}, res});
    }
    printf("%d\n", sz+1);
    printf("-inf %.3lf 1.000\n", vt[0]);
    for(l i = 0; i < sz-1; i++){
        printf("%0.3lf %0.3lf %0.3lf\n", result[i].first.first, result[i].first.second, result[i].second);
    }
    printf("%.3lf +inf 1.000\n", vt[sz-1]);
    p++;
    //s.clear(); vt.clear(); v.clear(); result.clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //run();
    l n;cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
