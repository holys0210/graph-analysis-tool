#include "graph.h"

namespace snu {

	Graph::Graph() {}

	/* destructor */
	Graph::~Graph() {
		// delete vertex, edge, vertex_label, edge_label;
		for(auto it = id_to_vertex.begin(); it != id_to_vertex.end(); it++) delete it->second;
		for(auto it = id_to_edge.begin(); it != id_to_edge.end(); it++) delete it->second;
		for(auto it = vlabel_to_class.begin(); it != vlabel_to_class.end(); it++) delete it->second;
		for(auto it = elabel_to_class.begin(); it != elabel_to_class.end(); it++) delete it->second;
	}

	/* do not have to define destructor of child classes */

	/* array version */
	int Graph::add_vertex(Vid id, unsigned int num, Vlabel lbl[]) {
		if(id_to_vertex.count(id)) return 1; // error: graph already has a vertex having same id

		Vertex *v = new Vertex(); // create vertex class
		id_to_vertex[id] = v;
		v->id = id; // set id
		// set labels
		// if no vertex label class then create it
		for(unsigned int i = 0; i < num; i++) {
			auto it = vlabel_to_class.find(lbl[i]);
			Label_of_Vertices *vl;

			if(it == vlabel_to_class.end()) { // no vertex label class
				vl = new Label_of_Vertices();
				vlabel_to_class[lbl[i]] = vl;
				vl->label = lbl[i];
			}
			else vl = it->second;
			
			vl->vertices.push_back(v);
			v->labels.push_back(vl);
		}

		return 0;
	}

	/* vector version */
	int Graph::add_vertex(Vid id, std::vector <Vlabel> *lbl) {
		return add_vertex(id, lbl->size(), lbl->data());
	}

	/* base add_edge function, DSGraph version */
	int Graph::add_edge(Eid id, unsigned int num, Elabel lbl[], Vid from, Vid to, Weight wgt) {
		if(id_to_edge.count(id) || !id_to_vertex.count(from) || !id_to_vertex.count(to))
			return 1;
		// error: already have edge having same id or no from or to vertex

		Edge *e = new Edge(); // create edge class
		id_to_edge[id] = e;
		e->id = id; // set id
		// set edge labels
		// if no edge label class then create it
		for(unsigned int i = 0; i < num; i++) {
			auto it = elabel_to_class.find(lbl[i]);
			Label_of_Edges *el;

			if(it == elabel_to_class.end()) { // no edge label class
				el = new Label_of_Edges();
				elabel_to_class[lbl[i]] = el;
				el->label = lbl[i];
			}
			else el = it->second;

			el->edges.push_back(e);
			e->labels.push_back(el);
		}
		e->from = id_to_vertex[from]; // set from
		e->to = id_to_vertex[to]; // set to
		e->to->indegree++; // increase indegree
		e->wgt = wgt; // set weight
		e->from->edges.push_back(e); // insert edge in from vertex
		
		is_connected.insert(std::make_pair(from, to)); // insert vertex pair

		if(wgt < 0) negative_edge_num++;

		return 0;
	}

	/* array version */
	int DSGraph::add_edge(Eid id, unsigned int num, Elabel lbl[], Vid from, Vid to, Weight wgt) {
		if(Graph::add_edge(id, num, lbl, from, to, wgt)) return 1; // there is error

		return 0;
	}

	/* vector version */
	int DSGraph::add_edge(Eid id, std::vector <Elabel> *lbl, Vid from, Vid to, Weight wgt) {
		return add_edge(id, lbl->size(), lbl->data(), from, to, wgt);
	}

	/* array version */
	int USGraph::add_edge(Eid id, unsigned int num, Elabel lbl[], Vid from, Vid to, Weight wgt) {
		if(Graph::add_edge(id, num, lbl, from, to, wgt)) return 1; // there is error

		Edge *e = id_to_edge[id];
		e->to->edges.push_back(e); // insert edge in to vertex
		e->from->indegree++; // increase indegree of from
		is_connected.insert(std::make_pair(to, from)); // insert reverse
		// be careful of switching from and to in this case

		return 0;
	}

	/* vector version */
	int USGraph::add_edge(Eid id, std::vector <Elabel> *lbl, Vid from, Vid to, Weight wgt) {
		return add_edge(id, lbl->size(), lbl->data(), from, to, wgt);
	}
}
