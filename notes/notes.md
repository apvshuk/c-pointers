## Basics

**1. Byte** — A chunk (bite) of information. It contains 8 bits (binary digits). 4 bits are a nibble.

**2. Data Types** — `char`, `short`, `int`, `long`, `float`, `double`. `short` and `long` are qualifiers for the integer data types `char` and `int`.

**3. Sizes:**
- `char` — 1 byte (8 bits)
- `short` — 2 bytes (16 bits)
- `int` — 4 bytes (32 bits)
- `long` — 4 or 8 bytes (32 or 64 bits)
- `float` — 4 bytes (32 bits; 6–7 decimal digits)
- `double` — 8 bytes (64 bits; 15 decimal digits)

**4. What does it mean to have x bits?**

Having 8 bits means a piece of data is made up of a sequence of 8 individual binary digits (0s and 1s) — only 8. Because each bit can only be a `0` or a `1`, an 8-bit slot has 2⁸ possible arrangements, meaning 256 unique combinations ranging from `00000000` to `11111111`. How these combinations are interpreted depends entirely on how the data type is defined:

- **As an unsigned integer:** any whole number from 0 to 255.
- **As a signed integer:** any whole number from −128 to 127 (one bit is used to track sign).

> **(?) I understand why the range is asymmetric about 0, but why is it heavier on the negative side rather than the positive — is this only a convention, or a consequence of binary algebra? (?)**

- **As text (ASCII):** each of the 256 combinations maps to a specific character. For example, the 8-bit pattern `01000001` equals the number 65, which computers read as the capital letter `'A'`.

So when we say a variable is x-bit, we mean it has a series of x boxes, each of which can store either `0` or `1`.

---

## Variable Sizes

**1.** `size_t`, with format specifier `%zu`, is 64 bits on my machine. `sizeof(a_variable)` also returns a `size_t`, so print it using `%zu`.

**2.** To find variable sizes, I define a variable as `var_type var_name = 1;`. In binary this would be `...00001`. If the variable is n-bit, there will be (n−1) zeros and one 1. The minimum number of times you can left-shift this before the variable becomes 0 is the number of bits the variable has — that is its size in bits. Divide by 8 to get the size in bytes.

---

## Pointers

**1.** The unary operator `*` is the indirection (or dereferencing) operator. When applied to a pointer, it accesses the object the pointer points to.

```c
int x = 1, y = 2, z[10];
int *ip; // ip is a pointer to int

ip = &x;    // ip now points to x
y = *ip;    // y is now 1
*ip = 0;    // x is now 0
ip = &z[0]; // ip now points to z[0]
```

```
To summarize:
int *ip    declares a pointer that will point to integer types only.

ip = &var  makes ip point to var.
           so now *ip gives access to the value of var,
           so another_var = *ip will give another_var the value of var,
           and *ip = 0 will set var to zero.
ip = &yet_another_var  makes ip point to yet_another_var instead.

Notice that when making ip point to a variable (ip = &var), the * operator is not used.
```

**Remember:** If `ip` points to the integer `x`, then `*ip` can appear in any context where `x` could. So `*ip = *ip + 10;` increments whatever `ip` points to by 10. The unary operators `*` and `&` bind more tightly than arithmetic operators, so `y = *ip + 1` takes whatever `ip` points at, adds 1, and assigns the result to `y`; `*ip += 1` and `++*ip` both increment whatever `ip` points at by 1.

**Remember:** Writing `*ip++` will increment `ip` itself rather than what it points to — so use `(*ip)++` instead. This is because unary operators like `*` and `++` associate right to left.

Also, given two pointers `int *ip, *iq;`, assigning `ip = iq` is valid — it copies the contents of `iq` into `ip`, making `ip` point to whatever `iq` was pointing to.

**Final Summary:**
1. `*ip` accesses the variable that `ip` is pointing to.
2. `ip = &x` makes `ip` point to `x`.
3. `*ip` can be used wherever `x` is valid.

---

## Pointers and Function Arguments

C passes arguments to functions by value, so there is no direct way for a called function to alter a variable in the calling function.

```c
void swap(int x, int y) {
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}
// This is wrong.
```

The function above simply copies `a` and `b` into new variables of the same name. The correct approach is to pass pointers to the values to be changed:

```c
// Function definition
void swap(int *px, int *py) {
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}

// Call site
swap(&a, &b);
```

---

## Pointers and Arrays

The book claims: *"Any operation that can be achieved by array subscripting can also be done with pointers. The pointer version will in general be faster but, at least to the uninitiated, somewhat harder to understand."*

```c
int *pa;
int a[10];
pa = &a[0]; // sets pa to point to element zero of array a
x = *pa;    // copies the contents of a[0] into x
```

If `pa` points to a particular element of an array, then by definition `pa + i` points to the element i positions after `pa`, and `pa - i` points to the element i positions before it.

If `pa` points to `a[0]`, then:
- `*(pa + 1)` refers to the contents of `a[1]`
- `pa + i` is the address of `a[i]`
- `*(pa + i)` is the contents of `a[i]`

These hold true regardless of the type or size of the elements in array `a`.

`pa = &a[0]` and `pa = a` are identical when `a` is an array and `pa` is a pointer.

A reference to `a[i]` can also be written directly as `*(a + i)` — no pointer variable needed. Applying `&` to both sides gives us: `&a[i]` and `a + i` are identical in C. Similarly, `pa[i]` is identical to `*(pa+i)`.

> **Note:** In short, an array-and-index expression is equivalent to one written as a pointer and offset.

---

- Note this:

```c
#include <stdio.h>

// strlen: return length of string s
int strlen_(char *);

int main(void) {
    char a[] = "Hello My name is Apoorva";

    // notice these two lines
    printf("%d", strlen_(&a[3]));
    printf("%d", strlen(a)); // this automatically does &a[0]

    return 0;
}

int strlen_(char *s) {
    int n;

    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}
```