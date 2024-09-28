class MyCircularDeque {
public:
    MyCircularDeque(int k) : capacity(k), front(0), rear(k - 1), size(0), data(k) {}

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        size++;
        front = (front - 1 + capacity) % capacity;
        data[front] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        size++;
        rear = (rear + 1) % capacity;
        data[rear] = value;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        size--;
        front = (front + 1) % capacity;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        size--;
        rear = (rear - 1 + capacity) % capacity;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : data[front];
    }

    int getRear() {
        return isEmpty() ? -1 : data[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

private:
    int capacity;
    int front;
    int rear;
    int size;
    vector<int> data;
};