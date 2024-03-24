/* 
 * Data Lab (adapted from CS:APP 3e)
 * 
 * <Please put your name and userid here>
 * Name: Jason Self UserID: selfj1
 * 
 * bits.c - Source file with your solutions to the data lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
/*
 * 
 */
int bitXor(int x, int y) {
	int a = x & y; /* Performs bitwise AND operation on x and y and stores it in a. The result is a 1 if both are 1 otherwise its 0  */
	int b = ~x & ~y; /* Performs bitwise AND operation after taking the bitwise NOT of x and y and stores it in b. This inverts all the bits in x & y and then gets the result where its a 1 if both are 1 otherwise its 0 */
	int c = ~a & ~b; /* Performs bitwise AND operation after taking the bitwise NOT of a and b and stores it in c. */
	return c;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {/* Returns the smallest two's complement integer by shifting the bits to the left 31 positions */
  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
	int a = ~((x + 1) ^ x);/* calculates the bitwise negation of (x + 1) XOR x */
	int b = !(x + 1);/* calculate the Boolean negation of (x + 1) */
	int c = !(a + b);/* calculates the boolean negation of the sum of a and b */
  	return c;/* returns the value stored in c */
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {/* Define a bitmask (oddBitMask) with all odd bits set to 1. 0xAA is a hexadecimal number representing 10101010 in binary,so it sets every other bit to 1 starting from the least significant bit */
	int oddBitMask = 0xAA | (0xAA << 8) | (0xAA << 16) | (0xAA << 24);
	return !((x & oddBitMask) ^ oddBitMask);/* Check if all the odd bits in x are set to 1. By performing a bitwise AND between x and oddBitMask, isolate the odd bits of x. Then compare the result with oddBitMask. If they are the same, it means all odd bits in x are set to 1, and the expression evaluates to true (1). Otherwise, it evaluates to false (0).*/
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
	/* Negates x by flipping all the bits and then adds 1 to it */
	return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
	int sign = 1 << 31;/* Defines a bitmask to get the sign bit */
	int lowerBound = ~(0x30);/* Defines what the lower bound of ASCII digits is by inverting the ASCII value of 0 */
	int upperBound = ~(sign | 0x39);/* Defines what the upper bound of ASCII digits is by taking the complement of the ASCII value of 9 and sets the sign bit */

	lowerBound = sign & (lowerBound + 1 + x) >> 31;/* Calculates whether the number is less than the lower bound; If x is less than 0, the result will all be 1's; else, it will be all 0's */
	upperBound = sign & (upperBound + x) >> 31;/* Calculates whether the number is greater than the upper bound; If x is greater than 9, the result will all be 1's; else, it will be all 0's */
	return !(lowerBound | upperBound);/* If either is non-zero, it shows that x is outside the range of ASCII digits, use the logical NOT operator to invert the result so that if 1 is returned x is within range else return 0 */    
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	/* Convert x to a boolean value: 1 if x is nonzero, 0 otherwise */
	x = !(!x);

	/* x will now be all 1's or 0's */
	x = ~x + 1;

	return (x & y) | (~x & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  return !(((y + (~x + 1)) >> 31) & 1);/* Get -x add it to y, shift the sign bit from this to the least significant bit, Bitwise AND the result with 1 to extract the least significant bit of the result,  negate this result which converts 1 to 0 and 0 to 1, if 1 x is less than or equal to and 0 otherwise  */
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  /* The sign bit is copied over when shifting right, by shifting both the original value ant its negation one of them will have a negative sign bit, and the other will have a 0 sign bit. The '|' operator is used to combine the two vals, and the '+1' at the end will map -1 to 0 and 0 to 1 */
  return ((x >> 31) | ((~x + 1) >>31)) + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
// https://zhuanlan.zhihu.com/p/614126795
int howManyBits(int x) {
  int bit16, bit8, bit4, bit2, bit1, bit0, sign;

  sign = x >> 31;// Save the sign bit of x in the sign variable
  x = (sign & ~x) | (~sign & x);// Flip the sign bit if x is positive, so that bitwise operations can be performed on it

  bit16 = !!(x >> 16) << 4;// Calculate the number of 16-bit blocks in x
  x = x >> bit16;// Shift x to the right by the calculated number of 16-bit blocks

  bit8 = !!(x >> 8) << 3;// Calculate the number of 8-bit blocks in the remaining bits of x 
  x = x >> bit8;// Shift x to the right by the calculated number of 8-bit blocks 

  bit4 = !!(x >> 4) << 2;// Calculate the number of 4-bit blocks in the remaining bits of x
  x = x >> bit4;// Shift x to the right by the calculated number of 4-bit blocks 

  bit2 = !!(x >> 2) << 1;// Calculate the number of 2-bit blocks in the remaining bits of x
  x = x >> bit2;// Shift x to the right by the calculated number of 2-bit blocks 
 
  bit1 = !!(x >> 1);// Calculate the number of 1-bit blocks in the remaining bits of x
  x = x >> bit1;// Shift x to the right by the calculated number of 1-bit blocks 
 
  bit0 = x;// The remaining bit is a 0-bit block

  // Return the total number of bits in x, including the leading 1 bit
  return bit16 + bit8 + bit4 + bit2 + bit1 + bit0 + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
	/* IEEE 754 floating point rules  */
	/* Seperate the sign, exponent, and fraction fields of the input float  */
	unsigned int exp = uf & 0x7f800000;// Exponent field
  unsigned int sign = uf & 0x80000000;// Sign field
  unsigned int frac = uf & 0x007fffff;// Fraction field

	/* If the input float is Nan or infinite return it  */
  if (exp == 0x7f800000 || !(uf & 0x7fffffff) )
    return uf;

	/* If the exponent is 0, the float is a denormalized number  */
  if (exp == 0) { 
		/* If the fraction field has a leading 1, adjusts the exponent and shifts the fraction left  */
    if (uf & 0x00200000) 
      exp += 0x00800000;
    frac = (uf & 0x003fffff) << 1;
  }
	/* If the exponent is not 0, adjust the exponent  */
  else {
    exp += 0x00800000;
  }
	
	/* Reconstruct the final float by combining the sign, exponent, and fraction fields  */
  return (sign | exp | frac);
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
	unsigned int exp = (uf & 0x7f800000) >> 23;// Extract the exponent from the float
  unsigned int sign = uf & 0x80000000;// Extract the sign from the float
  unsigned int frac = uf & 0x007fffff;// extract the fractional part from the float

	/* Check if the float is NaN or infinite */
  if (exp == 0xff){
    return 0x80000000u;
  }
	
	/* Checks if the float is out of range  */
  if (exp > 157) {
    return 0x80000000u;
  }
  
	/* If the exponent is greater than 0, add 1 to the fractional part */
  if (exp){
    frac += 0x00800000;
  }

	/* If the exponent is greater than 150, shift the fractional part left by the difference */
  if (exp > 150) {
    frac <<= (exp - 150);
  }

	/* If the exponent is greater than 126, shift the fractional part right by the difference */
  else if (exp > 126) {
    frac >>= (150 - exp);
  }
	/* If the exponent is less than or equal to 126, return 0 */
  else {
    return 0;
	}

	/* If the sign bit is set, invert the fractional part and add 1 */
	if(sign){
		frac= ~frac + 1;
	}

	/* Return the final value */
	return frac;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  // Initialize result variable to 0
  unsigned int result = 0;

  // Check if x is greater than 127
  if (x > 127) {
    // If it is, then return the maximum positive float value (2^127)
    return 0x7f800000u;
  }
  // Check if x is greater than or equal to -126
  else if (x >= -126) {
    // If it is, then calculate the float value by shifting the bias value (127) left by 23 bits (the number of bits in a float mantissa)
    // and adding x to the bias value. This works because the mantissa of a float is normalized, so the leading 1 is implied.
    result = ((x + 127) << 23);
    // Return the result
    return result;
  }
  // Check if x is greater than or equal to -149
  else if (x >= -149) {
    // If it is, then calculate the float value by shifting the implicit leading 1 left by x + 149 bits.
    // This works because the minimum positive float value is 2^-126, which is equivalent to a mantissa of 1.0 x 2^-126.
    // By shifting the implicit leading 1 left by x + 149 bits, we get the desired float value.
    result = (1 << (x + 149));
    // Return the result
    return result;
  }
  // If none of the above conditions are met, then x is less than -149, so return 0 (which represents negative infinity).
  else {
    return 0;
  }
  // Return 0 (just in case none of the above conditions are met, which should never happen)
  return 0;
}
