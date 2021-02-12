#ifndef GRAPHAH
#define GRAPHAH
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

class trio{
	private:
		int start;
		int end;
		float value;

	public:

		int get_start();

		int get_end();

		float get_value();

		void set_value(float Value);
		
		trio& operator= (trio T);

		trio(){}

		trio(int Start, int End, float Value){
			start = Start;
			end = End;
			value = Value;
		}
};


class graph_edge_list{
	public:
		vector <trio> G;

		bool delete_rib(int Start, int End);

		void rib_sequence(vector <trio>& seq);

		void uniq_vertex(vector <int>& vertex);

		void find_neighbour(int g, vector <int>& neighbour);

		float find(int Start, int End);

		bool add(int Start, int End, float Value = 1); 

		graph_edge_list(){}

		~graph_edge_list(){}
};


class graph_matrix{
	public:
		vector <vector <float> > G;
		
		bool delete_rib(int Start, int End);

		void rib_sequence(vector <trio>& seq);

		void uniq_vertex(vector <int>& vertex);

		void find_neighbour(int g, vector <int>& neighbour);

		float find(int Start, int End);

		bool add(int Start, int End, float Value = 1); 

		graph_matrix(){}

		~graph_matrix(){}
};


class graph_adjacent{
	public:
		vector <vector <pair <int, float> > > G;
		
		bool delete_rib(int Start, int End);

		void rib_sequence(vector <trio>& seq);

		void uniq_vertex(vector <int>& vertex);

		void find_neighbour(int g, vector <int>& neighbour);

		float find(int Start, int End);

		bool add(int Start, int End, float Value = 1);

		graph_adjacent(){}

		~graph_adjacent(){}
};


template <typename Graph = graph_edge_list >
class graph{
	private:
		bool temp_recurrence(int cur_vertex, int parent, vector <bool>& visited);

		void temp_deikstra(int cur_vertex, vector <float>& val, vector <bool>& visited, vector <int>& vertex);

		void temp_DFS(int cur_vertex, vector <bool>& visited, vector <int>& output);

		void temp_BFS(int cur_vertex, vector <bool>& gray, vector <bool>& black, vector <int>& output);

		void tmp_prim(vector <trio>& seq, vector <int>& G_vertex, trio& output, vector <int>& GG_vertex);

	public:
		Graph G;

		void floyd_warshall(vector <vector <float> >& GG);

		void prim(graph *GG);

		void kraskal(graph *GG);

		bool recurrence();

		float deikstra (int Start, int End);

		void DFS(int cur_vertex, vector <int>& output);

		void BFS(int cur_vertex, vector <int>& output);

		graph(){}

		~graph(){}
};


int trio::get_start(){
	return start;
}

int trio::get_end(){
	return end;
}
		
float trio::get_value(){
	return value;
}

void trio::set_value(float Value){
	value = Value;
}
		
trio& trio::operator= (trio T){
	if (this == &T){
		return *this;
	}
	start = T.get_start();
	end = T.get_end();
	value = T.get_value();
	return *this;
}


bool graph_edge_list::delete_rib(int Start, int End){
	for (auto i = G.begin(); i < G.end(); i++){
		if ((((*i).get_start() == Start)&&((*i).get_end() == End))||(((*i).get_start() == End)&&((*i).get_end() == Start))){
			G.erase(i);
			return true;
		}
	}
	return false;
}

void graph_edge_list::rib_sequence(vector <trio>& seq){
	int i, old_size;

	old_size = seq.size();
	for (i = 0; i < old_size; i++){
		seq.pop_back();
	}	

	for (i = 0; i < G.size(); i++){
		seq.push_back(G[i]);
	}
	sort(seq.begin(), seq.end(), [&](trio a, trio b){return (a.get_value() < b.get_value());});
}

void graph_edge_list::uniq_vertex(vector <int>& vertex){
	int i, j;
	int old_size = vertex.size();
	
	for (i = 0; i < old_size; i++){
		vertex.pop_back();
	}
	for (i = 0; i < G.size(); i++){
		for (j = 0; j < vertex.size(); j++){
			if (G[i].get_start() == vertex[j]){
				break;
			}
		}
		if (j == vertex.size()){
			vertex.push_back(G[i].get_start());
		}
	}
	for (i = 0; i < G.size(); i++){
		for (j = 0; j < vertex.size(); j++){
			if (G[i].get_end() == vertex[j]){
				break;
			}
		}
		if (j == vertex.size()){
			vertex.push_back(G[i].get_end());
		}
	}
	sort(vertex.begin(), vertex.end());
}

void graph_edge_list::find_neighbour(int g, vector <int>& neighbour){
	int i;
	int old_size = neighbour.size();
	for (i = 0; i < old_size; i++){
		neighbour.pop_back();
	}
	for (i = 0; i < G.size(); i++){
		if (G[i].get_start() == g){
			neighbour.push_back(G[i].get_end());
		}
		if (G[i].get_end() == g){
			neighbour.push_back(G[i].get_start());
		}
	}
	sort(neighbour.begin(), neighbour.end());
}

float graph_edge_list::find(int Start, int End){
	auto it {find_if(G.begin(), G.end(), [&](trio p){return ((p.get_start() == Start)&&(p.get_end() == End))||((p.get_start() == End)&&(p.get_end() == Start));} )};
	if (it != G.end()){
		float val = (*it).get_value();
		return val;
	} else {
		return 0;
	}
}

bool graph_edge_list::add(int Start, int End, float Value) {
	if ((Value > 0)&&(Start != End)&&(find(Start, End) == 0)){
		G.push_back(trio(Start, End, Value));
	} else {
		return false;
	}
	return true;
}


bool graph_matrix::delete_rib(int Start, int End){
	if (G[Start][End] != 0){
		G[Start][End] = 0;
		G[End][Start] = 0;
		return true;
	} else {
		return false;
	}
}

void graph_matrix::rib_sequence(vector <trio>& seq){
	int i, j, old_size;
	
	old_size = seq.size();
	for (i = 0; i < old_size; i++){
		seq.pop_back();
	}

	for (int i = 0; i < G.size(); i++){
		for (int j = i+1; j < G[i].size(); j++){
			if (G[i][j] != 0){
				seq.push_back(trio(i,j,G[i][j]));
			}
		}
	}
	sort(seq.begin(), seq.end(), [&](trio a, trio b){return (a.get_value() < b.get_value());});
}

void graph_matrix::uniq_vertex(vector <int>& vertex){
	int i, j;
	int old_size = vertex.size();
	
	for (i = 0; i < old_size; i++){
		vertex.pop_back();
	}
	for (i = 0; i < G.size(); i++){
		for (j = 0; j <G[i].size(); j++){
			if (G[i][j] != 0 ){
				vertex.push_back(i);
				break;
			}
		}
	}
	sort(vertex.begin(), vertex.end());
}

void graph_matrix::find_neighbour(int g, vector <int>& neighbour){
	int i;
	int old_size = neighbour.size();
	if (g > G.size()){
		return;
	}

	for (i = 0; i < old_size; i++){
		neighbour.pop_back();
	}

	for (i = 0; i < G[g].size(); i++){
		if (G[g][i] != 0){
			neighbour.push_back(i);
		}
	}
	sort(neighbour.begin(), neighbour.end());
}

float graph_matrix::find(int Start, int End){
	if ((Start <= G.size())&&(End <= G.size())){
		return G[Start][End];
	} else {
		return 0;
	}
}

bool graph_matrix::add(int Start, int End, float Value) {
	int i;

	if (G.size() <= Start){
		G.resize(Start+1);
		for (i = 0; i < G.size(); i++){
			G[i].resize(Start+1);
		}
	}

	if (G.size() <= End){
		G.resize(End+1);
		for (i = 0; i < G.size(); i++){
			G[i].resize(End+1);
		}
	}

	if ((G[Start][End] != 0)||(Value <= 0)||(Start == End)){
		return false;
	}

	G[Start][End] = Value;
	G[End][Start] = Value;

	return true;
}


bool graph_adjacent::delete_rib(int Start, int End){
	int i, old_size;
	if (find(Start, End) > 0){
		old_size = G[Start].size();
		for (i = 0; i < old_size; i++){
			if (G[Start][i].first == End){
				G[Start].erase(G[Start].begin()+i);
				break;
			}
		}
		if (i == old_size){
			return false;
		}
		for (i = 0; i < G[End].size(); i++){
			if (G[End][i].first == Start){
				G[End].erase(G[End].begin()+i);
				break;
			}
		}
		return true;
	} else {
		return false;
	}
}

void graph_adjacent::rib_sequence(vector <trio>& seq){
	int i, old_size;

	old_size = seq.size();
	for (i = 0; i < old_size; i++){
		seq.pop_back();
	}
	
	for (i = 0; i < G.size(); i++){
		for (auto j = G[i].begin(); j < G[i].end(); j++){
			if ((*j).first > i){
				seq.push_back(trio(i,(*j).first,(*j).second));
			}
		}
	}
	sort(seq.begin(), seq.end(), [&](trio a, trio b){return (a.get_value() < b.get_value());});
}

void graph_adjacent::uniq_vertex(vector <int>& vertex){
	int i, j;
	int old_size = vertex.size();
	
	for (i = 0; i < old_size; i++){
		vertex.pop_back();
	}
	for (i = 0; i < G.size(); i++){
		if (G[i].size() != 0){
			vertex.push_back(i);
		}
	}
	sort(vertex.begin(), vertex.end());
}

void graph_adjacent::find_neighbour(int g, vector <int>& neighbour){
	int i;
	int old_size = neighbour.size();
	if (g > G.size()){
		return;
	}
	for (i = 0; i < old_size; i++){
		neighbour.pop_back();
	}

	for (i = 0; i < G[g].size(); i++){
		neighbour.push_back(G[g][i].first);
	}
	sort(neighbour.begin(), neighbour.end());
}

float graph_adjacent::find(int Start, int End){
	int i;
	if (Start <= G.size()){
		int old_size = G[Start].size();
		for (i = 0; i < old_size; i++){
			if (G[Start][i].first == End){
				return G[Start][i].second;
			}
		}
	}
	return 0;
}

bool graph_adjacent::add(int Start, int End, float Value) {
	int i;

	if (G.size() <= Start){
		G.resize(Start+1);
	}
	
	if (G.size() <= End){
		G.resize(End+1);
	}


	if ((Value <= 0)||(Start == End)){
		return false;
	}

	for (i = 0; i < G[Start].size(); i++){
		if (G[Start][i].first == End){
			return false;
		}
	}
	
	G[Start].push_back(pair<int, float>(End, Value));
	G[End].push_back(pair<int, float>(Start, Value));

	return true;
}


template <typename Graph>
bool graph<Graph>::temp_recurrence(int cur_vertex, int parent, vector <bool>& visited){
	bool answ = true;
	int i;
	vector <int> neighbour;

	G.find_neighbour(cur_vertex, neighbour);
	visited[cur_vertex] = true;
	for (i = 0; i < neighbour.size(); i++){
		if (!visited[neighbour[i]]){
			answ *= temp_recurrence(neighbour[i], cur_vertex, visited);
		} else {
			if ((G.find(cur_vertex, neighbour[i]) > 0)&&(neighbour[i] != parent)){
				return false;
			}
		}
	}
	return answ;
}

template <typename Graph>
void graph<Graph>::temp_deikstra(int cur_vertex, vector <float>& val, vector <bool>& visited, vector <int>& vertex){
	int i, min;
	float tmp;
	visited[cur_vertex] = true;
	vector <int> neighbour;

	G.find_neighbour(cur_vertex, neighbour);
	for (i = 0; i < neighbour.size(); i++){
		if (!visited[neighbour[i]]){
			tmp = G.find(cur_vertex, neighbour[i]);
			if (tmp != 0){
				if (val[cur_vertex] > 0){
					if (val[neighbour[i]] > 0){
						if((val[cur_vertex]+tmp) < val[neighbour[i]]){
							val[neighbour[i]] = val[cur_vertex]+tmp;
						}
					} else {
						val[neighbour[i]] = val[cur_vertex]+tmp;
					}
				} else {
					val[neighbour[i]] = tmp;
				}
			}
		}
	}

	tmp = -1;
	min = -1;
	for (i = 0; i < vertex.size(); i++){
		if ((!visited[vertex[i]])&&(val[vertex[i]] > 0)){
			if ((tmp < 0)||(tmp > val[vertex[i]])){
				min = vertex[i];
				tmp = val[vertex[i]];
			}
		}
	}

	if (min > -1){
		temp_deikstra(min, val, visited, vertex);
	}
}

template <typename Graph>
void graph<Graph>::temp_DFS(int cur_vertex, vector <bool>& visited, vector <int>& output){
	int i, j;
	vector <int> neighbour;

	G.find_neighbour(cur_vertex, neighbour);
	sort(neighbour.begin(), neighbour.end());
	output.push_back(cur_vertex);
	visited[cur_vertex] = true;
	for (i = 0; i < neighbour.size(); i++){
		if (!visited[neighbour[i]]){
			temp_DFS(neighbour[i], visited, output);
		}
	}
}

template <typename Graph>
void graph<Graph>::temp_BFS(int cur_vertex, vector <bool>& gray, vector <bool>& black, vector <int>& output){
	int i, j;
	vector <int> neighbour;

	G.find_neighbour(cur_vertex, neighbour);
	
	for (i = 0; i < neighbour.size(); i++){
		if (!gray[neighbour[i]]){
			output.push_back(neighbour[i]);
			gray[neighbour[i]] = true;
		}
	}

	for (i = 0; i < neighbour.size(); i++){
		if (!black[neighbour[i]]){
			black[neighbour[i]] = true;
			temp_BFS(neighbour[i], gray, black, output);
		}
	}

}

template <typename Graph>
void graph<Graph>::tmp_prim(vector <trio>& seq, vector <int>& G_vertex, trio& output, vector <int>& GG_vertex){
	int i, j, k;
	vector <trio> temp_seq;

	for (i = 0; i < seq.size(); i++){
		for (j = 0; j < G_vertex.size(); j++){
			if (seq[i].get_start() == G_vertex[j]){
				for (k = 0; k < G_vertex.size(); k++){			
					if (seq[i].get_end() == G_vertex[k]){
						break;
					}
				}
				if (k == G_vertex.size()){
					temp_seq.push_back(seq[i]);
				}
			} else if (seq[i].get_end() == G_vertex[j]){
				for (k = 0; k < G_vertex.size(); k++){
					if (seq[i].get_start() == G_vertex[k]){
						break;
					}
				}
				if (k == G_vertex.size()){
					temp_seq.push_back(seq[i]);
				}
			} 
		}
	}

	if (temp_seq.size() > 0){
		sort(temp_seq.begin(), temp_seq.end(), [&](trio a, trio b){return (a.get_value() < b.get_value());});	
		output = temp_seq[0];
	} else {
		for (i = 0; i < GG_vertex.size(); i++){
			for (j = 0; j < G_vertex.size(); j++){
				if(GG_vertex[i] == G_vertex[j]){
					break;
				}
			}
			if (j == G_vertex.size()){
				G_vertex.push_back(GG_vertex[i]);
				tmp_prim(seq, G_vertex, output, GG_vertex);
				return;
			}
		}
	}
}

template <typename Graph>
void graph<Graph>::floyd_warshall(vector <vector <float> >& GG){
	int i, j, k, old_size, max;
	vector <int> G_vertex;
	
	G.uniq_vertex(G_vertex);
	if (G_vertex.size() == 0){
		cout << "graph is empty" << endl;
		return;
	}
	if (!recurrence()){
		cout<<"graph has recurrence"<<endl;
		return;
	}
	max = G_vertex[0];
	for (i = 1; i < G_vertex.size(); i++){
		if (G_vertex[i] > max){
			max = G_vertex[i];
		}
	}
	
	old_size = GG.size();

	for (i = 0; i < old_size; i++){
		GG.pop_back();
	}	

	GG.resize(max+1);

	for (i = 0; i < GG.size(); i++){
		for (j = 0; j < GG.size(); j++){
			GG[i].push_back(0);
		}
	}

	for (i = 0; i < G_vertex.size(); i++){
		for(j = 0; j < G_vertex.size(); j++){
			if (G.find(G_vertex[i],G_vertex[j])){
				GG[G_vertex[i]][G_vertex[j]] = G.find(G_vertex[i], G_vertex[j]);
			}
		}
	}

	for (k = 0; k < GG.size(); k++){
		for (i = 0; i < GG.size(); i++){
			for(j = 0; j < GG.size(); j++){
				if ((GG[i][k] > 0)&&(GG[k][j] > 0)&&(i != j)){
					if (GG[i][j] > 0){
						GG[i][j] = min(GG[i][j], GG[i][k]+GG[k][j]);
					} else {
						GG[i][j] = GG[i][k]+GG[k][j];
					}
				}
			}
		}
	}
}

template <typename Graph>
void graph<Graph>::prim(graph *GG){
	int i;
	vector <int> G_vertex;
	vector <int> GG_vertex;
	vector <trio> seq;
	trio tmp_trio;

	G.rib_sequence(seq);
	for (i = 0; i < seq.size(); i++){
		G.delete_rib(seq[i].get_start(), seq[i].get_end());
	}

	GG->G.uniq_vertex(GG_vertex);
	if (GG_vertex.size() == 0){
		cout << "graph is empty" << endl;
		return;
	}
	
	GG->G.rib_sequence(seq);

	G_vertex.push_back(seq[0].get_start());
	G_vertex.push_back(seq[0].get_end());
	G.add(seq[0].get_start(),seq[0].get_end(), seq[0].get_value());
	
	while (G_vertex.size() < GG_vertex.size()){
		tmp_prim(seq, G_vertex, tmp_trio, GG_vertex);
		for (i = 0; i < G_vertex.size(); i++){
			if (tmp_trio.get_start() == G_vertex[i]){
				break;
			}
		}
		if (i == G_vertex.size()){
			G_vertex.push_back(tmp_trio.get_start());
		} else {
			G_vertex.push_back(tmp_trio.get_end());
		}
		G.add(tmp_trio.get_start(), tmp_trio.get_end(), tmp_trio.get_value());
	}
}

template <typename Graph>
void graph<Graph>::kraskal(graph *GG){ 
	int i;
	vector <int> G_vertex;
	vector <int> GG_vertex;
	vector <trio> seq;

	G.rib_sequence(seq);
	for (i = 0; i < seq.size(); i++){
		G.delete_rib(seq[i].get_start(), seq[i].get_end());
	}

	GG->G.uniq_vertex(G_vertex);
	if (G_vertex.size() == 0){
		cout << "graph is empty" << endl;
		return;
	}
	
	GG->G.rib_sequence(seq);

	for (i = 0;i < seq.size(); i++){
		G.add(seq[i].get_start(), seq[i].get_end(), seq[i].get_value());
		if (!recurrence()){
			G.delete_rib(seq[i].get_start(), seq[i].get_end());
		} else {
			G.uniq_vertex(GG_vertex);
			if (GG_vertex.size() == G_vertex.size()){
				return;
			}
		}
	}
}

template <typename Graph>
bool graph<Graph>::recurrence(){
	int i;
	bool answ = true;
	vector <int> vertex;
	G.uniq_vertex(vertex);
	vector <int> neighbour;
	vector <bool> visited;

	if (vertex.size() == 0){
		cout << "graph is empty" << endl;
		return true;
	}

	int max = vertex[0];
	for (i = 1; i < vertex.size(); i++){
		if (vertex[i] > max){
			max = vertex[i];
		}
	}

	for (i = 0; i < max+1; i++){
		visited.push_back(false);
	}

	G.find_neighbour(vertex[0], neighbour);
	visited[vertex[0]] = true;
	for (i = 0; i < neighbour.size(); i++){
		if (!visited[neighbour[i]]){
			answ *= temp_recurrence(neighbour[i], vertex[0], visited);
		}
	}
	return answ;
}

template <typename Graph>
float graph<Graph>::deikstra (int Start, int End){
	float ans = 0;
	int i;
	int start_flag = 0;
	int end_flag = 0;
	vector <int> vertex;
	vector <float> val;
	vector <bool> visited;

	G.uniq_vertex(vertex);
	if (vertex.size() == 0){
		cout << "graph is empty" << endl;
		return 0;
	}
	
	for (i = 0; i < vertex.size(); i++){
		if (vertex[i] == Start){
			start_flag = 1;
		}
		if (vertex[i] == End){
			end_flag = 1;
		}
	}
	if ((start_flag = 0)||(end_flag = 0)){
		cout << "start or end vertex out of graph" << endl;
		return 0;
	}

	int max = vertex[0];
	for (i = 1; i < vertex.size(); i++){
		if (vertex[i] > max){
			max = vertex[i];
		}
	}

	for (i = 0; i < max+1; i++){
		val.push_back(0);
		visited.push_back(false);
	}

	temp_deikstra(Start, val, visited, vertex);

	ans = val[End];
	return ans;
}

template <typename Graph>
void graph<Graph>::DFS(int cur_vertex, vector <int>& output){
	int i, old_size;
	vector <int> vertex;
	vector <bool> visited;
	G.uniq_vertex(vertex);
	if (vertex.size() == 0){
		cout << "graph is empty" << endl;
		return;
	}

	old_size = output.size();

	for (i = 0; i < old_size; i++){
		output.pop_back();
	}

	int max = vertex[0];
	for (i = 1; i < vertex.size(); i++){
		if (vertex[i] > max){
			max = vertex[i];
		}
	}
	
	for (i = 0; i < max+1; i++){
		visited.push_back(false);
	}

	for (i = 0; i < vertex.size(); i++){
		if (vertex[i] == cur_vertex){
			break;
		}
	}
	if (i == vertex.size()){
		cout << "DFS error" << endl;
		return;
	}
	temp_DFS(cur_vertex, visited, output);
}

template <typename Graph>
void graph<Graph>::BFS(int cur_vertex, vector <int>& output){
	int i, old_size;
	vector <int> vertex;
	vector <bool> gray;
	vector <bool> black;

	G.uniq_vertex(vertex);
	if (vertex.size() == 0){
		cout << "graph is empty" << endl;
		return;
	}

	old_size = output.size();
	for (i = 0; i < old_size; i++){
		output.pop_back();
	}

	int max = vertex[0];
	for (i = 1; i < vertex.size(); i++){
		if (vertex[i] > max){
			max = vertex[i];
		}
	}

	for (i = 0; i < max+1; i++){
		gray.push_back(false);
		black.push_back(false);
	}

	for (i = 0; i < vertex.size(); i++){
		if (vertex[i] == cur_vertex){
			break;
		}
	}
	if (i == vertex.size()){
		cout << "BFS error" << endl;
		return;
	}

	output.push_back(cur_vertex);
	black[cur_vertex] = true;
	gray[cur_vertex] = true;
	temp_BFS(cur_vertex, gray, black, output);
}

#endif
