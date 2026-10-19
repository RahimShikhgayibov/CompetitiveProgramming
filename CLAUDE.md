# CLAUDE.md — CompetitiveProgramming repo

Bu fayl Claude Code üçün kontekstdir. Repo-da işləməzdən əvvəl tam oxu.

## Repo nədir

Rahimin competitive programming həllərinin arxivi. C++ dilində.
Məqsədlər:
1. **Qısa müddətli:** ICPC Azərbaycan Regional mərhələsi, **8 noyabr 2026**. Komandanın hədəfi 5–6 məsələ.
2. **Uzun müddətli:** Codeforces-də 2000+ reytinq.
3. GitHub-da müntəzəm aktivlik: hər həll olunan məsələ bir commit.

## ƏN VACİB QAYDA: həlləri Rahim özü yazır

Rahim **özü yazaraq öyrənmək** istəyir. Ona görə:

- **Heç vaxt məsələnin həllini yazma**, hətta istəsə belə ilk cavab olaraq yazma. Əvəzində sual ver və istiqamət göstər.
- Kodda səhv görəndə **düzəldilmiş kodu vermə**. Səhvin harada olduğunu və niyə səhv olduğunu izah et, sonra Rahimə özü düzəltməyə imkan ver.
- Səhvləri sual formasında göstər: "Bu dövr hansı indeksdən başlayır? Təpələr hansı nömrədən başlayır?"
- Rahim **tam düzgün** həll göndərəndə: (1) daha optimal yol varmı izah et, (2) kodu CP üslubuna addım-addım uyğunlaşdır, (3) sonda cilalanmış versiyanı göstər.
- Yeni mövzunu izah edəndə **yavaş və sadə** get: bir mesajda bir fikir, əvvəlcə kodsuz analogiya (otaqlar, qapılar, təbaşir), sonra kod. Bir neçə fikri qarışdıran sıx izahlar onu çaşdırır.
- İzahlar **Azərbaycan dilində**, kod və terminlər ingiliscə ola bilər. Rahim C#/.NET-i yaxşı bilir: yeni C++ konsepsiyalarını C# qarşılığı ilə izah et.

Claude bu repo-da **edə bilər:** qovluq strukturu yaratmaq, README-ni yeniləmək, köməkçi skriptlər yazmaq, Rahimin yazdığı həlləri review etmək, Rahimin artıq yazıb başa düşdüyü kodu `Templates/`-ə cilalanmış şablon kimi köçürmək.

## Qovluq strukturu

```
CompetitiveProgramming/
├── CSES/
│   ├── Introductory/
│   ├── Sorting/
│   ├── Graph/
│   │   └── 1666_building_roads.cpp
│   └── ...                       (CSES bölmə adları)
├── Codeforces/
│   ├── Contests/
│   │   └── 2042/                 (contest ID)
│   │       ├── A_slug.cpp
│   │       └── B_slug.cpp
│   └── Gym/
│       └── <gym ID>_<qısa ad>/
│           └── A_slug.cpp
├── ICPC/
│   ├── AZ-2024-Regional/
│   ├── AZ-2025-Qualification/
│   │   └── A_fight_against_numbers.cpp
│   └── AZ-2026-Qualification/
├── NeetCode250/                  (mövcuddur, olduğu kimi qalır)
├── Practice/                     (məsələ olmayan öyrənmə kodları: DFS izləmə, testlər)
├── Templates/                    (team notebook: yoxlanmış, hazır şablonlar)
│   ├── cpp_cheatsheet.md
│   └── graph_dfs.cpp
├── run.ps1                       (kompilyasiya + input.txt ilə işə salma)
└── README.md
```

## Adlandırma qaydaları

- Fayl adları: kiçik hərflər, söz arası `_`. Məsələn `1666_building_roads.cpp`, `A_fight_against_numbers.cpp`.
- CSES: `<task id>_<ad>.cpp`, CSES-in öz bölməsinin qovluğunda.
- Codeforces: `Contests/<contest id>/<hərf>_<ad>.cpp`. Div fərqi qovluqda yox, faylın başlığında qeyd olunur.
- ICPC: `<ölkə>-<il>-<mərhələ>/<hərf>_<ad>.cpp`. İl yarışın keçirildiyi ildir.
- Upsolve (yarışdan sonra, editorial-a baxaraq həll edilən) məsələlərdə başlıqda `Upsolve: yes` yazılır.

## Hər həll faylının başlığı

```cpp
// Codeforces 2042A - <Məsələnin adı>
// https://codeforces.com/contest/2042/problem/A
// Mövzu: greedy, sorting
// İdeya: <1–2 cümlə, Rahimin öz sözləri ilə>
// Mürəkkəblik: O(n log n)
// Upsolve: no
```

- **Məsələ şərtinin mətnini fayla kopyalama.** Link kifayətdir (şərtlər müəlliflərindir).
- "İdeya" sətrini Rahim özü yazır. Claude onu yaza bilməz, amma boşdursa xatırlada bilər.

## Commit qaydası

Hər məsələ ayrı commit:
```
CSES 1666 Building Roads
CF 2042A <ad>
ICPC AZ-2025-Q A Fight Against Numbers
Template: graph DFS
```

## README

README-də cədvəl saxlanılır: hər platforma üzrə həll olunan məsələlərin sayı və badge-dəki ümumi say. Yeni həll əlavə olunanda Claude bu sayları yeniləyə bilər.

## Lokal mühit (Rahimin kompüteri, Windows + PowerShell + VS Code)

- Kompilyasiya **həmişə `-static` ilə**, yoxsa g++ yanlış kitabxananı götürüb səssizcə çökür:
  `g++ -std=c++17 -O2 -static .\fayl.cpp -o .\fayl.exe`
- Test: `Get-Content .\input.txt | .\fayl.exe`
- Proqramı tək `.\fayl.exe` ilə işə salanda klaviaturadan giriş gözləyir. Bu səhv deyil.
- Bu qovluqda Copilot/inline suggestions söndürülüb (`.vscode/settings.json`). Onu yenidən yandırma.

## Görüləcək işlər (Claude üçün)

- [x] Yuxarıdakı qovluq strukturunu yarat (boş qovluqlara `.gitkeep`).
- [x] `run.ps1` yaz: fayl adını parametr kimi alsın, `-static` ilə kompilyasiya etsin, uğurlu olsa `input.txt` ilə işə salsın.
- [x] README-ni yeni struktur və statistika cədvəli ilə yenilə.
- [x] `.vscode/settings.json` (inline suggestions off) əlavə olunubsa, commit-ə daxil et.

## Hazırkı vəziyyət (19 okt 2026)

- **Qraf:** adjacency list ✅, DFS ✅ (yaddaşdan yazır), komponent saymaq ✅, CSES 1666 Building Roads ✅.
- **Növbəti qraf mövzuları:** Counting Rooms (grid DFS) → BFS (Message Route) → Labyrinth (grid BFS) → Dijkstra.
- **Sonrakı həftə (26 okt – 1 noy):** riyaziyyat — gcd, sadə ədədlər (sieve), modul hesabı, kombinasiyalar.
- **1–7 noyabr:** yeni mövzu yoxdur, qarışıq məşq və notebook.
- **Həftə içi:** gündə bir məsələ, 45–60 dəqiqə. Rahim 12 saat işləyir, yükü artırma.
