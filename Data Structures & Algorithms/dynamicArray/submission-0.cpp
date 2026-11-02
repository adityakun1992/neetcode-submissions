class DynamicArray {
private:
    int mCapacity;
    size_t mSize;
    int* arr;

private:
    void increaseCapacity(int newCapacity) {
        int* temp = new int[newCapacity];
        for (size_t i = 0; i < mSize; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        mCapacity = newCapacity;
    }
public:

    DynamicArray(const int capacity) {
        arr = new int[capacity];
        mSize = 0;
        mCapacity = capacity;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (mSize == mCapacity) {
            increaseCapacity(mCapacity * 2);
        }
        mSize++;
        arr[mSize-1] = n;
    }

    int popback() {
        mSize--;
        return arr[mSize];

    }

    void resize() {
        increaseCapacity(mCapacity * 2);
    }

    int getSize() {
        return mSize;
    }

    int getCapacity() {
        return mCapacity;
    }
};
