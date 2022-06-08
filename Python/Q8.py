#Check no is prime or not
def prime_check1(n):
    c=0
    for i in range(1,n+1):
        if n%i==0:
            c+=1
    if c==2:
        print(f'{n} is a prime number.')
    else:
        print(f'{n} is not a prime number.')           

def prime_check2(n):
    for i in range(2,n):
        if n%i==0:
            return f'{n} is not prime.'
    return f'{n} is prime.'   

def prime_check3(n):
    f=False
    for i in range(2,n):
        if n%i==0:
            f=True 
            break   
    if f:
        print(f'{n} is not a prime.')
    else:
        print(f'{n} is prime.')    

n=int(input('Enter a no. '))
prime_check1(n)
print(prime_check2(n))         
prime_check3(n)