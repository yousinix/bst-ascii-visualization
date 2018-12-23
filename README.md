# Binary Search Tree Visualization

This program helps to Visualize [Binary Search Trees](https://en.wikipedia.org/wiki/Binary_search_tree) using C++.

## Preview

![capture](https://user-images.githubusercontent.com/41103290/49118099-cb5d0300-f2ab-11e8-9302-b90c3e1a6b04.JPG)

## Binary Search Tree Main Functions

- Insert
- Remove
- Traverse (In-Order, Pre-order, Post-order)

## Binary Search Tree Extra Functions

- Count Number of Nodes
- Visualize Tree
- Create a Balanced Tree from an Array

---

# Binary Search Tree Visualization Possible Algorithms

## I. Fixed Node/Space Width Algorithm [_Current_]

- Set both nodes' and spaces' widths to a Fixed value (3 chars for example).

| Advantages | Disadvantages                                                       |
| :--        | :--                                                                 |
|            | Nodes with large values won't be displayed properly                 |
|            | Nodes' and spaces' widths should be either even or odd but not both |

### fixed-3-char-width Tree

```shell

                     0X0                     
                     / \                     
                    /   \                    
                   /     \                   
                  /       \                  
                 /         \                 
                /           \                
               /             \               
              /               \              
             /                 \             
            /                   \            
           /                     \           
         0X0                     0X0         
         / \                     / \         
        /   \                   /   \        
       /     \                 /     \       
      /       \               /       \      
     /         \             /         \     
   0X0         0X0         0X0         0X0   
   / \         / \         / \         / \   
  /   \       /   \       /   \       /   \  
0X0   0X0   0X0   0X0   0X0   0X0   0X0   0X0

```

## II. Matching Adjustable Node/Space Width Algorithm

- Set both nodes' and spaces' widths to the maximum node value's length.

| Advantages               | Disadvantages                                                           |
| :--                      | :--                                                                     |
| Visually symmetric       | 1-char-width node/space trees are bugged                                |
| Node width is adjustable | Trees' width/height is too big                                          |
|                          | Consecutive even-width trees and odd-width trees have different heights |
|                          | Nodes' and spaces' widths should be either even or odd but not both     |



### 1-char-width Tree (~~bugged~~)

```shell

       X       
      / \      
     /   \     
    /     \    
   X       X   
  / \     / \  
 X   X   X   X 
X X X X X X X X

```

### 2-char-width Tree

```shell

              XX              
              /\              
             /  \             
            /    \            
           /      \           
          /        \          
         /          \         
        /            \        
      XX              XX      
      /\              /\      
     /  \            /  \     
    /    \          /    \    
  XX      XX      XX      XX  
  /\      /\      /\      /\  
XX  XX  XX  XX  XX  XX  XX  XX

```

### 3-char-width Tree

```shell

                     0X0                     
                     / \                     
                    /   \                    
                   /     \                   
                  /       \                  
                 /         \                 
                /           \                
               /             \               
              /               \              
             /                 \             
            /                   \            
           /                     \           
         0X0                     0X0         
         / \                     / \         
        /   \                   /   \        
       /     \                 /     \       
      /       \               /       \      
     /         \             /         \     
   0X0         0X0         0X0         0X0   
   / \         / \         / \         / \   
  /   \       /   \       /   \       /   \  
0X0   0X0   0X0   0X0   0X0   0X0   0X0   0X0

```

### 4-char-width Tree

```shell

                            0XX0                            
                             /\                             
                            /  \                            
                           /    \                           
                          /      \                          
                         /        \                         
                        /          \                        
                       /            \                       
                      /              \                      
                     /                \                     
                    /                  \                    
                   /                    \                   
                  /                      \                  
                 /                        \                 
                /                          \                
               /                            \               
            0XX0                            0XX0            
             /\                              /\             
            /  \                            /  \            
           /    \                          /    \           
          /      \                        /      \          
         /        \                      /        \         
        /          \                    /          \        
       /            \                  /            \       
    0XX0            0XX0            0XX0            0XX0    
     /\              /\              /\              /\     
    /  \            /  \            /  \            /  \    
   /    \          /    \          /    \          /    \   
0XX0    0XX0    0XX0    0XX0    0XX0    0XX0    0XX0    0XX0

```

### 5-char-width Tree

```shell

                                   00X00                                   
                                    / \                                    
                                   /   \                                   
                                  /     \                                  
                                 /       \                                 
                                /         \                                
                               /           \                               
                              /             \                              
                             /               \                             
                            /                 \                            
                           /                   \                           
                          /                     \                          
                         /                       \                         
                        /                         \                        
                       /                           \                       
                      /                             \                      
                     /                               \                     
                    /                                 \                    
                   /                                   \                   
                  /                                     \                  
               00X00                                   00X00               
                / \                                     / \                
               /   \                                   /   \               
              /     \                                 /     \              
             /       \                               /       \             
            /         \                             /         \            
           /           \                           /           \           
          /             \                         /             \          
         /               \                       /               \         
        /                 \                     /                 \        
     00X00               00X00               00X00               00X00     
      / \                 / \                 / \                 / \      
     /   \               /   \               /   \               /   \     
    /     \             /     \             /     \             /     \    
   /       \           /       \           /       \           /       \   
00X00     00X00     00X00     00X00     00X00     00X00     00X00     00X00

```

## III. Adjustable Node Width with Fixed Space Width Algorithm

- Set spaces' width to **3 chars** in case of odd-nodes-width trees.
- Set spaces' width to **4 chars** in case of even-nodes-width trees.
- Set nodes' width to the maximum node value's length.

| Advantages                                                          | Disadvantages                                                       |
| :--                                                                 | :--                                                                 |
| Node width is adjustable                                            | Spacing between long-length-leaves is visually low                  |
| Trees' width/height is smaller than Matching Node/Space width Trees | Nodes' and spaces' widths should be either even or odd but not both |
| 1-char-node-width trees aren't bugged                               |                                                                     |
| Consecutive even-width trees and odd-width trees have same height   |                                                                     |

### 1-char-width-node + fixed-3-char-width-space Tree

```shell

              X              
             / \             
            /   \            
           /     \           
          /       \          
         /         \         
        /           \        
       /             \       
      X               X      
     / \             / \     
    /   \           /   \    
   /     \         /     \   
  X       X       X       X  
 / \     / \     / \     / \ 
X   X   X   X   X   X   X   X

```

### 2-char-width-node + fixed-4-char-width-space Tree

```shell

                     XX                     
                     /\                     
                    /  \                    
                   /    \                   
                  /      \                  
                 /        \                 
                /          \                
               /            \               
              /              \              
             /                \             
            /                  \            
           /                    \           
         XX                      XX         
         /\                      /\         
        /  \                    /  \        
       /    \                  /    \       
      /      \                /      \      
     /        \              /        \     
   XX          XX          XX          XX   
   /\          /\          /\          /\   
  /  \        /  \        /  \        /  \  
XX    XX    XX    XX    XX    XX    XX    XX

```

### 3-char-width-node + fixed-3-char-width-space Tree

```shell

                     0X0                     
                     / \                     
                    /   \                    
                   /     \                   
                  /       \                  
                 /         \                 
                /           \                
               /             \               
              /               \              
             /                 \             
            /                   \            
           /                     \           
         0X0                     0X0         
         / \                     / \         
        /   \                   /   \        
       /     \                 /     \       
      /       \               /       \      
     /         \             /         \     
   0X0         0X0         0X0         0X0   
   / \         / \         / \         / \   
  /   \       /   \       /   \       /   \  
0X0   0X0   0X0   0X0   0X0   0X0   0X0   0X0

```

### 4-char-width-node + fixed-4-char-width-space Tree

```shell

                            0XX0                            
                             /\                             
                            /  \                            
                           /    \                           
                          /      \                          
                         /        \                         
                        /          \                        
                       /            \                       
                      /              \                      
                     /                \                     
                    /                  \                    
                   /                    \                   
                  /                      \                  
                 /                        \                 
                /                          \                
               /                            \               
            0XX0                            0XX0            
             /\                              /\             
            /  \                            /  \            
           /    \                          /    \           
          /      \                        /      \          
         /        \                      /        \         
        /          \                    /          \        
       /            \                  /            \       
    0XX0            0XX0            0XX0            0XX0    
     /\              /\              /\              /\     
    /  \            /  \            /  \            /  \    
   /    \          /    \          /    \          /    \   
0XX0    0XX0    0XX0    0XX0    0XX0    0XX0    0XX0    0XX0

```

### 5-char-width-node + fixed-3-char-width-space Tree

```shell

                            00X00                            
                             / \                             
                            /   \                            
                           /     \                           
                          /       \                          
                         /         \                         
                        /           \                        
                       /             \                       
                      /               \                      
                     /                 \                     
                    /                   \                    
                   /                     \                   
                  /                       \                  
                 /                         \                 
                /                           \                
               /                             \               
            00X00                           00X00            
             / \                             / \             
            /   \                           /   \            
           /     \                         /     \           
          /       \                       /       \          
         /         \                     /         \         
        /           \                   /           \        
       /             \                 /             \       
    00X00           00X00           00X00           00X00    
     / \             / \             / \             / \     
    /   \           /   \           /   \           /   \    
   /     \         /     \         /     \         /     \   
00X00   00X00   00X00   00X00   00X00   00X00   00X00   00X00

```

### 6-char-width-node + fixed-4-char-width-space Tree

```shell

                                   00XX00                                   
                                     /\                                     
                                    /  \                                    
                                   /    \                                   
                                  /      \                                  
                                 /        \                                 
                                /          \                                
                               /            \                               
                              /              \                              
                             /                \                             
                            /                  \                            
                           /                    \                           
                          /                      \                          
                         /                        \                         
                        /                          \                        
                       /                            \                       
                      /                              \                      
                     /                                \                     
                    /                                  \                    
                   /                                    \                   
               00XX00                                  00XX00               
                 /\                                      /\                 
                /  \                                    /  \                
               /    \                                  /    \               
              /      \                                /      \              
             /        \                              /        \             
            /          \                            /          \            
           /            \                          /            \           
          /              \                        /              \          
         /                \                      /                \         
     00XX00              00XX00              00XX00              00XX00     
       /\                  /\                  /\                  /\       
      /  \                /  \                /  \                /  \      
     /    \              /    \              /    \              /    \     
    /      \            /      \            /      \            /      \    
00XX00    00XX00    00XX00    00XX00    00XX00    00XX00    00XX00    00XX00

```

### 7-char-width-node + fixed-3-char-width-space Tree

```shell

                                   000X000                                   
                                     / \                                     
                                    /   \                                    
                                   /     \                                   
                                  /       \                                  
                                 /         \                                 
                                /           \                                
                               /             \                               
                              /               \                              
                             /                 \                             
                            /                   \                            
                           /                     \                           
                          /                       \                          
                         /                         \                         
                        /                           \                        
                       /                             \                       
                      /                               \                      
                     /                                 \                     
                    /                                   \                    
                   /                                     \                   
               000X000                                 000X000               
                 / \                                     / \                 
                /   \                                   /   \                
               /     \                                 /     \               
              /       \                               /       \              
             /         \                             /         \             
            /           \                           /           \            
           /             \                         /             \           
          /               \                       /               \          
         /                 \                     /                 \         
     000X000             000X000             000X000             000X000     
       / \                 / \                 / \                 / \       
      /   \               /   \               /   \               /   \      
     /     \             /     \             /     \             /     \     
    /       \           /       \           /       \           /       \    
000X000   000X000   000X000   000X000   000X000   000X000   000X000   000X000

```

## IV. Hybrid Algorithm

- Set spaces' width to **3 chars** or **4 chars** depending on node-width value is even or odd.
- Set nodes' width to the maximum node value's length and type (odd/even).

| Advantages                                                                 | Disadvantages |
| :--                                                                        | :--           |
| Nodes' and spaces' widths can be both even and odd in the same tree        |               |
| Branching & spacing depends on whether the node-width value is even or odd |               |


### Hybrid Trees

```shell

+----------------------------------------------+-----------------------------------------------+
|    2-char-width-node + 4-char-width-space    |    3-char-width-node + 3-char-width-space     |
+----------------------------------------------+-----------------------------------------------+
|                      XX                      |                      0X0                      |
|                      /\                      |                      / \                      |
|                     /  \                     |                     /   \                     |
|                    /    \                    |                    /     \                    |
|                   /      \                   |                   /       \                   |
|                  /        \                  |                  /         \                  |
|                 /          \                 |                 /           \                 |
|                /            \                |                /             \                |
|               /              \               |               /               \               |
|              /                \              |              /                 \              |
|             /                  \             |             /                   \             |
|            /                    \            |            /                     \            |
|          XX                      XX          |          0X0                     0X0          |
|          /\                      /\          |          / \                     / \          |
|         /  \                    /  \         |         /   \                   /   \         |
|        /    \                  /    \        |        /     \                 /     \        |
|       /      \                /      \       |       /       \               /       \       |
|      /        \              /        \      |      /         \             /         \      |
|    XX          XX          XX          XX    |    0X0         0X0         0X0         0X0    |
|    /\          /\          /\          /\    |    / \         / \         / \         / \    |
|   /  \        /  \        /  \        /  \   |   /   \       /   \       /   \       /   \   |
| XX    XX    XX    XX    XX    XX    XX    XX | 0X0   0X0   0X0   0X0   0X0   0X0   0X0   0X0 |
+----------------------------------------------+-----------------------------------------------+

+----------------------------------------------+-----------------------------------------------+
|               Hybrid-even-root               |                Hybrid-odd-root                |
+----------------------------------------------+-----------------------------------------------+
|                      XX                      |                      0X0                      |
|                      /\                      |                      / \                      |
|                     /  \                     |                     /   \                     |
|                    /    \                    |                    /     \                    |
|                   /      \                   |                   /       \                   |
|                  /        \                  |                  /         \                  |
|                 /          \                 |                 /           \                 |
|                /            \                |                /             \                |
|               /              \               |               /               \               |
|              /                \              |              /                 \              |
|             /                  \             |             /                   \             |
|            /                    \            |            /                     \            |
|          XX                     0X0          |          XX                      0X0          |
|          /\                     / \          |          /\                      / \          |
|         /  \                   /   \         |         /  \                    /   \         |
|        /    \                 /     \        |        /    \                  /     \        |
|       /      \               /       \       |       /      \                /       \       |
|      /        \             /         \      |      /        \              /         \      |
|    XX         0X0         XX          0X0    |    XX         0X0          XX          0X0    |
|    /\         / \         /\          / \    |    /\         / \          /\          / \    |
|   /  \       /   \       /  \        /   \   |   /  \       /   \        /  \        /   \   |
| XX   0X0   XX    0X0   XX   0X0    XX    0X0 | XX   0X0   XX    0X0    XX   0X0    XX    0X0 |
+----------------------------------------------+-----------------------------------------------+

```

### Helper Grids

```shell

Hybrid-even-root:
+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|--|0|0|0|0|0|0|0|0|0|1|1|1|1|1|1|1|1|1|2|2|2|2|2|2|2|2|2|3|3|3|3|3|3|3|3|3|4|4|4|4|4|4|4|4|
|--|1|2|3|4|5|6|7|8|9|1|2|3|4|5|6|7|8|9|1|2|3|4|5|6|7|8|9|1|2|3|4|5|6|7|8|9|1|2|3|4|5|6|7|8|
+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|01| | | | | | | | | | | | | | | | | | | | | |X|X| | | | | | | | | | | | | | | | | | | | | |
|02| | | | | | | | | | | | | | | | | | | | | |/|\| | | | | | | | | | | | | | | | | | | | | |
|03| | | | | | | | | | | | | | | | | | | | |/| | |\| | | | | | | | | | | | | | | | | | | | |
|04| | | | | | | | | | | | | | | | | | | |/| | | | |\| | | | | | | | | | | | | | | | | | | |
|05| | | | | | | | | | | | | | | | | | |/| | | | | | |\| | | | | | | | | | | | | | | | | | |
|06| | | | | | | | | | | | | | | | | |/| | | | | | | | |\| | | | | | | | | | | | | | | | | |
|07| | | | | | | | | | | | | | | | |/| | | | | | | | | | |\| | | | | | | | | | | | | | | | |
|08| | | | | | | | | | | | | | | |/| | | | | | | | | | | | |\| | | | | | | | | | | | | | | |
|09| | | | | | | | | | | | | | |/| | | | | | | | | | | | | | |\| | | | | | | | | | | | | | |
|10| | | | | | | | | | | | | |/| | | | | | | | | | | | | | | | |\| | | | | | | | | | | | | |
|11| | | | | | | | | | | | |/| | | | | | | | | | | | | | | | | | |\| | | | | | | | | | | | |
|12| | | | | | | | | | | |/| | | | | | | | | | | | | | | | | | | | |\| | | | | | | | | | | |
|13| | | | | | | | | |X|X| | | | | | | | | | | | | | | | | | | | | |0|X|0| | | | | | | | | |
|14| | | | | | | | | |/|\| | | | | | | | | | | | | | | | | | | | | |/| |\| | | | | | | | | |
|15| | | | | | | | |/| | |\| | | | | | | | | | | | | | | | | | | |/| | | |\| | | | | | | | |
|16| | | | | | | |/| | | | |\| | | | | | | | | | | | | | | | | |/| | | | | |\| | | | | | | |
|17| | | | | | |/| | | | | | |\| | | | | | | | | | | | | | | |/| | | | | | | |\| | | | | | |
|18| | | | | |/| | | | | | | | |\| | | | | | | | | | | | | |/| | | | | | | | | |\| | | | | |
|19| | | |X|X| | | | | | | | | |0|X|0| | | | | | | | | |X|X| | | | | | | | | | |0|X|0| | | |
|20| | | |/|\| | | | | | | | | |/| |\| | | | | | | | | |/|\| | | | | | | | | | |/| |\| | | |
|21| | |/| | |\| | | | | | | |/| | | |\| | | | | | | |/| | |\| | | | | | | | |/| | | |\| | |
|22|X|X| | | |0|X|0| | | |X|X| | | | |0|X|0| | | |X|X| | | |0|X|0| | | | |X|X| | | | |0|X|0|
+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

Hybrid-odd-root
+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|--|0|0|0|0|0|0|0|0|0|1|1|1|1|1|1|1|1|1|2|2|2|2|2|2|2|2|2|3|3|3|3|3|3|3|3|3|4|4|4|4|4|4|4|4|4|
|--|1|2|3|4|5|6|7|8|9|1|2|3|4|5|6|7|8|9|1|2|3|4|5|6|7|8|9|1|2|3|4|5|6|7|8|9|1|2|3|4|5|6|7|8|9|
+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|01| | | | | | | | | | | | | | | | | | | | | |0|X|0| | | | | | | | | | | | | | | | | | | | | |
|02| | | | | | | | | | | | | | | | | | | | | |/| |\| | | | | | | | | | | | | | | | | | | | | |
|03| | | | | | | | | | | | | | | | | | | | |/| | | |\| | | | | | | | | | | | | | | | | | | | |
|04| | | | | | | | | | | | | | | | | | | |/| | | | | |\| | | | | | | | | | | | | | | | | | | |
|05| | | | | | | | | | | | | | | | | | |/| | | | | | | |\| | | | | | | | | | | | | | | | | | |
|06| | | | | | | | | | | | | | | | | |/| | | | | | | | | |\| | | | | | | | | | | | | | | | | |
|07| | | | | | | | | | | | | | | | |/| | | | | | | | | | | |\| | | | | | | | | | | | | | | | |
|08| | | | | | | | | | | | | | | |/| | | | | | | | | | | | | |\| | | | | | | | | | | | | | | |
|09| | | | | | | | | | | | | | |/| | | | | | | | | | | | | | | |\| | | | | | | | | | | | | | |
|10| | | | | | | | | | | | | |/| | | | | | | | | | | | | | | | | |\| | | | | | | | | | | | | |
|11| | | | | | | | | | | | |/| | | | | | | | | | | | | | | | | | | |\| | | | | | | | | | | | |
|12| | | | | | | | | | | |/| | | | | | | | | | | | | | | | | | | | | |\| | | | | | | | | | | |
|13| | | | | | | | | |X|X| | | | | | | | | | | | | | | | | | | | | | |0|X|0| | | | | | | | | |
|14| | | | | | | | | |/|\| | | | | | | | | | | | | | | | | | | | | | |/| |\| | | | | | | | | |
|15| | | | | | | | |/| | |\| | | | | | | | | | | | | | | | | | | | |/| | | |\| | | | | | | | |
|16| | | | | | | |/| | | | |\| | | | | | | | | | | | | | | | | | |/| | | | | |\| | | | | | | |
|17| | | | | | |/| | | | | | |\| | | | | | | | | | | | | | | | |/| | | | | | | |\| | | | | | |
|18| | | | | |/| | | | | | | | |\| | | | | | | | | | | | | | |/| | | | | | | | | |\| | | | | |
|19| | | |X|X| | | | | | | | | |0|X|0| | | | | | | | | | |X|X| | | | | | | | | | |0|X|0| | | |
|20| | | |/|\| | | | | | | | | |/| |\| | | | | | | | | | |/|\| | | | | | | | | | |/| |\| | | |
|21| | |/| | |\| | | | | | | |/| | | |\| | | | | | | | |/| | |\| | | | | | | | |/| | | |\| | |
|22|X|X| | | |0|X|0| | | |X|X| | | | |0|X|0| | | | |X|X| | | |0|X|0| | | | |X|X| | | | |0|X|0|
+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

```