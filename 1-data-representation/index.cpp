/* --------------------------------------
1. **Definition of Informatics:**
   - Derived from "information" + "automatic."
   - Computers process information (text, numbers, etc.) in binary form.

2. **Binary Representation:**
   - Information unit: 0 or 1 (bit).
   - Coding bridges external representation to binary.

3. **Number Systems:**
   - Decimal (Base 10): Common representation using digits 0-9.
     Example: 352 = 3 * 10^2 + 5 * 10^1 + 2 * 10^0.
   - Binary (Base 2): Uses digits 0 and 1.
     Conversion: Divide/multiply by the base to convert integers/fractions.
     90 = 64 + 16 + 8 + 2 = 1000000 + 10000 + 1000 + 10 = 1011010
     floating numbers (numbers with fractions):
     52.25 =>
      1. 52 = 32 + 16 + 4 = 100000 + 10000 + 100 = 110100
      2. 0.25 * 2 = 0.5 (0)
         0.5 * 2 = 1 (1)

      so :: (52.25)10 = (110100.01)2

4. **Binary Operations:** [revise computer architecture operations of numeric systems]
   - Addition: 0+0=0 ; 0+1=1 ; 1+1=0 (carry 1).
   - Subtraction: Borrowing applies for 0-1.
   - Multiplication: Binary rules. ex: 8 * 9
        1000
        1001
      * ----
        1000
       0000. 
      0000.
     1000.
     -------
     1001000
   - Division: Successive subtraction.

5. **Information Encoding:**
   - ASCII Code: Standard (7 bits) and Extended (8 bits).
     Example: 'A' = 65 (10) = 1000001 (2).
   - Unicode expands further for multilingual support.

  1 octet = 1 byte (1ko is same as 1 kb)
  1 oc = 2^3 bits = 8 bits
  1 Ko = 2^10 octets = 1,024 octets
  1 Mo = 2^20 octets = 1,048,576 octets
  1 Go = 2^30 octets = 1,073,741,824 octets
  1 To = 2^40 octets = 1,099,511,627,776 octets

  ASCII Representation:
    7-bit ASCII: Uses 7 bits to represent 128 characters (0-127), including basic English letters and symbols.
    8-bit Extended ASCII: Uses 8 bits to represent 256 characters (0-255), adding accented letters and special symbols.


6. **Number Representation:**
   - Signed Magnitude: 1 bit for sign, n-1 bits for value.
     Example: +18 = 0 0010010, -18 = 1 0010010.
   - Complement Systems:
     a) 1's Complement: Flip bits.
     b) 2's Complement: Flip bits + 1.
   - Floating Point:
     - Form: ±0.m x b^E (Mantissa, Base, Exponent).
     - IEEE 754 standard for binary representation.

    Representation of a real number in floating-point format (Sign, Mantissa, Exponent)

    1. **Sign**:
        - If the number is positive (+), the sign bit is **0**.
        - If the number is negative (-), the sign bit is **1**.
        - Example: for 143.52, the sign would be **0** (positive).

    2. **Mantissa**:
        - The real number is converted to binary => 143 = 10001111
        - The fraction part => 0.52 ≈ 0.1000011 
        - Combine the two => 10001111.1000011 
        - Then, it is normalized in the form 0.1xxxx... (with the leading 1 being implicit).
        - For example, for 143.52, the normalized binary would be 0.111000011101... .

    3. **Exponent**:
        - The exponent is calculated based on the normalization of the number.
        - It is then converted to binary.
        - The exponent is stored in **two's complement** to handle negative values.
        - For example, if the exponent is 3 (as in 143.52 normalized to 0.111000011101...), we represent it in binary with a bias (e.g., 127 for an 8-bit exponent).
        - The exponent in two's complement might be **10000011** (for an exponent of 3, after bias).

    result: 143.52 ≈ 1.00011111000011_2 × 2^7


    Summary of the storage structure:
     ---------------------------------------------------
    | **Sign** | **Mantissa**       | **Exponent**      |
    |----------|--------------------|-------------------|
    | 0        | 1,111000011101...  | 10000011 (7+127)  |
     ---------------------------------------------------
*/