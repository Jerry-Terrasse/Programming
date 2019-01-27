#'''
r1=input()
r1=r1.split()
s=int(r1[1])
r1=int(r1[0])
#'''
'''
ln=input()
ipt=ln.split()
r1=ipt[0]
s=ipt[1]
'''
for r2 in range(2001):
  if (r1+r2-1000)/2==s:
    print(r2-1000)
    break