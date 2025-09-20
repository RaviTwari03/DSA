class Router {
public:

    int MAX_SIZE;
    unordered_map <string, vector<int>> packetStore;
    unordered_map <int,vector<int>>destTimeMap;
    queue<string>que;

    Router(int memoryLimit) {
        MAX_SIZE = memoryLimit;
    }
    
    string makeKey(int S, int D, int T){
        return to_string(S) + "_" + to_string(D) + "_" + to_string(T);
    }


    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source,destination,timestamp);
        if(packetStore.find(key) != packetStore.end()){
            return false;
        }

        if(que.size()>=MAX_SIZE){
            forwardPacket();
        }
        packetStore[key] = {source,destination,timestamp};
        que.push(key);
        destTimeMap[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(packetStore.empty()){
            return {};
        }

        string key = que.front();
        que.pop();
        vector<int> packet = packetStore[key];
        packetStore.erase(key);

        int dest = packet[1];
        destTimeMap[dest].erase(destTimeMap[dest].begin());
        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimeMap.find(destination);
        if (it == destTimeMap.end() || it->second.empty())
            return 0;

            int i = lower_bound(begin(it->second), end(it->second), startTime) - begin(it->second);//log(size of vec)
        int j = upper_bound(begin(it->second), end(it->second), endTime) - begin(it->second); //log(size of vec)

        return j-i;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */