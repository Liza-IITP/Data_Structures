def maximumWealth(accounts):
    maxWealth = 0
    for account in accounts:
        maxWealth = max(maxWealth, sum(account))
    return maxWealth
accounts = [[1,2,3],[3,2,1],[1,1,1]]

print(maximumWealth(accounts)) # Output: 6