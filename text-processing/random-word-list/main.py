import random
import sys

n = 7

if (len(sys.argv) > 1):
	if (sys.argv[1] > 0):
		n = int(sys.argv[1])

file = open('20k-words.txt', 'r');

lines = file.readlines();

words = [x.strip() for x in lines];

for i in range(n):
	print(random.choice(words));
