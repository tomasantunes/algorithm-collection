# Python 3
# Module Dependencies: "dirsync" and "six"

from dirsync import sync

paths = {
	'C:/EXAMPLE1': 'F:/EXAMPLE1',
	'C:/EXAMPLE2': 'F:/EXAMPLE2'
}
	
for a, b in paths.items():
	sync(a, b, "sync")
	sync(b, a, "sync")
