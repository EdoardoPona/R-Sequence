import jax.numpy as jnp
import numpy as np 
import jax


def phi(d): 
	x=2.0000 
	for i in range(10): 
		x = pow(1+x,1/(d+1)) 
	return x



def quasirandom(d, N, seed=0.5):
	g=2.0000 
	for i in range(10): 
		g = jnp.power(1+g,1/(d+1)) 
	a = 1.0/jnp.power(g, jnp.arange(1, d+1))
	print("this is the basis", a)
	X = jnp.vstack([(seed + a * n) % 1 for n in range(1, N+1)])
	return X
		

print(quasirandom(2, 10))



