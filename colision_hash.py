#Programador: Francisco Javier Cifuentes Cajas, Id: 2590-20-10308.
N=10
arreglo = [None]*(N+1)

def hash_mo(k):
    return k%N+1

def hash_mo2(k):
    return (k+1)%10+1

def Doble_orden_hash(clave, indice):
    nuevo=hash_mo2(indice)
    if(arreglo[nuevo]==None):
        arreglo[nuevo]=clave
    else:
        Doble_orden_hash(clave,nuevo)

def insertar (clav):
    indice = hash_mo(clav)
    if  arreglo[indice] == None:
        arreglo[indice]= clav
    else:
        Doble_orden_hash(clav,indice)
insertar(25)
insertar(43)
insertar(56)
insertar(35)
insertar(54)
insertar(13)
insertar(80)
insertar(104)
print(arreglo)