class Solution:

    def minimizeXor(self, num1: int, num2: int) -> int:
        #count the number of set bits in num2
        def count_set_bits(num2):
            count=0
            while num2!=0:
                num2=num2 & (num2-1)
                count+=1
            
            return count
        
        bit_count = count_set_bits(num2)

        res = 0
        if bit_count:
            for i in range(31,-1,-1):
                if bit_count:
                    if (num1 & (1<<i)):
                        res = res | (1<<i)
                        bit_count-=1

        if bit_count:
            for i in range(0,31):
                if bit_count:
                    if  (res & (1<<i)) == 0 :
                        res = res | (1<<i)
                        bit_count-=1
        
        return res
