import ast

test_id=0

for line in open("gcdlcm.dat", "r"):
	if line.strip()=="":
		continue
	print "Start ", test_id
	line=[x.strip() for x in line.split('\t') if x.strip()!=""]
	inp, ans, ver = line
	inp = inp.replace("{", "(").replace("}", ",)").replace("(,)", "()");
	inp = ast.literal_eval("(" + inp + ",)");
	n, s, a, b, c = inp
	m=len(s)
	with open("{}.in".format(test_id), "w") as F:
		F.write("{} {}\n".format(n, m))
		for i in range(m):
			F.write("{} {} {} {}\n".format(s[i], a[i], b[i], c[i]))
			
	with open("{}.ans".format(test_id), "w") as F:
		F.write("{}\n".format(ans.strip()[1:-1]))
	
	print "Done ", test_id
	test_id+=1;
	
