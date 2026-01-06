class Solution(object):
    def size(self, a):
        s = 0
        while a != 0:
            a //= 10
            s += 1
        return s

    def encrypt(self, a):
        mx = 0
        for i in range(self.size(a)):
            if int(str(a)[i ]) > mx:
                mx = int(str(a)[i])
        nx = 0
        for i in range(self.size(a)):
            nx += (10**i)*mx

        return nx


    def sumOfEncryptedInt(self, nums):
        sum = 0
        for i in range(len(nums)):
            sum += self.encrypt(nums[i])
        return sum

    
