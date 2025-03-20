#!/usr/bin/python

import cgi, os

form = cgi.FieldStorage()
fileitem = form['file1']
path = "./uploads/"

if not os.path.exists(path):
	os.makedirs(path)

if fileitem.filename:
	fn = os.path.basename(fileitem.filename)
	file_path = os.path.join(path, fn)
	with open(file_path, 'wb') as f:
		f.write(fileitem.file.read())
	message = "Le fichier '{}' a ete telecharge avec succes avec Python.".format(fn)
else:
	message = "Aucun fichier telecharge."

print("""\
<html>
<body>
<p>{}</p>
</body>
</html>
""".format(message))
