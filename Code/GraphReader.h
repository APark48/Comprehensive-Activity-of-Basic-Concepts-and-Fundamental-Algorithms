#pragma once
#include "Reader.h"
#include "ComputerConnections.h"
#include "graph.h"
#include "Data.h"

class GraphReader
{
public:
    GraphReader(){};
    ~GraphReader(){};

    int returnB(Reader data)
    {
        int size = data.getSize();
        std::string newDate = data.getDate(0);
        Graph<std::string> g;
        for (int i=0; i<size; i++){
            if (data.getDestinationIp(i) == "40.193.248.207"){
                g.add_node(data.getSourceIp(i));
                g.add_node(data.getDestinationIp(i));
                g.add_edge(data.getInternalIP2(i), data.getDestinationIp(i));
            }
            if (data.getDate(i) != newDate){
                newDate = data.getDate(i);
            }
        }
    }
    int returnC();
};



