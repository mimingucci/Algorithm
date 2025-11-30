#pragma once
#include <bits/stdc++.h>
using namespace std;

// fastio.hpp
// Fast input/output for competitive programming
// Usage:
//   FastInput in;
//   int a = in.readInt();
//   long long b = in.readLong();
//   string s = in.readToken();
//
//   FastOutput out;
//   out.writeInt(a);
//   out.writeChar('\n');
//   out.writeString(s);
//   out.flush();

struct FastInput {
    static const int BUFSIZE = 1 << 20;
    int idx, size;
    char buf[BUFSIZE];
    FastInput() : idx(0), size(0) {}

    inline char read() {
        if (idx >= size) {
            size = fread(buf, 1, BUFSIZE, stdin);
            idx = 0;
            if (size == 0) return EOF;
        }
        return buf[idx++];
    }

    int readInt() {
        char c;
        int x = 0;
        int sign = 1;
        do { c = read(); } while (c <= ' ' && c != EOF);
        if (c == '-') { sign = -1; c = read(); }
        for (; c >= '0' && c <= '9'; c = read()) x = x * 10 + (c - '0');
        return x * sign;
    }

    long long readLong() {
        char c;
        long long x = 0;
        int sign = 1;
        do { c = read(); } while (c <= ' ' && c != EOF);
        if (c == '-') { sign = -1; c = read(); }
        for (; c >= '0' && c <= '9'; c = read()) x = x * 10 + (c - '0');
        return x * sign;
    }

    string readToken() {
        char c;
        string s;
        do { c = read(); } while (c <= ' ' && c != EOF);
        for (; c > ' ' && c != EOF; c = read()) s.push_back(c);
        return s;
    }
};

struct FastOutput {
    static const int BUFSIZE = 1 << 20;
    int idx;
    char buf[BUFSIZE];
    FastOutput() : idx(0) {}
    ~FastOutput() { flush(); }

    inline void writeChar(char c) {
        if (idx == BUFSIZE) flush();
        buf[idx++] = c;
    }
    inline void writeString(const string &s) {
        for (char c : s) writeChar(c);
    }
    inline void writeInt(long long x, char end = '\0') {
        if (x < 0) { writeChar('-'); x = -x; }
        char s[24]; int n = 0;
        if (x == 0) s[n++] = '0';
        while (x > 0) { s[n++] = char('0' + x % 10); x /= 10; }
        for (int i = n - 1; i >= 0; --i) writeChar(s[i]);
        if (end) writeChar(end);
    }
    inline void flush() {
        if (idx) {
            fwrite(buf, 1, idx, stdout);
            idx = 0;
        }
    }
};
