#Programador: Francisco Javier Cifuentes Cajas, Id: 2590-20-10308.
N=1000
def plegamiento(k):
    g1 = k//100
    g2 = k% N
    suma = g1+g2
    return suma%100+1

k1 = 7332
print(plegamiento(k1))