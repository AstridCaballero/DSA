// Count lines in triangle
// create structure to save a copy of the triangle
// penultima linea is [lines - 1]
// i = 0 
// loop each line strating at lines -1
// loop each number in each line
// starting at index[lines - 1][i] sum the node with child [lines][i] and [lines][i+1]
// compare the sum of the node's children and pick the biggest
// replace value in [lines - 1][i] with highest sum value of the node and children


/* sources 
https://stackoverflow.com/questions/10588283/pyramid-tree-data-structure-c-c
https://www.geeksforgeeks.org/binary-tree-set-1-introduction/
https://dev-notes.eu/2018/07/double-pointers-and-linked-list-in-c/
https://ourcodeworld.com/articles/read/858/how-to-print-the-pascals-triangle-in-c
*/