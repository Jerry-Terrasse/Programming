import math
ch="abcdefghijklmnopqrstuvwxyz"
maxc=0;minc=int(1e9)
s=input()
for i in range(26):
  f=s.count(ch[i])
  #print(ch[i],':',f,'\n')
  if f==0:
    continue
  if f>maxc:
    maxc=f
  if f<minc:
    minc=f
f=maxc-minc
s=int(math.sqrt(f))+2
#print(s)
for i in range(2,s):
  if i>=f:
    continue
  if f%i==0:
    print("No Answer\n0")
    break
else:
  if f<=1:
    print("No Answer\n0")
  else:
    print("Lucky Word\n%d"%(f))