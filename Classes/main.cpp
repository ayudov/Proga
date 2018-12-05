#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

class arr
{
    public:
        arr (unsigned int capasity2)
        {
            srand (time(0));
            this->ptr = new int[capasity2];
            this->value=0;
            this->capasity=capasity2;
            for (int i=0; i<capasity; i++)
                {
                    ptr[i]=rand()%10;
                    value++;
                }
            for (int i=0; i<value; i++)
                cout<<ptr[i]<<"  ";
        }
        ~arr()
        {
            delete [] ptr;
        }
        void pushBack(int x)
        {
            sizep();
            ptr[value]=x;
            value++;
            for (int i=0; i<value; i++)
            {
                cout<<ptr[i]<<"  ";
            }
            cout<<endl;
        }
        int getCapasity()
        {
            return (capasity);
        }
        unsigned int getSize()
        {
            return (value);
        }
        void display()
        {
            for (int i=0; i<value; i++)
            {
                cout<<ptr[i]<<"  ";
            }
            cout<<endl;
        }
        elementAt(int pos)
        {
            cout<<pos<<"-d element is "<< ptr[pos]<<endl;
        }
        int sort()
        {
            for(int i=0; i<value; i++)
            {
                for(int j=0; j<value; j++)
                {
                    if(ptr[i] > ptr[j])
                    {
                        int tmp = ptr[i];
                        ptr[i] = ptr[j] ;
                        ptr[j] = tmp;
                    }
                }
            }
            for (int i=0; i<value; i++)
            {
                cout<<ptr[i]<<"  ";
            }
                cout<<endl;
        }
        int partition(int p, int q)
        {
            int x= ptr[p];
            int i=p;
            int j;
            for(j=p+1; j<q; j++)
            {
                if(ptr[j]<=x)
                {
                    i++;
                    swap(ptr[i],ptr[j]);
                }

            }
            swap(ptr[i],ptr[p]);
            return i;
        }
        void quickSort(int p, int q)
        {
            int r;
            if(p<q)
            {
                r=partition(p,q);
                quickSort(p,r);
                quickSort(r+1,q);
            }
        }
        void insert(int x, int y)
        {
            int *t=new int [value+1];
            for (int i=0; i<value+1; i++)
            {
                if (i==x)
                {
                    t[i]=y;
                    i++;
                    do
                    {
                        t[i]=ptr[i-1];
                        i++;
                    }while (i!=value+1);
                    break;
                }
                else
                {
                    t[i]=ptr[i];
                }
            }
            delete[] ptr;
            ptr=t;
            value++;

            for (int i=0; i<value; i++)
            {
                cout<<ptr[i]<<"  ";
            }
            cout<<endl;
        }
        void deleteAt(int x)
        {
            int *t=new int [value];
            for (int i=0; i<value; i++)
            {
                if (i!=x)
                {
                    t[i]=ptr[i];
                }
                else
                {
                    do
                    {
                        t[i]=ptr[i+1];
                        i++;
                    }while (i!=value);
                    break;
                }
            }
            delete[] ptr;
            ptr=t;
            value--;
            for (int i=0; i<value; i++)
            {
                cout<<ptr[i]<<"  ";
            }
            cout<<endl;
        }
        void reverse()
        {
            int *t=new int [value];
            for (int i=0; i<value; i++)
            {
                t[i]=ptr[value-i-1];
            }
            delete[] ptr;
            ptr=t;
            for (int i=0; i<value; i++)
            {
                cout<<ptr[i]<<"  ";
            }
            cout<<endl;
        }
        string toString()
        {
            ostringstream oss(" ");
            for (int i=0; i<value; i++)
            {
                oss<<ptr[i];
            }
            return oss.str();
        }
        void pushFront(int x)
        {
            sizep();
            int *t=new int [capasity+1];
            t[0]=x;
            value++;
            for (int i=1; i<value; i++)
            {
                t[i]=ptr[i-1];
            }
            delete[] ptr;
            ptr=t;
            for (int i=0; i<value; i++)
            {
                cout<<ptr[i]<<"  ";
            }
            cout<<endl;
        }

    private:
        unsigned int value;
        int *ptr, tmp, capasity;

        void sizep()
        {
            if (value==capasity)
            {
                int *t=new int [capasity+5];
                for (int i=0; i<capasity; i++)
                {
                    t[i]=ptr[i];
                }
                delete[] ptr;
                ptr=t;
                capasity+=5;
            }
        }
};


    typedef struct Node
{
    int value;
    struct Node *next;
} Node;


class list
{
    public:
        list (int n)
        {
            srand (time(0));
            head = NULL;
            size = 0;
            for (int i=0; i<n; i++)
            {
                pushfrontl(rand()%10, 0);
            }
        }
        void pushfrontl(int x, int check)
        {
            if (check == 1){cout<<"element = "<<x<<"\n";}
            Node *tmp = new Node;
            tmp->value = x;
            tmp->next = head;
            head = tmp;
            size++;
        }
        void displayl()
        {
            if(head==NULL)
            {
                exit(-1);
            }
            Node *tmp=new Node;
            tmp=head;
            while(tmp)
            {
                cout<<tmp->value<<" ";
                tmp=tmp->next;
            }
            cout<<"\n";
            delete tmp;
        }
        void popfront()
        {
            Node* tmp=new Node;
            tmp=head->next;
            delete head;
            head=tmp;
            size--;
        }
        void pushBackl(int x)
        {
            cout<<"element = "<<x<<"\n";
            Node *tmp = new Node;
            tmp=head;
            while (tmp->next!=NULL)
            {
                tmp=tmp->next;
            }
            Node *last = new Node;
            last->value = x;
            last->next = NULL;
            tmp->next = last;
            size++;
            delete tmp;
            displayl();
        }
        int getsizel()
        {
            return (size);
        }
        void insertl (int pos, int element)
        {
            cout<<">element = "<<element;
            cout<<", position  = (after "<<pos<<" element)\n";
            Node *tmp = new Node;
            tmp=head;
            for (int i=0; i<pos-1; i++)
            {
                tmp=tmp->next;
            }
            Node *insert = new Node;
            insert->value=element;
            insert->next = tmp->next;
            tmp->next = insert;
            delete tmp;
            delete insert;
            size++;
            displayl();
        }
        void deleteAtl(int pos)
        {
            cout<<">position  = (after "<<pos<<" element)\n";
            Node *el = new Node;
            Node *prev = new Node;
            el=head;
            prev=head;
            for (int i=0; i<pos; i++)
            {
                el=el->next;
            }
            for (int i=0; i<pos-1; i++)
            {
                prev=prev->next;
            }
            prev->next=el->next;
            delete el;
            delete prev;
            size--;
            displayl();
        }
        string toStringl()
        {
            ostringstream oss(" ");
            Node *tmp = new Node;
            tmp=head;
            while(tmp->next!=NULL)
            {
                oss<<tmp->value;
                tmp=tmp->next;
            }
            oss<<tmp->value;
            delete tmp;
            return oss.str();
        }
        int elementAtl(int pos)
        {
            cout<<"\n>position = "<<pos<<endl;
            Node *tmp = new Node;
            tmp=head;
            for (int i=0; i<pos-1; i++)
            {
                tmp=tmp->next;
            }
            cout<<tmp->value<<endl;
        }
        void reversel()
        {
            Node *tmp = new Node;
            tmp=head;
            int temp[size];
            int i=0;
            while (tmp)
            {
                temp[i]=tmp->value;
                tmp=tmp->next;
                i++;
            }
            tmp=head;
            i=size-1;
            while (tmp)
            {
                tmp->value=temp[i];
                tmp=tmp->next;
                i--;
            }
            displayl();
        }
       /* mergesort(int n)
        {
            Node *tmp = new Node;
            tmp=head;
            int temp[size];
            int i=0;
            while (tmp)
            {
                temp[i]=tmp->value;
                tmp=tmp->next;
                i++;
            }
            merge(0, size);
            for (int i = 0; i < n; i++)
            cout << temp[i] << " ";
            delete temp;
        }
        void merge(int l, int r)
        {
            Node *tmp = new Node;
            tmp=head;
            int temp[size];
            int i=0;
            while (tmp)
            {
                temp[i]=tmp->value;
                tmp=tmp->next;
                i++;
            }
            if (r == l)
                return;
            if (r - l == 1) {
                if (temp[r] < temp[l])
                    swap(temp[r], temp[l]);
                return;
            }
            int m = (r + l) / 2;
            merge(l, m);
            merge(m + 1, r);
            int buf[100];
            int xl = l;
            int xr = m + 1;
            int cur = 0;
            while (r - l + 1 != cur)
            {
                if (xl > m)
                    buf[cur++] = temp[xr++];
                else if (xr > r)
                    buf[cur++] = temp[xl++];
                else if (temp[xl] > temp[xr])
                    buf[cur++] = temp[xr++];
                else buf[cur++] = temp[xl++];

            }
            for (int i = 0; i < cur; i++)
                temp[i + l] = buf[i];
                cout << "\n\n";
            for (int i = 0; i < size; i++)
            {
            cout << temp[i] << " ";}
        }*/
        ~list()
        {
            while(head!=NULL)
            {
                popfront();
            }
        }
    private:
        friend Node;
        int size;
        Node *head;
};

int main()
{
    int cap=5;
    int elat=4;
    int pushb=3;
    int pushfel=4;
    int posad=4;
    int addel=9;
    int posdel=3;

    cout<<">Your primary array (random) :\n";
    arr* obj=new arr(cap);
    cout<<"\n\n>pushBack"<<" ("<<pushb<<")\n";
    obj->pushBack(pushb);
    cout<<"\n>display\n";
    obj->display();
    cout<<"\n>elementAt"<<" ("<<elat<<")\n";
    obj->elementAt(elat);
    cout<<"\n>getCapasity\n";
    cout<<">Capasity="<<obj->getCapasity()<<endl;
    cout<<"\n>getSize\n";
    cout<<">Size="<<obj->getSize()<<endl;
    cout<<"\n>sort (decrease)\n";
    obj->sort();
    cout<<"\n>insert (element = "<<addel<<", "<<"position = "<<posad<<")\n";
    obj->insert(posad, addel);
    cout<<">Capasity="<<obj->getCapasity()<<endl;
    cout<<">Size="<<obj->getSize()<<endl;
    cout<<"\n>delete (position = "<<posdel<<")\n";
    obj->deleteAt(posdel);
    cout<<">Capasity="<<obj->getCapasity()<<endl;
    cout<<">Size="<<obj->getSize()<<endl;
    cout<<"\n>reverse\n";
    obj->reverse();
    cout<<"\n>toString\n";
    cout<<obj->toString()<<endl;
    cout<<"\n>pushFront ("<<pushfel<<")\n";
    obj->pushFront(pushfel);
    cout<<">Capasity="<<obj->getCapasity()<<endl;
    cout<<">Size="<<obj->getSize()<<endl;
    cout<<"\n>quickSort\n";
    obj->quickSort(0, obj->getSize());
    obj->display();
    delete obj;
    cout<<endl<<"---------------------------------------------------------------------"<<endl<<endl;
    int listposad = 5;
    int deletelistpos = 3;
    int elementat = 4;
    list* spisok=new list(5);
    cout<<">Your primary list (random):\n";
    spisok->displayl();
    cout<<"\n>display\n";
    spisok->displayl();
    cout<<"\n>pushBack ";
    spisok->pushBackl(rand()%10);
    cout<<"\n>pushFront ";
    spisok->pushfrontl(rand()%10, 1);
    spisok->displayl();
    cout<<"\n>getSize\n";
    cout<<">Size="<<spisok->getsizel()<<endl;
    cout<<"\n>insert\n";
    spisok->insertl(listposad, rand()%10);
    cout<<">Size="<<spisok->getsizel()<<endl;
    cout<<"\n>deleteAt\n";
    spisok->deleteAtl(deletelistpos);
    cout<<">Size="<<spisok->getsizel()<<endl;
    cout<<"\n>toString\n";
    cout<<spisok->toStringl()<<endl;
    cout<<">Size="<<spisok->getsizel()<<endl;
    cout<<"\n>elementAt";
    spisok->elementAtl(elementat);
    cout<<"\n>reverse\n";
    spisok->reversel();
   /* cout<<"\n>mergesort\n";
    spisok->mergesort(spisok->getsizel());*/


    delete spisok;
    system("PAUSE");
    return 0;
}

