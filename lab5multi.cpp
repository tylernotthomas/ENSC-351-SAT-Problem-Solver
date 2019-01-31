#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <fstream>
#include <math.h>
#include <thread>
//#include <omp.h>
#include "lab5utility.h"
#include <unistd.h> //sleep

using namespace std;

vector<vector<int> > clauses;
vector<int> finalSol;
int signalVar = 0;
int varCount = 0;

void solveSAT_1(){
	vector<int> testSol;
	bool result = false;

	for(int n=1; n<pow(2, varCount)/4; n++){
		if(signalVar == 1){
			break;
		}
		testSol.clear();
		string binarySol = bitset<1023>(n).to_string();

		for(int i=1022; i>1022-varCount; i--){
			if(binarySol[i] == '0'){
				testSol.push_back(-1);
			}
			else{
				testSol.push_back(1);
			}
		}

		result = checkSol(testSol, clauses);
		if(result == true){
			finalSol = testSol;
			signalVar = 1;
			break;
		}
	}
}

void solveSAT_2(){
	vector<int> testSol;
	bool result = false;

	for(int n=pow(2, varCount)/4; n<(pow(2, varCount)/4)*2; n++){
		if(signalVar == 1){
			break;
		}
		testSol.clear();
		string binarySol = bitset<1023>(n).to_string();

		for(int i=1022; i>1022-varCount; i--){
			if(binarySol[i] == '0'){
				testSol.push_back(-1);
			}
			else{
				testSol.push_back(1);
			}
		}

		result = checkSol(testSol, clauses);
		if(result == true){
			finalSol = testSol;
			signalVar = 1;
			break;
		}
	}
}

void solveSAT_3(){
	vector<int> testSol;
	bool result = false;

	for(int n=(pow(2, varCount)/4)*2; n<(pow(2, varCount)/4)*3; n++){
		if(signalVar == 1){
			break;
		}
		testSol.clear();
		string binarySol = bitset<1023>(n).to_string();

		for(int i=1022; i>1022-varCount; i--){
			if(binarySol[i] == '0'){
				testSol.push_back(-1);
			}
			else{
				testSol.push_back(1);
			}
		}

		result = checkSol(testSol, clauses);
		if(result == true){
			finalSol = testSol;
			signalVar = 1;
			break;
		}
	}
}

void solveSAT_4(){
	vector<int> testSol;
	bool result = false;

	for(int n=(pow(2, varCount)/4)*3; n<pow(2, varCount); n++){
		if(signalVar == 1){
			break;
		}
		testSol.clear();
		string binarySol = bitset<1023>(n).to_string();

		for(int i=1022; i>1022-varCount; i--){
			if(binarySol[i] == '0'){
				testSol.push_back(-1);
			}
			else{
				testSol.push_back(1);
			}
		}

		result = checkSol(testSol, clauses);
		if(result == true){
			finalSol = testSol;
			signalVar = 1;
			break;
		}
	}
}

int main(){
	ifstream inf("problem.cnf");
	vector<vector<int> > clauses;
	string garbage1, garbage2;
	int clauseCount = 0;
	int test = 0;

	inf >> garbage1;
	inf >> garbage2;
	inf >> varCount;
	inf >> clauseCount;
	
	cout << garbage1 << endl << garbage2 << endl << "variables: " << varCount << endl << "clauses: " << clauseCount << endl;

	for(int i=0; i<clauseCount; i++){
		vector<int> toPush;
		int nextVal = 1;
		while(nextVal != 0){
			inf >> nextVal;
			if(nextVal == 0){
				break;
				//this is a safety if a clause contains nothing
			}
			toPush.push_back(nextVal);
		}
		clauses.push_back(toPush);
	}


	cout << "PRINTING CLAUSES: " << endl;

	for(int i=0; i<clauses.size(); i++){
		for(int j=0; j<clauses[i].size(); j++){
			cout << clauses[i][j] << " ";
		}
		cout << endl;
	}

	if(varCount==1){
		finalSol = solveSATsingle(varCount, clauses);
	}
	else{
		thread t1(solveSAT_1);
		thread t2(solveSAT_2);
		thread t3(solveSAT_3);
		thread t4(solveSAT_4);

		t1.join();
		t2.join();
		t3.join();
		t4.join();
	}

	cout << "ANSWER: ";
	for(int i=0; i<finalSol.size(); i++){
		cout << finalSol[i]*(i+1) << " ";
	}
	cout << endl;
	return 0;
}
