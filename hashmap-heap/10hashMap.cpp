#include<bits/stdc++.h>
using namespace std;
// at(key) - gives the value for key //get
// insert(key,value) - insert key, value pair //put
// erase(key) - remove the key // remove
// size() - give size of keys
// keys() - return keys list
// count(key) - return 0 or 1
// In hash table their are N buckets and n elements which filled thoses buckets
// buckets are simply array of linked list..
// then their is lambda(Y) = n/N which tells avg number of elements per bucket
// when we call insert/put method, first it hash the key to find corresponding bucket
// and then each bucket contains the address for linked list. if the element 
// with the given key is already there it will get updated otherwise we insert 
// at the end of the list.
// also Y never exceeds a constant k (Y <= K)..
// but if it does exceed the k, then rehasing take place
// in rehasing we make new array with more buckets (>N) and again fill all the 
// n elements again while passing their key to hash function.
// it will decrease the (Y) = n/N as the N increases.
// all this help to main constant operation of insert/put, at/get, count/find, erase/remove.


template <class K, class V>
class HashMmap {
    private:
    class HMNode {
        public:
        K key;
        V value;
        HMNode(K k, V v) {
            key = k;
            value = v;
        }
    };
    
    int sizeHM;
    list<HMNode> *buckets;

    void initBuckets(int bucketSize) {
        buckets = new list<HMNode>[bucketSize];
    }

    int hashfn(K key) {
        hash<K> hashFunction;
        size_t hc = hashFunction(key);
        return hc % bucketCount;
    }

    int getIndWithInBucket(K key, int bi) {
        int di = 0;
        for(HMNode node : buckets[bi]) {
            if(node.key == key) {
                return di;
            }
            di++;
        }
        return -1;
    }

    void rehash() {
        int oldBucketCount = bucketCount;
        list<HMNode> *oldBuckets = buckets;
        bucketCount = oldBucketCount*2;
        initBuckets(bucketCount);
        sizeHM = 0;
        for(int i = 0; i < oldBucketCount; i++) {
            for(auto node : oldBuckets[i]) {
                insert(node.key, node.value);
            }
        }
        delete[] oldBuckets;
    }

    public:
    int bucketCount;
    HashMmap() {
        bucketCount = 4;
        initBuckets(bucketCount);
        sizeHM = 0;
    }
    
    void insert(K key, V value) {
        int bi = hashfn(key);
        int di = getIndWithInBucket(key, bi);

        if(di != -1) {
            auto it = buckets[bi].begin();
            advance(it, di);
            HMNode &node = *it;
            node.value = value;
        } else {
            HMNode node(key, value);
            buckets[bi].push_back(node);
            sizeHM++;
        }

        double lambda = sizeHM * 1.0 / bucketCount;
        if(lambda > 2.0) {
            rehash();
        }
    }

    V at(K key) {
        int bi = hashfn(key);
        int di = getIndWithInBucket(key, bi);
        if(di != -1) {
            auto it = buckets[bi].begin();
            advance(it, di);
            HMNode &node = *it;
            return node.value;
        } else {
            cout << "no Such Key";
            return V();
        }
    }

    bool contain(K key) {
        int bi = hashfn(key);
        int di = getIndWithInBucket(key, bi);
        if(di != -1) {
            return true;
        } else {
            return false;
        } 
    }

    void remove(K key) {
        int bi = hashfn(key);
        int di = getIndWithInBucket(key, bi);
        if(di != -1) {
            auto it = buckets[bi].begin();
            advance(it, di);
            buckets[bi].erase(it);
            sizeHM--;
        }
    }

    int size() {
        return sizeHM;
    }

    vector<K> keySet() {
        vector<K> keys;
        for(int i = 0; i < bucketCount; i++) {
            for(auto node : buckets[i]) {
                keys.push_back(node.key);
            }
        }
        return keys;
    }

    ~HashMmap() {
        delete[] buckets;
    }
};

int main() {
    HashMmap<string, int> hm;
    hm.insert("faizan", 23);
    hm.insert("shad", 56);
    hm.insert("fai23zan", 23);
    hm.insert("sh523ad", 56);
    hm.insert("sad66f", 56);
    hm.insert("as11dg", 56);
    hm.insert("sadf", 56);
    hm.insert("asdg", 56);
    cout << hm.bucketCount << endl;
    hm.insert("hashha", 56);
    cout << hm.bucketCount << endl;
    cout << hm.at("faizan") << endl;
    cout << hm.contain("faizan") << endl;
    cout << hm.size() << endl;
    hm.remove("faizan");
    cout << hm.contain("faizan") << endl;
    vector<string> keys = hm.keySet();
    for(auto s : keys) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}