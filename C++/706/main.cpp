class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<int> hashMap;
    MyHashMap() {

    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        if(key >= hashMap.size()){
            for(int i = hashMap.size(); i <= key; i++){
                hashMap.push_back(-1);
            }
        }
        hashMap[key] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if(key >= hashMap.size())
            return -1;
        return hashMap[key];

    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if(key >= hashMap.size())
            return;
        hashMap[key] = -1;
    }
};
