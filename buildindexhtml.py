


totalCodeFiles = 0

import os

fp = open("index.html", "w")
fp.write("<html><head></head><body>")
fp.write("<br>")
fp.write('<a href="https://github.com/advancedgamesprogramming/advancedgamesprogramming.github.io">https://github.com/advancedgamesprogramming/</a><br><br>')

for root, dirs, files in os.walk("."):
	path = root.split(os.sep)
	if ( ".git" in path ):
		continue
	if ( ".vs" in path ):
		continue
	ss = ((len(path) - 1) * '---', os.path.basename(root))
	ss = str( ss ) + "<br>"
	print ss
	fp.write( ss )
	for file in files:
		ss = (len(path) * '---', file)  
		ss = str( ss ) + "<br>"
		print ss
		fp.write(ss)
		totalCodeFiles+=1

fp.write("Total Code Files: " + str(totalCodeFiles))
fp.write("</body></html>")
fp.close()
fp = 0




