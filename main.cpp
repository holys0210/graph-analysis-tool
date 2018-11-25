#include <stdio.h>
#include "snugal.h"

int main(int argc, char *argv[]) {

	// test library
	snu::DSGraph *graph1 = snu::parse_DSGraph("data/example.snu");
	//snu::DSGraph *graph2 = snu::parse_DSGraph("data/com-dblp_label.snu");
	//snu::DSGraph *graph3 = snu::parse_DSGraph("data/web-Google_label.snu");
	//snu::DSGraph *graph4 = snu::parse_DSGraph("data/as-skitter_label.snu");

	snu::DSResult result1, result2, result3, result4;
	snu::Plot plot1, plot2, plot3, plot4;

	snu::init_stat(&result1);
	snu::basic_stat(graph1, &result1);
	snu::count_stat(graph1, &result1);
	snu::init_plot(&plot1);
	snu::make_plot(graph1, &plot1);
	snu::make_html("graph1", &result1, &plot1);
	delete graph1;

/*
	snu::init_stat(&result2);
	snu::basic_stat(graph2, &result2);
	snu::count_stat(graph2, &result2);
	snu::init_plot(&plot2);
	snu::make_plot(graph2, &plot2);
	snu::make_html("graph2", &result1, &plot2);
	delete graph2;

	snu::init_stat(&result3);
	snu::basic_stat(graph3, &result3);
	snu::count_stat(graph3, &result3);
	snu::init_plot(&plot3);
	snu::make_plot(graph3, &plot3);
	snu::make_html("graph3", &result1, &plot3);
	delete graph3;

	snu::init_stat(&result4);
	snu::basic_stat(graph4, &result4);
	snu::count_stat(graph4, &result4);
	snu::init_plot(&plot4);
	snu::make_plot(graph4, &plot4);
	snu::make_html("graph4", &result1, &plot4);
	delete graph4;
*/
	return 0;
}
