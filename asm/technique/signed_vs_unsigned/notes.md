# Bit Shifting — Signed vs Unsigned (x86 ASM)

## The 4 Shift Instructions
```asm
shrl  → shift logical right   (unsigned)
sarl  → shift arithmetic right (signed)
shll  → shift logical left
sall  → shift arithmetic left
```

## Memory Layout (32-bit)
```
bit position: 31 30 29 ... 2  1  0
              0  0  0  ... 0  0  0
```
bit 31 is the **sign bit** — 0 means positive, 1 means negative

## Shift Left Example
```
value = 5
bits:  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1  = 5

shl 1: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0  = 10
shl 2: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0  = 20
```
shift left by 1 = multiply by 2

## Shift Right Example
```
value = 10
bits:  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0  = 10

shr 1: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1  = 5
```
shift right by 1 = divide by 2

## The Important Part — Negative Numbers

Negative numbers are stored using **two's complement**:
1. start with the positive value in bits
2. flip all bits
3. add 1
```
-10 in 32-bit:
step 1 (10):  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0
step 2 flip:  1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 0 1
step 3 +1:    1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 0  = -10
```

## sarl vs shrl on Negative Numbers
```
-10 sarl 1:   1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1  = -5
              ↑ fills with 1 — preserves sign

-10 shrl 1:   0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 0  = 2147483642
              ↑ fills with 0 — sign bit gone, now huge positive number
```

- `sarl` — looks at bit 31, fills incoming bit with same value (keeps sign)
- `shrl` — always fills with 0, doesn't care about sign

## The -128 Edge Case (8-bit)
```
128 in 8-bit:   1 0 0 0 0 0 0 0
flip:           0 1 1 1 1 1 1 1
+1:             1 0 0 0 0 0 0 0  ← same bits as 128!
```

`-128` and `128` have the exact same bits in 8-bit. There is no way to store `128` in `int8_t` — it becomes `-128` instead.
```
128 + 128 in 8-bit:
  1 0 0 0 0 0 0 0
+ 1 0 0 0 0 0 0 0
─────────────────
1 0 0 0 0 0 0 0 0  ← carry falls off, result = 0
```

This is called **integer overflow**.

## The Key Takeaway

> signed and unsigned are not about the bits — they are about **interpretation**
> the CPU stores the same bits either way, you just tell it how to read them
```
sarl = "hey CPU, bit 31 is a sign bit, respect it when shifting"
shrl = "hey CPU, just shift, treat all bits as data"
```

## Output
```
original                = -3
shift right unsigned    = 2147483646   ← sign bit treated as data
shift right signed      = -2           ← sign preserved
shift left              = -6           ← -3 * 2 = -6
```