class Solution:
    def minTime(self, skill: List[int], mana: List[int]) -> int:
        m, n = len(mana), len(skill)
        _sum = sum(skill)
        t = mana[0] * _sum
        for i in range(1, m):
            tprev = t
            for j in range(n-2, -1, -1):
                tprev -= mana[i-1] * skill[j+1]
                t = max(t - mana[i] * skill[j], tprev)
            t += mana[i] * _sum
        return t
            