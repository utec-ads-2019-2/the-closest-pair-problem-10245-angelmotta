#include <iostream>
#include <cmath>

using namespace std;

float min_distance;

void calculateDistances(int index_origen, int index_destino, int* x, int* y){
	int x_dist, y_dist;
	float distance;
	x_dist = x[index_destino] - x[index_origen];
	y_dist = y[index_destino] - y[index_origen];
	distance = sqrt(x_dist*x_dist + y_dist*y_dist);
	distance = (int)(distance*10000);
	distance = (float)distance/10000;
	//cout << distance << "\n";
	if(distance < min_distance){
		min_distance = distance;
	}
}

void generateCombinations(int number_points, int* x_dots, int* y_dots){
	for(int i=0; i<number_points-1; ++i){
		int destino = i;
		for(int j=0; j<number_points-1-i; ++j){
			//cout << i << " con " << destino+1 << " ";
			calculateDistances(i, destino+1, x_dots, y_dots);
			destino++;
		}
		//cout << '\n';
	}
}

int main(){
	int number_points;
	while(scanf("%d",&number_points) == 1){
		min_distance = 100000;
		if(number_points == 0) break;
		int x, y, num_distancias;
		int* x_coordinates = new int[number_points];
		int* y_coordinates = new int[number_points];
		num_distancias = number_points*(number_points-1)/2;
		//int* distancias = new int[num_distancias];

		for(int i=0; i<number_points; ++i){
			scanf("%d %d", &x, &y);
			x_coordinates[i] = x;
			y_coordinates[i] = y;
		}
		generateCombinations(number_points, x_coordinates, y_coordinates);
		if(min_distance < 10000){
			cout << min_distance << "\n";
		}
		else{
			cout << "INFINITY \n";
		}
		delete[] x_coordinates;
		delete[] y_coordinates;
	}
	return 0;
}