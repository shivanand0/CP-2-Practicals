// Freckles

#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
#define MAXV 100
#define START_POINT 1
#define MAX_DOUBLE (1.7E10)


 // The edge right is set to the square of the distance for comparison, not the actual distance.
  struct edge { int vertex; double weight; };
  //Fig.
  struct graph
  { edge edges[MAXV + 1][MAXV + 1];
    int degree[MAXV + 1];
    int nvertices;
  };
  //Dot.
  struct point { double x; double y;
  };
  // Use the Prim algorithm to find the minimum spanning tree.

  double prim(graph *g, int start)
  {
      double distance[MAXV + 1];
      bool intree[MAXV + 1];
      double shortest = 0.0;
      //Initialize.
       memset(intree, false, sizeof(intree));
      for (int c = 1; c <= g->nvertices; c++)
            distance[c] = MAX_DOUBLE;
            distance[start] = 0.0;
            int vertex = start;
      while (intree[vertex] == false)
      {
          // Shortest distance plus the distance from the start point to this point vertex.
          shortest += sqrt(distance[vertex]);
         //The point is already in the minimum spanning tree, updating the distance from start to the point connected to this point.
          intree[vertex] = true;
          for (int c = 0; c < g->degree[vertex]; c++)
          {
              int neighbor = g->edges[vertex][c].vertex;
              double weight = g->edges[vertex][c].weight;
              if (distance[neighbor] > weight && intree[neighbor] == false)
                     distance[neighbor] = weight;
          }
          // Look for the next one with the smallest edge weight in the edge "Pointing out of the tree"
           vertex = START_POINT;
           double smallest = MAX_DOUBLE;
           for (int c = 1; c <= g->nvertices; c++)
                if (intree[c] == false && smallest > distance[c])
                { smallest = distance[c]; vertex = c; }
      }
      return shortest;
      }//end of prim

      int main(int ac, char *av[])
      {
          int cases, n; double x, y;
          vector < point > points;
          graph g;
          cin >> cases;
          while (cases--)
          {
              // Read point coordinate data.
             cin >> n;
             points.clear();
             points.resize(n + 1);
             for (int p = 1; p <= n; p++)
             {
                 cin >> x >> y;
                 points[p] = (point){x, y};
             }

             // Build edges, the edge weight is the square of the distance between two points, and its distance is not calculated for the time being.
             g.nvertices = n;
             memset(g.degree, 0, sizeof(g.degree));
             for (int current = 1; current <= (n - 1); current++)
                for (int next = current + 1; next <= n; next++)
                {
                    double dx = abs(points[current].x - points[next].x);
                    double dy = abs(points[current].y - points[next].y);
                    double distance = dx * dx + dy * dy;
                    g.edges[current][g.degree[current]++] = (edge){next, distance};
                    g.edges[next][g.degree[next]++] = (edge){current, distance};
                }
                // Any starts with a vertex to find the minimum spanning tree, starting with a point with the ordinal START_POINT by default, starting with any
                 // point should be the same.
                 cout.precision(2);
                 cout.setf(ios::fixed | ios::showpoint);
                 cout << prim(&g, START_POINT) << endl;
                 //Outputs blank lines.
                 if (cases) cout << endl;
            }
             return 0;
        }

