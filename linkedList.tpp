template <class U>
pDStructures::linkedListNode<U>::linkedListNode(U constructData, linkedListNode &construcNext) : data(constructData), next(construcNext) {}

template <class U>
U pDStructures::linkedListNode<U>::getData(void) const{
	return this->data;
}

template <class U>
void pDStructures::linkedListNode<U>::setData(const U &nData) {
	this->data = nData;	
}

//pure functions only!
//recursive, pattern matching based func to map, Returns 0 if success 
template <class U>
int pDStructures::linkedListNode<U>::map(std::function<U(U)> func, pDStructures::linkedListNode<U> &head){
	switch(head->next){
		case NULL:	
			return 0;
		default:
			head->data = func(head->data);	
			return map(func, head->next);
	}
}

template <class U>
void pDStructures::linkedListNode<U>::voidlinkTail(pDStructures::linkedListNode<U> &toLink){
	this->next = toLink;
}
//Mem leak!! next looses pointer, got to do double linked list! OR make LL major class to call the destructor
// from there and make the node class unaccesible
~linkedListNode(){
	delete(this);
}
