    #include "queue.h"
    #include <stdio.h>

    void initQueue(Queue * Q){
        Front(Q) = -1;
        Rear(Q) = -1;
    }

    boolean isEmpty(Queue * Q){
        return (Front(Q) == -1 || Rear(Q) == -1);
    }

    boolean isfull(Queue * Q){
        return (Front(Q) == (Rear(Q) + 1) % jml_maks);
        
    }

    void endQueue(Queue * Q, int X){
        if (!isfull(Q))
        {
            if (Front(Q) == -1)
            {
                Front(Q) = 0;
                Rear(Q) = 0;
            }else{
                Rear(Q) = (Rear(Q) + 1) % jml_maks; 
            }
            Items(Q)[Rear(Q)] = X;
            
        }else printf("Sudah penuh\n");
        
    }

    int deQueue(Queue * Q){
        if (!isEmpty(Q))
        {
           int X = Items(Q)[Front(Q)];
            
            if (Front(Q) == Rear(Q))
            {
                Front(Q) = -1;
                Rear(Q) = -1;
            }else{
                Front(Q) = (Front(Q) + 1) % jml_maks;
            }
            return X;
        }else printf("Queue Kosong\n");
        
    }

    void display(Queue * Q){
        if(!isEmpty(Q)){
            
            int i = Front(Q);
            while (1)
            {
                printf(" ->  %d", Items(Q)[i]);
                if (i == Rear(Q)) break;
                i = (i + 1) % jml_maks;
            }
            
            printf("\n");
        }else printf("Queue Kosong\n");
    }

    int peek(Queue * Q){
        if (!isEmpty(Q))
        {
            return Items(Q)[Rear(Q)];
        }else{
            printf("List masih kosong\n");
            return -1;
        }
        
        
    }