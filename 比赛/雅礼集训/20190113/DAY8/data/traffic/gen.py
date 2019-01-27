import os
from random import *

cs = [7, 6, 5, 5]
nl = [1500, 50000, 20000, 50000]
nr = [2000, 100000, 50000, 100000]

# for i in range(4):
#     n = randint(nl[i], nr[i])
# 
#     outp = "%d\n" % n
#     fname = "ex_traffic%d" % (i + 1)
# 
#     for x in range(2, n + 1):
#         if(i == 1):
#             outp += "%d " % randint(1, x - 1)
#         else:
#             outp += "%d " % randint(max(1, x - 10), x - 1)
# 
#     print (outp, file = open("%s.in" % fname, "w"))
#     os.system("./traffic < %s.in > %s.out" % (fname, fname))
# 
# exit()

for i in range(4):
    print(i)
    os.system("mkdir subtask%d" % (i + 1))

    for j in range(cs[i]):
        n = randint(nl[i], nr[i])

        outp = "%d\n" % n
        fname = "subtask%d/traffic%d" % (i + 1, j + 1)

        for x in range(2, n + 1):
            if(i == 1):
                outp += "%d " % randint(1, x - 1)
            else:
                if(j == 0):
                    outp += "%d " % (x // 2)                    
                else:
                    outp += "%d " % randint(max(1, x - j * 10), x - 1)

        print (outp, file = open("%s.in" % fname, "w"))
        os.system("./traffic < %s.in > %s.out" % (fname, fname))
