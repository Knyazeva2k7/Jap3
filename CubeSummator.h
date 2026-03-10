#pragma once

#include "Summator.h"

class CubeSummator : public Summator {
public:
    CubeSummator();
    virtual ~CubeSummator();

    
    virtual long long transform(int i) const override;

    
    virtual const char* getType() const override;
};