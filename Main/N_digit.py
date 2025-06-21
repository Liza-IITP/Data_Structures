''' N digits number in increasing order of digit 
given n and allowed set of digits
find the number of n digit numbers that can be formed
such that digits are in increasing order
eg. n = 2 
allowed digits = [1,2,3,4,0]
ans = [12,13,14,23,24,34] = 6
'''

def generate_combinations(current_combination, start_index, n, allowable_digits):
    allowable_digits.sort()
    if len(current_combination) == n:
        print(''.join(map(str, current_combination)))  # Join and print the current combination
        return
    for i in range(start_index, len(allowable_digits)):
        current_combination.append(allowable_digits[i])   
        generate_combinations(current_combination, i + 1, n, allowable_digits) 
        current_combination.pop()

# Example usage:
allowable_digits = [5,1, 2, 3, 4]  # List of allowable digits
n = 2  # Length of number to generate
generate_combinations([], 0, n, allowable_digits)