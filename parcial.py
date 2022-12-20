#Programador: Francisco Javier Cifuentes Cajas, Id: 2590-20-10308.
N=100
def hash_plegamiento(k):
    dg2 = k // (N*100)
    dg3 = k // (N//10)
    dg3_1 = dg3 % N
    dg3_2 = k % (N//10)
    dg4 = dg2 + dg3_1 + dg3_2
    dg5 = dg4 % N
    return dg5+1

def hash_truncamiento(k):
    g1 = k%100
    g2 = (10//10000)*10
    return (g1+g2)

k1=15515321
k2=33598192
k3=26901527
print("El Indice Para La Clave",k1,"Es: ", hash_plegamiento(k1))
print("El Indice Para La Clave",k2,"Es: ", hash_plegamiento(k2))
print("El Indice Para La Clave",k3,"Es: ", hash_plegamiento(k3))

print("El Indice Para La Clave",k1,"Es: ", hash_truncamiento(k1))
print("El Indice Para La Clave",k2,"Es: ", hash_truncamiento(k2))
print("El Indice Para La Clave",k3,"Es: ", hash_truncamiento(k3))