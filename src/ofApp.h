#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	//SUN
	ofPath m_sun;
	ofVec2f m_sunPos;

    //TRAIL
    ofPath m_trail;

	//PLANETS
	ofPath m_mercury;
	float m_mercuryAngle;
	ofVec2f m_mercuryPos;
    ofPath m_mercuryTrail;

	ofPath m_venus;
	float m_venusAngle;
	ofVec2f m_venusPos;
    ofPath m_venusTrail;

	ofPath m_earth;
	float m_earthAngle;
	ofVec2f m_earthPos;
    ofPath m_earthTrail;

	ofPath m_mars;
	float m_marsAngle;
	ofVec2f m_marsPos;
    ofPath m_marsTrail;

	ofPath m_jupiter;
	float m_jupiterAngle;
	ofVec2f m_jupiterPos;
    ofPath m_jupiterTrail;

	ofPath m_saturn;
	float m_saturnAngle;
	ofVec2f m_saturnPos;
    ofPath m_saturnTrail;

	ofPath m_uranus;
	float m_uranusAngle;
	ofVec2f m_uranusPos;
    ofPath m_uranusTrail;

	ofPath m_neptune;
	float m_neptuneAngle;
	ofVec2f m_neptunePos;
    ofPath m_neptuneTrail;

	//MOONS
	//earth
	ofPath m_moon;
	float m_moonAngle;
	ofVec2f m_moonPos;

	//mars
	ofPath m_phobos;
	float m_phobosAngle;
	ofVec2f m_phobosPos;
	ofPath m_deimos;
	float m_deimosAngle;
	ofVec2f m_deimosPos;

	//jupiter
	ofPath m_ganymede;
	float m_ganymedeAngle;
	ofVec2f m_ganymedePos;

	//saturn
	ofPath m_titan;
	float m_titanAngle;
	ofVec2f m_titanPos;
	ofPath m_smallMoon;
	float m_smallMoonAngle;
	ofVec2f m_smallMoonPos;
	ofPath m_smallMoon1;
	float m_smallMoonAngle1;
	ofVec2f m_smallMoonPos1;

	//uranus
	ofPath m_titania;
	float m_titaniaAngle;
	ofVec2f m_titaniaPos;

	//neptune
	ofPath m_triton;
	float m_tritonAngle;
	ofVec2f m_tritonPos;

	//SPACESHIP
	ofImage m_shipImage;
	float m_shipAngle;
	ofVec2f m_shipPos;

	//BOXES
	ofImage m_boxImage;
	float m_boxAngle;
	ofVec2f m_boxPos;

	ofImage m_boxImage1;
	float m_boxAngle1;
	ofVec2f m_boxPos1;

	//STORING POSITIONS
	ofVec2f m_mousePos;
	ofVec2f m_targetPos; //saving where mouse was clicked

	void mousePressed(int x, int y, int button);
	void mouseDragged(int x, int y, int button);
	float lerp(float start, float end, float percent);
    void planetSetUp(ofPath &planet, int radius, int r, int g, int b, int alpha, ofVec2f &planetPos, int posX, int posY);
    void trailSetUp(ofPath &trail, int radius);
    void drawTrail();
};

