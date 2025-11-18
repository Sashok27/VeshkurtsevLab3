#ifndef GASNETWORK_H
#define GASNETWORK_H

#include "pipe.h"
#include "cs.h"
#include <vector>
#include <map>
#include <set>

struct Connection {
    int pipe_id;
    int cs_in_id;   // ID станции входа
    int cs_out_id;  // ID станции выхода
};

class GasNetwork {
private:
    std::vector<Connection> connections;
    
public:
    void addConnection(int pipe_id, int cs_in_id, int cs_out_id);
    void displayConnections(const std::map<int, Pipe>& pipes, const std::map<int, CompressorStation>& stations) const;
    bool isPipeConnected(int pipe_id) const;
    bool isConnectionExists(int cs_in_id, int cs_out_id) const;
    bool hasCycle() const;
    std::vector<int> topologicalSort(const std::map<int, CompressorStation>& stations) const;
    void removeConnectionsWithPipe(int pipe_id);
    void removeConnectionsWithCS(int cs_id);
    
private:
    bool dfs(int v, std::set<int>& visited, std::set<int>& recursionStack, 
             const std::map<int, std::vector<int>>& graph) const;
};

#endif