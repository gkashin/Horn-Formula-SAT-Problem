# Horn-Formula-SAT-Problem
The algorithm solves the problem of satisfiability of the Horn-formula. If it's satisfiable, the algorithm prints satisfying set of variables.
Otherwise, it warns about that the formula is not satisfiable

## Complexity
The complexity of this algorithm is linear in the length of the Horn-formula

## Input Data
* *verticesCount* - number of vertices in the graph
* *adjacency lists* of graph ending with '-1' after every list
* *initialVertex* - the vertex from which the search for minimum distances begins

## Example
### Input
```
8 // number of vertices

0 4 2 -1 // edge from vertex 0 to vertex 4 with weight of 2, etc.
1 0 1 2 1 -1
2 3 3 -1
3 4 1 -1
4 1 2 -1
5 0 4 4 1 -1
6 5 1 -1
7 6 8 0 10 -1

0 // initial vertex
```
![alt text](https://i.ibb.co/H7phsHk/Graph.png)
### Output
```
The weight of a shortest path from vertex 0 to vertex:
0 is 0
1 is 4
2 is 5
3 is 8
4 is 2
5 is INF
6 is INF
7 is INF

The shortest-path tree:
0
  4
    1
      2
        3
```
![alt text](https://i.ibb.co/3SyV5b5/Tree.png)
