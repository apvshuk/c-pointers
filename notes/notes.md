## Basics
Byte - is a chunk (bite) of information. It contains 8 bits (binary digit). 4 bits are a nibble.


Data Types - char, short, int, long, float, double. SHORT and LONG are just qualifiers for integer datatypes which are CHAR and INT.


char - 1 byte (8 bits)
short - 2 bytes (16 bits)
int - 4 bytes (32 bits)
long - 4 or 8 bytes (32 or 64 bits)
float - 4 bytes (32 bits; 6-7 decimal digits)
double - 8 bytes (64 bits; 15 decimal digits)


What does it mean to have x bits?

- Having 8 bits means a piece of data is made up of a sequence of 8 individual binary digits (0s and 1s). Only 8. Because each bit can be only a "0" or a "1", an 8-bit slot has 2^8 possible arrangements. Meaning, 256 unique combinations, ranging from 00000000 to 11111111. Okay now, how these combinations are interpreted depends totally on how the data type is defined:

As an unsigned integer, it can represent any whole number from 0 to 255
As a signed integer, it can represent from -128 to 127. (it used one bit to track + or -)

(?) okay I understand why it is asymmetric about 0, but why heavier towards the negative side, why not towards the positive; is it only a convention, or a consequence of binary algebra (?)

As Text (ASCII Characters), each of the 256 combinations maps to a specific character. For eg, the 8-bit binary pattern 01000001 equals the number 65, which computers read as capital letter "A".


## Pointers

