#Programador: Francisco Javier Cifuentes Cajas, Id: 2590-20-10308.
N = 100
def hash_truncamiento(k):
    g1 = k%1000
    g2 = (10//10000000)*N
    return (g1+g2)+1

k1=15515321
print('Indice para la clave es: ',hash_truncamiento(k1))
k2=33598192
print('Indice para la clave es: ',hash_truncamiento(k2))
k3=26901527
print('Indice para la clave es: ',hash_truncamiento(k3))
