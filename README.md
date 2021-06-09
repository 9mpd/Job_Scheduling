# Job_Scheduling
**Job scheduling : Greedy Algorithm versus Brute Force Algorithm**

![image](https://user-images.githubusercontent.com/58243776/121296370-29074700-c90e-11eb-905f-9741d8286d72.png) 

## Greedy Algorithm
*Choosing the locally optimal choice available at each stage. And finally, combining the all 
locally optimal choices selected at each stage to give the globally optimal solution. The 
algorithm is “greedy” in the sense that each local optimum is found solely by considering 
what is best at that step, with no consideration of future steps.*

### Analysis of Greedy Algorithm in Job Scheduling : T(n) = O(n<sup>2</sup>)
![image](https://user-images.githubusercontent.com/58243776/121297819-843a3900-c910-11eb-8967-d76931e304ef.png)

## Brute Force Algorithm
*Enumerating all possible candidates for the solution and checking whether each candidate 
satisfies the problem’s statement or not. This is basically a problem of permutation and 
combinatorics.*

### Analysis of Brute Force Algorithm in Job Scheduling : T(n) = O(n\*2<sup>n</sup>)
![image](https://user-images.githubusercontent.com/58243776/121297927-af248d00-c910-11eb-9053-c48ca628a665.png)
