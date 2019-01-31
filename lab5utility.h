#ifndef LAB5UTILITY_H
#define LAB5UTILITY_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <fstream>
#include <math.h>
#include <unistd.h> //sleep

using namespace std;

vector<int> solveSATsingle(int varCount, vector<vector<int> > clauses){
	vector<int> testSol;
	for(int n=1; n<pow(2, varCount); n++){

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
		
		for(int i=0; i<clauses.size(); i++){
			for(int j=0; j<clauses[i].size(); j++){
				int badCount = 0;

				int currentVar = 0;
				currentVar = clauses[i][j];
				if(currentVar*testSol[currentVar-1] < 0){
					badCount++;
				}
				if(badCount == clauses[i].size()){
					goto tryNextSol;
				}
			}
		}
		goto haveAns;
		tryNextSol:
		continue;
	}
	haveAns:
	return testSol;
}

bool checkSol(vector<int> testSol, vector<vector<int> > clauses){
//check testSol
	for(int i=0; i<clauses.size(); i++){
		for(int j=0; j<clauses[i].size(); j++){
			int badCount = 0;

			int currentVar = 0;
			currentVar = clauses[i][j];
			if(currentVar*testSol[currentVar-1] < 0){
				badCount++;
			}
			if(badCount == clauses[i].size()){
				return false;
			}
		}
	}
	return true;
}

#endif
