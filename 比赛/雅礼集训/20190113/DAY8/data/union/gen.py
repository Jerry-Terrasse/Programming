import os
from random import *

cs = [5, 5, 7, 7]
nl = [5, 10, 16, 16]
nr = [7, 15, 20, 20]

mo = 10 ** 9 + 7

for i in range(4):
    n = randint(nl[i], nr[i])

    outp = "%d\n" % n
    fname = "ex_union%d" % (i + 1)

    if(i == 2):
        t = randint(0, mo - 1)
        for x in range(1, n):
            for y in range(x, n):
                outp += "%d " % t
            outp += "\n"
    else:
        for x in range(1, n):
            for y in range(x, n):
                outp += "%d " % randint(0, mo - 1)
            outp += "\n"

    print (outp, file = open("%s.in" % fname, "w"))
    os.system("./union < %s.in > %s.out" % (fname, fname))

exit()

for i in range(4):
    print (i)
    os.system("mkdir subtask%d" % (i + 1))

    for j in range(cs[i]):

        n = randint(nl[i], nr[i])

        outp = "%d\n" % n
        fname = "subtask%d/union%d" % (i + 1, j + 1)

        if(i == 2):
            t = randint(0, mo - 1)
            for x in range(1, n):
                for y in range(x, n):
                    outp += "%d " % t
                outp += "\n"
        else:
            for x in range(1, n):
                for y in range(x, n):
                    outp += "%d " % randint(0, mo - 1)
                outp += "\n"

        print (outp, file = open("%s.in" % fname, "w"))
        os.system("./union < %s.in > %s.out" % (fname, fname))

