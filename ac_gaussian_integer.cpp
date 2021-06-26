struct Gi {
    long long a, b;

    explicit Gi(long long x = 0, long long y = 0) : a(x), b(y) {}

    Gi operator*(const Gi &other) const {
        return Gi(a * other.a - b * other.b, a * other.b + b * other.a);
    }

    Gi operator-(const Gi &other) const {
        return Gi(a - other.a, b - other.b);
    }

    bool operator<(const Gi &other) const {
        if (a == other.a) return b < other.b;
        return a < other.a;
    }

    bool operator>(const Gi &other) const {
        if (a == other.a) return b > other.b;
        return a > other.a;
    }

    bool operator==(const Gi &other) const {
        return a == other.a && b == other.b;
    }

    [[nodiscard]] long long norm() const {
        return a * a + b * b;
    }
};