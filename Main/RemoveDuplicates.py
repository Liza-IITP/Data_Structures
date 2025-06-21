def removeDuplicates( s: str) -> str:
        stack = []
        for i in s : 
            if i not in stack : 
                stack.append(i)
            else :
                if stack!=[] and i== stack[-1] : 
                    stack.pop() 
        return "".join(stack) 
# remove duplicates 
s = "abbaca"
print(removeDuplicates(s))
print(removeDuplicates("abbaca"))  # Output: "ca"
print(removeDuplicates("azxxzy"))  # Output: "ay"
print(removeDuplicates("a"))       # Output: "a"
print(removeDuplicates("aaaa"))    # Output: ""
print(removeDuplicates("abccba"))  # Output: ""


