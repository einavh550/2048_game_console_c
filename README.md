# 2048 — C (Linux/Ubuntu, Terminal)

A clean, portable C implementation of the 2048 puzzle that runs in the terminal on Linux/Ubuntu. The board is stored as a flat `int*` array (pointer arithmetic), moves are implemented per direction (U/D/L/R), and the game supports multiple board sizes with different win targets. Built with a Makefile; no external libraries.

---

## TL;DR (What this does)
- Slide and merge equal tiles to reach the target value (classic 2048 rules).
- Three demo runs: **3×3 → 16**, **2×2 → 32**, **4×4 → 2048** (configurable in `main.c`).
- Keys: **N** new game, **U/D/L/R** move, **E** exit. Score and best are printed each turn.

---

## Features
- **Pointer-based board**: the grid is a flat `int*` buffer, indexed via pointer arithmetic for cache-friendly iteration and simple pass-by-reference APIs. :contentReference[oaicite:0]{index=0}
- **Movement and merging**: four move functions (`moveUp/Down/Left/Right`) implement slide → single-merge-per-line → slide, updating the score by the value of the new tile. :contentReference[oaicite:1]{index=1}
- **Random spawns (2/4)**: new tiles appear in empty cells with **70% = 2** and **30% = 4**; spawning occurs at start and after valid moves only. :contentReference[oaicite:2]{index=2}
- **Multiple board sizes & targets**: the program demonstrates 3×3, 2×2, and 4×4 runs with win values 16/32/2048; easily extensible. :contentReference[oaicite:3]{index=3}
- **Terminal rendering**: ASCII board with separators plus **Score** and **Best** on every turn; clear text menu of controls. :contentReference[oaicite:4]{index=4}
- **Game state guards**: prevents moves before a game starts (“Need to start game first”); detects game-over when no moves remain. :contentReference[oaicite:5]{index=5}

---

## Design & Implementation Notes
- **API design (`game.h`)**: operations receive `int* board`, `size`, and pointers to `score/best/flags` so state updates are explicit and testable. :contentReference[oaicite:6]{index=6}
- **Algorithmic clarity**: each move direction follows the same three-phase logic (compact → merge once per line/column → compact), keeping invariants simple and avoiding double-merges. :contentReference[oaicite:7]{index=7}
- **RNG & spawns**: seeded once (`srand(time(NULL))`). A helper picks a **random empty** cell; probability split is enforced in `chooseRandomNum()`. :contentReference[oaicite:8]{index=8}
- **I/O contract**: menu lists valid inputs (N/R/L/U/D/E), and the board/score/best print every turn for a deterministic UI. :contentReference[oaicite:9]{index=9}
- **Standards-compliant C**: uses standard headers only; code compiles cleanly as **C99**.

---

## Build & Run (Ubuntu)
```bash
make            # builds the program per the provided Makefile
./<executable>  # run (name depends on the Makefile target)

# or compile manually (example):
gcc -std=c99 -Wall -Wextra -O2 main.c game.c -o game2048
./game2048
