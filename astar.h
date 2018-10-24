#ifndef _ASTAR_H_
#define _ASTAR_H_

#define N 4

typedef int TileBlk[N][N]; //4*4타일

typedef struct anode *Ty_nodeptr;
typedef struct anode{
	TileBlk tile;
	double fhat, ghat, hhat;
	int direction;  //움직인방향을 가지는 변수
	Ty_nodeptr pred;
}Ty_node;

typedef struct linknode* Ty_linknodeptr;
typedef struct linknode{
	Ty_nodeptr nodeptr;
	Ty_linknodeptr next;
}Ty_linknode;

typedef struct _linkedList{
	Ty_linknodeptr head;
	Ty_linknodeptr tail;
}LinkedList;


Ty_nodeptr InsertStartnode(TileBlk start_tile,TileBlk goal_tile);
Ty_nodeptr CreateNode(TileBlk tile, TileBlk goal_tile, double precost);
void CreateList(LinkedList* list);
Ty_nodeptr InsertList(LinkedList* list, Ty_nodeptr node);
Ty_nodeptr AppendFromFront(LinkedList* list, Ty_nodeptr node);
Ty_nodeptr DeleteFromFront(LinkedList* list);
Ty_nodeptr DeleteList(LinkedList* list, Ty_nodeptr node);
Ty_nodeptr MinOnOpen(LinkedList* list);
Ty_nodeptr IsOnList(LinkedList* list, Ty_nodeptr node);
Ty_linknodeptr Getsuccessor(Ty_nodeptr pred);
int CompareTile(TileBlk start_tile, TileBlk dest_tile);
void PrintPath(LinkedList* list);
#endif