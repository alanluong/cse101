from random import randint
from math import log10
import sys

def longmul(x, y):
	if y // 10: return x * y
	return 10 * longmul(x, y // 10) + longmul(x, y % 10)

def kmul(x, y):
	if x < 10 or y < 10: return x * y
	sizex = (int)(log10(x) + 1)
	sizey = (int)(log10(y) + 1)
	m = max(sizex, sizey)
	half = m // 2
	shift = (10 ** half)

	xlow = x % shift
	ylow = y % shift
	xhigh = x // shift
	yhigh = y // shift

	z0 = kmul(xlow, ylow)
	z1 = kmul(xlow + xhigh, ylow + yhigh)
	z2 = kmul(xhigh, yhigh)
	return (z2 * (10 ** m)) + ((z1 - z2 - z0) * (10 ** (m // 2))) + z0
	
	

'''
procedure karatsuba(num1, num2)
  if (num1 < 10) or (num2 < 10)
      return num1*num2
	    /* calculates the size of the numbers */
	  m = max(size(num1), size(num2))
		low1, low2 = lower half of num1, num2
			  high1, high2 = higher half of num1, num2
			    /* 3 calls made to numbers approximately half the size */
				  z0 = karatsuba(low1,low2)
				    z1 = karatsuba((low1+high1),(low2+high2))
					  z2 = karatsuba(high1,high2)
					    return (z2*10^(m))+(?z1-z2-z0?*10^(m/2))+(z0)
'''

if __name__ == "__main__":
	n = int(sys.argv[1])
	x = randint(10 ** (n - 1), (10 ** n) - 1)
	y = randint(10 ** (n - 1), (10 ** n) - 1)
	
	print("x: ", x)
	print("y: ", y)
	print("longmul: ", longmul(x, y))
	print("kmul: ", kmul(x, y))
	print("built-in: ", x * y)
