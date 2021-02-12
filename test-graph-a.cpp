#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include "graph-a.h"

using namespace std;

int main() {
	graph <> Graph1;
	graph <graph_matrix> Graph2;
	graph <graph_adjacent> Graph3;
	int i, j, tmp_start, tmp_end;
	float tmp_value;
	vector <int> neighbour;
	vector <int> vertex;
	vector <int> new_vertex;
	vector <int> output;
	graph <> core_graph1;
	graph <graph_matrix> core_graph2;
	graph <graph_adjacent> core_graph3;
	vector <vector <float> > GG;
	vector <int> tmp_vertex;
	vector <trio> seq;
	vector <trio> new_seq;
	
	srand(time(NULL));

	cout<<"----------------"<<endl<<"filling in the graph:"<<endl;
	for(i = 0; i < 20; i++){
		tmp_start = rand()%10;
		tmp_end = rand()%10;
		tmp_value = rand()%4;
		cout<<"try add rib ("<<tmp_start<<", "<<tmp_end<<", "<<tmp_value<<")"<<endl;
		if (Graph1.G.add(tmp_start, tmp_end, tmp_value)){
			cout<<"successful adding to edge_list rib ("<<tmp_start<<", "<<tmp_end<<", "<<tmp_value<<")"<<endl;
		}
		if (Graph2.G.add(tmp_start, tmp_end, tmp_value)){
			cout<<"successful adding to matrix rib ("<<tmp_start<<", "<<tmp_end<<", "<<tmp_value<<")"<<endl;
		}
		if (Graph3.G.add(tmp_start, tmp_end, tmp_value)){
			cout<<"successful adding to adjacent_list rib ("<<tmp_start<<", "<<tmp_end<<", "<<tmp_value<<")"<<endl;
		}

		tmp_value = Graph1.G.find(tmp_start, tmp_end);
		cout<<"find edge_list rib ("<<tmp_start<<", "<<tmp_end<<", "<<tmp_value<<")"<<endl;
		tmp_value = Graph2.G.find(tmp_start, tmp_end);
		cout<<"find matrix rib ("<<tmp_start<<", "<<tmp_end<<", "<<tmp_value<<")"<<endl;
		tmp_value = Graph3.G.find(tmp_start, tmp_end);
		cout<<"find adjacent_list rib ("<<tmp_start<<", "<<tmp_end<<", "<<tmp_value<<")"<<endl;

	}
	cout<<"---------------------"<<endl;

	cout<<"try to delete rib ("<<tmp_start<<", "<<tmp_end<<")"<<endl;
	if (Graph1.G.delete_rib(tmp_start, tmp_end)){
		cout<<"successful deleting edge_list rib ("<<tmp_start<<", "<<tmp_end<<")"<<endl;
	}
	if (Graph2.G.delete_rib(tmp_start, tmp_end)){
		cout<<"successful deleting matrix rib ("<<tmp_start<<", "<<tmp_end<<")"<<endl;
	}
	if (Graph3.G.delete_rib(tmp_start, tmp_end)){
		cout<<"successful deleting adjacent_list rib ("<<tmp_start<<", "<<tmp_end<<")"<<endl;
	}

	cout<<"---------------------"<<endl;

	cout<<"edge_list graph:"<<endl; 

	Graph1.G.uniq_vertex(vertex);
	cout<<"unique vertex: "<<vertex[0];
	for (i = 1; i < vertex.size(); i++){
		cout<<", "<<vertex[i];
	}
	cout<<endl;

	for (i = 0; i < vertex.size(); i++){
		Graph1.G.find_neighbour(vertex[i], neighbour);
		
		cout<<"vertex "<<vertex[i]<<" neighbour: ";
		if (neighbour.size() > 0){
			cout<<neighbour[0];
			for (j = 1; j < neighbour.size(); j++){
				cout<<", "<<neighbour[j];
			}
		}
		cout<<endl;
	}
	cout<<"---------------------"<<endl;
	
	cout<<"matrix graph:"<<endl; 
	
	Graph2.G.uniq_vertex(vertex);
	cout<<"unique vertex: "<<vertex[0];
	for (i = 1; i < vertex.size(); i++){
		cout<<", "<<vertex[i];
	}
	cout<<endl;
	
	for (i = 0; i < vertex.size(); i++){
		Graph2.G.find_neighbour(vertex[i], neighbour);
		
		cout<<"vertex "<<vertex[i]<<" neighbour: ";
		if (neighbour.size() > 0){
			cout<<neighbour[0];
			for (j = 1; j < neighbour.size(); j++){
				cout<<", "<<neighbour[j];
			}
		}
		cout<<endl;
	}
	cout<<"---------------------"<<endl;
	
	cout<<"adjacent_list graph:"<<endl; 

	Graph3.G.uniq_vertex(vertex);
	cout<<"unique vertex: "<<vertex[0];
	for (i = 1; i < vertex.size(); i++){
		cout<<", "<<vertex[i];
	}
	cout<<endl;

	for (i = 0; i < vertex.size(); i++){
		Graph3.G.find_neighbour(vertex[i], neighbour);
		
		cout<<"vertex "<<vertex[i]<<" neighbour: ";
		if (neighbour.size() > 0){
			cout<<neighbour[0];
			for (j = 1; j < neighbour.size(); j++){
				cout<<", "<<neighbour[j];
			}
		}
		cout<<endl;
	}
	cout<<"---------------------"<<endl;

	cout<<"DFS:"<<endl;

	cout<<"edge_list graph output for "<<vertex[0]<<" : ";
	Graph1.DFS(vertex[0], output);
	if (output.size() > 0){
		cout<<output[0];
		for (j = 1; j < output.size(); j++){
			cout<<", "<<output[j];
		}
	}
	cout<<endl;

	cout<<"matrix graph output for "<<vertex[0]<<" : ";
	Graph2.DFS(vertex[0], output);
	if (output.size() > 0){
		cout<<output[0];
		for (j = 1; j < output.size(); j++){
			cout<<", "<<output[j];
		}
	}
	cout<<endl;

	cout<<"adjacent_list graph output for "<<vertex[0]<<" : ";
	Graph3.DFS(vertex[0], output);
	if (output.size() > 0){
		cout<<output[0];
		for (j = 1; j < output.size(); j++){
			cout<<", "<<output[j];
		}
	}
	cout<<endl;

cout<<"---------------------"<<endl;

	cout<<"BFS:"<<endl;

	cout<<"edge_list graph output for "<<vertex[0]<<" : ";
	Graph1.BFS(vertex[0], output);
	if (output.size() > 0){
		cout<<output[0];
		for (j = 1; j < output.size(); j++){
			cout<<", "<<output[j];
		}
	}
	cout<<endl;

	cout<<"matrix graph output for "<<vertex[0]<<" : ";
	Graph2.BFS(vertex[0], output);
	if (output.size() > 0){
		cout<<output[0];
		for (j = 1; j < output.size(); j++){
			cout<<", "<<output[j];
		}
	}
	cout<<endl;

	cout<<"adjacent_list graph output for "<<vertex[0]<<" : ";
	Graph3.BFS(vertex[0], output);
	if (output.size() > 0){
		cout<<output[0];
		for (j = 1; j < output.size(); j++){
			cout<<", "<<output[j];
		}
	}
	cout<<endl;

	cout<<"---------------------"<<endl;

	cout<<"deikstra for ("<<vertex[0]<<", "<<vertex[vertex.size()-1]<<"):"<<endl;

	cout<<"edge_list: "<<Graph1.deikstra(vertex[0], vertex[vertex.size()-1])<<endl;
	cout<<"matrix: "<<Graph2.deikstra(vertex[0], vertex[vertex.size()-1])<<endl;
	cout<<"adjacent_list: "<<Graph3.deikstra(vertex[0], vertex[vertex.size()-1])<<endl;

	cout<<"---------------------"<<endl;

	cout<<"recurrence check:"<<endl;
	
	if (Graph1.recurrence()){
		cout<<"edge_list graph hasn't recurrence"<<endl;
	} else {
		cout<<"edge_list graph has recurrence"<<endl;
	}
	if (Graph2.recurrence()){
		cout<<"matrix graph hasn't recurrence"<<endl;
	} else {
		cout<<"matrix graph has recurrence"<<endl;
	}
	if (Graph1.recurrence()){
		cout<<"adjacent_list graph hasn't recurrence"<<endl;
	} else {
		cout<<"adjacent_list graph has recurrence"<<endl;
	}

	cout<<"---------------------"<<endl;

	cout<<"kraskal:"<<endl;

	Graph1.G.rib_sequence(seq);
	
	core_graph1.kraskal(&Graph1);
	cout<<"edge_list:"<<endl;
	cout<<"    regular graph: amount of vertex - "<<vertex.size()<<endl;
	cout<<"    regular graph: amount of ribs - "<<seq.size()<<endl;
	core_graph1.G.uniq_vertex(new_vertex);
	core_graph1.G.rib_sequence(new_seq);
	cout<<"    core graph: amount of vertex - "<<new_vertex.size()<<endl;	
	cout<<"    core graph: amount of ribs - "<<new_seq.size()<<endl;
	if (core_graph1.recurrence()){
		cout<<"edge_list core graph hasn't recurrence"<<endl<<endl;
	} else {
		cout<<"edge_list core graph has recurrence"<<endl<<endl;
	}


	core_graph2.kraskal(&Graph2);
	cout<<"matrix:"<<endl;
	cout<<"    regular graph: amount of vertex - "<<vertex.size()<<endl;
	cout<<"    regular graph: amount of ribs - "<<seq.size()<<endl;
	core_graph2.G.uniq_vertex(new_vertex);
	core_graph2.G.rib_sequence(new_seq);
	cout<<"    core graph: amount of vertex - "<<new_vertex.size()<<endl;	
	cout<<"    core graph: amount of ribs - "<<new_seq.size()<<endl;
	if (core_graph2.recurrence()){
		cout<<"matrix core graph hasn't recurrence"<<endl<<endl;
	} else {
		cout<<"matrix core graph has recurrence"<<endl<<endl;
	}

	core_graph3.kraskal(&Graph3);
	cout<<"adjacent_list:"<<endl;
	cout<<"    regular graph: amount of vertex - "<<vertex.size()<<endl;
	cout<<"    regular graph: amount of ribs - "<<seq.size()<<endl;
	core_graph3.G.uniq_vertex(new_vertex);
	core_graph3.G.rib_sequence(new_seq);
	cout<<"    core graph: amount of vertex - "<<new_vertex.size()<<endl;	
	cout<<"    core graph: amount of ribs - "<<new_seq.size()<<endl;
	if (core_graph3.recurrence()){
		cout<<"adjacent_list core graph hasn't recurrence"<<endl<<endl;
	} else {
		cout<<"adjacent_list core graph has recurrence"<<endl<<endl;
	}

	cout<<"---------------------"<<endl;
	

	cout<<"prim:"<<endl;
	
	core_graph1.prim(&Graph1);
	cout<<"edge_list:"<<endl;
	cout<<"    regular graph: amount of vertex - "<<vertex.size()<<endl;
	cout<<"    regular graph: amount of ribs - "<<seq.size()<<endl;
	core_graph1.G.uniq_vertex(new_vertex);
	core_graph1.G.rib_sequence(new_seq);
	cout<<"    core graph: amount of vertex - "<<new_vertex.size()<<endl;	
	cout<<"    core graph: amount of ribs - "<<new_seq.size()<<endl;
	if (core_graph1.recurrence()){
		cout<<"edge_list core graph hasn't recurrence"<<endl<<endl;
	} else {
		cout<<"edge_list core graph has recurrence"<<endl<<endl;
	}


	core_graph2.prim(&Graph2);
	cout<<"matrix:"<<endl;
	cout<<"    regular graph: amount of vertex - "<<vertex.size()<<endl;
	cout<<"    regular graph: amount of ribs - "<<seq.size()<<endl;
	core_graph2.G.uniq_vertex(new_vertex);
	core_graph2.G.rib_sequence(new_seq);
	cout<<"    core graph: amount of vertex - "<<new_vertex.size()<<endl;	
	cout<<"    core graph: amount of ribs - "<<new_seq.size()<<endl;
	if (core_graph2.recurrence()){
		cout<<"matrix core graph hasn't recurrence"<<endl<<endl;
	} else {
		cout<<"matrix core graph has recurrence"<<endl<<endl;
	}

	core_graph3.prim(&Graph3);
	cout<<"adjacent_list:"<<endl;
	cout<<"    regular graph: amount of vertex - "<<vertex.size()<<endl;
	cout<<"    regular graph: amount of ribs - "<<seq.size()<<endl;
	core_graph3.G.uniq_vertex(new_vertex);
	core_graph3.G.rib_sequence(new_seq);
	cout<<"    core graph: amount of vertex - "<<new_vertex.size()<<endl;	
	cout<<"    core graph: amount of ribs - "<<new_seq.size()<<endl;
	if (core_graph3.recurrence()){
		cout<<"adjacent_list core graph hasn't recurrence"<<endl<<endl;
	} else {
		cout<<"adjacent_list core graph has recurrence"<<endl<<endl;
	}

	cout<<"---------------------"<<endl;

	cout<<"floyd-warshall for (0, 9):"<<endl<<endl;


	cout<<"edge_list core graph:"<<endl; 

	core_graph1.G.uniq_vertex(tmp_vertex);
	cout<<"unique vertex: "<<tmp_vertex[0];
	for (i = 1; i < tmp_vertex.size(); i++){
		cout<<", "<<tmp_vertex[i];
	}
	cout<<endl;

	for (i = 0; i < tmp_vertex.size(); i++){
		core_graph1.G.find_neighbour(tmp_vertex[i], neighbour);
		
		cout<<"vertex "<<tmp_vertex[i]<<" neighbour: ";
		if (neighbour.size() > 0){
			cout<<neighbour[0];
			for (j = 1; j < neighbour.size(); j++){
				cout<<", "<<neighbour[j];
			}
		}
		cout<<endl;
	}

	cout<<endl;

	cout<<"matrix core graph:"<<endl; 

	core_graph2.G.uniq_vertex(tmp_vertex);
	cout<<"unique vertex: "<<tmp_vertex[0];
	for (i = 1; i < tmp_vertex.size(); i++){
		cout<<", "<<tmp_vertex[i];
	}
	cout<<endl;

	for (i = 0; i < tmp_vertex.size(); i++){
		core_graph2.G.find_neighbour(tmp_vertex[i], neighbour);
		
		cout<<"vertex "<<tmp_vertex[i]<<" neighbour: ";
		if (neighbour.size() > 0){
			cout<<neighbour[0];
			for (j = 1; j < neighbour.size(); j++){
				cout<<", "<<neighbour[j];
			}
		}
		cout<<endl;
	}

	cout<<endl;

	cout<<"adjacent_list core graph:"<<endl; 

	core_graph3.G.uniq_vertex(tmp_vertex);
	cout<<"unique vertex: "<<tmp_vertex[0];
	for (i = 1; i < tmp_vertex.size(); i++){
		cout<<", "<<tmp_vertex[i];
	}
	cout<<endl;

	for (i = 0; i < tmp_vertex.size(); i++){
		core_graph3.G.find_neighbour(tmp_vertex[i], neighbour);
		
		cout<<"vertex "<<tmp_vertex[i]<<" neighbour: ";
		if (neighbour.size() > 0){
			cout<<neighbour[0];
			for (j = 1; j < neighbour.size(); j++){
				cout<<", "<<neighbour[j];
			}
		}
		cout<<endl;
	}

	cout<<endl;

	core_graph1.floyd_warshall(GG);
	cout<<"edge_list: "<<GG[vertex[0]][vertex[vertex.size()-1]]<<endl;
	core_graph2.floyd_warshall(GG);
	cout<<"matrix: "<<GG[vertex[0]][vertex[vertex.size()-1]]<<endl;
	core_graph3.floyd_warshall(GG);
	cout<<"adjacent_list: "<<GG[vertex[0]][vertex[vertex.size()-1]]<<endl;

	cout<<"---------------------"<<endl;

	return 0;
}
