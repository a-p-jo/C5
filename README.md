# C5 v2.5
C5 is short for Counter Conventional Caesar Cipher Contraption

**Full Disclosure :** 

C5 is **not** intended for any commercial or serious security purposes. It is loosely based on the Vigenère  and  Caesar Ciphers, and remains, a shift cipher at its core. It's intended for making puzzle-ciphers and for the purposes of throwing off casual snooping. A challenge to break C5 is posted [here](https://puzzling.stackexchange.com/questions/100920/can-you-crack-this-multiple-shift-cipher) , and while not yet cracked, it is only a matter of time. It is not immune to being treated as multiple caesar ciphers, where it may be broken by frequency analysis, as long as the message is long enough. 

**Algorithm/Steps:**

C5 cipher involves maximum 8 different shifts, of possible values 0, 32-47 and 49-126 applied mostly unevenly across the message, resulting in ciphertext that is not easy to casually crack. Thus each character in the ciphertext has 93 possible shifts used on it.

It is not necessary that all 8 shifts are used, nor that 8 shifts have unique values, nor even that all 8 shifts have non-zero values -- all this depends on the pin and the length of the message.

Hence, a number can be ecnrypted as itself, and the ciphertext can prima facie be very random looking in most cases.

- Encryption :

1. Password is taken. Password has 8 characters. These  are stored as their ASCII values(except 0, which is stored with the value 0) individually in an array.These values are used as the 8 possible shifts.
2. A Message is taken from the user, stored into a string 'msg'.
4. Each character in msg is changed depending on its position value. The position number is matched with 6 mathematical number series. Depending on which it matches with, a digit from the pin is used as a shift on the char in that position. If it is a part of none of these series, the position value is checked for being odd or even. The shifted value is stored as an int.(ASCII value of char x is used for the shift operations)
5. Each int is stored in an int array 'en'. Then, all elements of en are printed in , with a space separating each from the other , and the last number is always -999  (used to terminate input in decryption).
- Decryption :

1. Pin is taken and digits are stored to array. 
2. Ciphertext is taken from user.
3. Every entered int is stored and the same rules as in encrypt are applied and reversed according to the entered password and stored to string 'msg_d'.
4. String 'msg_d' is printed, and if pin was correct, the decoded text makes sense and is the same as the original message. 

- **Example :**

Message = "hello"

PIN = "12345678"

Ciphertext =  12 117 118 -999 
