import random
import sys

size = int(sys.argv[1])
min = int(sys.argv[2])
max = int(sys.argv[3])
outName = sys.argv[4]

unsorted = []
sorted = []

for i in range(0,size):
	pick = random.randint(min,max)
	unsorted.append(pick)
	sorted.append(pick)
	
sorted.sort()

fU = open("%s-problem" %(outName), "w")
fS = open("%s-solution" %(outName), "w")

for i in range(0, size):
	fU.write("%d\n" %(unsorted[i]))
	fS.write("%d\n" %(sorted[i]))
	
fU.close()
fS.close()


	
