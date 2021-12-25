#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int l;
#define loop(a, b) for(int i = a; i < b; i++)

l q = 1;

int main()
{
    l ts;
    while(cin>>ts && ts){
        if(q != 1) cout << endl;
        vector<pair<l, string> > v;
        v.clear();
        string s = "", t = "";
        for(l i = 10000; i <= 99999; i++){
            t = "";
            if(i % ts == 0){
                s = to_string(i/ts);
                l sz = s.size();
                if(sz <= 3) continue;
                while(sz != 5){ t+='0';sz++;}
                t+=s;
                set<char> c;
                for(l k = 0; k < 5; k++) c.insert(t[k]);
                if(c.size() < 5) continue;
                string d = to_string(i);
                for(l k = 0; k < 5; k++) c.insert(d[k]);
                if(c.size() < 10) continue;
                c.clear();
                v.push_back({i, t});
            }
        }
        sort(v.begin(), v.end());
        l sz = v.size();
        if(sz == 0) cout << "There are no solutions for " << ts << "." << endl;
        else{
            loop(0, sz) cout << v[i].first << " / " << v[i].second << " = " << ts << endl;
        }
        q++;
    }
    return 0;
}
