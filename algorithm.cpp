#include <fstream>
#include <string>
#include <iostream>
#include <algorithm.h>
using namespace std;

    std::vector <std::vector <int>> algorithm::make_adj(int holder[] , int nrows){
        std::vector <std::vector <int>> adj(nrows*nrows);
    for(int i = 0 ; i<nrows*nrows; i++)
    {
       for(int j = 0 ; j<nrows*nrows; j++)
       {

           adj[i].push_back(0);
       }
    }
    for(int i = 0 ; i<nrows*nrows ; i++)
    {
        adj[i][i]=1;
        if(holder[i]==0){
    int j = 1 ;
    for( ; j<=6 ; j++)
      if(i+j<nrows*nrows)
      {
          if(holder[i+j]==0){
          adj[i][i+j]=1;
          }
      }

    }
        else{
              int j = 1 ;
            for( ; j<=6 ; j++){
            if(i-j>=0)
            {
               adj[i-j][holder[i]]=1;
            }
        }
            }
        }

    return adj;
    }
    std::vector <long int> algorithm::djikstra(int cell , std::vector< std::vector <int> > &adj_matrix , int nrows){
     int vertex_count =nrows*nrows;
        std::vector <long int> dist;
    for(int i = 0 ; i< vertex_count ; i++)
    {
        if(i!=cell){
    dist.push_back(INT_MAX);
    }
        else{
            dist.push_back(0);
        }
    }
        std::vector <bool> visited_node;
    int current = cell ;

       for(int  i = 0 ; i<vertex_count ; i++)
       {
           visited_node.push_back(false);
       }


       int i ;
       int mini = INT_MAX;
       int index = 0;
        for(int j = 0 ; j<vertex_count-1 ; j++)
       {
             visited_node[current]=true;
       for(i = 0 ; i < vertex_count; i++)
       {
        if( adj_matrix[current][i] > 0 && dist[current] + adj_matrix[current][i] > 0 && dist[current] + adj_matrix[current][i]< dist[i] && visited_node[i]==false)
    {
        dist[i] = dist[current]+adj_matrix[current][i];
        }
          if(mini>dist[i]  && visited_node[i]==false)
        {
    mini = dist[i];
    index = i;
        }

    }
    current = index;
    mini = INT_MAX;
       }

    return dist;

    }
std::vector <int> algorithm::bfs(int cell, std::vector< std::vector <int > > &rgraph , int nrows)
    {
        std::vector <bool> visited;
        std::vector <int> dist;
        for(int i  =0 ; i<nrows*nrows ; i++)
        {
            visited.push_back(false);
        }
        for(int i  =0 ; i<nrows*nrows ; i++)
        {
            dist.push_back(false);
        }
        int p=cell;
        std::queue <int> q;
        q.push(cell);
        visited[cell] = true;
        std::vector <int> parent(nrows*nrows);
        for(int i = 0 ; i< nrows*nrows  ; i++)
        {
            parent.push_back(0);
        }
        while (q.empty()==false && visited[nrows*nrows-1]==false)
        {

            if(q.empty()==false){
                p = q.front();
                visited[p]=true;
            q.pop();
            }
            for (int i = 0; i < nrows*nrows ; i++)
            {
                if (rgraph[p][i] > 0 && visited[i]==false) {
                    q.push(i);
    visited[i]=true;
    dist[i]=dist[p]+rgraph[p][i];
    parent[i]=p;
                }
            }

        }

        return dist;
    }

