# Check if Palindrome number or not.
#Method 1
from sys import platlibdir


def armstr(n):
    temp=n
    pal=0
    while temp>0:
        rem=temp%10
        pal=pal*10+rem
        temp//=10
    if pal==n:
        print(f'{n} is Palindrome number.')
    else:
        print(f'{n} is not Palindrome number.')

n= int(input('Enter a no. '))
armstr(n)