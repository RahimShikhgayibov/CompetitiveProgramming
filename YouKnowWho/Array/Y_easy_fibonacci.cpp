// YouKnowWho Academy (Array) Y - Easy Fibonacci
// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/Y
// Mövzu: iki elementlik pəncərə
// İdeya: Yalnız son iki ədədi saxla: növbəti = a + b, sonra pəncərəni sürüşdür (a = b, b = yeni).
// Mürəkkəblik: O(n)
// Upsolve: no

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a=0;int b=1;
    if(n==1){
        cout<<a<<" ";
        return 0;
    }
    cout<<a<<" "<<b;

    for(int i=0;i<n-2;i++){
        cout<<" "<<a+b;
        int temp=b;
        b=a+b;
        a=temp;
    }
    return 0;
}
