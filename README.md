# C5 v3.0
C5 is short for Counter Conventional Caesar Cipher Contraption

**Full Disclosure :** 

C5 is **not** intended for any critical security purposes. It is loosely based on the Vigenère  and  Caesar ciphers, and remains, a shift cipher at its core. It's intended for puzzle-ciphers and throwing off casual snooping.It is not immune to being treated as multiple Caesar ciphers, where it may be broken by frequency analysis, as long as the message is long enough or if the password is easily guessed. 

**Algorithm/Steps:**

C5 cipher involves maximum 8 different shifts, of possible values 0, 32-47 and 49-126 applied mostly unevenly across the message, resulting in ciphertext that is not easy to casually crack. Thus each character in the ciphertext has 93 possible shifts used on it.

It is not necessary that all 8 shifts are used, nor that 8 shifts have unique values, nor even that all 8 shifts have non-zero values -- all this depends on the pin and the length of the message.

Hence, a number can be ecnrypted as itself, and the ciphertext can prima facie be very random looking in most cases.

C5 can, as of v3.0, encode/decode text files upto 100,000 chars as well as smaller messages upto 3000 chars entered through the console.

- Encoding :

1. Password is taken. Password has 8 characters. These  are stored as their ASCII values(except 0, which is stored with the value 0) individually.These values are used as the 8 possible shifts.
2. Plaintext is taken in through cosole or as a (text) file.
4. Each character in plaintext is changed depending on its position. The position number is matched with 6 mathematical number series. Depending on which it matches with, a value from the password is used as a shift on the char in that position. If it is a part of none of these series, the position value is checked for being odd or even. The shifted value is stored as an int. ASCII value of char is used for the shift operations. 
5. Each resultant int is printed or saved to a file, and the last number is always -999  (used to terminate input in decryption).
- Decoding :

1. Password is taken and each char's value is stored just as with the encoding process.
2. Ciphertext is taken from user through console or as a file.
3. Same rules as in encrypt are applied and reversed according to the entered password .
4. Decoded text is printed or saved to a file, and if password was correct, the decoded text makes sense and is the same as the original message. 

- **Example :**

Message = "hello"

PIN = "12345678"

Ciphertext =  12 117 118 -999 

**Misc.**

-Windows C5 **=>** Compiled with VS2019 | x86_64 & x86 only | requires ' _ ' prefix before getw & putw |
-MacOS C5 **=>** Compiled with Apple Clang 11 | x86_64 only | Compiled with : " make C5 " |
-Linux C5 **=>** Compiled with Ubuntu GCC 9.3.0 | x86_64 only | Compiled with : " make C5 " & " gcc -static -o C5_static C5.c " |

