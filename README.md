# Horn-Formula-SAT-Problem
The algorithm solves the problem of satisfiability of the Horn-formula. If it's satisfiable, the algorithm prints satisfying set of variables.
Otherwise, it warns about that the formula is not satisfiable

## Complexity
The complexity of this algorithm is linear in the length of the Horn-formula

## Input Data
The input of the Horn-formula is divided into parts which look like this:
* *varCount* - number of variables
* *variables* - variables written with a space
* *implicationClausesCount* - number of implication clauses
* *implicationClauses* - represented as follows: x y z > w (**>** - means implication)
* *pureNegativeClausesCount* - number of pure negative clauses
* *pureNegativeClauses* - represented as follows: x y z; (separated by semicolon)

## Example
### Input
(w * y * z -> x) * (x * z -> w) * (x -> y) * (-> x) * (x * y -> w) * (~z)
```
4 // number of variables
x y z w // variables
5 // number of implication clauses
w y z > x // implication clauses
x z > w
x > y
> x
x y > w
1 // number of pure negative clauses
z; // pure negative clause

```

### Output
```
w: 1
x: 1
y: 1
z: 0
```
