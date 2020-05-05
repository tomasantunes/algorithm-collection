import random

my_lst = [0,3,5,2,9,3,4,6,8,7]

key_lst = []

def process(a):
	b = []
	rang = list(range(len(my_lst)))
	random.shuffle(rang)
	for i in rang:
		b.append(my_lst[i])
		key_lst.append(i)
	return b

random_lst = process(my_lst)

print(random_lst)
print(key_lst)

decoded = []

for i in range(len(random_lst)):
	next = key_lst.index(i)
	decoded.append(random_lst[next])

print(decoded)
