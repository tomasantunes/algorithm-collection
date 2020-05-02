import os

username = "example"
desktop_path = "C:/Users/" + username + "/Desktop/"
documents_path = "C:/Users/" + username + "/Documents/"
excluded_extensions = [".lnk", ".url", ".appref-ms"]

for file in os.listdir(desktop_path):
	ext = os.path.splitext(file)[1]
	name = os.path.splitext(file)[0]
	if ext not in excluded_extensions:
		src = desktop_path + file
		dest = documents_path + file
		i = 2
		while(os.path.isfile(dest)):
			dest = documents_path + name + str(i) + ext
			i += 1
		os.rename(src, dest)
		print(src + " moved to " + dest)
