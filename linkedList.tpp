// ########################## Constructors & Destructors ##########################

// DONE
template <class U>
pDStructures::linkedListNode<U>::linkedListNode(U constructData, pDStructures::linkedListNode<U> *constructNext) : data(constructData), next(constructNext) {}

// DONE
template <class U>
pDStructures::linkedList<U>::linkedList(U constructData, pDStructures::linkedListNode<U> *constructNext) {
	this->head = pDStructures::linkedListNode<U>(constructData, constructNext);
}
// DONE
template <class U>
void pDStructures::linkedList<U>::recurDestructorLinkedList(pDStructures::linkedListNode<U> & headRecDest){
	using namespace pDStructures;

	if(headRecDest.next != nullptr){
		linkedList<U>::recurDestructorLinkedList((*headRecDest.next));
	}	
	delete headRecDest.next;
}
// DONE
template <class U>
pDStructures::linkedList<U>::~linkedList() {
	pDStructures::linkedList<U>::recurDestructorLinkedList(this->head);
}

//######################### Linked List Node methods #########################

// DONE
// RA getData, first param is posicion of the node to retrieve data (you are supposed to only use that one).
template <class U>
U pDStructures::linkedList<U>::getData(const unsigned int &pos, const pDStructures::linkedListNode<U> &Node, unsigned int acc) const{
	switch(pos == acc){
		case 1:
			return Node.data;
		case 0:
			return pDStructures::linkedList<U>::getData(pos, Node.next, acc++); 
	}	
}
// DONE
template <class U>
void pDStructures::linkedList<U>::setData(const unsigned int &pos, const U &nData, const pDStructures::linkedListNode<U> &Node, unsigned int acc) {
	switch(pos == acc){
		case 1:
			Node->data = nData;
			break;
		case 0:
			pDStructures::linkedList<U>::setData(pos, Node->next, acc++);
	}
}
// DONE
//pure functions only!
//recursive, pattern matching based func to map, Returns 0 if success 
template <class U>
int pDStructures::linkedList<U>::map(std::function<U(U)> func, pDStructures::linkedListNode<U> &headMap){
	switch(headMap->next){
		case nullptr:	
			return 0;
		default:
			headMap->data = func(headMap->data);	
			return pDStructures::linkedList<U>::map(func, headMap->next);
	}
}

//template <class U>
//void pDStructures::linkedListNode<U>::pushFront(pDStructures::linkedListNode<U> &toLink){
//	this->next = toLink;
//}

#undef uINT
