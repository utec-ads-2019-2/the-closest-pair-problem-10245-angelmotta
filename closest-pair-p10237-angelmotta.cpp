#include <iostream>
#include <cmath>

using namespace std;

double min_distance;

void calculateDistances(int index_origen, int index_destino, double* x, double* y){
	double x_dist, y_dist;
	double distance;
	x_dist = x[index_destino] - x[index_origen];
	y_dist = y[index_destino] - y[index_origen];
	distance = sqrt(x_dist*x_dist + y_dist*y_dist);
	distance = (int)(distance*10000);
	distance = (double)distance/10000;
	//cout << distance << "\n";
	if(distance < min_distance){
		min_distance = distance;
	}
}

void generateCombinations(int number_points, double* x_dots, double* y_dots){
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
		min_distance = 100000.0;
		if(number_points == 0) break;
		int num_distancias;
		double x, y;
		double* x_coordinates = new double[number_points];
		double* y_coordinates = new double[number_points];
		num_distancias = number_points*(number_points-1)/2;
		//int* distancias = new int[num_distancias];

		for(int i=0; i<number_points; ++i){
			scanf("%lf %lf", &x, &y);
			x_coordinates[i] = x;
			y_coordinates[i] = y;
		}
		generateCombinations(number_points, x_coordinates, y_coordinates);
		if(min_distance < 10000){
			printf("%.4lf\n", min_distance);
		}
		else{
			printf("INFINITY \n");
		}
		delete[] x_coordinates;
		delete[] y_coordinates;
	}
	return 0;
}