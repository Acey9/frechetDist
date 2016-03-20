# frechetDist
frechet distance for c

#compile
* gcc -fpic -c -I/usr/include/python2.6/ -I./ frechet.c wrap.c
* gcc -shared -o frechet.so frechet.o  wrap.o -lpython2.6

#example
```python
import frechet
p = [[0,1], [1,2]]
q = [[0,1], [1,20]]
frechet.distance(len(p), len(q), p, q)
```
