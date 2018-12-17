n1=int(input("the number of phrases you want to enter"))
n=[]
a=[]
for i in range(n1):
	l=input().split()
	a.append(l)
	k=len(l)
	n.append(k)
for j in range(n1):
	for i in range (n[j]):
		print (a[j][i][0],end="")
	print("\n",end="")