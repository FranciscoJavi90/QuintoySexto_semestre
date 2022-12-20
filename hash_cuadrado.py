#Programador: Francisco Javier Cifuentes Cajas, Id: 2590-20-10308.
N = 1000
k_1= int(input("Ingrese numero: "))
def hash_cuadrado(k):
    k_2 = k*k    
    d_g = k_2/1000
    dg_2 =d_g % N
    return dg_2+1
print("El indice es: ", hash_cuadrado(k_1))