# Find sum and product of digits of a number.
def sum_prod(n):
    temp=n
    sum,prod=0,1
    while temp>0:
        rem=temp%10
        sum+=rem
        prod*=rem
        temp//=10
    print(f'Sum and Product of Nos are {sum} and {prod}.')

n=int(input("Enter a number: "))
sum_prod(n)        