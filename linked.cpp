#include<iostream>
#include<stdlib.h>

class Linkedlist
{
	private:
		struct node {
			int info;
			node *next;
		};
		node * start;
		int capacity;
	public:
	    Linkedlist()
	    {
	        capacity = 0;
	        start = NULL;
	    }
	    Linkedlist(Linkedlist *l)
	    {
	        node *t = l->start;
	        while(t!=NULL)
            {
                append(t->info);
                t = t->next;
            }
            delete t;
	    }
	    void append(int info)
	    {
	        if(start == NULL)
            {
                node *temp = new node();
                temp->info = info;
                temp->next = NULL;
                start = temp;
                capacity = 1;
            }
            else
            {
                node * t;
                t = start;
                while(t->next!= NULL)
                {
                    t = t->next;
                }
                node *temp = new node();
                temp->info = info;
                temp->next = NULL;
                t->next = temp;
                capacity += 1;
            }
	    }
	    int pop(int index)
	    {
	        if(index >= capacity || index < 0)
            {
                throw  "out of bound";
            }
            if(index == capacity -1)
            {
                node *t = start;
                while(t->next->next!=NULL)
                    t = t->next;
                node *temp = t->next;
                int val;
                val = temp->info;
                delete temp;
                t->next = NULL;
                capacity -= 1;
                return val;
            }
            if (index == 0)
            {

                int val = start->info;
                node *t = start->next;
                delete start;
                start = t;
                capacity -= 1;
                return val;
            }
            node *t = start;
            int i = 0;
            while(true)
            {
                if(i == index -1)
                    break;
                t = t->next;
                i+=1;
            }
            int val;
            val = t->next->info;
            node *temp = t->next->next;
            delete t->next;
            t->next = temp;
            capacity -= 1;
            return val;
	    }
	    int getValue(int index)
	    {
	        if(index >= capacity || index < 0)
            {
                throw "out of bound";
            }
            if(index == capacity -1)
            {
                node *t = start;
                while(t->next!=NULL)
                    t = t->next;
                return t->info;
            }
            if (index == 0)
            {

                return start->info;
            }
            node *t = start;
            int i = 0;
            while(true)
            {
                if(i == index)
                    break;
                t = t->next;
                i++;
            }
            return t->info;
	    }
	    int getCap()
	    {
	        return capacity;
	    }
	    int replace(int index , int info)
	    {
	        int i = 0;
	        if(index > capacity)
            {
                throw "out of bound";
            }
            if(index < 0)
            {
                throw "lower bound";
            }
            if( index == 0)
            {
                start->info = info;
                return 1;
            }
            node *t;
            t = start;
            while(true)
            {
                if(i == index)
                {
                    break;
                }
                t = t->next;
                i++;
            }
            t->info = info;
            return 1;
	    }

	    int insert(int index,int info)
	    {
	        int i = 0;
	        if(index > capacity)
            {
                throw "out of bound";
            }
            if(index < 0)
            {
                throw "lower bound";
            }
            if(index == capacity)
            {
                this->append(info);
                return 1;
            }
            if( index == 0)
            {
                node * newNode = new node();
                newNode->info = info;
                newNode->next = start;
                start = newNode;
                capacity += 1;
                return 1;
            }
            node *t;
            t = start;
            while(true)
            {
                if(i == index-1)
                {
                    break;
                }
                t = t->next;
                i++;
            }


            node * newNode = new node();
            newNode->info = info;
            newNode->next = t->next;
            t->next = newNode;
            capacity += 1;
            return 1;
	    }

	    friend std::ostream & operator <<(std::ostream &out,Linkedlist *);
	    friend Linkedlist * merge(Linkedlist *,Linkedlist *);
	    Linkedlist * sort(int acdc = 1)
	    {
	        Linkedlist *l2 = new Linkedlist();
	        if(start == NULL || capacity == 1)
            {
                return l2;
            }
            node *t = start;
	        while(t!=NULL)
            {
                l2->append(t->info);
                t = t->next;
            }
            if(acdc  == 1)
            {
                int key,j;
                int cap = l2->getCap();
                for (int i = 1;i<cap;i++)
                {
                    key = l2->getValue(i);
                    j = i-1;
                    while(j>=0 && l2->getValue(j) > key)
                    {
                        l2->replace(j+1,l2->getValue(j));
                        j = j-1;
                    }
                    l2->replace(j+1,key);

                }
            }
            if(acdc == -1)
            {
                int key,j;
                int cap = l2->getCap();
                for (int i = 1;i<cap;i++)
                {
                    key = l2->getValue(i);
                    j = i-1;
                    while(j>=0 && l2->getValue(j) < key)
                    {
                        l2->replace(j+1,l2->getValue(j));
                        j = j-1;
                    }
                    l2->replace(j+1,key);

                }
            }

            return l2;
	    }
};

Linkedlist * merge(Linkedlist *l1,Linkedlist *l2)
{
    Linkedlist *l3 = new Linkedlist;
    Linkedlist::node *t;
    t = l1->start;
    while(t != NULL)
    {
        l3->append(t->info);
        t = t->next;
    }
    t = l2->start;
    while(t != NULL)
    {
        l3->append(t->info);
        t = t->next;
    }
    return l3;
}

std::ostream & operator <<(std::ostream &out,Linkedlist *l)
{
    Linkedlist::node *t;
    t = l->start;
    out<<'[';
    while(t!=NULL)
    {
        out<<t->info;
        t = t->next;
        if(t!=NULL)
        {
            out<<", ";
        }
    }
    out<<']'<<'\n';
    return out;
}


main()
{
    Linkedlist *l = new Linkedlist(); std::cout<<l->getCap()<<std::endl;
    std::cout<<l; l->append(47); std::cout<<l->getCap()<<std::endl;
    std::cout<<l; l->append(98);
    std::cout<<l->getCap()<<std::endl; std::cout<<l;
    l->append(85); std::cout<<l->getCap()<<std::endl;
    std::cout<<l; l->append(85); std::cout<<l->getCap()<<std::endl;
    std::cout<<l; l->insert(0,1); std::cout<<l->getCap()<<std::endl;
    std::cout<<l; l->insert(2,1256); std::cout<<l->getCap()<<std::endl;
    std::cout<<l; l->insert(2,7856); std::cout<<l->getCap()<<std::endl;
    std::cout<<l; l->insert(7,256); std::cout<<l->getCap()<<std::endl;
    std::cout<<l; std::cout<<l->pop(l->getCap()-1)<<std::endl;
    std::cout<<l->getCap()<<std::endl; std::cout<<l;
    std::cout<<l->pop(0)<<std::endl; std::cout<<l->getCap()<<std::endl;
    std::cout<<l; std::cout<<l->pop(2)<<std::endl;
    std::cout<<l->getCap()<<std::endl; std::cout<<l;
    std::cout<<l->pop(3)<<std::endl; std::cout<<l->getCap()<<std::endl;
    std::cout<<l; std::cout<<"=======================getting value ======="<<std::endl;
    std::cout<<l->getValue(l->getCap()-1)<<std::endl; std::cout<<l->getCap()<<std::endl;
    std::cout<<l; std::cout<<l->getValue(0)<<std::endl;
    std::cout<<l->getCap()<<std::endl; std::cout<<l;
    std::cout<<l->getValue(2)<<std::endl; std::cout<<l->getCap()<<std::endl;
    std::cout<<l; std::cout<<l->getValue(1)<<std::endl;
    std::cout<<l->getCap()<<std::endl; std::cout<<l;
    std::cout<<"=======================merging ======="<<std::endl;
    Linkedlist *l1 = new Linkedlist; Linkedlist *l2 = new Linkedlist;
    Linkedlist *l3 = new Linkedlist; l1->append(45);
    l1->append(42); l1->append(40); l2->append(32);
    l2->append(31); l2->append(35); l2->append(39);
    l3 = merge(l1,l2); std::cout<<"l1 is = "<<l1;
    std::cout<<"l2 is = "<<l2; std::cout<<"l3 is = "<<l3;
}



