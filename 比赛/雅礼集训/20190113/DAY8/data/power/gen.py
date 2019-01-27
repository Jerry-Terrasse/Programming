import os
from random import *

cs = [8, 8, 8, 10, 10, 10]
nl = [1, 15, 15, 15, 15, 40]
nr = [1, 20, 20, 20, 20, 50]
ar = [100000, 0, 0, 100000, 100000, 100000]

# for i in range(6):
#     n = randint(nl[i], nr[i])
#     k = randint(1, 1000000)
#     a = randint(0, ar[i])
# 
#     if(randint(0, 1) == 0): 
#         a = -a
#     
#     if(i == 1 and k % 2 == 0): 
#         k -= 1
# 
#     if(i == 3):
#         k = randint(1, 100)
# 
#     outp = "%d %d %d\n" % (n, k, a)
#     fname = "ex_power%d" % (i + 1)
# 
#     for x in range(n):
#         l = randint(-2000, 2000)
#         r = randint(l, 2000)
# 
#         if(randint(0, 10) == 0):
#             r = l
#         outp += "%d %d\n" % (l, r)
# 
#     print (outp, file = open("%s.in" % fname, "w"))
#     os.system("./power < %s.in > %s.out" % (fname, fname))
# 
# exit()

for i in range(6):
    print (i)
    os.system("mkdir subtask%d" % (i+1))

    for j in range(cs[i]):
        n = randint(nl[i], nr[i])
        k = randint(1, 1000000)
        a = randint(0, ar[i])

        if(randint(0, 1) == 0): 
            a = -a
        
        if(i == 1 and k % 2 == 0): 
            k -= 1

        if(i == 3):
            k = randint(1, 100)

        outp = "%d %d %d\n" % (n, k, a)
        fname = "subtask%d/power%d" % (i+1, j+1)

        for x in range(n):
            l = randint(-2000, 2000)
            r = randint(l, 2000)

            if(randint(0, 10) == 0):
                r = l
            outp += "%d %d\n" % (l, r)

        print (outp, file = open("%s.in" % fname, "w"))
        os.system("./power < %s.in > %s.out" % (fname, fname))
