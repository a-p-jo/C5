#include <stdio.h>
int pin(void);
void encrypt(void);
void decrypt(void);
#define error printf("\nInvalid Input, Sorry.\n"); //macro template for std error message
int main()
{	
	printf("\n| C5 v1.1 |\n");

	while(1)
	{
		printf("\n-------------------\n\nEncrypt(e) / Decrypt(d) : ");
		char ed;
		scanf("%c", &ed);

		if (ed == 'e' || ed == 'E')
		{
			encrypt();
		}
		else if (ed == 'd' || ed == 'D')
		{
			decrypt();
			getchar();
		}
		else if (ed == 'x' || ed == 'X')
		{
			break;
		}
		else 
		{
			error
		}
	}
	return 0;
}
int pin()
{
	int num, sum = 0;
	printf("Enter 6-digit PIN : ");
	scanf("%d", &num);
	for(register int i = 100000 ; i >= 1 ; i = (i/10))
	{
		int d = ((num - (num % i)) / i);
		sum += d;
		num = (num - ( d * i )); 
	}
	return (sum - (sum/6));
} 
void encrypt()
{
    char msg[3001], ch;
    int i,key, en[3001], count = 0;
	printf("\n");
    key = pin();
	getchar();
	printf("\nType Message - \n\n");
	fgets(msg,sizeof(msg),stdin);
    for(i=0;msg[i]!='\0';i++)
    {
        ch=msg[i];
		int d = (ch - key);
		en[i] = d;
		count++;
    }
    printf("\nEncrypted message -\n\n");
	for(i=0;i <= count; i++)
	{
		printf("%x ", en[i]);
	}
	printf("-6f");
}
void decrypt()
{
	char msg[3001], ch;
    int i,key, en[3001],d;
	printf("\n");
    key = pin();
	printf("\nEnter encrypted message -\n\n");
	getchar();
	for(i=0; i <= 3001;i++)
	{
		scanf("%x",&d);

		if(d==-111){
			msg[i] = '\0';
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

