# R Sequence :game_die:

Simple C++ class for sampling low discrepancy reccurrence sequence described in 
[The Unreasonable Effectiveness of Quasirandom Sequences](http://extremelearning.com.au/unreasonable-effectiveness-of-quasirandom-sequences/)

Uses pybind to expose functionality in python. 


## Installation 
```python
pip install . 
```
from the root of this repo 

Then `rsequence` can be imported in python. 


For usage check out the example notebook 

## Quick look
This is how the low discrepancy sequence looks compared to a pseudorandom sample (uniform)
![comparison](./img/compare.png)


You can keep sampling from the same object, and the whole sequence will be low-discrepancy. 
![sample](./img/stateful.png)

