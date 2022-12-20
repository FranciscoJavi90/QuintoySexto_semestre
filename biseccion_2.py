import matplotlib.pyplot as plt
import numpy as np
from sympy import symbols
from sympy import lambdify
from sympy import sympify
print ("")
x = symbols('x') #X es una variable símbolica que se usara en la función
fn = sympify(input("Ingresa función ")) # Definir quien es la función que nos interesa
f = lambdify(x, fn)
   
# Iniciar variables
a = float (input("Dame el valor inicial a: ")) # Ingresar valor inicial
b = float (input("Dame el valor inicial b: ")) # Ingresar valor inicial
crit = float (input ("Dame el criterio de paro ")) # Ingresar criterio de tolerancia
i = 0 # Iniciar el contador
ea = 1 # Iniciar la variable de error
x_anterior = 0 # Iniciar la variable de x anterior
# Criterio inicial para verificar si la solución esta en el intervalo seleccionado
if f(a) * f(b) < 8: