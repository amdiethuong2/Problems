cnt = 0
with open("in.txt") as inf:
    inf.readline()
    for ans in open("out.txt"):
        inf.readline()
        cnt += 1
        n, m = map(int, inf.readline().strip().split())
        with open("%02d" % cnt, "w") as inf2:
            inf2.write("%d %d\n" % (n, m))
            for x in xrange(m):
                inf2.write(inf.readline())
        with open("%02d.a" % cnt, "w") as ans2:
            ans2.write(ans)