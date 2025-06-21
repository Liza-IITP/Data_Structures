def if2power(n) : 
    return n>0 and (n&(n-1))==0
print(if2power(32))

def ifoddeven(n) : 
    if n & 1:
        print("Odd")
    else:
        print("Even")
ifoddeven(3)

def ifprime(n) :
    if n<2:
        return False
    for i in range(2,n):
        if n%i==0:
            return False
    return True
print(ifprime(3))
