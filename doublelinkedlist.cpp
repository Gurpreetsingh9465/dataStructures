#include<iostream>
#include<stdlib.h>

class DoubleLinkedList
{
private:
    struct node
    {
        int info;
        node *next;
        node *pre;
    };
    node * start,*end;
    int capacity;
public:
    DoubleLinkedList()
    {
        end = NULL;
        start = NULL;
        capacity = 0;
    }
    void append(int info)
    {
        node *newNode = new node;
        newNode->info = info;
        if(start == NULL)
        {
            start = newNode;
            end = newNode;
            newNode->next = NULL;
            newNode->pre = NULL;
        }
        else
        {
            newNode->pre = end;
            end = newNode;
            newNode->next = NULL;
            newNode->pre->next = newNode;
        }
        capacity +=1;
    }
    int insert(int index,int value)
    {
        if(index  < 0 || index > capacity)
        {
            throw "value out of bound";
            return 0;
        }
        if(index == capacity)
        {
            append(value);
            return 1;
        }
        if(index == 0)
        {
            node *newNode = new node;
            newNode->info = value;
            newNode->next = start;
            newNode->next->pre = newNode;
            newNode->pre = NULL;
            start = newNode;
            capacity += 1;
            return 1;
        }
        int half = capacity/2;
        if(half > index)
        {
            node * temp =start;
            int i = 0;
            while(true)
            {
                if(i == index)
                    break;
                temp = temp->next;
                i++;
            }
            node *newNode = new node;
            newNode->info = value;
            newNode->next = temp;
            newNode->pre = temp->pre;
            temp->pre->next = newNode;
            temp->pre = newNode;
        } else {
            node * temp =end;
            int i = capacity-1;
            while(true)
            {
                if(i == index)
                    break;
                temp = temp->pre;
                i--;
            }
            node *newNode = new node;
            newNode->info = value;
            newNode->next = temp;
            newNode->pre = temp->pre;
            temp->pre->next = newNode;
            temp->pre = newNode;

        }
        capacity += 1;
        return 1;


    }
    int pop(int index)
    {
        if(index  < 0 || index >= capacity)
        {
            throw "value out of bound";
            return -1;
        }
        if(capacity == 0 && index == 0)
        {
            int val = start->info;
            delete start;
            start = NULL;
            end = NULL;
            capacity--;
            return val;
        }
        if (index == 0)
        {
            node *temp = start;
            start = temp->next;
            start->pre = NULL;
            int val = temp->info;
            delete temp;
            capacity--;
            return val;
        }
        if(index == capacity-1)
        {
            node *temp = end;
            end = temp->pre;
            end->next = NULL;
            int val = temp->info;
            delete temp;
            capacity--;
            return val;
        }
        int half = capacity/2;
        int val;
        if(half > index)
        {
            node * temp =start;
            int i = 0;
            while(true)
            {
                if(i == index)
                    break;
                temp = temp->next;
                i++;
            }
            val = temp->info;
            temp->next->pre = temp->pre;
            temp->pre->next = temp->next;
            delete temp;

        } else {
            node * temp =end;
            int i = capacity-1;
            while(true)
            {
                if(i == index)
                    break;
                temp = temp->pre;
                i--;
            }
            val = temp->info;
            temp->next->pre = temp->pre;
            temp->pre->next = temp->next;
            delete temp;
        }
        capacity--;
        return val;



    }
    int replace(int index,int value)
    {
        if(index  < 0 || index >= capacity)
        {
            throw "value out of bound";
            return 0;
        }
        if(index == capacity-1)
        {
            end->info = value;
            return 1;
        }
        if(index == 0)
        {
            start->info = value;
            return 1;
        }
        int half = capacity/2;
        if(half > index)
        {
            node * temp =start;
            int i = 0;
            while(true)
            {
                if(i == index)
                    break;
                temp = temp->next;
                i++;
            }
            temp->info = value;
        } else {
            node * temp =end;
            int i = capacity-1;
            while(true)
            {
                if(i == index)
                    break;
                temp = temp->pre;
                i--;
            }
            temp->info = value;
        }
        return 1;


    }
    int getCap()
    {
        return capacity;
    }
    friend std::ostream & operator <<(std::ostream &out,DoubleLinkedList *);



};

std::ostream & operator <<(std::ostream &out,DoubleLinkedList *l)
{
    DoubleLinkedList::node *t;
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
main() {
    DoubleLinkedList *l = new DoubleLinkedList;
    std::cout<<l; std::cout<<l->getCap()<<std::endl;
    l->append(45); std::cout<<l; std::cout<<l->getCap()<<std::endl;
    l->append(92); std::cout<<l; std::cout<<l->getCap()<<std::endl;
    l->append(8); std::cout<<l; std::cout<<l->getCap()<<std::endl; l->append(78);
    std::cout<<l; std::cout<<l->getCap()<<std::endl; l->append(8);
    std::cout<<l; std::cout<<l->getCap()<<std::endl; l->insert(0,7);
    std::cout<<l; std::cout<<l->getCap()<<std::endl; l->insert(l->getCap(),9);
    std::cout<<l; std::cout<<l->getCap()<<std::endl; l->insert(l->getCap()-2,5);
    std::cout<<l; std::cout<<l->getCap()<<std::endl; l->insert(2,0);
    std::cout<<l; std::cout<<l->getCap()<<std::endl; l->replace(2,1025);
    std::cout<<l; std::cout<<l->getCap()<<std::endl; l->replace(l->getCap()-1,1025);
    std::cout<<l; std::cout<<l->getCap()<<std::endl; l->replace(l->getCap()/2,1025);
    std::cout<<l; std::cout<<l->getCap()<<std::endl;
    std::cout<<"=====================poping========"<<std::endl;
    std::cout<<l->pop(l->getCap()/2)<<std::endl; std::cout<<l;
    std::cout<<"len ="<<l->getCap()<<std::endl; std::cout<<l->pop(l->getCap()-1)<<std::endl;
    std::cout<<l; std::cout<<"len ="<<l->getCap()<<std::endl;
    std::cout<<l->pop(l->getCap()-2)<<std::endl; std::cout<<l;
    std::cout<<"len ="<<l->getCap()<<std::endl;
    std::cout<<l->pop(1)<<std::endl; std::cout<<l;
    std::cout<<"len = "<<l->getCap()<<std::endl;
}



