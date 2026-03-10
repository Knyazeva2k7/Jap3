#pragma once


class Summator {
public:
    Summator();
    virtual ~Summator();
    virtual long long transform(int i) const;  
    long long sum(int N) const;
    virtual const char* getType() const;
};