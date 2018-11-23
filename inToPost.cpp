#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
class Stack
{
	private:
		struct node {
			string info;
			node *next;
		};
		node * start;
		int capacity;
	public:
	    Stack()
	    {
	        capacity = 0;
	        start = NULL;
	    }

	    void push(string info)
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
	    string pop()
	    {
	        if (capacity == 1)
            {
                node *t = start;
                string val = t->info;
                delete t;
                start == NULL;
                capacity -= 1;
                return val;
            }
            node *t = start;
            while(t->next->next!=NULL)
                t = t->next;
            node *temp = t->next;
            string val;
            val = temp->info;
            delete temp;
            t->next = NULL;
            capacity -= 1;
            return val;

	    }
	    int getCap()
	    {
	        return capacity;
	    }
};
string in2post(string ques)
{
    ques += ")";
    string ans = "";
    Stack *s = new Stack();
    s->push("(");
    int len = ques.length();
    for(int i = 0;i<len;i++)
    {
        char temp = ques[i];
        if(temp == '*' || temp == '/' || temp == '%' || temp == '+' || temp == '-' || temp == '^')
        {
            ans += s[i];
        }
        if(temp == ')')
        {
            s->push(')');
        }

    }
    return ans;
}

main()
{

}
