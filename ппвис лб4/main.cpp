
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
template <typename G>
class Graph {

private:
	vector<G> node;
	vector<G> line;
	vector<vector <G> >graph;
	int arc=0;

public:

	Graph() {

	}
	~Graph() {

	}
	Graph(const Graph<G> &graph) {


	}
	int getnodes() {
		return node.size();
	}
	int getarc() {
		return arc;
	}
	bool isGEmpty() {
		if (getnodes() == 0)
			return true;
		return false;
	}
	bool addnode(G new_node) {
		if (!isNodeinGraph(new_node)) {
			node.push_back(new_node);
			graph.push_back(line);
			line.clear();
			return true;
		}
		return false;

	}
	bool addArc(G first, G second) {
		int i = 0;
		if (!isArcinGraph( first, second)) {
			arc++;
			while (i != getnodes()) {
				if (node[i] == first) {
					break;
				}
				i++;
			}
			if (i == getnodes())
				return false;
			graph[i].push_back(second);



			return true;
		}
		return false;
	}
	bool isArcinGraph(G first, G second) {
		int i = 0;
		if (isNodeinGraph(first) && isNodeinGraph(second)) {
			while (i != getnodes()) {
				if (node[i] == first) {
					break;
				}
				i++;
			}
			for (int z = 0; z < graph[i].size();z++)
				if (graph[i][z] == second) {
					return true;
				}


		}
		return false;
	}
	bool isNodeinGraph(G first) {
		int i = 0;
		while (i != getnodes()) {
			if (node[i] == first) {
				return true;
			}
			i++;
		}
		return false;
	}
	bool delArc(G first, G second) {
		int i = 0;
		int z = 0;
		if (isArcinGraph(first, second)) {
			arc--;
			while (i != getnodes()) {
				if (node[i] == first) {
					break;
				}
				i++;
			}
			if (i == getnodes())
				return false;
			for (; z < graph[i].size(); z++)
				if (graph[i][z] == second) {
					break;
				}
			swap(graph[i][z], graph[i][graph[i].size()-1]);
			graph[i].pop_back();


			return true;
		}
		return false;
	}
	int	getNodePower(G first) {
		int i = 0;
		for (; i < node.size(); i++)
			if (node[i] == first)
				break;
		if (i == node.size())
			return 0;
		return graph[i].size();
	}
	int	getArcPower(G first, G second) {
		if (isArcinGraph(first, second)) {
			if (first == second)
				return 1;
			return 2;
		}
		return 0;
	}
	bool delNode(G first) {
		int i = 0;
		if (isNodeinGraph(first)) {

			for (int z = 0; z < node.size(); z++) {
				delArc(node[z],first);
			}
			while (i != getnodes()) {
				if (node[i] == first) {
					break;
				}
				i++;
			}

			swap(node[i], node[node.size()-1]);
			node.pop_back();
			swap(graph[i], graph[graph.size() - 1]);
			graph.pop_back();



			return true;
		}
		return false;
	}
	public:
		class Node_Iterator {
			int index ;
			Graph<G> *gr;
		public:
			Node_Iterator( Graph<G> &graph){
				gr = &graph;
				index = 0;
			}
			bool next() {
				if (gr->node.size() <= index+1)
					return false;
				index++;
				return true;
			}
			G get() {
				return gr->node[index];
			}
			bool delNode() {
				if (gr->delNode(gr->node[index])) {
					if (index == gr->node.size())
						index--;
					return true;
				}

				return false;
			}
			bool prev() {
				if (index==0)
					return false;
				index--;
				return true;
			}
		};
		class NodeAdjacent_Iterator {
			int index;
			int node_index;
			Graph<G> *gr;
		public:
			NodeAdjacent_Iterator(Graph<G> &graph,G node) {
				do {
					if (graph.isNodeinGraph(node)) {
						gr = &graph;
						int i = 0;
						while (i != graph.getnodes()) {
							if (graph.node[i] == node) {
								break;
							}
							i++;
						}
						node_index = i;
						index = 0;
						break;
					}
					cout << "ERROR:node is not in graph" << endl;
				} while (false);

			}
			bool next() {
				if (gr->graph[node_index].size() <= index + 1)
					return false;
				index++;
				return true;
			}
			G get() {
				if(gr->graph[node_index].size()>0)
					return gr->graph[node_index][index];
				cout << "ERROR:node have not adjacent node" << endl;
				return NULL;
			}
			bool delNode() {
				if (gr->delNode(gr->graph[node_index][index]))
					if (index == gr->graph[node_index].size())
						index--;
					return true;
				return false;
			}
			bool prev() {
				if (index == 0)
					return false;
				index--;
				return true;
			}
		};
};

int main()
{
	Graph<int> graph;

	graph.addnode(1);
	graph.addnode(2);
	graph.addnode(3);
	graph.addArc(1, 2);
	graph.addArc(2, 1);
	graph.addArc(1, 3);
	cout << graph.getnodes() << endl;

	Graph<int> graph1(graph);
	cout << graph1.getnodes() << endl;
/*	Graph<int>::NodeAdjacent_Iterator it1(graph,1);
	do {
		cout << it1.get() << " ";
	} while (it1.next());
	cout << endl;
	do {
		cout << it1.get() << " ";
	} while (it1.prev());
	cout << endl;
	it1.delNode();
	cout << graph.getnodes() << endl;
	graph.addnode(2);
	cout << endl;
	cout << endl;
	cout << endl;
	Graph<int>::Node_Iterator it(graph);
	it.delNode();
	cout << graph.getnodes() << endl;
	graph.addnode(1);
	cout << graph.getnodes() << endl;
	do {
		cout << it.get() << " ";
	} while (it.next());
	cout << endl;
	do {
		cout << it.get() << " ";
	} while (it.prev());
	cout << endl;
	cout << endl;
	cout << endl;

	Graph<int> graph3;
	graph3.addnode(1);
	graph3.addnode(2);
	graph3.addnode(3);
	graph3.addArc(1, 2);
	graph3.addArc(2, 3);
	graph3.addArc(3, 1);
	/*Graph<int>::Arc_Iterator it3(graph3);
	do {
		cout << it3.get_first() << "->" << it3.get_second() << endl;
	} while (it3.next());
	cout << graph3.getarc()<<endl;
	it3.Del();*/
	/*cout << graph3.getarc()<<endl;
	Graph<int> gr;
	if (gr.isGEmpty())
		cout << "graph is empty" << endl;
	gr.addnode(1);
	gr.addnode(2);
	if (gr.isNodeinGraph(3))
		cout << "3 isn't in the graph"<<endl;
	if (gr.isNodeinGraph(2))
		cout << "2 is in the graph" << endl;
	if (gr.isGEmpty())
		cout << "error" << endl;
	if (!gr.isGEmpty())
		cout << "graph isn't empty" << endl;

	if (!gr.isArcinGraph(1,2))
		cout << "1->2 isn't in the graph" << endl;
	gr.addArc(1,2);
	if (gr.isArcinGraph(1,2))
		cout << "1->2 is in the graph" << endl;
	if (gr.isArcinGraph(2,1))
		cout << "error" << endl;

	gr.addArc(2,1);
	if (gr.isArcinGraph(2,1))
		cout << "2->1 is in the graph" << endl;
	gr.delArc(2,1);
	if (gr.isArcinGraph(2,1))
		cout << " error" << endl;
	cout << "V=" << gr.getnodes() << endl;;
	cout << "G=" << gr.getarc() << endl;;
	cout << "node power 1 =" << gr.getNodePower(1) << endl;;
	cout << "arc power 1-2 =" << gr.getArcPower(1,2) << endl;;
	cout << "arc power 1-5 =" << gr.getArcPower(1, 5) << endl;;
	gr.addnode(5);
	gr.addArc(1,5);
	cout << "arc power 1-5 =" << gr.getArcPower(1, 5) << endl;;
	gr.delNode(5);
	cout << "arc power 1-5 =" << gr.getArcPower(1, 5) << endl;;
	cout << "V=" << gr.getnodes() << endl;;
	cout << "G=" << gr.getarc() << endl;;*/
	return 0;
}
