f = open("text.txt","r")
s = f.read(1)
vowels = ['a','e','i','o','u']
vowel_count = 0
consonant_count = 0
C_Count = 0
VOWEL_COUNT = 0
VOWELS = ['A','E','I','O','U']
while s:
	if s in vowels:
		vowel_count = vowel_count + 1
	elif s.islower():
		consonant_count = consonant_count + 1
	elif s in VOWELS:
		VOWEL_COUNT = VOWEL_COUNT + 1
	elif s.isupper():
		C_Count = C_Count + 1
	s = f.read(1)

print("Vowels in lower case:",vowel_count)
print("Vowel in upper case:",VOWEL_COUNT)
print("Consonant in lower case:" , consonant_count)
print("Consonants in upper Case:" , C_Count)
