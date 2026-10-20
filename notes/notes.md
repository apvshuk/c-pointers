## Basics
1. Byte - is a chunk (bite) of information. It contains 8 bits (binary digit). 4 bits are a nibble.

2. Data Types - char, short, int, long, float, double. SHORT and LONG are just qualifiers for integer datatypes which are CHAR and INT.

3. char - 1 byte (8 bits)
short - 2 bytes (16 bits)
int - 4 bytes (32 bits)
long - 4 or 8 bytes (32 or 64 bits)
float - 4 bytes (32 bits; 6-7 decimal digits)
double - 8 bytes (64 bits; 15 decimal digits)

4. What does it mean to have x bits?
- Having 8 bits means a piece of data is made up of a sequence of 8 individual binary digits (0s and 1s). Only 8. Because each bit can be only a "0" or a "1", an 8-bit slot has 2^8 possible arrangements. Meaning, 256 unique combinations, ranging from 00000000 to 11111111. Okay now, how these combinations are interpreted depends totally on how the data type is defined:

As an unsigned integer, it can represent any whole number from 0 to 255

As a signed integer, it can represent from -128 to 127. (it used one bit to track + or -)

(?) okay I understand why it is asymmetric about 0, but why heavier towards the negative side, why not towards the positive; is it only a convention, or a consequence of binary algebra (?)

As Text (ASCII Characters), each of the 256 combinations maps to a specific character. For eg, the 8-bit binary pattern 01000001 equals the number 65, which computers read as capital letter "A".

So when we say a variable is x-bit, we mean - it has a series of x number of boxes and each can store either 0 or 1.

## Variable Sizes
1. size_t with format specifier %zu, is 64 bits on my machine.
sizeof(a_variable) also returns in size_t type, so print using %zu.

2. To find variable sizes, I have done the following - I define a variable (var_type) var_name = 1; This in binary would be ....00001. If variable is n-bit, there will be (n-1) 0's and one 1. Minimum number of times you can left shift this so that variable becomes 0, is the number of bits the variable has - that is the variable size in bits; divide by 8 you get the same in bytes.

## Pointers
1. The unary operator * is the indirection of dereferencing operator;
when applied to a pointer,  it accesses the object the pointer points to.
```c
int x = 1, y = 2, z[10];
int *ip; // ip is a pointer to int

ip = &x; // ip now points to x
y = *ip; // y is now 1
*ip = 0; // x is now 0
ip = &z[0]; // ip now points to z[0]
```
```
To summarize:
int *ip declares a pointer and says it will point to interger types only

ip = &(var) makes ip point to var
so now *ip will have access to value of var
so, another_var = *ip will cause another_var to have value of var
*ip = 0 will make var have value zero
ip = &yet_another_var will make now ip point to yet_another_var

Notice that when pointing to a variable ip = &var or ip = &yet_another_var, * operator is not used.
```

**Remember:** If ```ip``` points to the integer ```x```, then ```*ip``` can occur in any context where x could, so ```*ip = *ip + 10;``` increments whatever ip points to by 10. Unary ops * and & bind more tightly than arithmentic ops, so the expression: ```y = *ip + 1``` takes whatever ip points at, adds 1, and assigns the result to y; ```*ip += 1``` or ```++*ip``` both increment whatever ip points at by 1.

**Remember:** If you do ```*ip++, it would increment ip instead of what it points to. So do (*ip)++. This is because unary operators like * and ++ associate right to left.

Also, ```int *ip, *iq;``` are two pointers, then ip = iq is a valid thing to do. This copies the contents of ip into iq, thus making ip point to whatever iq is pointed to.
