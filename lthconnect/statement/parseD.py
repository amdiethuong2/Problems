inp = open('in.txt')
cnt = 0
for x in open('out.txt').readlines():
    cnt += 1
    nl = inp.readline()
    with open('%02d' % cnt, 'w') as finp:
        finp.write(nl)
        for i in xrange(map(int, nl.strip().split())[1]):
            finp.write(inp.readline())
    with open('%02d.a' % cnt, 'w') as fout:
        fout.write(x)
