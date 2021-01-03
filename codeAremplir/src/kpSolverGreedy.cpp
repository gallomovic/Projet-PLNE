//********* knapsackGreedy.cpp *********

#include "kpSolverGreedy.hpp"

//glouton continu
void KpSolverGreedy::solveUpperBound() {
	double somme =  0;
	int lim = knapsackBound;
	for (int i=0; i<nbItems; i++){
		if(weights.at(i) <= lim){
			somme += values.at(i);
			lim -= weights.at(i);
		}
		else{
			somme += ((double)lim/ (double)weights.at(i)* (double)values.at(i));
			lim = 0;
		}
	}
	upperBoundOPT = somme;
 }

//glouton entier
void KpSolverGreedy::solveLowerBound() {

	solution.resize(nbItems);
	int somme = 0;
	int lim = knapsackBound;
	for(int i=0; i<nbItems; i++){
		if(weights.at(i) <= lim){
			solution.at(i)= true;
			somme += values.at(i);
			lim -= weights.at(i);
		}
		else{
			solution.at(i) = false;
		}
		costSolution = somme;
	}	
	
 }

void KpSolverGreedy::solve() {
	solveUpperBound();
	solveLowerBound();
}
