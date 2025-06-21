# Write a Python program to print all permutations of a given string

def permute(s):
    if len(s) == 1:
        return [s]
    permutations = []
    for i in range(len(s)):
        current_char = s[i]
        remaining_chars = s[:i] + s[i+1:]
        for perm in permute(remaining_chars):
            if current_char+perm not in permutations:
                permutations.append(current_char + perm)
    return permutations

print(permute("aaba"))
print(permute("ab"))   
''' a+permute(b) = ab 
    b+permute(a) = ba'''
print(permute("abc"))
'''
if we start from the beginning
pick first char of string and permute rest of the string
abc -> a + permute(bc) -> a + b + permute(c) -> a + b + c
abc -> a + permute(bc) -> a + c + permute(b) -> a + c + b
pick second char 
abc -> b + permute(ac) -> b + a + permute(c) -> b + a + c
abc -> b + permute(ac) -> b + c + permute(a) -> b + c + a
pick third char
abc -> c + permute(ab) -> c + a + permute(b) -> c + a + b
abc -> c + permute(ab) -> c + b + permute(a) -> c + b + a'''
print(permute("abcd"))


# OPTIMISED 
 
    