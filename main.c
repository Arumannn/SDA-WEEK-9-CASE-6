#include <stdio.h>
#include "nbtrees.h"

int main() {
    Isi_Tree tree;  
    int Jml_Node = 7;   
    Create_Tree(tree, Jml_Node);
   
    tree[1].info = 'A';  
    tree[1].ps_fs = 2;   
    tree[1].ps_nb = nil;  // ✅ Root tidak punya sibling
    
    tree[2].info = 'B';
    tree[2].ps_fs = 4;
    tree[2].ps_nb = 3;
    tree[2].ps_pr = 1;
    
    tree[3].info = 'C';
    tree[3].ps_fs = 5;
    tree[3].ps_nb = nil;
    tree[3].ps_pr = 1;
    
    tree[4].info = 'D';
    tree[4].ps_fs = nil;
    tree[4].ps_nb = nil;
    tree[4].ps_pr = 2;
    
    tree[5].info = 'E';
    tree[5].ps_fs = 6;
    tree[5].ps_nb = nil;
    tree[5].ps_pr = 3;
    
    tree[6].info = 'F';
    tree[6].ps_fs = nil;
    tree[6].ps_nb = nil;
    tree[6].ps_pr = 5;

    PrintTree(tree);
    return 0;
}
