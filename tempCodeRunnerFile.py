



sigmaSet = [0,1,2,3,4,5,6,7,8,9]
def count_strings(n, zeroCount):
    dp = [[0] * (n+10) for _ in range(n + 10)]
    for i in range (0,n+1,2):
        dp[0][i]=1

    for len in range (1,n+1):
        for aCount in range (0,n+1):
            for ch in sigmaSet:
                if ch==0:
                    dp[len][aCount]+=dp[len - 1][aCount + 1]
                else:
                    dp[len][aCount]+=dp[len - 1][aCount]

    return dp[n][0]
        





n = int(input())
ans = count_strings(n, 0)

print(ans)
