# Description

Numerically calculates the unknown functions in a system of the type  
$$f(x) = G(n(x), x)$$    
$$g(x) = H(f(x), x)$$  

Returning the numerical values of $f(x)$ and $g(x)$ in the $x$ domain. The algorithm uses a 2D Newton method and a matrix diagonalization algorithm (LDA decomposition)


For example, in the code the system is solved:

$sin(t) + x^2 + 2y^4 + 5z = 6$   
$t^5 + 3x + 2e^{-y} - 2z^2 = 4$   
$sinh(t^2) + 2x^3 - cos(y) + z^2 = 2$  
$t^3 + x + 2y + 3z = 4$    

The input are the initial 'test' values, an 'ansatz'.




