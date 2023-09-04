#include<iostream>
#include<map>
#include<list>
#include<vector>

using namespace std;

class LFUCache {

    int size;  // Size of LFU cache
    int count; // keys track of the elements that are pushed.

    map <int, pair<int, int>> cache; // LFU cache table stores < key, < value, frequency > >

    // Table stores list of keys based on their frequency. The first element of the list is the LRU key.
    map <int, list<int>> freq_table;

    public:

    LFUCache (int arg_size) : size (arg_size), count(0) { }

    // Update the frequency of the key
    void Update_FrequencyTable (int freq, int key) {

        // Update would involve deleting the previous pair <frequency, <key>> from the list.
        if (freq > 1) { // Element should be already be present at previous frequency. So remove it.
            freq_table[freq-1].remove(key);
        }
        freq_table[freq].push_back(key);

        cout << "Frequency Table" << endl;
        cout << "===============" << endl;
        for (int freq=1; freq<=count; freq++) {
             cout << "Freq [" << freq << "] : ";
             list<int> :: iterator it;
             for (it = freq_table[freq].begin(); it != freq_table[freq].end(); ++it)
                  cout << *it << " ";
             cout << endl;
        }
    }

    int Get (int key) {
        cout << "\nOperation GET : " << key << endl;
        if (cache.find(key) != cache.end()) {
            cache[key].second += 1;
            int freq = cache[key].second;
            Update_FrequencyTable (freq, key);
            cout << "Return ----> ";
            return cache[key].first;
        }
        return -1;
    }

    void Put (int key, int value) {

        if (size == 0)
            return;

        cout << "\nOperation PUT : [" << key << ":" << value << "]" << endl;

        if (cache.find(key) != cache.end()) { // Key is found in the cache
            cache[key].first = value;
            cache[key].second += 1;
            int freq = cache[key].second;
            Update_FrequencyTable (freq, key);
        } else { // Key not found in the cache
            count++;
            if (cache.size() == size) { // Cache is already full
                cout  << "Cache is full !!" << endl;
                for (int freq=1; freq<=count; freq++) {
                    if (freq_table.find(freq) != freq_table.end() and freq_table[freq].size() > 0) {
                        int key = freq_table[freq].front();
                        cout << "Erasing key : " << key << endl;
                        cache.erase(key);
                        freq_table[freq].pop_front();
                        break;
                    }
                }
            }
            cache[key].first = value;
            cache[key].second = 1;
            Update_FrequencyTable (1, key);
        }
    }
};

int main() {

    LFUCache cache(2);

    cache.Put(1,1);
    cache.Put(2,2);
    cout << cache.Get(1) << endl;
    cache.Put(3,3);
    cout << cache.Get(2) << endl;
    cout << cache.Get(3) << endl;
    cache.Put(4,4);
    cout << cache.Get(1) << endl;
    cout << cache.Get(3) << endl;
    cout << cache.Get(4) << endl;
    return 0;
}
