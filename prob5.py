n=input().split()
n=list(map(int,n))
a={}
for x in n:
	if x not in a:
		a[x]=1
	elif x in a:
		a[x]+=1
print (a)
