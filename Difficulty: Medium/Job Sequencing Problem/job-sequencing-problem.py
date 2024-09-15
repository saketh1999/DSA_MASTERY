#User function Template for python3
'''
class Job:
    
    # Job class which stores profit and deadline.
    
    def __init__(self,profit=0,deadline=0):
        self.profit = profit
        self.deadline = deadline
        self.id = 0
'''        

class Solution:
    
    #Function to find the maximum profit and the number of jobs done.
    def JobScheduling(self,Jobs,n):
        Jobs.sort(key = lambda x: x.profit,reverse=True)
        max_deadline = max([x.deadline for x in Jobs])
        
        # for x in Jobs:
        #     print(x.id,x.profit,x.deadline)
        jobq = [-1]*(max_deadline+1)
        
        profit = 0
        count = 0
        for x in Jobs:
            if jobq[x.deadline] == -1:
                jobq[x.deadline] = x.id
                profit += x.profit
                count+=1
            else:
                i=x.deadline-1
                
                
                while i > 0:
                    if jobq[i] == -1:
                        # print(x.profit,x.id)
                        jobq[i] = x.id
                        profit += x.profit
                        count+=1
                        break
                    i-=1
                    
                    
        # print(jobq)
        
        return [count,profit]
        
        # code here


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys


#Contributed by : Nagendra Jha
class Job:
    '''
    Job class which stores profit and deadline.
    '''

    def __init__(self, profit=0, deadline=0):
        self.profit = profit
        self.deadline = deadline
        self.id = 0


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        info = list(map(int, input().strip().split()))
        Jobs = [Job() for i in range(n)]
        for i in range(n):
            Jobs[i].id = info[3 * i]
            Jobs[i].deadline = info[3 * i + 1]
            Jobs[i].profit = info[3 * i + 2]
        ob = Solution()
        res = ob.JobScheduling(Jobs, n)
        print(res[0], end=" ")
        print(res[1])

# } Driver Code Ends