#include <bits/stdc++.h>
using namespace std;
typedef int l;
typedef long long int ll;
#define loop(a, b) for(int i = a; i < b; i++)

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

char mark[102][5];

l check1(char d, char d1){
    if(d == 'r' && d1 == 'P') return 0;
    if(d == 'o' && d1 == 'G') return 1;
    if(d == 'y' && d1 == 'A') return 2;
    if(d == 'g' && d1 == 'S') return 3;
    if(d == 'b' && d1 == 'N') return 4;
    return -1;
}

l check(char d){
    if(d == 'r') return 0;
    if(d == 'o') return 1;
    if(d == 'y') return 2;
    if(d == 'g') return 3;
    if(d == 'b') return 4;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //run();
    string s;
    l city = 0;
    for(l i = 0; i < 102; i++){
        for(l j = 0; j < 5; j++) mark[i][j] = 0;
    }
    while(cin>>s && s[0] != '#'){
        if(s[0] != 'e'){
            l sz = s.size();
            for(l i = 0, j = 2; i <= 16; i+=4, j+=4){
                l x = check(s[i]);
                if(x != -1) {mark[city][x] = s[j];}
            }
            city++;
        }
        else{ 
            l res = -1; l ma = -1;
            for(l i = 0; i < city; i++){
                l sum = 0;
                for(l j = 0; j < city; j++){
                    for(l k = 0; k < 5; k++){
                        if(mark[i][k] == mark[j][k]) sum+=1;
                    }
                }
                if(sum > ma){
                    ma = sum;
                    res = i+1;
                }
            }

            // for(l i = 0; i < city; i++){
            //     for(l j = 0; j < 5; j++) cout << mark[i][j];
            //     cout << endl;
            // }

            // cout << ma << " " << res << endl;
            cout << res << endl;
            for(l i = 0; i < 102; i++){
                for(l j = 0; j < 5; j++) mark[i][j] = 0;
            }
            city = 0;
        }
    }
    return 0;
}