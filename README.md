# Manhattan Distance Problem
In this itteration of the problem, a robot picks up the most coins possible from a grid while only moving right and down (aka Manhattan Distance).
I have found 3 ways to solve the problem:
> Recursively - Using Dynamic Programing - Recursion with memory

`Input Example`:
```
8 8
..C..C..
.C.C...C
...C....
..C..C..
....C...
........
C.C.....
.....C..
```
`Output Example`:
Path is: .(1,1)/0 --> .(1,2)/0 --> C(1,3)/1 --> .(1,4)/1 --> .(1,5)/1 --> C(1,6)/2 --> .(1,7)/2 --> .(1,8)/2 --> C(2,8)/3 --> .(3,8)/3 --> .(4,8)/4 --> .(5,8)/4 --> .(6,8)/4 --> .(7,8)/4 --> .(8,8)/5 --> Picked up 5 coins
```
