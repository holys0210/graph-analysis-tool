#ifndef STAT_H
#define STAT_H

namespace snu {

	struct DSResult {
		/* basic_stat */
		unsigned int size; // number of vertices
		unsigned int volume; // number of edges
		double avg_degree; // not defined well but calculate it as m / n
		double fill; // m / n^2, directed graph with loops
		unsigned int max_indegree; // maximum indegree
		unsigned int max_outdegree; // maximum outdegree
		double reciprocity; // only defined in directed graph
		double negativity;
		unsigned int lcc; // largest connected component
		//unsigned int diameter; // diameter of graph

		/* count_stat */
		// unsigned long long four_tour_count;

		/* stat check */
		bool basicstat;
		bool countstat;
	};

	struct USResult {
		/* basic_stat */
		unsigned int size;
		unsigned int volume;
		double avg_degree; // average degree, 2m / n
		double fill; // 2m / (N * (N + 1)), undirected graph with loops
		unsigned int max_degree; // maximum degree
		double negativity;
		unsigned int lcc;
		//unsigned int diameter;

		/* count_stat */
		unsigned long long wedge_count;
		unsigned long long claw_count;
		//unsigned long long triangle_count;
		//unsigned long long square_count;
		//unsigned long long four_tour_count;

		/* stat check */
		bool basicstat;
		bool countstat;
	};

	typedef struct DSResult DSresult;
	typedef struct USResult USresult;

	void init_stat(DSResult *result);
	void init_stat(USResult *result);
}

#endif // STAT_H