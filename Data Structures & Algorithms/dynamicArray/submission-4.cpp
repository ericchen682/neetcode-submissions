class DynamicArray {
public:
    DynamicArray(int capacity) {
        size = capacity;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (arr.size() == size) resize();
        arr.push_back(n);
    }

    int popback() {
        int temp = arr[arr.size()-1];
        arr.pop_back();
        return temp;
    }

    void resize() {
        size *= 2;
    }

    int getSize() {
        return arr.size();
    }

    int getCapacity() {
        return size;
    }
private:
    int size;
    vector<int> arr;
};
