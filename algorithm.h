#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <vector>
#include <limits.h>
#include <queue>
class algorithm{
public:
    std::vector <std::vector <int>> make_adj(int holder[] , int nrows);
    std::vector <long int> djikstra(int cell , std::vector< std::vector <int> > &adj_matrix , int nrows);
    std::vector <int> bfs(int cell, std::vector< std::vector <int > > &rgraph , int nrows);

};

#endif // ALGORITHM_H
