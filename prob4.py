n=int(input("the number of numbers you wana enter: "))
a=[]
for i in range(n):
	l=input()
	a.append(l)
for i in range(n):
	l=len(a[i])
	s=list(a[i])
	if l>3:
		for j in range(3,l,3):
			s.insert(l-j,",")
		k="".join(s)
		print(k)
