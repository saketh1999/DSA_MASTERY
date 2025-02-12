class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        myDict = defaultdict(list)
        def sum_of_digit(num):
            sum=0
            while num>0:
                sum += num%10
                num//=10
            return sum

        for i in range(len(nums)):
            digit_sum = sum_of_digit(nums[i])
            myDict[digit_sum].append(nums[i])

        print(myDict)
        maxi = float("-inf")
        for mylist in myDict.values():
            if len(mylist) >=2:
                mylist.sort()
                maxi = max(maxi,mylist[-1]+mylist[-2])

        return maxi if maxi>float("-inf") else -1