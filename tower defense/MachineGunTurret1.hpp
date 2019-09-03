#ifndef MACHINEGUNTURRET1_HPP
#define MACHINEGUNTURRET1_HPP
#include "Turret.hpp"

class MachineGunTurret1: public Turret {
public:
	static const int Price;
    MachineGunTurret1(float x, float y);
	void CreateBullet() override;
};
#endif // MACHINEGUNTURRET1_HPP
