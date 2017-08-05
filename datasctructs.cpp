class Node{
    protected:
        int data;
    public:
        void Node (int pData = 0){
            this.data = pData;
        }
}

class SimpleNode(): public Node {
    protected:
        SimpleNode* next;
    public:
        void  SimpleNode(int pData){
            this.data = pData;
            this.next = null;
        }
        SimpleNode* next(){
            return this.next;
        }
        void setNext(SimpleNode* pNode){
            this.next = pNode;
        }

        void removeNext(){
            this.next = null;
        }

        int getData(){
            return this.data;
        }

        void setData(int pInt){
            this.data = pInt;
        }
}

class SimpleList(){
    protected: 
        SimpleNode* head;
        SimpleNode* tail;
        int size;

    public:
        SimpleList(){
            this.head = null;
            this.tail = null;
            this.size = 0;
        }

        void add(int pData){
            if (this.size == 0){
                this.head = new *SimpleNode(pData);
            }else{
                SimpleNode* toAdd = new *SimpleNode(pData);
                this.tail.setNext(toAdd);
                this.tail = toAdd;
            }
            this.size ++;
        }

        int search(int pData){
            SimpleNode* current = this.head;
            while((*current).next() != null){
                if ((*current).next().getData() == pData){return 1;}
                return 0;
            }
        }
        
        void remove(int pData){
            SimpleNode* current = this.head;
            SimpleNode* previous = null;
            while((*current).next() != null){
                if ((*current).next().getData() == pData){
                    if (previous == null){
                        this.head = (*this.head).next();
                    }else{
                        (*previous).setNext((*current).next());
                        (*current).removeNext();
                    }
                }
            }
        }
}