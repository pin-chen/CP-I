import math
n, k = map(int, input().split())
if n <= math.pow(2,k):
    print("Your wish is granted!")
else:
    print("You will become a flying monkey!")
