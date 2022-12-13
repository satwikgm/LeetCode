class Solution(object):
    def countVowels(self, word):
        """
        :type word: str
        :rtype: int
        """
        ans=0
        x=0
        for i in range(0,len(word)):
            if(word[i] in ['a','e','i','o','u']):
                x = x+i+1
            ans = ans+x
        return ans
