class Solution:
    def sortVowels(self, s: str) -> str:
        k = ""
        vowels = "aeiouAEIOU"
        for i in s:
            if i in vowels:
                k+= i
        k = ''.join(sorted(k))
        s = list(s)
        c = 0
        for i in range(len(s)):
            if(s[i] in k):
                s[i] = k[c]
                c+=1
        return ''.join(s)