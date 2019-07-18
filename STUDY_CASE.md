# Binary Search Tree Visualization Study Case

<!-- TOC -->

[**I. Fixed Node/Space Length Algorithm**](#i-fixed-nodespace-length-algorithm)

- [fixed-3-char-length Tree](#fixed-3-char-length-tree)

[**II. Matching Adaptive Node/Space Length Algorithm**](#ii-matching-adaptive-nodespace-length-algorithm)

- [1-char-length Tree (~~bugged~~)](#1-char-length-tree-bugged)
- [2-char-length Tree](#2-char-length-tree)
- [3-char-length Tree](#3-char-length-tree)
- [4-char-length Tree](#4-char-length-tree)
- [5-char-length Tree](#5-char-length-tree)

[**III. Adaptive Node Length with Fixed Space Length Algorithm**](#iii-adaptive-node-length-with-fixed-space-length-algorithm)

- [1-char-length-node + fixed-3-char-length-space Tree](#1-char-length-node--fixed-3-char-length-space-tree)
- [2-char-length-node + fixed-4-char-length-space Tree](#2-char-length-node--fixed-4-char-length-space-tree)
- [3-char-length-node + fixed-3-char-length-space Tree](#3-char-length-node--fixed-3-char-length-space-tree)
- [4-char-length-node + fixed-4-char-length-space Tree](#4-char-length-node--fixed-4-char-length-space-tree)
- [5-char-length-node + fixed-3-char-length-space Tree](#5-char-length-node--fixed-3-char-length-space-tree)
- [6-char-length-node + fixed-4-char-length-space Tree](#6-char-length-node--fixed-4-char-length-space-tree)
- [7-char-length-node + fixed-3-char-length-space Tree](#7-char-length-node--fixed-3-char-length-space-tree)

[**IV. Hybrid Algorithm**](#iv-hybrid-algorithm)

- [Hybrid Trees](#hybrid-trees)

<!-- /TOC -->

---

## I. Fixed Node/Space Length Algorithm

- Set both nodes' and spaces' lengths to a Fixed value (3 chars for example).

| Advantages | Disadvantages                                                        |
| :--        | :--                                                                  |
|            | Nodes with large values won't be displayed properly                  |
|            | Nodes' and spaces' lengths should be either even or odd but not both |

### fixed-3-char-length Tree

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

## II. Matching Adaptive Node/Space Length Algorithm

- Set both nodes' and spaces' lengths to the maximum node value's length.

| Advantages              | Disadvantages                                                             |
| :--                     | :--                                                                       |
| Visually symmetric      | 1-char-length node/space trees are bugged                                 |
| Node length is adaptive | Trees' width/height is too big                                            |
|                         | Consecutive even-length trees and odd-length trees have different heights |
|                         | Nodes' and spaces' lengths should be either even or odd but not both      |



### 1-char-length Tree (~~bugged~~)

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

### 2-char-length Tree

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

### 3-char-length Tree

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

### 4-char-length Tree

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

### 5-char-length Tree

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

## III. Adaptive Node Length with Fixed Space Length Algorithm

- Set spaces' length to **3 chars** in case node length is odd.
- Set spaces' length to **4 chars** in case node length is even.
- Set nodes' length to the maximum node value's length.

| Advantages                                                           | Disadvantages                                                       |
| :--                                                                  | :--                                                                 |
| Node length is adaptive                                              | Spacing between long-length-leaves is visually low                  |
| Trees' width/height is smaller than Matching Node/Space length Trees | Nodes' and spaces' lengths should be either even or odd but not both |
| 1-char-node-length trees aren't bugged                               |                                                                     |
| Consecutive even-length trees and odd-length trees have same height  |                                                                     |

### 1-char-length-node + fixed-3-char-length-space Tree

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

### 2-char-length-node + fixed-4-char-length-space Tree

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

### 3-char-length-node + fixed-3-char-length-space Tree

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

### 4-char-length-node + fixed-4-char-length-space Tree

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

### 5-char-length-node + fixed-3-char-length-space Tree

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

### 6-char-length-node + fixed-4-char-length-space Tree

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

### 7-char-length-node + fixed-3-char-length-space Tree

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

- Set spaces' length to **3 chars** or **4 chars** depending on node length value is even or odd.
- Set nodes' length to the maximum node value's length and type (odd/even).

| Advantages                                                                  | Disadvantages |
| :--                                                                         | :--           |
| Nodes' and spaces' lengths can be both even and odd in the same tree        |               |
| Branching & spacing depends on whether the node length value is even or odd |               |

### Hybrid Trees

```shell

+----------------------------------------------+-----------------------------------------------+
|   2-char-length-node + 4-char-length-space   |   3-char-length-node + 3-char-length-space    |
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
