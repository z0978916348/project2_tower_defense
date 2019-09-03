#include <algorithm>
#include <string>
#include "Image.hpp"
#include "Point.hpp"
#include "Slider.hpp"
#include <iostream>
using namespace std;
Slider::Slider(float x, float y, float w, float h) :
	ImageButton("stage-select/slider.png", "stage-select/slider-blue.png", x, y),
	Bar("stage-select/bar.png", x, y, w, h),
	End1("stage-select/end.png", x, y + h / 2, 0, 0, 0.5, 0.5),
	End2("stage-select/end.png", x + w, y + h / 2, 0, 0, 0.5, 0.5) {
	Position.x += w;
	Position.y += h / 2;
	Anchor = Engine::Point(0.5, 0.5);
}
// TODO 4 (0/6): Finish the 6 functions below and ensure it can control both BGM and SFX volume.
//               The slider shouldn't be dragged outside the bar, and you should also keep the mouse-in / mouse-out effect.
void Slider::Draw() const {
    Engine::ImageButton::Draw();
    Slider::Bar.Draw();
    Slider::End1.Draw();
    Slider::End2.Draw();
	// TODO 4 (1/6): Draw all components.
}
void Slider::SetOnValueChangedCallback(std::function<void(float value)> onValueChangedCallback) {
    OnValueChangedCallback =  onValueChangedCallback;
	// TODO 4 (2/6): Set the function pointer. Can imitate ImageButton's 'SetOnClickCallback'.
}
void Slider::SetValue(float value) {
    if ( Down ) {
        if (OnValueChangedCallback){
            OnValueChangedCallback(value);
        }
    }
	// TODO 4 (3/6): Call 'OnValueChangedCallback' when value changed. Can imitate ImageButton's 'OnClickCallback'.
	//               Also move the slider along the bar, to the corresponding position.
}
void Slider::OnMouseDown(int button, int mx, int my) {
    float len = (End2.Position.x-End1.Position.x);
    if ((button & 1)) {
        Down = true;
        SetValue( (Position.x-End1.Position.x)/len );
    }
	// TODO 4 (4/6): Set 'Down' to true if mouse is in the slider.
}
void Slider::OnMouseUp(int button, int mx, int my) {
    if (button & 1) {
        Down = false;
    }
	// TODO 4 (5/6): Set 'Down' to false.
}
void Slider::OnMouseMove(int mx, int my) {
    float len = End2.Position.x-End1.Position.x;

    if ( Down && mx>=End1.Position.x && mx<=End2.Position.x && my<=Position.y+25 && my>=Position.y-25){
        Position.x = mx;
        SetValue( (Position.x-End1.Position.x)/len );
        //cout << "value = " << (Position.x-End1.Position.x)/len << endl;
        bmp = imgIn;
    } else {
        bmp = imgOut;
    }

	// TODO 4 (6/6): Clamp the coordinates and calculate the value. Call 'SetValue' when you're done.
}
