//
//  main.cpp
//  Horn Formula SAT Problem
//
//  Created by Георгий Кашин on 19.11.2019.
//  Copyright © 2019 Georgii Kashin. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <stack>

using namespace std;

/// Function checks whether the Horn-formula is satisfiability or not
/// @param varMap dictionary of variables with false value for each one
/// @param implicationClauses implication clauses of the Horn-formula
/// @param pureNegativeClauses pure negative clauses of the Horn-formula
bool checkSat(map<char, bool>& varMap,
              vector<pair<list<char>, char>>& implicationClauses,
              const vector<list<char>>& pureNegativeClauses
              ) {
    stack<char> emptyImplVar;
    
    // Find all of the variables that are the head of implications in which the tail is empty
    for (auto clause : implicationClauses) {
        if (clause.first.empty()) {
            emptyImplVar.push(clause.second);
        }
    }
    
    // Check all of the implication clauses
    while (!emptyImplVar.empty()) {
        char trueVar = emptyImplVar.top();
        emptyImplVar.pop();
        varMap[trueVar] = true;
        for (auto& clause : implicationClauses) {
            for (auto iter = clause.first.begin(); iter != clause.first.end(); ++iter) {
                if (*iter == trueVar) {
                    clause.first.erase(iter);
                    if (clause.first.empty()) {
                        emptyImplVar.push(clause.second);
                    }
                    break;
                }
            }
        }
    }
    
    // Check all of the pure negative clauses
    for (auto pureNegativeClause : pureNegativeClauses) {
        int count = 0;
        for (auto var : pureNegativeClause) {
            if (varMap[var] == false) {
                break;
            }
            count++;
            if (count == pureNegativeClause.size()) {
                return false;
            }
        }
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    
    map<char, bool> varMap;
    
    cout << "Enter count of variables" << endl;
    int varCount;
    cin >> varCount;
    
    cout << "Enter variables" << endl;
    char nextVar;
    for (int i = 0; i < varCount; ++i) {
        cin >> nextVar;
        varMap[nextVar] = false;
    }
    
    cout << "Enter count of implication clauses" << endl;
    int implicationClausesCount;
    cin >> implicationClausesCount;
    vector<pair<list<char>, char>> implicationClauses(implicationClausesCount);
    
    char nextChar;
    for (int i = 0; i < implicationClausesCount; ++i) {
        cout << "Enter implication clause №" << i << endl;
        cin >> nextChar;
        
        while (nextChar != '>') {
            implicationClauses[i].first.push_back(nextChar);
            cin >> nextChar;
        }
        
        cin >> nextChar;
        implicationClauses[i].second = nextChar;
    }
    
    cout << "Enter count of pure negative clauses" << endl;
    int pureNegativeClausesCount;
    cin >> pureNegativeClausesCount;
    vector<list<char>> pureNegativeClauses(pureNegativeClausesCount);
    
    for (int i = 0; i < pureNegativeClausesCount; ++i) {
        cout << "Enter pure negative clause №" << i << endl;
        cin >> nextChar;
        
        while (nextChar != ';') {
            pureNegativeClauses[i].push_back(nextChar);
            cin >> nextChar;
        }
    }
    
    bool isSat = checkSat(varMap, implicationClauses, pureNegativeClauses);
    
    if (isSat) {
        for (auto var : varMap) {
            cout << var.first << ": " << var.second << endl;
        }
    } else {
        cout << "Function is not satisfiable" << endl;
    }
    
    return 0;
}
