** bit manupulation imp tricks
1.x^x =0
2.x^0=x
~ << >> , right shift for -ve no. returns all 1 from LHS 

3. bit toggle -xor
4.one’s complement of the number :~num
5.Two’s complement of the number :(~num+1)
6.Stripping off(removing) the lowest set bit : X = X & (X-1)
(method also used for counting no. of set bits(c) with O(c))
7.Getting the lowest set bit of a number: X &(-X)
 Let X = 00101100. So ~X(1’s complement) will be ‘11010011’ 
 and 2’s complement will be (~X+1 or -X) i.e.  ‘11010100

00101100
& 11010100
-----------
  00000100
8. Divide by 2 using the right shift operator

00001100 >> 1 (00001100 is 12)
------------
00000110 (00000110 is 6)

9.Multiply by 2 using the left shift operator

10. 2^x by 1<<x;

11. char('C'|' ') -> c

12. char('c'&'_') -> C

13. unset a bit num &= (~(1 << pos));

14. set a bit num |= (1 << pos);

15.Count set bits in integer  
while (x)
    {
        x &= (x-1);
        count++;
    }

16. like x+=1; ...is ... x=x+1;
         x>>=1          x=x>>1;
         also while(x=....) is while(x)
              if(x=....)  is if(x) but RHS of = is evaluated first

          for non zero x->1 else x->0

17. log base 2 of 32 bit integer
int log2(int x)
{
    int res = 0;
    while (x >>= 1)
        res++;
    return res;
}

18.Checking if given 32 bit integer is power of 2 
 x & (x-1) = 0

19. Compute XOR from 1 to n (direct method):
int computeXOR(int n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}

20.Count of numbers (x) smaller than or equal to n such that n+x = n^x:

count = pow(2, count of zero bits until left most set bit)

21. Find XOR of all subsets of a set
We can do it in O(1) time. The answer is always 0 if the given set has
 more than one element. For sets with a single element, the answer is the value of the single element. 

22.Number of leading zeroes: __builtin_clz(x)
Number of trailing zeroes : __builtin_ctz(x)
Number of 1-bits: __builtin_popcount(x)(no. of set bits)

23.auto number = 0b011;
    cout << number; -> 3

** ** *** 
24. if a number has bits in an alternate pattern
  n ^ (n >> 1) 
  If n has an alternate pattern, then n ^ (n >> 1)
operation will produce a number having all bits set.


//https://www.geeksforgeeks.org/bits-manipulation-important-tactics/#count

*** ****** ****
    inbuilt function ->(int)log2(n);--> for position of max. set bit

    binary to gray code :
    G (n) = n xor (n >> 1)

    **** *** v imp-
    to get a hint to the solution after reading the problem , consider its constraints carefully

    void print_bi(int n){
    for(int i=63;i>=0;i--){
        if((n&(1LL<<i))!=0)cout << 1 ;
        else cout << 0 ;
    }
    cout << endl;
}

when using 64 bit 

        unsigned long long  a=0,b=0;
        unsigned long long  c=1LL;
        (b&(c<<i))
        ******
        *****
        ****
        **
        int x;
        due to implicit type conversion (c<<x)
        is a unsigned long long type

        ** take corner cases -- starting no.s 

        for better underestanding of bit manupulation
            use set theory

******
