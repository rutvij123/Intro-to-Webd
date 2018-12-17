def gcd_finder(dividend,divisor):
	if dividend%divisor ==0:
		return divisor
	else:
		return gcd_finder(divisor,dividend%divisor)

n=list(map(int,input("enter your two numbers").split(" ")))
if n[0]>n[1]:
	l=n[0]
	s=n[1]
else:
	l=n[1]
	s=n[0]
print(gcd_finder(l,s))