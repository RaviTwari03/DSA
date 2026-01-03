class Solution:
    def numOfWays(self, n: int) -> int:
        MOD = 10**9+7
        cache = {}
        def dp(i, j, mask):
            if (i, j, mask) in cache:
                return cache[(i, j, mask)]

            if i == n and j == 0: return 1
            newj, newi = j + 1, i
            if newj == 3:
                newi += 1
                newj = 0            

            res = 0
            for c in ('r', 'y', 'g'):
                if mask[j] == c or (j > 0 and mask[j-1] == c): continue
                newmask = mask[:j] + c + mask[j+1:]
                res = (res + dp(newi, newj, newmask))%MOD
            cache[(i, j, mask)] = res    
            return res

        return dp(0, 0, '000')