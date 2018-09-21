#!/usr/bin/python3

#this program requires Linux system utility and 'file' command support.

import os

#clean repository trees : remove all ELF Linked files .

def checkfile(filename):
	descrip = list (os.popen('file '+ filename).read().split(' '))
	if 'ELF' in descrip:
		os.remove(filename)
		print('ELF file '+filename+' has been removed.')
	elif 'precompiled' in descrip:
		os.remove(filename)
		print('header precompiled file '+filename+' has been removed')
	elif 'ASCII' in descrip:
		os.chmod(filename, 511)
		print(filename +' is a source file and will not be removed.')
	else :
		print(filename+' : unknown filetype found & will not be removed')

def cleandir():
	dirlist = os.listdir()
	for item in dirlist:
		if item[0] != '.':
			if os.path.isdir(item):
				os.chdir(item)
				cleandir()
				os.chdir('..')
			elif os.path.isfile(item):
				checkfile(item)

if __name__ =="__main__":

	cleandir()
	if_update_git = input("Update to github?\n[y/N] : ")
	if if_update_git == 'y' or if_update_git == 'Y':	
		#update the git repository
		os.system('git add .')
		os.system('git commit -m "update"')
		os.system('git push')
	else :
		pass







