# Lookup Table Technique

## What is a Lookup Table?
Instead of calculating `sin()` and `cos()` every frame (which is slow), you calculate all the values **once** at startup and store them in an array. After that, getting a value is just `array[index]` which is super fast.

## Why Bother?
- `sin()` and `cos()` are expensive — they do a lot of math internally
- Array lookup is basically free
- This is how **Doom (1993)** handled all its angle math — no floating point at runtime at all

## How It Works
```c
// build the table once
for (int i = 0; i < N; i++) {
    double s = sin((i * 2.0 * PI) / N);
    sin_table[i] = (int32_t)(s * 65536);
}

// now use it anywhere — no sin() call needed
int32_t x = (radius * cos_lookup(angle)) >> 16;
int32_t y = (radius * sin_table[angle]) >> 16;

## The 65536 Thing
We multiply by `65536` (which is `2^16`) before storing as integer because:
- You cant store `0.707` in an `int32_t` — it becomes `0`
- So we scale it up: `0.707 * 65536 = 46340` — now we can store it
- When using it, we shift right by 16 (`>> 16`) to scale back down
- This is called **fixed-point math** — doing decimal math with integers

BUILD:   sin(angle) * 65536  →  store as int
USE:     (x * sin_table[i]) >> 16  →  get real value back


## Cosine For Free
```c
// cosine is just sine shifted 90 degrees
// so no second table needed!
int32_t cos_lookup(int angle) {
    return sin_table[(angle + N/4) % N];
}


## The Unsigned Bug (classic mistake)

We made this mistake while writing this:

uint32_t cos_lookup(int angle) {  // WRONG
    return sin_table[(angle + N/4) % N];
}


Output was broken and looked like this:

angle=2560  x=65497  y=92    // should be x=-39
angle=3072  x=65465  y=70    // should be x=-71


### Why?

Computers store negative numbers in a format called **2's complement**.
So `-39` in binary looks like this:

11111111 11111111 11111111 11011001


When you use `uint32_t` (unsigned), C reads the exact same bits but treats that leading `1` as just a normal data bit instead of a minus sign — so `-39` becomes `65497`.

No crash, no warning — just silently wrong numbers. Super sneaky bug.

### Fix

int32_t cos_lookup(int angle) {  // CORRECT
    return sin_table[(angle + N/4) % N];
}


### Simple Rule
> if the value can go negative → use `int`  
> if the value is always positive (sizes, colors, flags) → use `uint`

## Pitfalls
- always use `int32_t` not `uint32_t` — sine goes negative!
- cast to `int64_t` before multiplying to avoid overflow
- the `>> 16` shift goes at **usage time**, not when building the table

## Result

angle=0     x=100   y=0
angle=512   x=92    y=38
angle=1024  x=70    y=70
angle=2048  x=0     y=100
angle=4096  x=-100  y=0      ← negatives working correctly
angle=6144  x=0     y=-100

A perfect circle using nothing but integer math and array lookups.