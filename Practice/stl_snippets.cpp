#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(),a.end());
    for(int i=0;i<n;i++) cout<< a[i] << " ";
    cout<<"\n";

    string s;
    cin >> s;
    cout << s.size() << " " << s.substr(0, 3) << "\n";
    reverse(s.begin(), s.end());
    cout<< s << "\n";

    vector<pair<int,int>> v;
    v.push_back({3,100});
    v.push_back({1,200});
    sort(v.begin(), v.end());
    for(auto p:v) cout<<p.first << ":" << p.second << " ";
    cout<<"\n";

    map<char, int> cnt;
    for(char c:s) cnt[c]++;
    for(auto[key,value] : cnt) cout<< key << "=" << value << " ";
    cout<<"\n";

    int k = 1000000;
    ll kv = ll(k) * k;
    cout << kv << "\n";
    cout << __gcd(12,18) << " " << abs(-5) << " " << max(3,9) << "\n";

    double d = 2.0 / 3.0;
    cout<< fixed << setprecision(6) << d << "\n";

    bool ok = (kv > 0);
    cout << (ok ? "YES" : "NO") << "\n";

    string t = "SaLaM";
    for (char &c:t) c = tolower(c);
    cout << t << "\n";

    return 0;
}