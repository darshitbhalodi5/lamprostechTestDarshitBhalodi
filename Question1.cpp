// Including header file
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

// In question we have to inform about the no cycle then we use graph data structure
class Graph
{
public:
    unordered_map<int, vector<int>> adjList;

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }
};

bool topologicalSortUtil(int node, Graph &graph, unordered_set<int> &visited, unordered_set<int> &recursionStack, stack<int> &result)
{
    // insert the node to the visited node and stack node
    visited.insert(node);
    recursionStack.insert(node);

    for (int neighbor : graph.adjList[node])
    {
        if (!visited.count(neighbor))
        {
            if (!topologicalSortUtil(neighbor, graph, visited, recursionStack, result))
                return false;
        }
        else if (recursionStack.count(neighbor))
        {
            // If the neighbor is already in the recursion stack, then there is a cycle
            return false;
        }
    }
    // If there are no cycle then we return true and no cycle is found
    recursionStack.erase(node);
    result.push(node);
    return true;
}

// Function for topological sorting
bool topologicalSort(Graph &graph, stack<int> &result)
{
    // Creating the set for visited and stack element
    unordered_set<int> visited;
    unordered_set<int> recursionStack;

    for (const auto &entry : graph.adjList)
    {
        int node = entry.first;
        if (!visited.count(node))
        {
            if (!topologicalSortUtil(node, graph, visited, recursionStack, result))
                return false;
        }
    }
    return true;
}

// Function for find the order of the courses
vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites)
{

    // Iterate the graph
    Graph graph;
    for (const auto &prereq : prerequisites)
    {
        graph.addEdge(prereq.second, prereq.first);
    }

    stack<int> result;
    if (!topologicalSort(graph, result))
        // Empty vector indicates that there is a cycle (no valid course order)
        return vector<int>();

    vector<int> order;
    while (!result.empty())
    {
        order.push_back(result.top());
        result.pop();
    }
    // Return vector indicates that there is no cycle and return the correct order
    return order;
}

// Main Function start from here
int main()
{
    // Enter the number of courses
    int numCourses = 4;

    // Give the input in form of dependency or prerequisite
    vector<pair<int, int>> prerequisites = {{0, 1}, {1, 2}, {2, 3}, {3, 0}}; // with cycle
    vector<pair<int, int>> prerequisites = {{0, 1}, {1, 2}, {2, 3}};         // without cycle

    // Call the function for find the order of the courses
    vector<int> courseOrder = findOrder(numCourses, prerequisites);

    if (courseOrder.empty())
    {
        cout << "No valid course order or there may be cycle formation." << endl;
    }
    else
    {
        // Printing the course order
        cout << "Valid course order: ";
        for (int course : courseOrder)
        {
            cout << course << " ";
        }
        cout << endl;
    }
    return 0;
}
