
#include <stdio.h> //for printf(), scanf(), etc.
#include <string.h> //for strlen()
#define error printf("\nInvalid Input, Sorry.\n"); //macro template for std error message

int *pin(void); // Retruns digits in pin
void encrypt(void); 
void decrypt(void);
int ctln(int); //Catalan numbers
int fib(int);// Fib nos.
int luc(int);// Lucas nos.
int pent(int);// Pentagonal nos.
int hex(int);// Hexagonal numbers.
int prm(int);//Prime numbers.
// Refer https://edublognss.wordpress.com/2013/04/16/famous-mathematical-sequences-and-series/ for these number series.

#define error printf("\nInvalid Input, Sorry.\n"); //macro template for std error message


int main()
{	
	printf("\n| C5 v2 |\n"); // Non-looped version identification

	
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

	return 0;
}


//------Being Functions------

int *pin()
{
    
    int num,q=0; static int pins[8];

    
    printf("Enter 8-digit PIN : ");
    scanf("%d", &num);

    
    for(register int i = 10000000 ; i >= 1 ; i = (i/10)) // i is position of digit.
    {
        int d = ((num - (num % i)) / i); // d stores 'digit' ( divides quotient of (num % i) by i) 
        pins[q] = d; q++; //digit d is stored in pins[]
        num = (num - ( d * i )); 
    }
    

    return pins ; // pointer to static array storing digits of PIN 

} 



void encrypt()
{
    printf("\n");
    int *digits = pin(); int d[8];
	getchar();
    for (int i=0;i<8;i++)
        d[i] = *(digits + i); //puts each digit in a local array.

    char msg[3001]; int en[3001]; //arrays for storing message and encoded output
    printf("\nType Message - \n\n"); 
	fgets(msg,sizeof(msg),stdin); // stores message in msg
	int len = strlen(msg); // gets length of string , needs string.h
	if(msg[len-1] == '\n'){
  		 msg[len-1] = '\0'; // to remove \n added by fgets()
        len -- ; // len reduced to position of char before '\0'
    }

	char ch; int j; // ch -----loop------> j
    for(int i =0;i < len ;i++ ) // for loop to encrypt, contains all relevant rules.
    {   ch = msg[i];

    	if(ctln(i)==1)
        	j = ch + d[2];
    	else if(fib(i)==1)
        	j = ch - d[4];
    	else if(luc(i)==1)
        	j = ch + d[0];
    	else if(pent(i)==1)
        	j = ch - d[6];
    	else if(hex(i)==1)
        	j = ch + d[3];
    	else if(prm(i)==1)
        	j = ch - d[7];
    	else {
        	if(i%2 == 0)
            	j = ch + d[1];
        	else
            	j = ch - d[5];
    	}
    	en[i] = j;
    }
	
    printf("\nEncoded message -\n\n");
	for(int i=0;i < len; i++) // prints hex till last actual char, blocks garbage vals
	{
		printf("%x ", en[i]); // prints shifted char val in hex w.r.t. ASCII 
	}
	printf("-de\n"); // -6f = -222, used to terminate input in decrypt()
}

void decrypt()
{   //similar variable names as in encrypt() excep with '_d' suffix, for easy comparision.
    
    printf("\n");
    int *digits_d = pin(); int d_d[8];
	getchar();
    for (int i=0;i<8;i++)
        d_d[i] = *(digits_d + i); //puts each digit in a local array.

    printf("\nEnter encoded message -\n");
	
	int j_d; char ch_d, msg_d[3001];
	for(int i=0; i < 3000;i++)
	{
		scanf("%x",&j_d);

		if(j_d==-222){
			msg_d[i] = '\0'; //terminates string with 0
			break; 
		}
		else{ // all rules , reverses encryption with correct pin.
            if(ctln(i)==1)
                ch_d = j_d - d_d[2];
            else if(fib(i)==1)
                ch_d = j_d + d_d[4];
            else if(luc(i)==1)
                ch_d = j_d - d_d[0];
            else if(pent(i)==1)
                ch_d = j_d + d_d[6];
            else if(hex(i)==1)
                ch_d = j_d - d_d[3];
            else if(prm(i)==1)
                ch_d = j_d + d_d[7];
            else {
                if(i%2 == 0)
                    ch_d = j_d - d_d[1];
                else
                    ch_d = j_d + d_d[5];			
			
		    }
        }
        msg_d[i] = ch_d;   
    }
    printf("\nDecrypted message -\n\n");
    puts(msg_d);    
}

int ctln(int x)
{
    int arr[]= {1, 2, 5, 14, 42, 132, 429, 1430};int con=0;
    for(int i =0; i < sizeof(arr)/sizeof(arr[0]); i++){
        if(arr[i] == x){
            con = 1;
            break;
        }
    }
    return con;
}

int fib(int x)
{
    int arr[]= {0, 3, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584};
    int con=0;
    for(int i =0;i < sizeof(arr)/sizeof(arr[0]); i++){
        if(arr[i] == x){
            con = 1;
            break;
        }
    }
    return con;
}

int luc(int x)
{
    int arr[]= {4, 7, 11, 16, 17, 19, 31, 37, 41, 47, 53, 61, 71, 79, 113, 313, 353, 503, 613, 617, 863, 1097, 1361};
    int con=0;
    for(int i =0; i < sizeof(arr)/sizeof(arr[0]); i++){
        if(arr[i] == x){
            con = 1;
            break;
        }
    }
    return con;
}

int pent(int x)
{
    int arr[]= {12, 22, 35, 51, 70, 92, 117, 145, 176, 210, 247, 287, 330, 376, 425, 477, 532, 590, 651, 715, 782, 852, 925, 1001, 1080, 1162, 1247, 1335, 1426, 1520, 1617, 1717, 1820, 1926, 2035, 2147, 2262, 2380, 2501, 2625, 2752, 2882};
    int con=0;
    for(int i =0; i < sizeof(arr)/sizeof(arr[0]); i++){
        if(arr[i] == x){
            con = 1;
            break;
        }
    }
    return con;
}

int hex(int x)
{
    int arr[]= {0, 1, 6, 15, 28, 45, 66, 91, 120, 153, 190, 231, 276, 325, 378, 435, 496, 561, 630, 703, 780, 861, 946, 1035, 1128, 1225, 1326, 1431, 1540, 1653, 1770, 1891, 2016, 2145, 2278, 2415, 2556, 2701, 2850};
    int con=0;
    for(int i =0; i < sizeof(arr)/sizeof(arr[0]); i++){
        if(arr[i] == x){
            con = 1;
            break;
        }
    }
    return con;
}

int prm(int x)
{
    int arr[]= {7,13,23,29,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,1097,1103,1109,1117,1123,1129,1151,1153,1163,1171,1181,1187,1193,1201,1213,1217,1223,1229,1231,1237,1249,1259,1277,1279,1283,1289,1291,1297,1301,1303,1307,1319,1321,1327,1361,1367,1373,1381,1399,1409,1423,1427,1429,1433,1439,1447,1451,1453,1459,1471,1481,1483,1487,1489,1493,1499,1511,1523,1531,1543,1549,1553,1559,1567,1571,1579,1583,1597,1601,1607,1609,1613,1619,1621,1627,1637,1657,1663,1667,1669,1693,1697,1699,1709,1721,1723,1733,1741,1747,1753,1759,1777,1783,1787,1789,1801,1811,1823,1831,1847,1861,1867,1871,1873,1877,1879,1889,1901,1907,1913,1931,1933,1949,1951,1973,1979,1987,1993,1997,1999,2003,2011,2017,2027,2029,2039,2053,2063,2069,2081,2083,2087,2089,2099,2111,2113,2129,2131,2137,2141,2143,2153,2161,2179,2203,2207,2213,2221,2237,2239,2243,2251,2267,2269,2273,2281,2287,2293,2297,2309,2311,2333,2339,2341,2347,2351,2357,2371,2377,2381,2383,2389,2393,2399,2411,2417,2423,2437,2441,2447,2459,2467,2473,2477,2503,2521,2531,2539,2543,2549,2551,2557,2579,2591,2593,2609,2617,2621,2633,2647,2657,2659,2663,2671,2677,2683,2687,2689,2693,2699,2707,2711,2713,2719,2729,2731,2741,2749,2753,2767,2777,2789,2791,2797,2801,2803,2819,2833,2837,2843,2851,2857,2861,2879,2887,2897,2903,2909,2917,2927,2939,2953,2957,2963,2969,2971,2999,3001};
    int con=0;
    for(int i =0;i < sizeof(arr)/sizeof(arr[0]); i++){
        if(arr[i] == x){
            con = 1;
            break;
        }
    }
    return con;
}
// Special thanks to: 
/*  @MikeCAT & @SouravGhosh for [https://stackoverflow.com/questions/63269307/how-to-print-a-large-incompletely-filled-array-only-till-last-entered-int-in-c] ;
    @RobertHarvey & @chux-Reinstate Monica for [https://stackoverflow.com/questions/63287497/weird-characters-randomly-appearing-when-converting-int-arr-to-string-in-c-with] ;
    @Martinjames & @PaulOgive for [https://stackoverflow.com/questions/63314287/if-else-if-else-statement-not-working-as-expected] ;
    @MikeCAT for [https://stackoverflow.com/questions/63317914/while-loops-and-arrays-causing-very-odd-behaviour-maybe-a-memory-mixup-c-lan] ;
*/
