# What is data structure?
자료구조(data structure)는 프로그램에서 자료들을 정리하는 구조이다.  
이해를 쉽게 하기 위해서 자료구조의 종류들을 일상생활에서 볼 수 있는 것과 비교해보면 다음과 같은 예시들이 있다.

- List - 수첩에 해야할 일들을 기록  
순서를 가지고 일렬로 나열한 원소들의 모임이다. 순서가 있다는 점에서 집합과는 구별되며, 갈림길 없이 일렬로 나열되어 처음과 끝이 각각 하나씩만 있다는 점에서 그래프(graph)와도 구별된다. 리스트(list)의 종류에는 배열(array)과 연결리스트(linked list)가 있다.

- Stack - 바닥이 막힌 상자에 책을 쌓아 놓은 것  
데이터가 저장소의 끝 부분(Top 혹은 Top pointer)으로 들어오면서 저장되고, 데이터를 삭제 혹은 사용하기 위해 내보내는 데이터 역시 저장소의 끝 부분에서 나간다. 이러한 방식을 후입선출(Last In, First Out)이라고 한다.

- Queue - 물건을 구입하는 줄  
Queue라는 단어에서도 알 수 있듯이 데이터가 들어오는 위치는 가장 뒤(Rear)에 있고, 데이터가 나가는 위치는 가장 앞(Front)에 있다. Stack과는 다르게 먼저 들어오는 데이터가 먼저 나가게 되며 이러한 방식을 선입선출(First In, First Out)이라고 한다.

- Tree - 계층적인 조직(회사의 조직도, 컴퓨터의 폴더)  
부모 노드 밑에 여러 자식 노드가 연결되고, 자식 노드 각각에 다시 자식 노드가 연결되는 재귀적 형태이며 루트 노드를 중심으로 뻗어나가는 모습이 나무의 구조와 비슷하여 'tree'라는 이름이 붙었다.

- Graph - 지도(다대다매칭)  
그래프는 정점(vertex)과 정점들을 연결하는 변(edge)으로 구성이 된다. 변을 화살표로 나타내는 경우에는 해당 방향으로만 이동할 수 있으며, 이러한 그래프를 유향 그래프(directed graph)라고 말한다. 반대로 직선으로 표현되는 경우에는 양방향 모두 이동이 가능하며, 이러한 그래프를 무향 그래프(undirected graph)라고 말한다. 

# 1. linked list
연결리스트(linked list)는 리스트의 한 종류이며 배열과는 다른 특징을 가지고 있다.  

배열은 메모리 낭비를 피하기 위해 자료를 삭제하고 추가할 때마다 자료를 이동시켜야 한다는 불편함이 있지만 연결리스트는 자료를 삭제하거나 추가할 때 노드의 링크만 수정해주면 된다. 또한 메모리를 할당해놓고 자료를 저장하는 배열과는 다르게 동적할당을 통해 필요할 때 메모리를 할당받을 수 있으므로 자료의 삽입 삭제가 빈번한 경우 많이 사용한다.  

한 노드에는 데이터를 저장하는 부분(data)과 다음 데이터의 위치를 나타내는 부분(link)이 있으며 첫 번째 노드인 헤더(header)는 첫 번째 데이터가 어디 있는지 알려주며 마지막 노드의 링크(link)는 다음 데이터가 없으므로 마지막이라는 것을 알려주기 위해 NULL값을 세팅한다.  

    typedef struct node {  
	    void *dataPtr;  
	    struct node* link;  
    } NODE;  
노드를 정의하는 부분이다. node라는 구조체를 NODE타입으로 정의하여 뒤에 노드를 생성할 때 한눈에 쉽게 들어오도록 하였다. 노드 안에는 데이터를 저장하는 부분(dataPtr)과 다음 노드의 위치를 알려주는 부분(link)으로 구성되어 있다.

    NODE* createNode(void* itemPtr)             // void형의 itemPtr를 인수로 가지는 createNode라는 함수를 생성
    {
	    NODE* nodePtr = NULL;                     // NODE타입의 nodePtr노드를 NULL값으로 초기화
	    nodePtr = (NODE*)malloc(sizeof(NODE));    // nodePtr노드를 NODE타입의 크기만큼 메모리 할당
	    nodePtr->dataPtr = itemPtr;               // nodePtr노드의 dataPtr에 itemPtr값 저장
	    nodePtr->link = NULL;                     // nodePtr노드의 link는 NULL값으로 초기화
	    return nodePtr;
    }  
노드를 생성하는 함수이다. NODE타입의 createNode라는 함수를 생성하였으며 인수로는 itemPtr를 가진다. 연결리스트의 장점을 살리기 위해 malloc함수를 이용해 동적할당을 해주었고 하나의 노드를 만들기 위해 할당받는 메모리의 크기는 sizeof함수를 써서 NODE타입의 크기만큼을 할당받는다. malloc함수를 쓰기 위해서 라이브러리(#include <malloc.h>)를 반드시 포함시켜주고 이렇게 함으로써 메모리 낭비를 최소화 할수 있다. 또한 노드를 생성하는 함수이므로 dataPtr에 itemPtr가 저장되고 다음 노드에 대한 정보는 없으므로 link는 NULL값으로 초기화된다. 함수의 반환값으로 노드인 nodePtr를 반환한다.  

    int main(void)
    {
	    int* newData;
	    int* nodeData;
	    NODE* node;

	    newData = (int*)malloc(sizeof(int));
	    *newData = 7;
	    node = createNode(newData);
	    newData = (int*)malloc(sizeof(int));
	    *newData = 75; 
	    node->link = createNode(newData); 
	    nodeData = (int*)node->dataPtr;
	    printf("data1: %d\n", *nodeData);
	    nodeData = (int*)node->link->dataPtr; 
	    printf("data2: %d\n", *nodeData);
	    return 0;
    }  
노드를 2개 생성하여 각각의 노드에 7과 75를 저장하고 두 노드를 연결하는 메인문이다.

# 2. factorial
재귀함수의 간단한 예로 factorial을 구현하였다. 
