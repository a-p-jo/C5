# C5 v3.1
C5 is short for Counter Conventional Caesar Cipher Contraption

**Disclaimer :** 

- It "works" only on text files; it is at best a puzzle or toy encryption. It is, in fact, trivially crackable : https://puzzling.stackexchange.com/a/101467/70806

- C5 is no longer being developed/fixed/improved beyond v3.1 (which itself changed nothing critical , only cleaned up the code). It will likely remian archived. It is not brilliant code, it has much room for imporvement in File I/O , matching, etc.

*You may wish to take a look at my XOTP repo if you need a well optimized, decently secure and simple cipher.*

**Algorithm/Steps:**

C5 cipher involves maximum 8 different shift bytes, of possible values 0, 32-126 (printable ASCII range) applied mostly unevenly but in a pattern across the message to each of its bytes. Thus there are 94 possible shifts for each byte, one of which may be 0 , i.e, no shift.

The method uses the position of a byte in the plaintext to determine which shift will be applied and how. Suppose the byte being looked at in a given moment is the 43rd byte in the file. The value of it's position , 43, is matched with the values in the following number series (in order) : Catalan , Fibonacci, Lucas, Pentagonal, Hexagonal , Prime , Even , Odd. 

It is possible that a value might overlap from these lists, in such a case wherever it matches first is taken into consideration. Here, 43 will match with prime number series. As can be seen in the source code, this means that the 7th byte of the password will be subtracted from it. Depending on which series it matched with, a byte of plaintext is subjected to addition or substraction with a byte from the password to produce the corresponding byte of ciphertext. Using the key and reversing these operations, one can decode the ciphertext similarly. 

It is not necessary that all 8 shifts will used, nor that 8 shifts have unique values, nor even that all 8 shifts have non-zero values -- all this depends on the pin and the length of the plaintext.

C5 can, as of v3.1, encode/decode input from stdin. 

- **Example :**

Message = "hello"

Bytes of message = {'h', 'e' , 'l', 'l', 'o'} = {104, 101, 108 ,108, 111}

Password = "12345678"

Bytes of password = {'1', '2', '3', '4', '5', '6', '7', '8'} = {49, 50, 51, 52, 53, 54, 55, 56}

Thus :

1. plain = 104 , position  = 0 , match = fib , shift = -4th byte of pswd (-53) , Result = 104 - 53 = **51**
2. plain = 101 , position  = 1 , match = ctln , shift = +2nd byte of pswd (+51) , Result = 101 + 51 = **152**
3. plain = 108 , position  = 2 , match = ctln , shift = +2nd byte of pswd (+51) , Result = 108 + 51 = **159**
4. plain = 108 , position  = 3 , match = fib , shift = -4th byte of pswd (-53) , Result = 108 - 53 = **55**
5. plain = 111 , position  = 4 , match = luc , shift = +0th byte of pswd (+49) , Result = 111 + 49 = **160**
6. Signify end of plaintext , -999

Ciphertext =  51 152 159 55 160 -999
