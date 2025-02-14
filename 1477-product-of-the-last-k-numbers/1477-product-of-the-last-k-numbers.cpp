class ProductOfNumbers {

private:
    vector<int> prefix;

public:
    ProductOfNumbers() {
        prefix.clear();
        prefix.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            prefix.clear();
            prefix.push_back(1);
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {
        if (prefix.size() <= k) {
            return 0;
        }
        int n = prefix.size();
        return prefix[n - 1] / prefix[n - k - 1];
    }
};