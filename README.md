프로젝트:  A*  탐색시스템  개발

(1)  내용 설명:  
15-puzzle 탐색 문제는 8-puzzle 탐색 문제와 동일하나 다만 3 X 3 타일 블록 대신에 4 X 4 타일 블록을 사용하는 것이다
 

15-Puzzle 문제에 대하여 경로를 찾는 프로그램을 개발한다. 프로그램은 맨 처음에 start 노드와 goal 노드를 입력받는다. 그 다음 탐색을 수행하여 그 두 노드(상태) 사이를 연결하는 경로를 출력하고 종료한다. 

(주의:  주어진 start 상태에 대하여 goal 상태를  아무렇게나 임의의 state 를 넣으면 경로가 없을 수도 있고 아니면 너무 거리가 먼 goal 일수도 있다. 따라서 반드시 종이로 타일 블록을 만들어서 실지로 7 ~ 23 번의 이동 만에 도달 가능한 state 를 알아 내서 그것을 goal 로 넣어야 한다.)

• 사용할 탐색 알고리즘: 
    A* 탐색알고리즘을 사용한다. 
    g^(n) : n0부터 n 까지로의 지금까지 찾은 경로의 비용 (각 아크는 모두 비용이 1.0 으로 한다),
    h^(n) : state n 의 각 타일(1 ~ 15)를  goal state 의 대응 위치의 셀의 타일과 비교하여 잘못 
            놓여진 타일의 수.

(2)  데이타 구조
 - 상태 즉 노드:   4X4 타일블록을 하나의 구조체로 나타내도록 한다. 이는 2차원 배열을 필드로 가지는  구조체를 정의하여 이용한다.

     typedef int TileBlk [4][4] ; // 주의:  타일이 없는 셀에는 -1 을 넣어서 타일이 없음을 표시함
     typedef struct anode *Ty_nodeptr ;
     typedef struct anode { 
TileBlk  tile; 
Double fhat, ghat, hhat;
Ty_nodeptr pred ;   // 부모에 대한 포인터임.
} Ty_node ;

 - Open, Closed 의  연결리스트의 노드에 대한 구조체 정의:
    Typedef struct linknode *Ty_linknodePtr ;
    Typedef struct linknode {
             Ty_nodeptr nodeptr ;
             Ty_linkednodePtr next ;
    } Ty_linknode ;

 - Open, Closed :  노드에 대한 포인터들을 가지는 연결리스트이다.
    Ty_linknodePtr Open = NULL ;
    Ty_linknodePtr Closed = NULL ;

주의:  탐색트리 (TR) 은 각 노드의 pred 포인터로 표현된다.




(3)  실행 예:  텍스트 방식의 입출력

(타일이 없는 셀은 -1 으로 입력한다. 출력시에는 빈 셀은 blank 를 출력한다.)

시작노드를 입력하시오(1행, 2행, 3행, 4행 순으로 각 행마다 4 개의 수):
     -1  2   4  3     
     10  5   8  11    
     12  14  9  7    
     1   13  6  15

목표노드를 입력하시오:
     2  4    8   3     
     10  5  -1  11    
     12  14  9  7    
     1  13   6  15

경로 탐색 결과입니다:
[0]  This is the start state.
        2  4   3    
    10  5  8  11   
    12  14  9  7   
    1   13  6  15

==> move right (빈타일이 우측으로 옮겨간 것을 나타냄)
[1]  2     4   3    
    10  5  8  11   
    12  14  9  7   
    1  13  6  15

==> move right
[2]  2  4       3    
    10  5   8  11   
    12  14  9  7   
    1   13  6  15

==> move down
[3]  2  4   8  3    
    10  5      11   
    12  14  9  7   
    1   13  6  15

This sequence is a path to the goal !!
Length of the path  = 3




