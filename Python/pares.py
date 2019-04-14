
def main():
	
	arr = list(map(int, input().split()))
	
	for x in range (arr[0],arr[1]+1):
		if x % 2 == 0:
			print (x)
main()