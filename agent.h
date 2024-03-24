#pragma once

#include <vector>

class Agent{
public:
    Agent(int chromosome_len);
    Agent(const Agent& father, const Agent& mather);

    void cross();
    void mutation();

    int chromosome_len() const;
private:
    int chromosome_len_;
    std::vector<int> chromosome_[2];
};