
class Router {
private:
    int MAX_SIZE;  // memory limit
    unordered_map<string, vector<int>> packetStore;  // key -> packet [source, dest, timestamp]
    unordered_map<int, vector<int>> destTimestamps;  // destination -> sorted timestamps
    queue<string> que;  // FIFO order

    string makeKey(int source, int destination, int timestamp) {
        return to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);
    }

public:
    Router(int memoryLimit) {
        MAX_SIZE = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);

        if (packetStore.find(key) != packetStore.end()) {
            return false;  // duplicate
        }

        if ((int)packetStore.size() >= MAX_SIZE) { // remove the oldest packet
            forwardPacket();
        }

        packetStore[key] = {source, destination, timestamp};
        que.push(key);

        // insert timestamp in sorted order
        auto &ts = destTimestamps[destination];
        ts.insert(lower_bound(ts.begin(), ts.end(), timestamp), timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (packetStore.empty())
            return {}; // If there are no packets to forward, return an empty array.

        string key = que.front(); 
        que.pop();

        vector<int> packet = packetStore[key];
        packetStore.erase(key);

        int dest = packet[1];
        int timestamp = packet[2];

        // remove timestamp (erase one occurrence)
        auto &ts = destTimestamps[dest];
        auto it = lower_bound(ts.begin(), ts.end(), timestamp);
        if (it != ts.end() && *it == timestamp) {
            ts.erase(it);
        }

        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimestamps.find(destination);
        if (it == destTimestamps.end() || it->second.empty())
            return 0;

        int leftIdx = lower_bound(it->second.begin(), it->second.end(), startTime) - it->second.begin();
        int rightIdx = upper_bound(it->second.begin(), it->second.end(), endTime) - it->second.begin();

        return rightIdx - leftIdx;  // number of timestamps in [startTime, endTime]
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
