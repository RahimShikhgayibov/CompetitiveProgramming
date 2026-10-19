# Competitive Programming Solutions

C++ solutions — CSES, Codeforces, ICPC Azerbaijan and NeetCode 250.
Goal: ICPC Azerbaijan Regional (Nov 2026) and Codeforces 2000+.

![Language](https://img.shields.io/badge/Language-C++17-blue)
![Problems](https://img.shields.io/badge/Solved-8-brightgreen)

## Progress

| Platform | Solved |
|----------|--------|
| CSES | 6 |
| Codeforces | 1 |
| ICPC | 0 |
| NeetCode 250 | 1 |
| **Total** | **8** |

## Structure

```
CSES/<section>/<task id>_<name>.cpp          e.g. CSES/Graph/1666_building_roads.cpp
Codeforces/Contests/<contest id>/<letter>_<name>.cpp
Codeforces/Gym/<gym id>_<short name>/<letter>_<name>.cpp
ICPC/<country>-<year>-<stage>/<letter>_<name>.cpp
NeetCode250/<topic>/<name>.cpp
Practice/      learning code that is not a problem
Templates/     team notebook: tested, ready-to-use templates
```

Every solution starts with a header: problem name, link, topic, idea, complexity, upsolve flag.

## How to run

```powershell
.\run.ps1 .\CSES\Graph\1666_building_roads.cpp
```

Compiles with `g++ -std=c++17 -O2 -static` and runs with `input.txt` (next to the file, or in the repo root).
