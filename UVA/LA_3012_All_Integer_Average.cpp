#include <bits/stdc++.h>
using namespace std;
typedef int l;
typedef long long int ll;
#define loop(a, b) for(int i = a; i < b; i++)
#define PI acos(-1.0)
const ll INF = LLONG_MAX;

const ll mod = 1000000007;
ll gcd(ll a,ll b){ if(b == 0) return a; return gcd(b, a % b); }
 ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll power(ll a, ll b){ll res = 1;while(b){if(b&1) res = (res*a)%mod;b>>=1;a = (a*a)%mod;}return res%mod;}
//leftmost set bit
l clz(int N) {return N ? 32 - __builtin_clz(N) : -(1e9+1);}
//ll clz(unsigned long long N){return N ? 64 - __builtin_clzll(N) : -(1e18+1);}
l setbit(l x){return __builtin_popcountll(x);}
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

l j = 1;

void solve(){
    l n;
    while(cin>>n && n){
        cout << "Case " << j++ << ":" << endl;
        l sum = 0;
        loop(0, n){l x;cin>>x; sum+=x;}
        if(((sum/n)*n) == sum) {
            if(sum < 0) cout << "- " << (sum*(-1))/n << endl;  
            else cout << sum/n << endl;
        }
        else if(abs(sum/n) < 1){
            if(sum < 0) {l gcd = __gcd((sum*-1), n); sum/=gcd; n/=gcd;}
            if(sum > 0) {l gcd = __gcd((sum), n); sum/=gcd; n/=gcd;}
            if(sum < 0) {
                sum*=(-1);
                l s = (to_string(n)).size();
                l s1 = (to_string(sum)).size();
                l dif = s - s1;
                loop(0, dif+2) cout << " ";
                cout << sum << endl << "- "; 
                loop(0, s) cout << "-";
                cout << endl << "  " << n << endl;
                
            }
            else {
                l s = (to_string(n)).size();
                l s1 = (to_string(sum)).size();
                l dif = s - s1;
                loop(0, dif) cout << " ";
                cout << sum << endl; loop(0, s) cout << "-";
                cout << endl << n << endl;
            }
        }
        else{
            if(sum < 0) {l gcd = __gcd((sum*-1), n); sum/=gcd; n/=gcd;}
            if(sum > 0) {l gcd = __gcd((sum), n); sum/=gcd; n/=gcd;}
            if(sum > 0) {
                l s = (to_string(n)).size();
                l s1 = (to_string((sum - ((sum/n)*n)))).size();
                l s3 = (to_string(sum/n)).size();
                l dif = s - s1; loop(0, dif+s3) cout << " ";
                cout << (sum - ((sum/n)*n)) << endl << sum/n; loop(0, s) cout << "-";
                cout << endl; loop(0, s3) cout << " ";
                cout << n << endl;
            }
            else {
                sum *= (-1);
                l s = (to_string(n)).size();
                l s1 = (to_string((sum - ((sum/n)*n)))).size();
                l s3 = (to_string(sum/n)).size();
                l dif = s - s1; loop(0, dif+s3+2) cout << " ";
                cout << (sum - ((sum/n)*n)) << endl << "- " << sum/n; loop(0, s) cout << "-";
                cout << endl; loop(0, s3+2) cout << " ";
                cout << n << endl;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //clock_t tStart = clock(); 
    run();
    //l n;cin>>n;
    //while(n--) {solve();}
    solve();
    //string s;while(cin>>s){solve(s);}
    //printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}


// 11 1 -1 1 -1 1 -1 -1 1 1 -3 7
// 11 1 -1 1 -1 1 -1 -1 1 1 -3 -5
// 3 1 2 4
// 4 2 4 6 10
// 3 -1 -2 -4
// 10 1 1 1 1 1 1 1 1 1 4
// 10 1 -1 1 -1 1 -1 -1 1 1 1
// 10 1 -1 1 -1 1 -1 -1 1 1 -3
// 0
