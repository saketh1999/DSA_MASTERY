class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        self.carry = 0

        def adjuster(digits:List[int],i:int) :

            if i < -len(digits):
                return

            if i  == -len(digits) and digits[i]==10:
                digits[i] = 0
                digits.insert(0,1)
                return 


            digits[i] += self.carry
            print(digits[i])
            self.carry=0

          
            if digits[i] >= 10:
                print("Hi")
                digits[i] = 0 
                self.carry=1
                adjuster(digits,i-1)
            return


        digits[-1] += 1

        #Edge case 9
        if digits[-1] == 10 and len(digits)==1:
            digits[-1] = 0
            digits.insert(0,1)

        if digits[-1] >= 10:
            digits[-1] = 0
            self.carry=1
            adjuster(digits,-2)

        # print(carry)
        if self.carry == 1 :
            digits.insert(0,1)
        return digits