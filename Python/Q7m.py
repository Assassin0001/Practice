def Check_Vow(s, vowels):
    s = s.casefold()
    dict = {}.fromkeys(vowels, 0)
    for ch in s:
        if ch in dict:
            dict[ch] += 1   
    return dict
     
# Driver Code
vowels = 'aeiou'
string =input("Enter string: ")
print (Check_Vow(string, vowels))