# C++ Competitive Programming — Ultra Cheat Sheet
> Bütün data strukturlar, sintaks, funksiyalar — tam izahlı

---

## INCLUDE & SETUP

```cpp
#include <bits/stdc++.h>   // Hər şeyi bir-dəfəyə include edir
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);  // Input/output sürətləndirir
    cin.tie(NULL);                     // Mütləq yaz — böyük inputlarda lazımdır
    
    return 0;
}
```

---

## DATA TYPES

```cpp
int x = 5;                  // -2B to +2B (2,147,483,647)
long long x = 5LL;          // -9.2*10^18 to +9.2*10^18  ← böyük ədədlər üçün
double x = 3.14;            // onluq ədəd
float x = 3.14f;            // kiçik onluq (az dəqiq)
bool x = true;              // true / false
char x = 'a';               // tək hərf
string x = "hello";        // mətn

// Xüsusi dəyərlər
INT_MAX     // 2,147,483,647  (ən böyük int)
INT_MIN     // -2,147,483,648 (ən kiçik int)
LLONG_MAX   // 9.2 * 10^18   (ən böyük long long)
LLONG_MIN   // ən kiçik long long
1e9         // 1,000,000,000 (double kimi)
1e18        // 10^18

// Type casting
int a = (int) 3.9;          // → 3  (kəsir)
double b = (double) 7 / 2;  // → 3.5
long long c = (long long) a * b;  // overflow qarşısı üçün
```

---

## ARRAY

```cpp
// ---- Elan ----
int arr[5];                        // boş, garbage values
int arr[5] = {1, 2, 3, 4, 5};     // tam dolu
int arr[5] = {1, 2};               // qalan 0 olur → {1,2,0,0,0}
int arr[5] = {};                   // hamısı 0
int arr[] = {1, 2, 3};            // ölçü avtomatik (3 olur)

// 2D array
int grid[3][4];                    // 3 sətir, 4 sütun
int grid[2][3] = {{1,2,3},{4,5,6}};

// ---- İstifadə ----
arr[0];                            // ilk element
arr[4];                            // son element (5-liyin)
sizeof(arr) / sizeof(arr[0]);      // uzunluq

// ---- Sort / Reverse ----
sort(arr, arr + 5);                // kiçikdən böyüyə
sort(arr, arr + 5, greater<int>()); // böyükdən kiçiyə
reverse(arr, arr + 5);             // tərsinə

// ---- Loop ----
for (int i = 0; i < 5; i++) cout << arr[i];
```

---

## VECTOR

> Dinamik array — ən çox istifadə olunan struktur

```cpp
// ---- Elan ----
vector<int> v;                     // boş
vector<int> v(5);                  // 5 element, hamısı 0
vector<int> v(5, -1);             // 5 element, hamısı -1
vector<int> v = {1, 2, 3, 4, 5};  // initializer list
vector<int> v(arr, arr+5);         // array-dən

// 2D vector
vector<vector<int>> grid(3, vector<int>(4, 0));  // 3x4, hamısı 0

// ---- Əlavə / Silmə ----
v.push_back(10);                   // sona əlavə et  O(1)
v.pop_back();                      // sonu sil       O(1)
v.insert(v.begin() + 2, 99);      // index 2-yə əlavə et  O(n)
v.erase(v.begin() + 2);           // index 2-ni sil       O(n)
v.erase(v.begin()+1, v.begin()+3);// [1,3) range sil      O(n)
v.clear();                         // hamısını sil

// ---- Çatmaq ----
v[0];                              // index ilə (yoxlama yoxdur)
v.at(0);                           // index ilə (range yoxlanır, exception atır)
v.front();                         // ilk element
v.back();                          // son element

// ---- Məlumat ----
v.size();                          // element sayı
v.empty();                         // boşdurmu? true/false
v.capacity();                      // ayrılmış yer
v.resize(10);                      // ölçüyü dəyiş (yeni yerlər 0)
v.resize(10, -1);                  // yeni yerlər -1 olsun
v.reserve(100);                    // yer ayır (push_back sürətlənir)

// ---- Sort / Axtarış ----
sort(v.begin(), v.end());                      // kiçikdən böyüyə
sort(v.begin(), v.end(), greater<int>());      // böyükdən kiçiyə
reverse(v.begin(), v.end());                   // tərsinə
*min_element(v.begin(), v.end());              // ən kiçik dəyər
*max_element(v.begin(), v.end());              // ən böyük dəyər
count(v.begin(), v.end(), 5);                  // 5-in neçə dəfə var
find(v.begin(), v.end(), 5);                   // iterator qaytarır (tapılmazsa end())
binary_search(v.begin(), v.end(), 5);          // true/false (SORTED olmalı!)
lower_bound(v.begin(), v.end(), 5);            // 5-dən >= ilk iterator (SORTED)
upper_bound(v.begin(), v.end(), 5);            // 5-dən >  ilk iterator (SORTED)

// lower_bound / upper_bound INDEX almaq üçün:
int idx = lower_bound(v.begin(), v.end(), 5) - v.begin();

// ---- Loop ----
for (int x : v) cout << x;                    // range-based (oxumaq üçün)
for (int& x : v) x *= 2;                      // reference ilə dəyişmək üçün
for (int i = 0; i < v.size(); i++) cout << v[i];

// ---- Kopyalama / Birləşdirmə ----
vector<int> v2 = v;                // tam kopyala
v.insert(v.end(), v2.begin(), v2.end()); // v2-ni v-nin sonuna əlavə et
```

---

## STRING

```cpp
// ---- Elan ----
string s = "hello";
string s(5, 'a');                  // "aaaaa"
string s = "";                     // boş

// ---- Ölçü ----
s.length();                        // uzunluq
s.size();                          // eyni şeydir
s.empty();                         // boşdurmu?

// ---- Çatmaq ----
s[0];                              // ilk hərf
s[s.size()-1];                     // son hərf
s.front();                         // ilk hərf
s.back();                          // son hərf

// ---- Əlavə / Silmə ----
s.push_back('!');                  // sona hərf əlavə et
s.pop_back();                      // son hərfi sil
s += " world";                     // sona string əlavə et
s.append(" world");               // eyni şeydir
s.insert(2, "XY");                // index 2-yə "XY" əlavə et
s.erase(2, 3);                    // index 2-dən 3 hərf sil
s.replace(1, 3, "ABC");           // index 1-dən 3 hərf → "ABC" et

// ---- Axtarış ----
s.find("lo");                      // "lo"-nun başlanğıc indexi (yoxdursa string::npos)
s.find('l');                       // hərfin indexi
s.rfind("lo");                     // sondan axtarır
s.find("lo") != string::npos;      // tapılıbmı? (yoxlama üçün)

// ---- Hissə alma ----
s.substr(2);                       // index 2-dən sona qədər
s.substr(2, 4);                    // index 2-dən, 4 hərf

// ---- Çevirmə ----
stoi("123");                       // string → int
stoll("123456789012");            // string → long long
stod("3.14");                      // string → double
to_string(42);                     // int → string
to_string(3.14);                   // double → string

// ---- Müqayisə ----
s1 == s2;                          // bərabərmi?
s1 < s2;                           // leksikografik müqayisə
s1.compare(s2);                    // 0 = bərabər, <0 = kiçik, >0 = böyük

// ---- Loop ----
for (char c : s) cout << c;
for (int i = 0; i < s.size(); i++) cout << s[i];

// ---- Hərf əməliyyatları ----
tolower('A');                      // → 'a'
toupper('a');                      // → 'A'
isalpha('a');                      // hərf mi?
isdigit('5');                      // rəqəm mi?
isalnum('a');                      // hərf ya rəqəm mi?
isspace(' ');                      // boşluq mu?

// ---- Sort ----
sort(s.begin(), s.end());          // əlifba sırasına görə sort
reverse(s.begin(), s.end());       // tərsinə çevir
```

---

## PAIR

```cpp
// ---- Elan ----
pair<int, int> p = {1, 2};
pair<int, string> p = {5, "ali"};
pair<int,int> p = make_pair(1, 2);   // köhnə üsul

// ---- İstifadə ----
p.first;                           // birinci element (1)
p.second;                          // ikinci element (2)

// ---- Vector of pairs ----
vector<pair<int,int>> vp;
vp.push_back({3, 7});
vp.push_back({1, 5});
sort(vp.begin(), vp.end());        // first-ə görə sort, bərabərsə second-ə

// ---- Structured binding (C++17) ----
auto [a, b] = p;                   // a=1, b=2
```

---

## TUPLE

```cpp
// ---- Elan ----
tuple<int, string, double> t = {1, "ali", 3.14};

// ---- İstifadə ----
get<0>(t);                         // 1
get<1>(t);                         // "ali"
get<2>(t);                         // 3.14

// ---- Structured binding (C++17) ----
auto [a, b, c] = t;

// ---- Vector of tuples ----
vector<tuple<int,int,int>> vt;
vt.push_back({3, 1, 2});
sort(vt.begin(), vt.end());        // ilk elementə görə sort
```

---

## STACK

> LIFO — son girən, birinci çıxır

```cpp
stack<int> st;

st.push(5);                        // üstə əlavə et
st.push(10);
st.top();                          // üstdəkini GÖR (silmə)  → 10
st.pop();                          // üstdəkini SİL (qaytarmır!)
st.size();                         // neçə element var
st.empty();                        // boşdurmu?

// ---- Düzgün istifadə (pop + oxu) ----
while (!st.empty()) {
    cout << st.top();
    st.pop();
}
```

---

## QUEUE

> FIFO — ilk girən, birinci çıxır

```cpp
queue<int> q;

q.push(5);                         // sona əlavə et
q.push(10);
q.front();                         // ön elementə BAX  → 5
q.back();                          // arxa elementə bax → 10
q.pop();                           // ön elementi SİL (qaytarmır!)
q.size();                          // neçə element
q.empty();                         // boşdurmu?

// ---- Loop ----
while (!q.empty()) {
    cout << q.front();
    q.pop();
}
```

---

## DEQUE (Double Ended Queue)

> Həm önündən həm arxasından push/pop edə bilərsən

```cpp
deque<int> dq;

dq.push_back(10);                  // arxaya əlavə et
dq.push_front(5);                  // önə əlavə et
dq.pop_back();                     // arxadan sil
dq.pop_front();                    // öndən sil
dq.front();                        // ilk element
dq.back();                         // son element
dq[2];                             // index ilə çat
dq.size();
dq.empty();
```

---

## PRIORITY QUEUE (Heap)

```cpp
// ---- MAX HEAP (default) — ən böyük üstdədir ----
priority_queue<int> pq;
pq.push(3);
pq.push(10);
pq.push(1);
pq.top();                          // → 10 (ən böyük)
pq.pop();                          // ən böyüyü sil
pq.size();
pq.empty();

// ---- MIN HEAP — ən kiçik üstdədir ----
priority_queue<int, vector<int>, greater<int>> pq;
pq.push(3);
pq.push(10);
pq.push(1);
pq.top();                          // → 1 (ən kiçik)

// ---- Pair ilə (birinci elementə görə sort olur) ----
priority_queue<pair<int,int>> pq;   // max heap
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // min heap
```

---

## SET

> Unikal, sıralanmış elementlər — dublikat yoxdur

```cpp
set<int> s;

s.insert(5);                       // əlavə et   O(log n)
s.insert(3);
s.insert(5);                       // dublikat — ignore edilir
s.erase(3);                        // sil         O(log n)
s.count(5);                        // var mı? → 0 ya 1
s.find(5);                         // iterator qaytarır
s.find(5) != s.end();              // var mı? (düzgün yoxlama)
s.size();
s.empty();
s.clear();

// ---- Lower/Upper bound ----
s.lower_bound(5);                  // 5-dən >= ilk iterator
s.upper_bound(5);                  // 5-dən >  ilk iterator
*s.begin();                        // ən kiçik element
*s.rbegin();                       // ən böyük element

// ---- Loop (artan sırada gəlir) ----
for (int x : s) cout << x;

// ---- Multiset (dublikatlar saxlanır) ----
multiset<int> ms;
ms.insert(5);
ms.insert(5);                      // ikinci 5 saxlanır
ms.count(5);                       // → 2
ms.erase(ms.find(5));             // YALNIZ BİR ədəd sil (hamısını yox!)
ms.erase(5);                       // HAMISINI SİLİR — diqqətli ol!
```

---

## UNORDERED SET (Hash Set)

> Sırasız, unikal elementlər — SET-dən sürətlidir O(1) avg

```cpp
unordered_set<int> us;

us.insert(5);                      // O(1) average
us.erase(5);                       // O(1) average
us.count(5);                       // var mı? 0 ya 1  O(1)
us.find(5) != us.end();            // var mı? (iterator yoxlama)
us.size();
us.empty();
us.clear();

// ---- Loop (sırasız gəlir) ----
for (int x : us) cout << x;
```

---

## MAP

> Key-value cütlər, key-ə görə sıralanmış — O(log n)

```cpp
map<string, int> mp;

mp["ali"] = 5;                     // əlavə et / yenilə
mp["veli"] = 3;
mp["ali"]++;                       // dəyəri artır
mp["yeni"];                        // 0 ilə avtomatik yaranır (diqqət!)

mp.count("ali");                   // var mı? 0 ya 1
mp.find("ali") != mp.end();        // var mı? (iterator yoxlama)
mp.erase("ali");                   // sil
mp.size();
mp.empty();
mp.clear();

// ---- Çatmaq ----
mp["ali"];                         // dəyər (yoxdursa 0 yaradır!)
mp.at("ali");                      // dəyər (yoxdursa exception atır)

// ---- Loop (key-ə görə artan sırada) ----
for (auto& [key, val] : mp) {
    cout << key << ": " << val;
}

// ---- Lower/Upper bound ----
mp.lower_bound("ali");             // "ali"-dən >= ilk iterator
mp.upper_bound("ali");             // "ali"-dən >  ilk iterator
mp.begin()->first;                 // ən kiçik key
mp.rbegin()->first;                // ən böyük key
```

---

## UNORDERED MAP (Hash Map)

> Key-value cütlər, sırasız — O(1) average, MAP-dan sürətli

```cpp
unordered_map<string, int> mp;

mp["ali"] = 5;                     // əlavə et
mp["ali"]++;                       // artır
mp.count("ali");                   // var mı?
mp.find("ali") != mp.end();        // var mı?
mp.erase("ali");                   // sil
mp.size();
mp.empty();
mp.clear();

// ---- Loop (sırasız) ----
for (auto& [key, val] : mp) {
    cout << key << " " << val;
}

// ---- Frequency counter (çox işlənir!) ----
unordered_map<int, int> freq;
vector<int> nums = {1, 2, 2, 3, 3, 3};
for (int x : nums) freq[x]++;
// freq = {1:1, 2:2, 3:3}
```

---

## MULTIMAP

> Eyni key-dən bir neçəsi ola bilər

```cpp
multimap<int, string> mm;
mm.insert({1, "ali"});
mm.insert({1, "veli"});            // eyni key, fərqli value
mm.count(1);                       // → 2
mm.equal_range(1);                 // həmin key-in bütün dəyərləri

auto range = mm.equal_range(1);
for (auto it = range.first; it != range.second; it++)
    cout << it->second;
```

---

## LINKED LIST (std::list)

> Doubly linked list — ortaya insert/delete O(1), amma random access yoxdur

```cpp
list<int> lst;

lst.push_back(10);                 // arxaya əlavə et
lst.push_front(5);                 // önə əlavə et
lst.pop_back();                    // arxadan sil
lst.pop_front();                   // öndən sil
lst.front();                       // ilk element
lst.back();                        // son element
lst.size();
lst.empty();

// ---- Insert/Delete ----
auto it = lst.begin();
advance(it, 2);                    // iterator-u 2 irəli apar
lst.insert(it, 99);               // iterator yerindən əvvəl əlavə et
lst.erase(it);                     // iterator mövqeyini sil

lst.remove(5);                     // dəyəri 5 olan hamısını sil
lst.sort();                        // sırala
lst.reverse();                     // tərsinə çevir
lst.unique();                      // ardıcıl dublikatları sil (sort sonra)

// ---- Loop ----
for (int x : lst) cout << x;
```

---

## BITSET

> Bit əməliyyatları üçün — çox yaddaş effektiv

```cpp
bitset<8> bs;                      // 8 bit, hamısı 0
bitset<8> bs(42);                  // 42-nin binary (00101010)
bitset<8> bs("10110011");          // string-dən

bs.set(3);                         // index 3-ü 1 et
bs.reset(3);                       // index 3-ü 0 et
bs.flip(3);                        // index 3-ü tərsinə çevir
bs.flip();                         // hamısını tərsinə çevir
bs.test(3);                        // index 3 = 1 mi?
bs.count();                        // neçə 1 var
bs.any();                          // ən azı bir 1 varmı?
bs.none();                         // heç 1 yoxdurmu?
bs.all();                          // hamısı 1-dirmi?
bs[3];                             // index ilə çat
bs.to_string();                    // "00101010"
bs.to_ulong();                     // unsigned long-a çevir

// ---- Bit operatorlar ----
bs1 & bs2;                         // AND
bs1 | bs2;                         // OR
bs1 ^ bs2;                         // XOR
~bs;                               // NOT
bs << 2;                           // sola sürüş
bs >> 2;                           // sağa sürüş
```

---

## BIT MANIPULATION (integer)

```cpp
// ---- Əsas operatorlar ----
a & b;                             // AND
a | b;                             // OR
a ^ b;                             // XOR
~a;                                // NOT
a << 2;                            // sola sürüş (x4)
a >> 2;                            // sağa sürüş (/4)

// ---- Faydalı tricks ----
a & 1;                             // cüt mi tək mi? (0=cüt, 1=tək)
a | (1 << k);                      // k-cı biti 1 et
a & ~(1 << k);                     // k-cı biti 0 et
a ^ (1 << k);                      // k-cı biti flip et
(a >> k) & 1;                      // k-cı bitin dəyəri
a & (a - 1);                       // ən sağdakı 1-biti sil
a & (-a);                          // ən sağdakı 1-bit
__builtin_popcount(a);             // neçə 1-bit var (int)
__builtin_popcountll(a);           // neçə 1-bit var (long long)
__builtin_clz(a);                  // soldakı sıfırların sayı
__builtin_ctz(a);                  // sağdakı sıfırların sayı
```

---

## MATH FUNKSİYALAR

```cpp
abs(-5);                           // mütləq dəyər (int)
fabs(-5.5);                        // mütləq dəyər (double)
sqrt(16.0);                        // → 4.0
pow(2, 10);                        // → 1024.0 (double!)
ceil(3.2);                         // → 4.0 (yuxarı yuvarlaq)
floor(3.9);                        // → 3.0 (aşağı yuvarlaq)
round(3.5);                        // → 4.0 (ən yaxın tam)
min(3, 5);                         // → 3
max(3, 5);                         // → 5
min({1, 5, 3, 2});                 // çox element (C++11)
max({1, 5, 3, 2});                 // çox element
gcd(12, 8);                        // ƏBOB → 4     (C++17)
lcm(4, 6);                         // ƏKOB → 12    (C++17)
log(x);                            // ln(x) — natural log
log2(x);                           // log base 2
log10(x);                          // log base 10

// ---- Overflow-a diqqət ----
(long long) a * b;                 // int * int overflow edə bilər
```

---

## SORTING

```cpp
vector<int> v = {5, 2, 8, 1, 9};

sort(v.begin(), v.end());                          // kiçikdən böyüyə
sort(v.begin(), v.end(), greater<int>());           // böyükdən kiçiyə

// ---- Custom comparator ----
sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;                                  // böyükdən kiçiyə
});

// ---- Pair sort ----
vector<pair<int,int>> vp = {{3,2},{1,5},{3,1}};
sort(vp.begin(), vp.end());                        // first-ə görə, bərabərsə second-ə

// ---- Struct sort ----
struct Student { string name; int grade; };
vector<Student> students;
sort(students.begin(), students.end(), [](Student& a, Student& b) {
    return a.grade > b.grade;                      // grade-ə görə azalan
});

// ---- Partial sort ----
partial_sort(v.begin(), v.begin()+3, v.end());     // ilk 3-ü sırala

// ---- Stable sort (eyni elementlər öz sırasını saxlayır) ----
stable_sort(v.begin(), v.end());
```

---

## ALGORITHM FUNKSİYALAR

```cpp
// ---- Axtarış ----
find(v.begin(), v.end(), 5);                       // iterator (tapılmazsa end())
binary_search(v.begin(), v.end(), 5);              // bool (SORTED lazım!)
lower_bound(v.begin(), v.end(), 5);                // >= 5 olan ilk iterator
upper_bound(v.begin(), v.end(), 5);                // >  5 olan ilk iterator

// ---- Min/Max ----
*min_element(v.begin(), v.end());                  // ən kiçik dəyər
*max_element(v.begin(), v.end());                  // ən böyük dəyər
auto [mn, mx] = minmax_element(v.begin(), v.end()); // hər ikisi birdən

// ---- Count ----
count(v.begin(), v.end(), 5);                      // 5-in sayı
count_if(v.begin(), v.end(), [](int x){return x>3;}); // şərtə uyanların sayı

// ---- Fill / Replace ----
fill(v.begin(), v.end(), 0);                       // hamısını 0 et
fill_n(v.begin(), 3, 0);                          // ilk 3-ü 0 et
replace(v.begin(), v.end(), 5, 99);               // 5-ləri 99 et

// ---- Transform (hər elementə funksiya tətbiq et) ----
transform(v.begin(), v.end(), v.begin(), [](int x){ return x*2; });

// ---- Accumulate (cəm, vuruq...) ----
#include <numeric>
accumulate(v.begin(), v.end(), 0);                 // cəm (0 başlanğıc dəyər)
accumulate(v.begin(), v.end(), 1, multiplies<int>()); // vuruq

// ---- Unique (dublikatları arxaya at, sorted lazım) ----
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());      // dublikatları sil

// ---- Next/Prev Permutation ----
vector<int> p = {1, 2, 3};
next_permutation(p.begin(), p.end());              // növbəti permutasiya
prev_permutation(p.begin(), p.end());              // əvvəlki permutasiya
// Bütün permutasiyaları görmək üçün:
do {
    // p-ni istifadə et
} while (next_permutation(p.begin(), p.end()));

// ---- Rotate ----
rotate(v.begin(), v.begin()+2, v.end());           // 2 sola sürüş

// ---- Merge ----
merge(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin()); // iki sorted birləşdir
```

---

## INPUT / OUTPUT

```cpp
// ---- Cin / Cout ----
int n;
cin >> n;                          // bir ədəd oxu
cin >> a >> b;                     // iki ədəd oxu

string s;
cin >> s;                          // bir söz oxu (boşluqda dayanır)
getline(cin, s);                   // tam sətir oxu

cout << "deger: " << n << "\n";    // çıxış ("\n", endl-dən sürətlidir!)
cout << fixed << setprecision(2) << 3.14159; // → 3.14

// ---- Sürətli I/O (mütləq əlavə et!) ----
ios_base::sync_with_stdio(false);
cin.tie(NULL);

// ---- Array/Vector oxumaq ----
int n;
cin >> n;
vector<int> v(n);
for (int i = 0; i < n; i++) cin >> v[i];

// ---- Matrix oxumaq ----
int n, m;
cin >> n >> m;
vector<vector<int>> grid(n, vector<int>(m));
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        cin >> grid[i][j];

// ---- String + int birlikdə oxumaq (getline problemini həll et) ----
int n;
cin >> n;
cin.ignore();                      // \n-i skip et
string s;
getline(cin, s);
```

---

## GRAPH

```cpp
// ---- Adjacency List (ən çox istifadə olunan) ----
int n = 5;                         // node sayı
vector<vector<int>> adj(n + 1);   // 1-indexed

// Edge əlavə et (undirected)
adj[1].push_back(2);
adj[2].push_back(1);

// Edge əlavə et (directed)
adj[u].push_back(v);

// Weighted graph
vector<vector<pair<int,int>>> adj(n + 1);  // adj[u] = {node, weight}
adj[u].push_back({v, w});

// ---- BFS ----
vector<bool> visited(n + 1, false);
queue<int> q;
q.push(start);
visited[start] = true;
while (!q.empty()) {
    int node = q.front(); q.pop();
    for (int next : adj[node]) {
        if (!visited[next]) {
            visited[next] = true;
            q.push(next);
        }
    }
}

// ---- DFS (recursive) ----
vector<bool> visited(n + 1, false);
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int next : adj[node]) {
        if (!visited[next]) dfs(next, adj, visited);
    }
}

// ---- DFS (iterative) ----
stack<int> st;
st.push(start);
visited[start] = true;
while (!st.empty()) {
    int node = st.top(); st.pop();
    for (int next : adj[node]) {
        if (!visited[next]) {
            visited[next] = true;
            st.push(next);
        }
    }
}
```

---

## UNION FIND (Disjoint Set)

```cpp
vector<int> parent, rank_;

void init(int n) {
    parent.resize(n + 1);
    rank_.resize(n + 1, 0);
    iota(parent.begin(), parent.end(), 0); // parent[i] = i
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);       // path compression
    return parent[x];
}

bool unite(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return false;            // artıq eyni komponentdədir
    if (rank_[px] < rank_[py]) swap(px, py);
    parent[py] = px;
    if (rank_[px] == rank_[py]) rank_[px]++;
    return true;
}

bool connected(int x, int y) {
    return find(x) == find(y);
}
```

---

## DYNAMIC PROGRAMMING — Pattern-lər

```cpp
// ---- 1D DP ----
vector<int> dp(n + 1, 0);
dp[0] = base_case;
for (int i = 1; i <= n; i++) {
    dp[i] = max(dp[i-1], ...);
}

// ---- 2D DP ----
vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        dp[i][j] = dp[i-1][j] + dp[i][j-1]; // nümunə

// ---- Memoization ----
unordered_map<int, int> memo;
int solve(int n) {
    if (n <= 1) return n;
    if (memo.count(n)) return memo[n];
    return memo[n] = solve(n-1) + solve(n-2);
}
```

---

## LAMBDA FUNKSİYALAR

```cpp
// ---- Əsas sintaks ----
auto f = [](int a, int b) { return a + b; };
f(3, 4);                           // → 7

// ---- Capture ----
int x = 10;
auto f = [x](int a) { return a + x; };    // x-i kopyala
auto f = [&x](int a) { x = a; };          // x-i reference ilə tut
auto f = [=](int a) { return a + x; };    // hamısını kopyala
auto f = [&](int a) { x = a; };           // hamısını reference ilə tut

// ---- Sort ilə ----
sort(v.begin(), v.end(), [](int a, int b) { return a > b; });

// ---- Return type ----
auto f = [](int a) -> double { return a / 2.0; };
```

---

## FREQUENTLY USED PATTERNS

```cpp
// ---- Frequency map ----
unordered_map<int, int> freq;
for (int x : v) freq[x]++;

// ---- Two pointer ----
int left = 0, right = v.size() - 1;
while (left < right) {
    // process
    left++;
    right--;
}

// ---- Sliding window ----
int left = 0, sum = 0;
for (int right = 0; right < n; right++) {
    sum += v[right];
    while (sum > target) sum -= v[left++];
    // window = [left, right]
}

// ---- Prefix sum ----
vector<int> prefix(n + 1, 0);
for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + v[i];
int rangeSum = prefix[r+1] - prefix[l];  // sum [l, r]

// ---- Binary search template ----
int left = 0, right = n - 1, ans = -1;
while (left <= right) {
    int mid = left + (right - left) / 2;  // overflow-dan qaçmaq üçün
    if (check(mid)) { ans = mid; right = mid - 1; }
    else left = mid + 1;
}

// ---- Matrix 4-direction traverse ----
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
for (int d = 0; d < 4; d++) {
    int nx = x + dx[d];
    int ny = y + dy[d];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        // valid hüceyrə
    }
}
```

---

## TIME COMPLEXITY QUICK REFERENCE

| Əməliyyat | Struktur | Mürəkkəblik |
|-----------|---------|-------------|
| push/pop | Stack, Queue | O(1) |
| insert/find/erase | unordered_map/set | O(1) avg |
| insert/find/erase | map/set | O(log n) |
| push/pop | priority_queue | O(log n) |
| sort | vector | O(n log n) |
| binary search | sorted vector | O(log n) |
| BFS / DFS | graph | O(V + E) |
| Union Find | - | O(α(n)) ≈ O(1) |
| access by index | vector/array | O(1) |
| access by index | list | O(n) |

---

*Bu fayl zamanla genişlənəcək — yeni şeylər öyrəndikdə əlavə et!*