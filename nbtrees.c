#include "nbtrees.h"
#include <stdio.h>
#include <malloc.h>

void Create_Tree(Isi_Tree X, int Jml_Node){
    for (int i = 1; i < Jml_Node; i++)
    {
        X[i].info = nil;
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }
    
}

boolean IsEmpty(Isi_Tree P){
    if(P[1].info == nil)return true;
    else return false;
}

void PreOrder(Isi_Tree P){
    int Pcur = 1;
    boolean resmi = true;
    do
    {
        if (P[Pcur].ps_fs != nil && resmi)
        {
            Pcur = P[Pcur].ps_fs;
            printf("%c", P[Pcur].info);
        }else if(P[Pcur].ps_nb != nil){
            Pcur = P[Pcur].ps_nb;
            printf("%c", P[Pcur].info);
            resmi = true;            
        }else{
            Pcur = P[Pcur].ps_pr;
            resmi = false;
        }
        
    } while (P[Pcur].ps_pr != nil);
    
}

void InOrder(Isi_Tree P){
    int Pcur = 1;
    boolean resmi = true;
    while (Pcur != nil)
    {
        if (P[Pcur].ps_fs != nil && resmi)
        {
            Pcur = P[Pcur].ps_fs;
        }else{
            if (resmi)
            {
                printf("%c", P[Pcur].info);
            }
            if (Pcur == P[P[Pcur].ps_pr].info)
            {
                printf("%c", P[P[Pcur].ps_pr].info);
            }
            if (P[Pcur].ps_nb != nil)
            {
                Pcur = P[Pcur].ps_nb;
                resmi = true;
            }else{
                Pcur = P[Pcur].ps_pr;
                resmi = false;
            }
            
            
            
        }
        
    }
    
}

void PostOrder(Isi_Tree P){
    int Pcur = 1;
    boolean resmi = false;
    while (Pcur != nil)
    {
        if (P[Pcur].ps_fs != nil && !resmi)
        {
            Pcur = P[Pcur].ps_fs;
        }else{
            printf("%c", P[Pcur].info);
            if (P[Pcur].ps_nb != nil)
            {
                Pcur = P[Pcur].ps_nb;
                resmi = false;
            }else{
                Pcur = P[Pcur].ps_nb;
                resmi = true;
            }
            
        }
        
    }
    
}

void Level_order(Isi_Tree X, int Maks_node){
    Queue Q[Maks_node];
    initQueue(Q);
    int Pcur;
    printf("%c", X[1].info);
    Pcur = X[1].ps_fs;
    while (Pcur != nil)
    {
        printf("%c", X[Pcur].info);
        if (X[Pcur].ps_fs != nil)
        {
            if (!isfull(Q))
            {
                endQueue(Q, Pcur);
            }
        }
        if (X[Pcur].ps_nb != nil)
        {
            Pcur = X[Pcur].ps_nb;
        }else{
            if (isEmpty(Q))
            {
                Pcur = deQueue(Q);
            }else Pcur = 0;   
        }
    }
}

void PrintTree(Isi_Tree P) {
    int level = 0;
    int Pcur = 1;  // Mulai dari root

    while (Pcur != nil) {
        // Cetak indentasi berdasarkan level
        for (int i = 0; i < level; i++) {
            printf("   ");
        }
        printf("%c\n", P[Pcur].info);

        // Jika ada anak pertama
        if (P[Pcur].ps_fs != nil) {
            for (int i = 0; i < level; i++) {
                printf("   ");
            }
            printf("/\n");

            Pcur = P[Pcur].ps_fs;
            level++;
        }
        // Jika ada saudara (next sibling)
        else if (P[Pcur].ps_nb != nil) {
            Pcur = P[Pcur].ps_nb;
        }
        // Jika tidak ada anak maupun saudara
        else {
            while (Pcur != nil && P[Pcur].ps_nb == nil) {
                Pcur = P[Pcur].ps_pr;
                level--;
            }
            if (Pcur != nil) {
                Pcur = P[Pcur].ps_nb;
            }
        }
    }
}


boolean Search (Isi_Tree P, infotype X){
    int Pcur = 1;
    boolean found = false;
    do
    {
        if (P[Pcur].ps_fs != nil && !found)
        {
            if (P[Pcur].info == X)
            {
                found = true;
                return found;
            }
            Pcur = P[Pcur].ps_fs;
        }else if(P[Pcur].ps_nb != nil){
            Pcur = P[Pcur].ps_nb;    
        }else{
            Pcur = P[Pcur].ps_pr;
        }
        return found;
    } while (P[Pcur].ps_pr != nil);
}
int nbElmt (Isi_Tree P){
    int Pcur = 1;
    int count = 0;
    while (P[Pcur].info != nil && Pcur < jml_maks+1)
    {
        count++;
        Pcur++;
    }
    return count;
}

int nbDaun (Isi_Tree P){
    int Pcur = 1, count = 0;
    boolean resmi = false;
    while (Pcur != nil) {
        if (P[Pcur].ps_fs != nil && !resmi) {
            Pcur = P[Pcur].ps_fs;
        } else {
            if (P[Pcur].ps_fs == nil) count++;
            if (P[Pcur].ps_nb != nil) {
                Pcur = P[Pcur].ps_nb;
                resmi = false;
            } else {
                Pcur = P[Pcur].ps_nb;
                resmi = true;
            }
        }
    }
    return count;
}

int Level(Isi_Tree P, infotype X) {
    int Pcur = 1;
    int level = 0;
    boolean found = false;
    while (Pcur != nil && !found) {
        if (P[Pcur].info == X) {
            found = true;
            return level;
        }
        if (P[Pcur].ps_fs != nil) {
            Pcur = P[Pcur].ps_fs;
            level++;
        } else if (P[Pcur].ps_nb != nil) {
            Pcur = P[Pcur].ps_nb;
        } else {
            Pcur = P[Pcur].ps_pr;
            level--;
        }
    }
    return -1; 
}


int Depth(Isi_Tree P){
    int max_depth = 0;
    int current_depth = 0;
    int Pcur = 1;
    
    while (Pcur != nil) {
        if (P[Pcur].ps_fs != nil) {
            Pcur = P[Pcur].ps_fs;
            current_depth++;
        } else if (P[Pcur].ps_nb != nil) {
            Pcur = P[Pcur].ps_nb;
        } else {
            max_depth = (current_depth > max_depth) ? current_depth : max_depth;
            current_depth--;
            Pcur = P[Pcur].ps_pr;
        }
    }
    return max_depth;
}

int Max(infotype Data1, infotype Data2){
    return (Data1 > Data2) ? Data1 : Data2;
}