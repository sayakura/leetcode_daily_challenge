class Logger {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> data;
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        bool ret; 
        if (data.find(message) == data.end()) 
            ret = true;
        else
            ret = (timestamp - data[message]) >= 10;
        if (ret) // xijie
            data[message] = timestamp;
        return ret;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */