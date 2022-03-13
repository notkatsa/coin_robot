# Manhattan Distance Problem
In this itteration of the problem, a robot picks up the most coins possible from a grid while only moving right and down (aka Manhattan Distance).
I have found 3 ways to solve the problem:
> Recursively - Using Dynamic Programing - Recursion with memory

`Input Example`:
```
11 12
.C...CC.C...
..C.....C...
CCC.C.CC.C..
...C....C...
....CC..C...
.CC..CCC.C..
C...C.C.....
.C....C..C..
.C...CC.C...
......C.....
.C..C....C..
```

`Output Example`:
```.(1,1)/0 --> C(1,2)/1 --> .(1,3)/1 --> .(1,4)/1 --> .(1,5)/1 --> C(1,6)/2 --> C(1,7)/3 --> .(1,8)/3 --> C(1,9)/4 --> .(1,10)/4 --> .(1,11)/4 --> .(1,12)/4 --> .(2,12)/5 --> .(3,12)/7 --> .(4,12)/7 --> .(5,12)/8 --> .(6,12)/10 --> .(7,12)/10 --> .(8,12)/11 --> .(9,12)/12 --> .(10,12)/12 --> .(11,12)/13 --> Picked up 13 coins
```
