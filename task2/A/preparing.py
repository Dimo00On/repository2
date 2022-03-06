import random
import sys

output_file = sys.argv[1]
fout = open(output_file, 'w')
print("#include<iostream>", file=fout)
x = int(5 * random.random())
print("const int amount = ", x, ";", sep='', file=fout)
fout.close()
