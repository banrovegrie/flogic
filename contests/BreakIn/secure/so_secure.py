from Crypto.Util.number import *

FLAG = b"CTF{???????????????????????}"
pt=bytes_to_long(FLAG)
e=65537
d= -1
while d == -1:
    p,q,r,s= getPrime(1024),getPrime(1024),getPrime(2048),getPrime(2048)
    phi = (p - 1) * (q - 1) * (r - 1) * (s - 1)
    d = inverse(e, phi)

n=p*q*r*s

ct=pow(pt,e,n)
print(f"{ct=}\n{n=}\n{e=}")
t = r*q
pt = pow(ct,d,n)
dt = long_to_bytes(pt)
assert dt == FLAG
# Im so confident on my security that im deliberately leaking some stuff to challenge my implementation ;)
leak = (getPrime(9)*(p**2) + getPrime(420)*q*r*s + getPrime(72)*n)%(t)
print(f"{leak=}")

