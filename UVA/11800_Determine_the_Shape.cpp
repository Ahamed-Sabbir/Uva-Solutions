#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int l;
#define loop(a, b) for(int i = a; i < b; i++)
#define PI acos(-1.0)
//const ll INF = LLONG_MAX;
 
const ll mod = 1000000007;
ll gcd(ll a,ll b){ if(b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll power(ll a, ll b){ll res = 1;while(b){if(b&1) res = (res*a)%mod;b>>=1;a = (a*a)%mod;}return res%mod;}
//leftmost set bit
l clz(int N) {return N ? 32 - __builtin_clz(N) : -(1e9+1);}
//ll clz(unsigned long long N){return N ? 64 - __builtin_clzll(N) : -(1e18+1);}
ll setbit(ll x){return __builtin_popcountll(x);}
ll power(ll a, ll b){ll res = 1;while(b){if(b&1) res = (res*a);b>>=1;a = (a*a);}return res;}
bool arraySortedOrNot(int arr[], int n){if (n == 0 || n == 1) return true;for (int i = 1; i < n; i++)if (arr[i - 1] > arr[i]) return false;return true;}
// long long v[400002];
// void Quicksort(int begin,int end){
//   int e,b,aux,p;b=begin;e=end;p=v[(e+b)/2];
//   while(v[b]<p){b++;}while(v[e]>p){e--;}while(b<e){aux=v[b];v[b]=v[e];v[e]=aux;do{b++;}while(v[b]<p);
//   do{e--;}while(v[e]>p);}if(begin<e){ Quicksort(begin,e);}
//   if(e+1<end){ Quicksort(e+1,end);}
// }
 
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

vector<pair<l,l> > v;
l lower_index;
bool cmp(pair<l,l> a, pair<l,l> b){
    // l dhal1 = (a.second - v[lower_index].second)/(a.first - v[lower_index].first);
    // l dhal2 = (b.second - a.second)/(b.first - a.first);
    // if(dhal2 > dhal1) return true;
    // if(dhal2 < dhal1) return false;
    // return true;
    l value = (a.second - v[0].second)*(b.first - a.first) - (a.first - v[0].first)*(b.second - a.second);
    if(value < 0) {return true;}
    if(value > 0) {return false;}
    return true;
    // else{
    //     l dis1 = (v[0].first - a.first)*(v[0].first-a.first) + (v[0].second-a.second)*(v[0].second-a.second);
    //     l dis2 = (v[0].first-b.first)*(v[0].first-b.first) + (v[0].second-b.second)*(v[0].second-b.second);
    //     if(dis2 >= dis1) return true;
    //     return false;
    // }
}
l tc = 1;
void solve(){
    v.clear();
    loop(0, 4){
        l x, y;cin>>x>>y;
        v.push_back({x, y});
    }
    lower_index = 0;
    loop(1, 4){
        if(v[i].second < v[lower_index].second) lower_index = i;
        else if(v[i].second == v[lower_index].second) {
            if(v[i].first < v[lower_index].first) lower_index = i;
        }
    }
    swap(v[lower_index], v[0]);
    sort(v.begin()+1, v.end(), cmp);
    // loop(0, 4) cout << v[i].first << " " << v[i].second << endl;
    // cout << endl;
    vector<l> dis;loop(0, 4){
        l cal;
        if(i == 3){
            cal = (v[i].first-v[0].first)*(v[i].first-v[0].first) + (v[i].second-v[0].second)*(v[i].second-v[0].second);
            dis.push_back(cal);
        }
        else {
            cal = (v[i].first-v[i+1].first)*(v[i].first-v[i+1].first) + (v[i].second-v[i+1].second)*(v[i].second-v[i+1].second);
            dis.push_back(cal);
        }
    }
    l korno1 = (v[0].first-v[2].first)*(v[0].first-v[2].first) + (v[0].second-v[2].second)*(v[0].second-v[2].second);
    l korno2 = (v[1].first-v[3].first)*(v[1].first-v[3].first) + (v[1].second-v[3].second)*(v[1].second-v[3].second);

    if(dis[0] == dis[1] && dis[1] == dis[2] && dis[2] == dis[3]){
        if(korno1 == korno2) cout << "Case " << tc++ << ": Square" << endl;
        else cout << "Case " << tc++ << ": Rhombus" << endl;
    }
    else if(dis[0] == dis[2] && dis[1] == dis[3]){
        if(korno1 == korno2) cout << "Case " << tc++ << ": Rectangle" << endl;
        else cout << "Case " << tc++ << ": Parallelogram" << endl;
    }
    else{
        double dhal1, dhal2, dhal3, dhal4;
        l cnt1 = 0, cnt2 = 0;
        double x2_x2 = (double)(v[1].first - v[0].first); double y2_y1 = (double)(v[1].second - v[0].second);
        //cout << y2_y1 << " " << x2_x2 << endl;
        if(x2_x2 != 0) dhal1 = y2_y1/x2_x2;
        else cnt1++;
        x2_x2 = (double)(v[3].first - v[2].first); y2_y1 = (double)(v[3].second - v[2].second);
        //cout << y2_y1 << " " << x2_x2 << endl;
        if(x2_x2 != 0) dhal2 = y2_y1/x2_x2;
        else cnt1++;
        x2_x2 = (double)(v[3].first - v[0].first); y2_y1 = (double)(v[3].second - v[0].second);
        //cout << y2_y1 << " " << x2_x2 << endl;
        if(x2_x2 != 0) dhal3 = y2_y1/x2_x2;
        else cnt2++;
        x2_x2 = (double)(v[2].first - v[1].first); y2_y1 = (double)(v[2].second - v[1].second);
        //cout << y2_y1 << " " << x2_x2 << endl;cout << endl;
        if(x2_x2 != 0)  dhal4 = y2_y1/x2_x2;
        else cnt2++;
        //cout << dhal1 << " " << dhal2 << endl << dhal3 << " " << dhal4 << endl;

        if(cnt1==0 && cnt2==0) {
            //cout << dhal1 << " " << dhal2 << endl << dhal3 << " " << dhal4 << endl;
            if((dhal1 == dhal2) || (dhal3 == dhal4)) cout << "Case " << tc++ << ": Trapezium" << endl;
            else cout << "Case " << tc++ << ": Ordinary Quadrilateral" << endl;
        }  
        else {
            if(cnt1==2 || cnt2==2) cout << "Case " << tc++ << ": Trapezium" << endl;
            else if(cnt1 == 1){
                if(dhal3 == dhal4) cout << "Case " << tc++ << ": Trapezium" << endl;
                else cout << "Case " << tc++ << ": Ordinary Quadrilateral" << endl;
            }
            else if(cnt2 == 1){
                if(dhal1 == dhal2) cout << "Case " << tc++ << ": Trapezium" << endl;
                else cout << "Case " << tc++ << ": Ordinary Quadrilateral" << endl;
            }
            else cout << "Case " << tc++ << ": Ordinary Quadrilateral" << endl;
        }
    }
}
 
int main()
{
    //clock_t tStart = clock();
    //run();
    l n;cin>>n;
    while(n--){solve();}
    //printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}


