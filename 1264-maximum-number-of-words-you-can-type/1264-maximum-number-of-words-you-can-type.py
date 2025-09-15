class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        cnt =0
        arr  = text.split();
        for i in range(len(arr)):
            for j in brokenLetters:
                if j in arr[i]:
                    cnt +=1
                    break;

        return len(arr) - cnt