#WAF to find prime nos between two nos.
def prime_bet(n1,n2):
    n1,n2=min(n1,n2),max(n1,n2)
    primes=[]
    for i in range(n1,n2):
        c=0
        for j in range(1,i+1):
            if i%j==0:
                c+=1
        if c==2:
            primes.append(i)
    print(f'Prime nos between {n1} and {n2} are{primes}.')

prime_bet(50,100)            