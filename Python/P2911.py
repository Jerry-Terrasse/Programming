ln=input()
ln=ln.split()
s1=int(ln[0])
s2=int(ln[1])
s3=int(ln[2])
f=[0]
f=f*235
ans=0
for i in range(s1):
  for k in range(s2):
    for l in range(s3):
      f[i+k+l]=f[i+k+l]+1
for i in range(235):
  if f[i]>ans:
    ans=f[i]
print(ans)