from math import *
def f(x):
    func=cos (x)-x**3;
    return func
def df(x):
    return -sin(x)-3*pow(x,2)
def NewtonRaphson (x0, tol,n):
    for k in range (n):
        x1=x0-f(x0)/df(x0)
        if(abs(x1-x0)<tol):
            print('x',k+1,'=',x1,' es la raíz')
            return
        x0=x1
        print('x',k+1,'=',x1)
NewtonRaphson(pi,0.0000001,10)