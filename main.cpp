#include "genetic_setting.h"

#include "entity.h"
#include "rock_paper_scissors.h"

#include <vector>
#include <queue>    //priproty_queue
#include <tuple>    //pair
#include <algorithm>//sort()

#include <time.h>   //time()
#include <stdlib.h> //rand(), srand()

#include <iostream>  

using namespace Genetic_Algorithm;

int main1(){
    printf("testing");
}

int main(){
    srand(time(0)^rand());
    //init a polulation with POPULATION_SIZE
    std::vector<std::pair<int, Entity>> population(POPULATION_SIZE, {0, Entity(6, 3)});
    for(int evo_round = 0; evo_round < EVOLUTIONARY_ROUND; ++evo_round){
        // testing
        for(int i = 0; i < population.size(); ++i){
            if(population[i].first == 0){
                using namespace rock_paper_scissors;
                Game game;
                for(int game_round = 0; game_round < 10; ++game_round){
                    int reaction = population[i].second.reaction({game.get_environment()});
                    population[i].first += game.operate(type(reaction));
                }
            }
        }

        //die out
        std::sort(population.begin(), population.end(), [](const std::pair<int, Entity>& lhs, const std::pair<int, Entity>& rhs){
            return lhs.first > rhs.first;
        });
        const int save_cnt = SAVING_RAGE*POPULATION_SIZE;
        population.erase(population.begin()+save_cnt, population.end());

        //multiply
        while(population.size() < POPULATION_SIZE){
            const Entity& father = population[rand()%population.size()].second;
            const Entity& mather = population[rand()%population.size()].second;
            population.push_back({0, Entity(father, mather)});
        }
    }
    
    //finding the best entity
    const Entity* best = nullptr;
    int best_score = -0x7fffffff;
    for(int i = 0; i < population.size(); ++i){
        if(population[i].first == 0){
            using namespace rock_paper_scissors;
            Game game;
            for(int game_round = 0; game_round < 10; ++game_round){
                int reaction = population[i].second.reaction({game.get_environment()});
                population[i].first += game.operate(type(reaction));
            }
        }
        if(population[i].first > best_score){
            best = &population[i].second;
        }
    }

    //testing the action of the best entity
    std::cout << "the best entity:" << best->show_chromosome() << '\n';
    std::cout << "score: " << best_score << '\n';
    {using namespace rock_paper_scissors;
        Game game;
        for(int game_round = 0; game_round < 10; ++game_round){
            int env = game.get_environment();
            int reaction = best->reaction({env});
            std::cout << "env:" << to_type(reaction) << "   reaction:" << to_type(reaction) << "\n";
        } 
    }
    return 0;
}