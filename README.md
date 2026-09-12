# Contests
Competitive Programming Contests Solutions

# Codeforces Solutions

Competitive programming solutions, written in C++17.

**Profile:** [https://codeforces.com/profile/golu_0409](https://codeforces.com/profile/golu_0409)

**Current rating:** Expert (1728)

**Best contest finish:** Global Rank 174 — Codeforces Round 855

---

## Why this repository exists

I've competed on Codeforces since college and kept solutions rather than discarding them, mostly so I could go back and see how my approach to a problem type changed over time. The repository is organised for that — by technique, not by contest — so that a set of problems sharing an idea sit next to each other.

If you're here from a resume or LinkedIn profile: the interesting part isn't the solution count, it's `notes/` and the per-problem comments, where I've written down what the actual insight was and where I initially went wrong.

---

## Repository structure

```
.
├── by-topic/            # solutions grouped by technique
│   ├── graphs/
│   ├── dp/
│   ├── greedy/
│   ├── number-theory/
│   ├── data-structures/
│   ├── binary-search/
│   ├── strings/
│   └── combinatorics/
├── by-contest/          # solutions as submitted, per round
├── templates/           # competitive programming boilerplate
└── notes/               # write-ups on recurring patterns
```

Each solution file carries a short header:

```cpp
// Problem : 1849C - Binary String Copying
// Link    : https://codeforces.com/problemset/problem/1849/C
// Rating  : 1500
// Topic   : strings, sorting, data structures
// Idea    : each operation maps to a canonical interval; count distinct
//           intervals with a set rather than simulating each string
// Complexity : O(n log n) time, O(n) space
```

---

## Topics covered

| Area | What's here |
|---|---|
| Graphs | BFS/DFS, shortest paths, DSU, topological sort, bridges and articulation points |
| Dynamic programming | Knapsack variants, digit DP, bitmask DP, DP on trees |
| Data structures | Segment trees, Fenwick trees, sparse tables, ordered sets |
| Number theory | Sieve, modular arithmetic, GCD/LCM structure, combinatorics under a modulus |
| Greedy & sorting | Exchange arguments, interval scheduling |
| Binary search | On answer, on monotone predicates |
| Strings | Hashing, Z-function, KMP |

*(Prune this table to what's genuinely in the repo — an accurate short list beats an aspirational long one.)*

---

## How I practise

A few things that moved my rating more than raw volume did:

- **Solve above your rating, not at it.** Most of my improvement came from problems rated 200–400 above my current level, where I had to sit with the problem rather than pattern-match it.
- **Write the idea down before the code.** If I can't state the invariant or the observation in one sentence, I don't understand the problem yet, and the implementation will show it.
- **Upsolve the problem you didn't get.** The problem you failed in-contest is worth more than three you solved comfortably. Every contest directory here has an `upsolve/` subfolder for exactly this.
- **Re-read your own old solutions.** The clearest evidence that you've improved is finding an approach you wrote a year ago and immediately seeing the simpler one.

---

## Rating history


---

## Building locally

```bash
g++ -std=c++17 -O2 -Wall -Wextra solution.cpp -o solution
./solution < input.txt
```

---

## Also

- LeetCode: Guardian (2267, top 1%) — [solutions repository](https://github.com/durgeshkk/Leetcode)
- CodeChef: 5-star (2005), Global Rank 30 in May Lunchtime 2022
- Google Kickstart 2022 Round H: Global Rank 676
