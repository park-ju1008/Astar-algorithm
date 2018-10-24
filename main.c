#include "astar.h"
#include <stdio.h>


int main(){
	int i, j;
	TileBlk start_tile,goal_tile;
	Ty_nodeptr node,openNode,closedNode;
	LinkedList open,closed,path;
	Ty_linknodeptr suss,temp=NULL;
	//리스트의 생성
	CreateList(&open);
	CreateList(&closed);
	printf("start node를 입력하세요\n");
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			scanf("%d", &start_tile[i][j]);
		}
	}
	printf("goal node를 입력하세요\n");
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			scanf("%d", &goal_tile[i][j]);
		}
	}
	node=InsertStartnode(start_tile, goal_tile);
	InsertList(&open, node);

	while (open.head != NULL){
		node = MinOnOpen(&open);
		DeleteList(&open, node);
		InsertList(&closed, node);
		if (node->hhat == 0){
			CreateList(&path);
			while (node != NULL){
				AppendFromFront(&path, node);
				node = node->pred;
			}
			break;//path 만들기
		}
		//pred에 대한 석세스 구하는거
		suss=Getsuccessor(node,goal_tile);
		while (suss != NULL){ //모든 노드m에 대해서
			openNode = IsOnList(&open, suss->nodeptr);  //오픈에 있는지
			closedNode = IsOnList(&closed, suss->nodeptr); //클로즈에 있는지
			if (openNode==NULL&&closedNode==NULL){ //어디에도 없다면
				suss->nodeptr->pred = node;
				InsertList(&open, suss->nodeptr);
			}
			else if (openNode != NULL){
				if (suss->nodeptr->fhat < openNode->fhat){
					// 오픈에잇는 노드 찾아서 바꿔줌
					openNode->fhat = suss->nodeptr->fhat;
					openNode->ghat = suss->nodeptr->ghat;
					openNode->pred = node;
					temp = suss;
				}
			}
			else{
				if (suss->nodeptr->fhat < closedNode->fhat){
					closedNode->fhat = suss->nodeptr->fhat;
					closedNode->ghat = suss->nodeptr->ghat;
					closedNode->pred = node;
				}
				DeleteList(&closed, closedNode);
				InsertList(&open, closedNode);
			}
			suss = suss->next;
			if (temp!=NULL){  //새로만들고 이미 오픈에 들어있다면 할당된 공간 해제
				free(temp->nodeptr);
				free(temp);
				temp = NULL;
			}
		}
		
	}
	
	PrintPath(&path);
	while (open.head != NULL){
		node = DeleteFromFront(&open);
		free(node);
	}
	while (closed.head != NULL){
		node = DeleteFromFront(&closed);
		free(node);
	}
	while (path.head != NULL){
		node = DeleteFromFront(&path);
		free(node);
	}
	return 0;
}