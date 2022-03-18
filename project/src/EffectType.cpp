#include "EffectType.h"
EffectType::EffectType(const std::vector<float>& scaling, const std::vector<int>& power,
                       const std::vector<bool>& params, const std::string& newDescription) {
    defenceInfluenceScale = scaling[0];
    attackInfluenceScale = scaling[1];
    hpInfluenceScale = scaling[2];
    defenceInfluencePower = power[0];
    attackInfluencePower = power[1];
    hpInfluencePower = power[2];
    cardAmountInfluence = power[3];
    actionAmountInfluence = power[4];
    time = power[5];
    isGood = params[0];
    isOnArea = params[1];
    description = newDescription;
}
