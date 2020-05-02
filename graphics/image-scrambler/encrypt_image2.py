from PIL import Image
import random

def process(a):
	rang = list(range(0,len(a)))
	random.shuffle(rang)
	b = []
	for x in rang:
		b.append(a[x])
		key_lst.append(x)
	return b

filename = 'cat.jpg'

src_im = Image.open(filename)
src_list = list(src_im.getdata())
w, h = src_im.size

random_lst = []
key_lst = []

for i in src_list:
	random_lst.append(i)

random_lst = process(random_lst)

random_im = Image.new('RGB', (w, h))
random_im.putdata(random_lst)
random_im.save('random_im.png')

key_str = ""
for k in key_lst:
	key_str += str(k) + "\n"

key_file = open("key_file.txt", "w")
key_file.write(key_str)
key_file.close()
