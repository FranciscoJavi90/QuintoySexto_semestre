#Programador: Francisco Javier Cifuentes Cajas, Id: 2590-20-10308.
N = 100

def hash_truncamiento(k):
    g1 = k%100
    g2 = (5//10000)*10
    return (g1+g2)+1

#k=88995
k1 = int(input("Digite un numero de 5 digitos: "))
print('Indice para la clave es: ',hash_truncamiento(k1))