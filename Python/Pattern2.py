n =int(input())
for i in range(n):
  for j in range(n):
    if i%2==0:
        print(1-(j%2),end="")
    else:
        print((j%2),end="")
  print("")    