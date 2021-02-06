# C5 v3.1
C5 is short for Counter Conventional Caesar Cipher Contraption

**Full Disclosure :** 

C5 is **not** intended for any critical security purposes. It is based on the classical Vigenère  and  Caesar ciphers, and remains a shift cipher. It's intended for puzzle-ciphers and throwing off casual snooping.It is not immune to being treated as multiple Caesar ciphers, where it may be broken by frequency analysis, as long as the message is long enough or if the password is easily guessed. 

It is, in fact, cracked : https://puzzling.stackexchange.com/a/101467/70806

**Algorithm/Steps:**

C5 cipher involves maximum 8 different shifts, of possible values 0, 32-47 and 49-126 applied mostly unevenly across the message, resulting in ciphertext that is not easy to casually crack. Thus each character in the ciphertext has 93 possible shifts used on it.

It is not necessary that all 8 shifts are used, nor that 8 shifts have unique values, nor even that all 8 shifts have non-zero values -- all this depends on the pin and the length of the message.

Hence, a number can be ecnrypted as itself, and the ciphertext can prima facie be random looking.

C5 can, as of v3.1, encode/decode text files as well as small messages entered through the Terminal.

- Encoding :

1. Password has 8 characters. These  are stored as their ASCII values (except 0, which is stored with the value 0) individually.These values are used as the 8 possible shifts.

2. Plaintext is taken in through cosole or as a (text) file.

3. Each character in plaintext is shifted depending on its position and the characters of the password. The position is matched with 6 mathematical number series. Correspondingly, a character from the password is used as a shift on the character of the plaintext. If it is a part of none of these series, the position value is checked for being odd or even. The shifted value is stored as an int. ASCII value of plaintext character is operated on by the shift operations. 

4. Each resultant int is printed, and the terminal number of ciphertext is always -999  (used to terminate input in decryption).

- Decoding :

1. Password is taken and each char's value is stored just as with the encoding process.

2. Ciphertext is taken from user through console or as a file.

3. Same rules as in encrypt are applied and reversed according to the entered password .

4. Decoded text is printed or saved to a file, and if password was correct, the decoded text makes sense and is the same as the original message. 

- **Example :**

Message = "hello"

Password = "12345678"

Ciphertext =  51 152 159 55 160 -999
