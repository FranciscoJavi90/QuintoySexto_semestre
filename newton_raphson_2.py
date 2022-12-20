import numpy as np
import matplotlib.pyplot as plt
from tabulate import tabulate

#Valores para graficar la funcion
a = -1           #Valor inicial del rango de x para graficar
b = 10           #Valor final del rango de x para graficar
n = 50           #Cantidad de puntos


#Parametros para controlar las aproximaciones
emax = 10**-3
itermax = 20
x1 = 0


#f(x)
x = np.linspace(a, b, n)     #Se generan los valores de x para construir la grafica
def f(xs):
  f_x = np.sin(xs) - 2/(xs**2 + 1)  #Valor de la funcion para cada x
  return (f_x)

#f'(x) - Derivada de f(x)
def f1(xs):
  f1_x = np.cos(xs) + 4*xs/((xs**2 + 1)**2)
  return (f1_x)

fx = f(x)                     

#Newton - Raphson

xr, yr = NewtonRaphson(x1, emax, itermax)

print("Grafica de la funcion")
plt.figure(figsize=(10, 8))
plt.plot(x, fx, label=("fx"))
plt.plot(x, np.zeros(len(x)), 'k:', label=("0"))
plt.plot(xr, yr, 'ko', label=("Raiz Newton"))
plt.xlabel("x axis")            #Etiqueta de eje
plt.ylabel("y axis")            #Etiqueta de eje
plt.title("Grafica de fx") #Titulo del grafico
plt.legend()                    #Leyendas
plt.show()                      #Mostrar grafico
def NewtonRaphson(x1, es, imax):
  x = x1                              #aproximaciones de la raiz
  xv = []                             #vector que guarda las aproximaciones de la raiz
  ea = 2*es                           #error absoluto
  eav = []                            #vector que guarda el error absoluto
  i = 0                               #numero de iteraciones
  niter = []                          #vector del numero de iteraciones
  fxv = []                            #vector de la funcion f(x)
  Newton_table = []                   #tabla de datos del metodo newton - raphson

  Newton_table.append([i, x, f1(x), f(x), "--", "--"])
  xv.append(x)

  while ea > es and i <= imax:
    x = x - f(x)/f1(x)                #formula de newton - raphson
    xv.append(x)                      
    fxv.append(f1(x))
    i += 1
    niter.append(i)
    
    if x != 0:
      ea = abs((xv[i] - xv[i-1]))
      er = abs((xv[i] - xv[i-1])/xv[i])*100           #error relativo
      eav.append(ea)
    
    Newton_table.append([i, x, f1(x), f(x), ea, er])

  #Tabla de de datos
  print(" ")
  print("Metodo Newton-Raphson")
  print(tabulate(Newton_table, headers = ["Iteracion", "x", "f'(x)", "f(x)", "e abs", "er (%)"]))

  return(x, f(x))
  