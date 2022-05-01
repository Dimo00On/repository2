#include "DamageArtifact.h"
#include "../Const/Constants.h"
#include "../Types/EffectType.h"

void DamageArtifact::setMultiplier(float value) {
    multiplier = value;
}

void DamageArtifact::doSomething(LiveObject *user, LiveObject *target) {
    std::vector<float> scaling(3, 1);
    std::vector<int> power(6, 0);
    std::vector<bool> params(2, false);
    scaling[static_cast<int>(OrderScale::Damage)] = multiplier;
    params[static_cast<int>(OrderParams::Good)] = true;
    power[static_cast<int>(OrderPower::Time)] = kInfinity;
    EffectType effect(scaling, power, params, description);
    user->takeEffects({effect});
}

Reward* DamageArtifact::clone() {
    return new DamageArtifact(*this);
}