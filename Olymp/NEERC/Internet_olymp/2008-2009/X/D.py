def get_root (a, b):
	cnt = a.bit_length()
	l = 1
	r = a
	for i in range (0, cnt + 2, 1):
		mid = (r + l) // 2
		val = mid
		for j in range (0, b - 1, 1):
			val = val * mid
			if val > a:
				break
		if val > a:
			r = mid
		else:	
			l = mid
	
	return l

inf = open ("discuss.in", "r")
ouf = open ("discuss.out", "w")


n = int (inf.readline())

if n < 6:
	print (n, file = ouf)
else:
	for i in range (100, 0, -1):
		if i == 1:
			print (n, file = ouf)
			break
		z = get_root (n, i)
		
		mm = n
		if z > 1:
			mm = n * (z - 1)
		tmp = 1
		for j in range (z, z + 101, 1):
			tmp = tmp * j
			if tmp > mm:
				break
			if tmp == mm:
				print (j, file = ouf)
				break
		if tmp == mm:
			break