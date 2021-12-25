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

double total_dis = 0.0;
double speed = 0.0;
double total_now = 0.0, total_prev = 0.0;
double total_t = 0.0;
l h,m,s;
void solve(char st[]){
    /*char s1[7];char s2[50] = {0};
    l sz = strlen(st);
    if(sz == 8){
        strcpy(s1, st);
    }else{
        for(l i = 0; i < 8; i++) s1[i] = st[i];
        for(l i = 9, j = 0; i < sz; i++) s2[j++] = st[i];
    }*/
    sscanf(st, "%d:%d:%d", &h,&m,&s);
    total_now = (h*3600.0)+(m*60.0)+(s+0.0);
    total_t = abs(total_now-total_prev);
    //cout << total_t << " " << speed << endl;
    if(st[8] != '\0'){
        total_dis += ((speed*total_t)/3600.0);
        total_prev = total_now;
        sscanf(st+8, "%lf", &speed);
    }else {
        total_dis += ((speed*total_t)/3600.0);
        total_prev = total_now;
        printf("%s %.2lf km\n", st, total_dis);
    }
}

int main()
{
    //run();
    //l n;cin>>n;
    //while(n--) {solve();}
    char st[1000];
    while(scanf(" %[^\n]", &st) != EOF){
        solve(st);
    }
    return 0;
}

