#Programador: Francisco Javier Cifuentes Cajas.Id:2590-20-10308
'''
Tomando como referencia  la tabla y el grafo que se muestran en la parte inferior y empleando los algoritmos correspondientes cree un programa en el lenguaje python que realice lo siguiente:  
Imprima la Matriz de adyacencia (3pts)
Imprima la Matriz de wharshall (3pts)
Imprima la Matriz de Distancias/Costos (3pts)
Imprima la Matriz de Caminos Mínimos (3pts)
Imprima la Matriz T (3pts)
Considerando la matriz del inciso 2) y el formato que se indica al final del problema ,imprima en pantalla la posición (fila, col) y el valor que ahí se encuentra que permita indicar si existe o no camino entre:
F y A  (1pts)
H y A  (1pts)
Considerando la matriz del inciso 4) y el formato que se indica el final del problema, imprima en pantalla la posición (fila, col) y el valor que corresponde a:
La longitud mínima entre A y E (1pts)
Longitud mínima entre A y H (1pts)
Longitud mínima entre B y D (1pts)
Longitud mínima entre C y D (1pts)
Considerando la matriz del inciso 5) y el formato que se indica al final del problema, imprima en pantalla la posición (fila, col) y nombre del nodo:
Intermedio entre G y C (1.5pts)
Intermedio entre H y A (1.5pts)
 (11 pts) Inserte todos los valores de la Matriz de Caminos Mínimos (utilizando dos ciclos for anidados para recorrer la matriz) dentro de un arreglo de N = 100 utilizando la función hash módulo K%N+1. Si encuentra una colisión resolverla por medio del método de prueba lineal. Finalmente imprima en pantalla el arreglo completo.
Ejemplos de salida:
Numeral 6:
Según la Matriz C en la posición x,y cuyo valor es z existe camino entre A y B
Numeral 7:
Según la Matriz  de Caminos Mínimos en la posición x,y la longitud mínima entre A y B es z
Numeral 8: 
Según la Matriz  T en la posición x,y cuyo valor es Z el nodo intermedio es A
'''
from cmath import e
_infinito = float('inf')
n = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']
valores = [[0, 2, 0, 3, 0, 0, 0, 0],
         [4, 0, 4, 0, 6, 0, 0, 0],
         [0, 6, 0, 0, 0, 7, 0, 0],
         [0, 0, 0, 0, 5, 0, 4, 0],
         [0, 0, 0, 6, 0, 4, 0, 3],
         [0, 0, 4, 0, 0, 6, 0, 0],
         [0, 0, 0, 2, 0, 0, 3, 5],
         [0, 0, 0, 0, 0, 1, 0, 1]]

def imprimirMatriz(matriz):
    print("Indx:", end="\t")
    for i in range(len(matriz)):
        print(n[i], end="\t")
    print()
    for i in range(len(matriz)):
        print(n[i], ": ", end="\t")
        for j in range(len(matriz[i])):
            print(round(matriz[i][j], 1), end="\t")
        print()

print("Matriz de adyacencia:")
adyacencia = []
for i in range(len(n)):
    aux = []
    for j in range(len(n)):
        if valores[i][j] == 0:
            aux.append(0)
        else:
            aux.append(1)
    adyacencia.append(aux)
imprimirMatriz(adyacencia)
print()
print("Matriz C:")
c = []
for i in range(len(n)):
    aux = []
    for j in range(len(n)):
        if valores[i][j] == 0:
            aux.append(0)
        else:
            aux.append(1)
    c.append(aux)

for k in range(len(n)):
    for i in range(len(n)):
        for j in range(len(n)):
            if c[i][j] == 0:
                c[i][j] = c[i][k] * c[k][j]
imprimirMatriz(c)
print()
print("Matriz de distancias/costos:")
distancias = []
for i in range(len(n)):
    aux = []
    for j in range(len(n)):
        aux.append(valores[i][j])
    distancias.append(aux)
imprimirMatriz(distancias)
print()
print("Matriz de caminos minimos:")
caminos_minimos = []
for i in range(len(n)):
    aux = []
    for j in range(len(n)):
        if i == j:
            aux.append(0)
        elif distancias[i][j] == 0:
            aux.append(_infinito)
        else:
            aux.append(distancias[i][j])
    caminos_minimos.append(aux)
for k in range(len(n)):
    for i in range(len(n)):
        if i == k:
            continue
        for j in range(len(n)):
            if j == k:
                continue
            if caminos_minimos[i][j] > caminos_minimos[i][k] + caminos_minimos[k][j]:
                caminos_minimos[i][j] = caminos_minimos[i][k] + caminos_minimos[k][j]
imprimirMatriz(caminos_minimos)
print()
print("Fila y columna que indican si existe o no camino entre:")
print("F y A", end=": ")
if c[5][0] == 1:
    print(f"Según la Matriz C en la posición {5},{0} cuyo valor es {c[5][0]} existe camino entre A y B")
else:
    print(f"Según la Matriz C en la posición {5},{0} cuyo valor es {c[5][0]} NO existe camino entre A y B")
print()
print("H y A", end=": ")
if c[7][0] == 1:
    print(f"Según la Matriz de Caminos Mínimos en la posición {7},{0} la longitud mínima entre A y B es {c[7][0]}")
else:
    print(f"Según la Matriz de Caminos Mínimos en la posición {7},{0} la longitud mínima entre A y B NO es {c[7][0]}")        
print()
print("Posiciones y valores que corresponden a:")
print("La longitud mínima entre A y E", end=": ")
if caminos_minimos[0][4] == _infinito:
    print("No existe camino, ya que la fila 0 con la columna 4, que corresponde a el camino A -> E, es infinito")
else:
    print("Existe camino, ya que la fila 0 con la columna 4, que corresponde a el camino A -> E, es ", caminos_minimos[0][4])   
print()
print("Longitud mínima entre A y H", end=": ")
if caminos_minimos[0][7] == _infinito:
    print("No existe camino, ya que la fila 0 con la columna 7, que corresponde a el camino A -> H, es infinito")
else:
    print("Existe camino, ya que la fila 0 con la columna 7, que corresponde a el camino A -> H, es ", caminos_minimos[0][7])
print()
print("Longitud mínima entre G y C", end=": ")
if caminos_minimos[6][2] == _infinito:
    print("No existe camino, ya que la fila 6 con la columna 2, que corresponde a el camino G -> C, es infinito")
else:
    print("Existe camino, ya que la fila 6 con la columna 2, que corresponde a el camino G -> C, es ", caminos_minimos[6][2])
print()
print("Longitud mínima entre D y C", end=": ")
if caminos_minimos[3][2] == _infinito:
    print("No existe camino, ya que la fila 3 con la columna 2, que corresponde a el camino D -> C, es infinito")
else:
    print("Existe camino, ya que la fila 3 con la columna 2, que corresponde a el camino D -> C, es ", caminos_minimos[3][2])
print()
arreglo = []