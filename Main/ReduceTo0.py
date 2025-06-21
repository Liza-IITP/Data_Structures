def f(num):
        count = 0         
        if num == 0 : 
            return count
        while num!=0 :  
            if num%2==0 :
                count+=1 
                num=num/2
            else : 
                count+=1
                num-=1 
        return count

print(f(15))
print(f(6))
print(f(14))
print(f(8))
print(f(123))