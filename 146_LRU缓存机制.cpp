#include <unordered_map>
#include <list>
#include <iostream>
using namespace std;

class LRUCache {
    unordered_map<int, list<pair<int,int> >::iterator> hash;
    list<pair<int, int> > cache;
    int size;
public:
    LRUCache(int capacity) : size(capacity){}
    
    int get(int key) {
        auto it = hash.find(key);
        if (it == hash.end()) {
            return -1;
        }
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = hash.find(key);
        if (it == hash.end()) {
            cache.insert(cache.begin(), make_pair(key, value));
            hash[key] = cache.begin();
            if (cache.size() > size) {
                hash.erase(cache.back().first);
                cache.pop_back();
            }
        }
        else {
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */