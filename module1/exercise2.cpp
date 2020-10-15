#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>

template <typename Key, typename Value>
class VectorMap {
    static_assert(std::is_default_constructible<Value>::value);

public:
    VectorMap() = default;

    void insert(Key key, Value value) {
        keys_.emplace_back(key);
        values_.emplace_back(value);
    }

    Value& operator[](const Key& key) {
        auto keyIterator = std::find(keys_.begin(), keys_.end(), key);
        if (keyIterator == keys_.end()) {
            keys_.emplace_back(key);
            values_.emplace_back(Value{});
            return values_.back();
        }

        auto dist = std::distance(keys_.begin(), keyIterator);
        return values_[dist];
    }

    Value& at(Key key) {
        auto keyIterator = std::find(keys_.begin(), keys_.end(), key);
        if (keyIterator == keys_.end()) {
            throw std::out_of_range{"Out of range in map!"};
        }
        auto dist = std::distance(keys_.begin(), keyIterator);
        return values_[dist];
    }

private:
    //static_assert(std::is_default_constructible_v<Value>);
    std::vector<Key> keys_;
    std::vector<Value> values_;
};

int main() {
    VectorMap<int, char> map;
    map.insert(1, 'c');
    std::cout << map[1] << '\n';
    map[1] = 'e';         // replaces value under 1
    std::cout << map[1];  // prints 'e'
    map[2] = 'd';
    map.at(2);  // throw std::out_of_range
    std::cout << map[2];
    map.at(3) = 'd';

    return 0;
}
