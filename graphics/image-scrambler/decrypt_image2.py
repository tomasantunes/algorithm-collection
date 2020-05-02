from PIL import Image

key_file = "key_file.txt"
random_file = "random_im.png"

key_file = open(key_file, "r")
random_im = Image.open(random_file)

w, h = random_im.size

random_lst = list(random_im.getdata())
key_lines = key_file.readlines()
key_lst = map(int, key_lines)
output_lst = []

for i in range(0, len(key_lst)):
	index = key_lst.index(i)
	output_lst.append(random_lst[index])

output_im = Image.new('RGB', (w, h), (255, 255, 255))
output_im.putdata(output_lst)
output_im.save('output_im.png')
		
