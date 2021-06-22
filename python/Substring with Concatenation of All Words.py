'''
30. Substring with Concatenation of All Words
Hard

You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.
'''
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        # This is the resultant list
        indices = []
        
        # Base Conditions
        if( s == None or len(s) == 0 or words is None or len(words) == 0):
            return indices
        
        # This map is to store the word count of each work in the words array
        wordcount = dict()
        
        for word in words:
            if word not in wordcount:
                wordcount[word] = 1
            else:
                wordcount[word] += 1
        
        # We need the lenght of each word now
        wordlen = len(words[0])
        
        # Total length of the substring we need to look for 
        strlen = wordlen * len(words)
        
        # Now we iterate through the string and create a mapping for each string and compare
        for i in range(0, len(s) - strlen + 1):
            # Getting the current string to check
            current = s[i:i+strlen]
            # Creating a map and storing the words of this string. 
            temp = dict()
            
            j = 0
            while(j < strlen):
                if s[i+j:i+j+wordlen] in temp:
                    temp[s[i+j:i+j+wordlen]] += 1
                else:
                    temp[s[i+j:i+j+wordlen]] = 1
                j += wordlen
            
            if( temp == wordcount):
                indices.append(i)
        
        return indices
                
            
            
