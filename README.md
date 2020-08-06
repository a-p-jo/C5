# C5
C5 is short for Counter Conventional Caesar Cipher Contraption

C5 is not to be used in commercial applications, and is a hobbyist twist to the Caesar cipher.

**Algorithm/Steps:**

- Encryption :

1. Pin is taken. Pin can have (1-6) digits .
2. Key is made from PIN. Key = (sum of digits in PIN - (sum/6))
3. A Message is taken from the user, stored into a char array msg[]
4. Each character x in msg[] is changed as : int d  = (x - key) . Here, the ASCII value of char x is operated on.
5. Each int is stored in an int array en[]. Then, all these ints are printed in hex , with a space separating these , and the last number is always -6f  (hex for -111)
- Decryption :

1. Pin is taken and key is generated from it.
2. Ciphertext is taken from user.

(**Detail** - An if statement (which breaks loop if '-111' is entered) within the for loop (which ensures no. of entered ints <=  size of array storing it)  is used. Numbers taken through scanf(), which allows for whitespace to separate array elements  being entered.)

3. Every entered int d is stored as char ch such that :  ch = (d + key). Char ch is then stored to chararray msg[].
4. Char array msg[] is printed.

- **Example :**

Message = "hello"

PIN = "123456"

Ciphertext =  56 53 5a 5a 5d -6f  
