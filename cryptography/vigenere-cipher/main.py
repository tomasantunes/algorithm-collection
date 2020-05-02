# vigenere cipher

def rotate(l, n):
    return l[n:] + l[:n]

def createSquare():
	alphabet = []
	for i in range(65, 90 + 1):
		alphabet.append(chr(i))

	obj = {}
	for i in range(0, 26 + 1):
		alphabet = rotate(alphabet, 1)		
		obj[alphabet[0]] = alphabet
	return obj

def encode(square, message, key):
	str_lst = list(message)
	key_lst = list(key)
	result = ""
	current_key = 0
	for i in str_lst:
		result += square[key_lst[current_key]][square['A'].index(i)]
		current_key += 1
		if current_key >= len(key_lst):
			current_key = 0
	return result

def decode(square, message, key):
	str_lst = list(message)
	key_lst = list(key)
	result = ""
	current_key = 0
	for i in str_lst:
		result += square['A'][square[key_lst[current_key]].index(i)]
		current_key += 1
		if current_key >= len(key_lst):
			current_key = 0
	return result

message = "THEQUICKBROWNFOX"
key = "MYKEY"

square = createSquare()
encoded = encode(square, message, key)
decoded = decode(square, result, key)

print(encoded)
print(decoded)
	

