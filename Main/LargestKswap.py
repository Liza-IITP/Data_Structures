'''
Largest number in kth swap
eg: 1234567, k=4(atmost)
output: 7654321
swaps :
(7,1),(2,6),(3,5),(4,4)'''
def swaps(num, swap) : 
    num = list(num)
    for i in range(len(num)) :
        if swap == 0 :
            break
        max_index = i
        for j in range(i+1, len(num)) :
            if num[j] > num[max_index] :
                max_index = j
        if max_index != i :
            num[i], num[max_index] = num[max_index], num[i]
            swap -= 1
    return ''.join(num)

print(swaps('1234567', 4)) # output: 7654321
print(swaps('1234567', 2)) # output: 7634521
print(swaps('1234567', 3)) # output: 7654321