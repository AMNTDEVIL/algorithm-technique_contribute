# algorithms_techniques_contribute

A collection of algorithms, math concepts, and low-level techniques written across different languages — C, ASM, Python, and whatever else makes sense.

## What is this?
This is a learning repo. Every day (or close to it) one algorithm or technique gets added. The goal is to actually understand how things work under the hood — not just copy paste code.

## How to contribute
- Pick any algorithm, math concept, or technique
- Write it in any language you know
- **If it already exists in one language, write it in a different one** — no duplicates in the same language
- Use AI to help you learn and understand, not to copy paste — figure out why it works, break it, fix it, then write it

## How to document
Every technique or algorithm you add **must have a short explanation** in its folder README so anyone can understand what it does without reading the code. Keep it simple — if a beginner can't understand it, explain it better.

Example of a good doc:
```
## What it does
A lookup table precomputes sin/cos values once at startup
and stores them in an array. Instead of calling sin() every
frame, you just do array[angle] which is way faster.
```

## Example
```
signed_vs_unsigned/
├── signed_vs_unsigned.c     ← done
├── signed_vs_unsigned.s     ← done
├── signed_vs_unsigned.py    ← go ahead
└── signed_vs_unsigned.js    ← go ahead
└── README.md                ← explain what signed vs unsigned is
```
C and ASM are taken — but Python, JS, Rust, anything else is open.

## Structure
```
/C          → C implementations
/asm        → x86 Assembly implementations
/python     → Python implementations
/...        → whatever language fits
```

## Why?
Because reading about algorithms and actually writing them are two completely different things.
