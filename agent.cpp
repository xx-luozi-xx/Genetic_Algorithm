#include "agent.h"
#include "genetic_setting.h"

#include <stdlib.h>     //rand()
#include <assert.h>     //assert()

Agent::Agent(int chromosome_len)
    :chromosome_len_(chromosome_len){
    for(int i = 0; i < chromosome_len; ++i){
        chromosome_[0].push_back(rand());
        chromosome_[1].push_back(rand());
    }
}
Agent::Agent(const Agent& father, const Agent& mather){
    assert(father.chromosome_len() == mather.chromosome_len());
    
    chromosome_len_ = father.chromosome_len();

    //choose chromosome randomly 
    chromosome_[0] = father.chromosome_[rand()%2];
    chromosome_[1] = mather.chromosome_[rand()%2];

    //probability corss
    if(rand()/double(RAND_MAX) <= P_CROSS){
        cross();
    }

    //probability mutation
    if(rand()/double(RAND_MAX) <= P_MUTATION){
        mutation();
    }
}

void Agent::cross(){
    //switch chromosome from idx[0] to idx[rand()]
    int range = rand()%chromosome_len();
    for(int i = 0; i < range; ++i){
        std::swap(chromosome_[0][i], chromosome_[1][i]);
    }
}

void Agent::mutation(){
    //choose one genetic randomly and change.
    int chr_idx = rand()%2;
    int gene_idx = rand()%chromosome_len();

    chromosome_[chr_idx][gene_idx] = rand();
}

int Agent::chromosome_len() const{
    return chromosome_len_;
}