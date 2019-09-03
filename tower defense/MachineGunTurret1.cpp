#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "NewBullet.hpp"
#include "Group.hpp"
#include "MachineGunTurret1.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

const int MachineGunTurret1::Price = 300;
MachineGunTurret1::MachineGunTurret1(float x, float y) :
	Turret("play/tower-base.png", "play/turret-7.png", x, y, 400, Price, 0.1) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
}
void MachineGunTurret1::CreateBullet() {
	Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
	float rotation = atan2(diff.y, diff.x);
	Engine::Point normalized = diff.Normalize();
	// Change bullet position to the front of the gun barrel.
	getPlayScene()->BulletGroup->AddNewObject(new NewBullet(Position + normalized * 36, diff, rotation, this));
	AudioHelper::PlayAudio("gun.wav");
}
