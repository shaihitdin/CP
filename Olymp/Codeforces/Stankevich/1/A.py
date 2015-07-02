
def gcd (a, b):
	if b == 0:
		return a
	return gcd (b, a % b)

inf = open ("china.in", "r")
ouf = open ("china.out", "w")


n = int (inf.readline())

check = n // 2

for i in range (check, 0, -1):
	if gcd (n, i) == 1:
		print (i, file = ouf)
		break
