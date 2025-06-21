def hamwt(n) : 
    return bin(n).count('1')

print(hamwt(11))

def hammingweight(n) :
    count = 0
    while n:
        count += n & 1
        n >>= 1
    return count