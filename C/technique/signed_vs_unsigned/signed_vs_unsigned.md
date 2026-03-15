# Signed vs Unsigned

## What is it?
Both store numbers in binary, but they read the bits differently.
- `signed` — can go negative, uses one bit for the sign
- `unsigned` — always positive, uses all bits for the value

## Simple Demo
```c
int8_t   signed_negative   = -3;
works fine → -3

uint8_t  unsigned_negative = -3;
no error but → 253
```
No crash, no warning — just silently wrong. Sneaky bug.

## Why Does -3 Become 253?
Computers store negative numbers using **two's complement**.
`-3` in 8-bit binary looks like:
```
11111101
```
- `int8_t` sees the leading `1` as a minus sign → `-3`
- `uint8_t` sees the same bits as just a number → `253`

Same bits, different interpretation.

## Range Comparison
```
int8_t   (signed)  : -128        to 127
uint8_t  (unsigned):    0        to 255

int16_t  (signed)  : -32768      to 32767
uint16_t (unsigned):     0       to 65535

int32_t  (signed)  : -2147483648 to 2147483647
uint32_t (unsigned):           0 to 4294967295

int64_t  (signed)  : -9223372036854775808 to 9223372036854775807
uint64_t (unsigned):                    0 to 18446744073709551615
```

Signed wastes half its range on negatives.
Unsigned gets double the positive range for the same number of bits.

## So When To Use Which?
| Use `unsigned` | Use `signed` |
|---|---|
| array index | temperature |
| memory size | coordinates |
| pixel color | velocity |
| counter | bank balance |
| bit flags | anything that can go negative |

Simple rule:
> if the value can **never** be negative → use unsigned, you get double the range  
> if the value **can** go negative → use signed

## Format Specifiers
```c
%d   → int32_t
%u   → uint32_t
%ld  → int64_t
%lu  → uint64_t
%hd  → int16_t
%hu  → uint16_t
%hhd → int8_t
%hhu → uint8_t
```
Wrong format specifier = same silent bug as above. Always match them!