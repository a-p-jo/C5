//------------Begin Initialisation--------------

#include <stdio.h> //for printf(), scanf(), etc.
#include <string.h> //for strlen()

int pin(void); // Retruns key
void encrypt(void);
void decrypt(void);

#define error printf("\nInvalid Input, Sorry.\n"); //macro template for std error message

//------------End Initialisation--------------

//------------Begin Main--------------
int main()
{	
	printf("\n| C5 v1.2 |\n"); // Non-looped version identification

	//------------Begin While--------------
	while(1)
	{
		printf("\n-------------------\n\nEncode(e) / Decode(d) : "); //Looped Message 
		char edx; // stores choice 
		scanf("%c", &edx);

		if (edx == 'e' || edx == 'E')
		{
			encrypt(); 
		}
		else if (edx == 'd' || edx == 'D')
		{
			decrypt();
			getchar(); //absorbs \n produced after decrypt() 
		}
		else if (edx == 'x' || edx == 'X')
		{
			break; // terminates loop, causing program to end.
		}
		else 
		{
			error 
		}
	}
	//------------End While--------------
	return 0;
}
//------------End Main--------------

//------Being Functions------

int pin() //Takes PIN, returns KEY .
{
	
	int num, sum = 0;

	
	printf("Enter 6-digit PIN : ");
	scanf("%d", &num);

	
	for(register int i = 100000 ; i >= 1 ; i = (i/10)) // i is position of digit.
	{
		int d = ((num - (num % i)) / i); // d stores 'digit' ( divides quotient of (num % i) by i) 
		sum += d; // sum stores sum of digits 
		num = (num - ( d * i )); // reduces d (with its position) from num, enabling next digit to be first digit of num;
	}
	

	return (sum - (sum/6)); // key 
} 

//----------

void encrypt() // Encrypts by shifiting chars by -key ; prints hex val of shifted char w.r.t ASCII encoding.
{
	
	char msg[3001], ch; // msg take max 3000 chars 
    int i,key, en[3000],len; // en stores encoded chars, len tracks freq of chars encoded


	printf("\n"); 
    key = pin();
	getchar(); //absorbs \n produced after pin()
	
	
	printf("\nType Message - \n\n"); 
	fgets(msg,sizeof(msg),stdin); // stores message in msg
	len = strlen(msg); // gets length of string  
	if(msg[len-1] == '\n')
  		 msg[len-1] = '\0'; // to remove \n added by fgets()
    len -- ; // len reduced to position of char before '\0'
	
	
	for(i=0;msg[i]!='\0';i++)
    {
        ch=msg[i];
		int d = (ch - key);
		en[i] = d;
    }
    
	
	printf("\nEncoded message -\n\n");
	for(i=0;i < len; i++) // prints hex till last actual char, blocks garbage vals
	{
		printf("%x ", en[i]); // prints shifted char in hex w.r.t. ASCII 
	}
	printf("-6f\n"); // -6f = -111, used to terminate input in decrypt()

}

//---------

void decrypt()
{
	char msg[3001], ch;
    int i,key, en[3000],d;
	
	
	printf("\n");
    key = pin();
	
	
	printf("\nEnter encrypted message -\n\n");
	getchar();
	
	
	for(i=0; i < 3000;i++)
	{
		scanf("%x",&d);

		if(d==-111){
			msg[i] = '\0'; //terminates string with \0
			break; 
		}
		else{
			ch = d + key;
			msg[i] = ch;
		}
	}
    
	
	printf("\nDecrypted message -\n\n");
	puts(msg);
}

//------End Functions------
