// ########################## Constructors & Destructors ##########################

// DONE
template <class U>
pDStructures::linkedListNode<U>::linkedListNode(U constructData, linkedListNode &constructNext = nullptr) : data(constructData), next(constructNext) {}

// DONE
template <class U>
pDStructures::linkedListNode<U>::linkedList(U constructData, linkedListNode &constructNext = nullptr) {
	this->head = linkedListNode(constructData);
}
// DONE
template <class U>
void pDStructures::linkedListNode<U>::recurDestructorLinkedList(linkedListNode & headRecDest){
	using namespace pDStructures;

	if(headRecDest->next != nullptr){
		linkedListNode<U>::recurDestructorLinkedList(headRecDest->next);
	}	
	delete headRecDest;
}
// DONE
template <class U>
pDStructures::linkedListNode<U>::~linkedList() {
	pDStructures::linkedListNode<U>::recurDestructorLinkedList(this->head);
}

//######################### Linked List Node methods #########################

// DONE
// RA getData, first param is posicion of the node to retrieve data (you are supposed to only use that one).
template <class U>
U pDStructures::linkedList::getData(const unsigned int &pos, const linkedListNode &Node = head,unsigned int acc = 0) const{
	switch(pos == acc){
		case 1:
			return Node.data;
		case 0:
			return pDStructures::linkedList<U>::getData(*pos, Node.next, acc++); 
	}	
}
// DONE
template <class U>
void pDStructures::linkedList<U>::setData(const unsigned int &pos, const U &nData, const linkedListNode &Node = head, unsigned int acc = 0) {
	switch(pos == acc){
		case 1:
			Node.data = nData;
			break;
		case 0:
			pDStructures::linkedList<U>::setData(*pos, Node.next, acc++);
}
// DONE
//pure functions only!
//recursive, pattern matching based func to map, Returns 0 if success 
template <class U>
int pDStructures::linkedListNode<U>::map(std::function<U(U)> func, pDStructures::linkedListNode<U> &head){
	switch(head->next){
		case nullptr:	
			return 0;
		default:
			this->head.data = func(this->head.data);	
			return map(func, this->head.next);
	}
}

//template <class U>
//void pDStructures::linkedListNode<U>::pushFront(pDStructures::linkedListNode<U> &toLink){
//	this->next = toLink;
//}

