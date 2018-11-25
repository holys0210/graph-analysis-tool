#include "makeplot.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <Python.h>
#define MAX_BUF 100

namespace snu {

	void make_plot(DSGraph *graph, Plot *plot) {
		std::ofstream out;

		/* label-vertex */
		out.open("./pyplot/label-vertex.txt");

		unsigned int n = graph->id_to_vertex.size();
		typedef std::pair <std::string *, unsigned int> label_vertex;
		std::vector <label_vertex> lv;
		lv.reserve(n);
		for(auto it = graph->vlabel_to_class.begin(); it != graph->vlabel_to_class.end(); it++) {
			auto vlabel = it->second;
			lv.push_back(make_pair(&(vlabel->label), vlabel->vertices.size()));
		}

		std::sort(lv.begin(), lv.end(), [](label_vertex a, label_vertex b) { return a.second > b.second; });

		for(auto it = lv.begin(); it != lv.end(); it++)
			out << *(it->first) << " " << it->second << std::endl;

		out.close();

		/* indegree */
		out.open("./pyplot/indegree.txt");

		std::vector <unsigned int> degree;
		degree.reserve(n);
		for(auto it = graph->id_to_vertex.begin(); it != graph->id_to_vertex.end(); it++)
			degree.push_back((*it->second).indegree);
		
		std::sort(degree.begin(), degree.end());
		for(auto it = degree.begin(); it != degree.end(); it++)
			out << *it << " ";

		out.close();

		/* outdegree */
		out.open("./pyplot/outdegree.txt");

		degree.clear();
		degree.reserve(n);
		for(auto it = graph->id_to_vertex.begin(); it != graph->id_to_vertex.end(); it++)
			degree.push_back((*it->second).edges.size());
		
		std::sort(degree.begin(), degree.end());
		for(auto it = degree.begin(); it != degree.end(); it++)
			out << *it << " ";

		out.close();

		/* pyplot */
		FILE *fp = fopen("ploy.py", "r");
		if(fp == NULL) return; // error

		char buf[MAX_BUF];

		Py_Initialize();
		if(Py_IsInitialized()) {
			while(fgets(buf, MAX_BUF, fp)) {
				sprintf(buf, buf, *plot);
				PyRun_SimpleString(buf);
			}
			Py_Finalize();
		}

		fclose(fp);
	}

	void make_plot(USGraph *graph, Plot *plot) {
		std::ofstream out;

		/* label-vertex */
		out.open("./pyplot/label-vertex.txt");

		unsigned int n = graph->id_to_vertex.size();
		typedef std::pair <std::string *, unsigned int> label_vertex;
		std::vector <label_vertex> lv;
		lv.reserve(n);
		for(auto it = graph->vlabel_to_class.begin(); it != graph->vlabel_to_class.end(); it++) {
			auto vlabel = it->second;
			lv.push_back(make_pair(&(vlabel->label), vlabel->vertices.size()));
		}

		std::sort(lv.begin(), lv.end(), [](label_vertex a, label_vertex b) { return a.second > b.second; });

		for(auto it = lv.begin(); it != lv.end(); it++)
			out << *(it->first) << " " << it->second << std::endl;

		out.close();

		/* degree */
		out.open("./pyplot/degree.txt");

		std::vector <unsigned int> degree;
		degree.reserve(n);
		for(auto it = graph->id_to_vertex.begin(); it != graph->id_to_vertex.end(); it++)
			degree.push_back((*it->second).indegree);
		
		std::sort(degree.begin(), degree.end());
		for(auto it = degree.begin(); it != degree.end(); it++)
			out << *it << " ";

		out.close();

		/* pyplot */
		FILE *fp = fopen("ploy.py", "r");
		if(fp == NULL) return; // error

		char buf[MAX_BUF];

		Py_Initialize();
		if(Py_IsInitialized()) {
			while(fgets(buf, MAX_BUF, fp)) {
				sprintf(buf, buf, *plot);
				PyRun_SimpleString(buf);
			}
			Py_Finalize();
		}

		fclose(fp);
	}
}
