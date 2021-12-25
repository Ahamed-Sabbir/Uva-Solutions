#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int l;
#define loop(a, b) for(int i = a; i < b; i++)

bool cmp(pair<string, pair<l,l> >a, pair<string, pair<l,l> >b){
    if(a.second.first > b.second.first) return true;
    if(a.second.first == b.second.first) {
        if(a.second.second < b.second.second) return true;
        if(a.second.second == b.second.second) return a.first < b.first;
    }
    return false;
}

l ca = 1;

int main()
{
    l ts;cin>>ts;
    while(ts--){
        cout << "Case " << ca++ << ":" << endl;
        l x = 10;
        vector<pair<string, pair<l,l> > > v;
        while(x--){
            string s;cin>>s;l a, b;cin>>a>>b;
            v.push_back({s, {a, b}});
        }
        sort(v.begin(), v.end(), cmp);
        vector<string> v1, v2;
        loop(0, 5) v1.push_back(v[i].first);
        loop(5, 10) v2.push_back(v[i]. first);
        sort(v1.begin(), v1.end()); sort(v2.begin(), v2.end());
        cout << "(" << v1[0];loop(1, 5) cout << ", " << v1[i];
        cout << ")" << endl;
        cout << "(" << v2[0]; loop(1, 5) cout << ", " << v2[i]; 
        cout << ")" << endl;
    }
    return 0;
}
