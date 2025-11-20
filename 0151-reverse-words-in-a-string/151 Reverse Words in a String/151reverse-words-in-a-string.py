class Solution:
    def reverseWords(self, s: str) -> str:
        v = s.strip().split()
        s = " ".join(v[::-1])

        return s