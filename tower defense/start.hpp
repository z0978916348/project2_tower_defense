#ifndef START_HPP
#define START_HPP
#include "IScene.hpp"

class start final : public Engine::IScene {
public:
 explicit start() = default;
 void Initialize() override;
 void BackOnClick(int stage);
};

#endif // START_HPP
