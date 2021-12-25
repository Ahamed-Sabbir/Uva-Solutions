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
ll power(ll a, ll b){ll res = 1;while(b){if(b&1) res = (res*a)%mod;b>>=1;a = (a*a)%mod;}return res%mod;}
//leftmost set bit
l clz(int N) {return N ? 32 - __builtin_clz(N) : -(1e9+1);}
//ll clz(unsigned long long N){return N ? 64 - __builtin_clzll(N) : -(1e18+1);}
ll setbit(ll x){return __builtin_popcountll(x);}
//ll power(ll a, ll b){ll res = 1;while(b){if(b&1) res = (res*a);b>>=1;a = (a*a);}return res;}
bool arraySortedOrNot(int arr[], int n){if (n == 0 || n == 1) return true;for (int i = 1; i < n; i++)if (arr[i - 1] > arr[i]) return false;return true;}

void run(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
}

int mark[100];
void precal(){
    memset(mark, 0, sizeof(mark));
    mark[66] = 1;mark[80] = 1;mark[70] = 1;mark[86] = 1;mark[68] = 3;mark[84] = 3;mark[76] = 4;
    mark[77] = 5;mark[78] = 5;mark[82] = 6;mark[83] = 2;mark[67] = 2;mark[75] = 2;mark[71] = 2;
    mark[74] = 2;mark[81] = 2;mark[88] = 2;mark[90] = 2;
}

void solve(string s){
    string code = "";
    code+=(s[0]);
    l s_size = s.size();
    l start = 0;
    //cout << mark[((l)s[0])] << endl;
    if(!mark[((l)s[0])]) start = 1;
    else{
        loop(0,s_size-1){
            //cout << mark[((l)s[i])] << " " << mark[((l)s[i+1])] << endl;
            if(mark[((l)s[i])] != mark[((l)s[i+1])]) {
                start = i+1;break;
            }
        }
    }
    //cout << start << " "  << mark[start] << endl;
    l t = 0;
    loop(start, s_size){
        if(mark[((l)s[i])] != 0 && mark[((l)s[i])] != t){
            //cout << s[i] << " " << mark[((l)s[i])] << endl;
            code+=(to_string(mark[((l)s[i])]));
            t = mark[((l)s[i])];
        }
        else{
            if(mark[((l)s[i])] == 0) t = 0;
        }
        if(code.size()==4) break;
    }
    if(code.size() < 4){
        loop(code.size(), 4) code+=(to_string(0));
    }
    for(l i = 0; i < 35;){
        if(i==9){
            cout << s;
            i+=(s_size);
        }
        else if(i==34){
            cout << code << endl;
            break;
        }
        else {
            cout << " ";i++;
        }
    }
}

int main()
{
    //run();
    precal();
    //l n;cin>>n;
    //while(n--) {solve();}
    for(l i = 0; i < 35;){
        if(i==9){
            cout << "NAME";
            i+=4;
        }
        else if(i==34){
            cout << "SOUNDEX CODE" << endl;
            break;
        }
        else {
            cout << " ";i++;
        }
    }
    string s;
    while(cin>>s){
        solve(s);
    }
    loop(0,20){
        if(i==19){
            cout << "END OF OUTPUT" << endl;
            break;
        }
        else cout << " ";
    }
    return 0;
}

/*GUTIERREZ
TYMCZAK
JACKSON
PFISTER*/

