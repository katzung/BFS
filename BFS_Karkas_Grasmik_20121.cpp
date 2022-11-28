#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

enum vertexTypes
{
    original,
    opened,
    closed
};

using namespace std;

int main()
{
    int** adjacencyMatrix;
    int mSize;

    cout << "Grasmik Roman 20121, Algorythm 5\n";
    cout << "Vertexes will be numerated from 1 to N, where N is number of vertexes.\n";
    cout << "Number of vertexes: ";
    cin >> mSize;
    cout << endl;
    
    adjacencyMatrix = new int*[mSize];
    for (int i = 0; i < mSize; ++i)
    {
        adjacencyMatrix[i] = new int[mSize];
    }

    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < mSize; i++)
    {
        for (int j = 0; j < mSize; j++)
        {
            cin >> adjacencyMatrix[i][j];
        }
    }
    cout << endl;

    int root;

    cout << "Root vertex: ";
    cin >> root;
    cout << endl;

    unordered_map<int, int> vertexes(mSize);
    for (int i = 0; i < mSize; i++)
    {
        vertexes[i] = original;
    }

    queue<int> queue;
    queue.push(root - 1);
    vertexes[root - 1] = opened;

    int** frame;
    frame = new int* [mSize];
    for (int i = 0; i < mSize; ++i)
    {
        frame[i] = new int[mSize];
        for (int j = 0; j < mSize; j++)
        {
            frame[i][j] = 0;
        }
    }

    while (!queue.empty())
    {
        int currentVertex = queue.front();
        for (int i = 0; i < mSize; i++)
        {
            if (i != currentVertex && vertexes[i] == original && adjacencyMatrix[currentVertex][i] == 1)
            {
                vertexes[i] = opened;
                frame[currentVertex][i] = 1;
                frame[i][currentVertex] = 1;
                queue.push(i);
            }
        }
        vertexes[currentVertex] = closed;
        queue.pop();
    }

    cout << "BFS-Graph:\n";
    for (int i = 0; i < mSize; i++)
    {
        for (int j = 0; j < mSize; j++)
        {
            cout << frame[i][j] << " ";
        }
        cout << endl;
    }
}