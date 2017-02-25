#include <iostream>
#include <map>
#include<vector>


using namespace std;




template <typename T>
class Graph
{
private:
    struct Vertex
    {
        T value;
        vector <T> vert_list;

    };


    vector <Vertex> graph;
    Vertex return_vertex(int i)
    {
        return graph[i];
    }


    int get_number(T v)
    {
        for(int i=0; i<graph.size(); i++)
        {
            if(graph[i].value==v) return i;
        }

    return -1;
    }
public:
    Graph()
    {

    }
    Graph(const Graph<T> &obj)
    {
        graph=obj.graph;
    }
    void add_vertex(T vert)
    {
        bool check=true;
        for(int i=0; i<graph.size(); i++)
        {
            if(vert == graph[i].value) check=false;
        }
        if(check)
        {
            vector<int> tmp;
            tmp.clear();
            Vertex temp;
            temp.value = vert;
            temp.vert_list = tmp;
            graph.push_back(temp);
        }
    }

    bool add_arc(T v1,T v2)
    {
        if(!contain(v1)) return false;
        if(!contain(v2)) return false;
        int n1,n2;
        n1=get_number(v1);
        n2=get_number(v2);
        graph[n1].vert_list.push_back(v2);
        graph[n2].vert_list.push_back(v1);
        return true;
    }
    int size()
    {
        return graph.size();
    }

    int vert_pow(T v)
    {
        int index=get_number(v);
        return graph[index].vert_list.size();
    }

    bool is_empty()
    {
        if(graph.size()) return true;
        else return false;
    }

    T at(int tmp)
    {
        return graph[tmp].value;
    }


    void change_elem(T v1,T v2)
    {
        int n1;
        n1=get_number(v1);
        graph[n1].value=v2;
    }

    bool contain(T temp)
    {
        for(int i=0; i<graph.size(); i++)
        {
            if(temp == graph[i].value) return true;
        }
        return false;
    }

    bool check_connection(T v1,T v2)
    {
        if(!contain(v1)) return false;
        if(!contain(v2)) return false;
        int n1,n2;
        n1=get_number(v1);
        n2=get_number(v2);


        for(int i=0; i<graph[n1].vert_list.size(); i++)
        {
            if(v2 == graph[n1].vert_list[i]) return true;
        }

        return false;

    }

    void del_node(T vdel)
    {
        int del;
        if(contain(vdel))
        {
            del=get_number(vdel);

            for(int i=0; i<graph.size(); i++)
                for(int j=0; j<graph[i].vert_list.size(); j++)
                {
                    if(graph[i].vert_list[j]==vdel) graph[i].vert_list.erase(graph[i].vert_list.begin()+j);
                }

            graph.erase(graph.begin()+del);
        }
    }

    void clear_graph()
    {
        graph.clear();
    }

    void del_arc(T v1, T v2)
    {
        if(contain(v1) && contain(v2) && check_connection(v1,v2))
        {
            int vert1,vert2;
            vert1=get_number(v1);
            vert2=get_number(v2);
            for(int i=0; i<graph[vert1].vert_list.size(); i++)
            {
                if(graph[vert1].vert_list[i]==v2) graph[vert1].vert_list.erase(graph[vert1].vert_list.begin()+i);

            }
            for(int i=0; i<graph[vert2].vert_list.size(); i++)
            {
                if(graph[vert2].vert_list[i]==v1) graph[vert2].vert_list.erase(graph[vert2].vert_list.begin()+i);

            }
        }
    }

  /* void show_graph()
   {
    cout<<"graph: "<<endl;
    for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].vert_list.size();j++)
                        {
                           cout<<graph[i].vert_list[j]<<" ";
                        }
         cout<<endl;
        }
     cout<<"//----------------------------------------- "<<endl;
    }*/


public:
    class Node_Iterator
    {
    private:
        Graph<T> *gr;
        int index;
    public:
        Node_Iterator( Graph<T> &graph)
        {
            gr = &graph;
            index = 0;
        }

        bool next()
        {
            if (gr->graph.size() <= index+1)return false;
            index++;
            return true;
        }
        T get()
        {
            return gr->graph[index].value;
        }
        bool delNode()
        {
            gr->del_node(get());
        }
        bool prev()
        {
            if (index==0) return false;
            index--;
            return true;
        }
    };

    class Node_Adjacent_Iterator
    {
    private:
        Graph<T> *gr;
        int index;
        int number=0;
        T priv_vert;
        T val;
        T node_val;
    public:
        Node_Adjacent_Iterator( Graph<T> &graph, T v)
        {
        gr = &graph;
        node_val=v;
        }

        Node_Adjacent_Iterator( Graph<T> &graph)
        {

            gr = &graph;
            index = 0;
            if(gr->graph[index].vert_list.size())
            {
               val=gr->graph[index].vert_list[0];

            }
            if(!gr->graph[index].vert_list.size())
            {
               val=gr->graph[index].value;
            }
             node_val=gr->graph[index].value;
        }
        T next_elem()
        {
           if(gr->graph[index].vert_list.size())
            {
            number++;
            if(number>=gr->graph[index].vert_list.size()) number=0;
            val=gr->graph[index].vert_list[number];
            return val;
            }
        return gr->graph[index].value;
        }

        bool next()
        {
          for(int i=0; i<gr->graph.size(); i++)
          {
            if(gr->graph[i].value==node_val) index = i;
          }
        if(gr->graph[index].vert_list.size() && gr->contain(val))
         {
          priv_vert=get();
          for(int i=0; i<gr->graph.size(); i++)
          {
            if(gr->graph[i].value==val) index = i;
          }
          node_val=gr->graph[index].value;
            return true;
         }
         return false;
        }
        T get()
        {
          for(int i=0; i<gr->graph.size(); i++)
          {
            if(gr->graph[i].value==node_val) index = i;
          }
            return gr->graph[index].value;
        }
        bool delNode()
        {
            gr->del_node(get());
            node_val=priv_vert;
        }

    };

    ~Graph()
    {

    }
    Graph& operator = (const Graph<T> &obj)
    {
        graph=obj.graph;
        return *this;
    }


};



///TODO: Show Graph


int main()
{
    setlocale(LC_ALL,"rus");
    Graph<int> gr;
    gr.add_vertex(111);
    gr.add_vertex(222);
    gr.add_vertex(333);
    gr.add_vertex(444);
    gr.add_arc(111,222);
    gr.add_arc(111,333);
    gr.add_arc(333,444);
    ///--------------------------------------------------------------------------------
    cout<<"конструктор копирования и оператор присваивания тест"<<endl;
    cout<<gr.at(1)<<endl;       ///конструктор копирования и оператор присваивания тест
    cout<<gr.at(0)<<endl;
    cout<<gr.check_connection(111,222)<<endl;
    cout<<gr.check_connection(111,444)<<endl;
    cout<<gr.size()<<endl<<endl;
    Graph<int> gr1;
    gr1 = gr;
    cout<<gr1.at(1)<<endl;
    cout<<gr1.at(0)<<endl;
    cout<<gr1.check_connection(111,222)<<endl;
    cout<<gr1.check_connection(111,444)<<endl;
    cout<<gr1.size()<<endl<<endl;
    Graph<int> gr2(gr1);
    cout<<gr2.at(1)<<endl;
    cout<<gr2.at(0)<<endl;
    cout<<gr2.check_connection(111,222)<<endl;
    cout<<gr2.check_connection(111,444)<<endl;
    cout<<gr2.size()<<endl<<endl;
    ///--------------------------------------------------------------------------------

    cout<<"///--------------------------------------------------------------------------------" <<endl;
    cout<<"тест удаления"<<endl;
    cout<<gr.contain(222)<<endl;
    cout<<gr.check_connection(111,222)<<endl;
    cout<<gr.check_connection(222,111)<<endl;
    cout<<gr.check_connection(333,444)<<endl;
    gr.del_node(222); ///тест удаления
    cout<<endl;
    cout<<gr.contain(222)<<endl;
    cout<<gr.check_connection(111,222)<<endl;
    cout<<gr.check_connection(222,111)<<endl;
    cout<<gr.check_connection(333,444)<<endl;
    cout<<endl;
    gr.del_arc(333,444);
    cout<<gr.check_connection(333,444)<<endl;
    cout<<endl;
    gr.clear_graph();
    cout<<"size "<<gr.size()<<endl;
    cout<<endl;
    cout<<"///--------------------------------------------------------------------------------" <<endl;


    cout<<"тест итератора по вершинам"<<endl;
    Graph<int>::Node_Iterator it(gr1); ///тест итератора по вершинам

    it.next();
    it.next();
    cout<<it.get()<<endl;
    it.delNode();
    cout<<it.get()<<endl;
    it.prev();
    cout<<it.get()<<endl;

    cout<<"///--------------------------------------------------------------------------------" <<endl;

    cout<<"тест итератора по смежным вершинам"<<endl;
    Graph<int>::Node_Adjacent_Iterator it1(gr2,111);
    cout<<it1.get()<<endl;
    cout<<"test next elem"<<endl;
    cout<<it1.next_elem()<<endl;
    cout<<it1.next_elem()<<endl;
    cout<<it1.next_elem()<<endl;
    cout<<it1.next_elem()<<endl;
    cout<<"test next"<<endl;
    it1.next();
    cout<<it1.get()<<endl;
    cout<<it1.next_elem()<<endl;
    cout<<it1.next_elem()<<endl;
    it1.next();
    cout<<it1.next_elem()<<endl;
    it1.next();
    cout<<it1.get()<<endl;
    cout<<it1.next_elem()<<endl;
    cout<<it1.next_elem()<<endl;
    cout<<"delete test"<<endl;
    cout<<it1.get()<<endl;
    it1.delNode();
    cout<<it1.get()<<endl;
    cout<<it1.next_elem()<<endl;
    cout<<it1.next_elem()<<endl;
    return 0;
}
