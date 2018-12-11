#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetWindowShape(1920, 1080);
	ofSetFrameRate(60);
	ofSetBackgroundColor(ofColor::black);

	//SHIP SET UP
	m_shipImage.load("RocketShip.png"); //loading in image
	m_shipImage.resize(m_shipImage.getWidth() / 5, m_shipImage.getHeight() / 5); //resize image
	m_shipImage.setAnchorPoint(m_shipImage.getWidth() / 2, m_shipImage.getHeight()); //change anchor point to bottom of image
	m_shipAngle = 0.0f;
	m_shipPos = ofVec2f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);

	//BOX SET UP
	m_boxImage.load("Box.png");
	m_boxImage.resize(m_boxImage.getWidth() / 20, m_boxImage.getHeight() / 20);
	m_boxImage.setAnchorPoint(m_boxImage.getWidth() / 2, 0);
	m_boxAngle = 0.0f;
	m_boxPos = ofVec2f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);

	m_boxImage1.load("Box.png");
	m_boxImage1.resize(m_boxImage1.getWidth() / 20, m_boxImage1.getHeight() / 20);
	m_boxImage1.setAnchorPoint(m_boxImage.getWidth() / 2, 0);
	m_boxAngle1 = 0.0f;
	m_boxPos1 = ofVec2f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);

	//SUN SET UP
	m_sun.circle(0, 0, 50);
    m_sun.setCircleResolution(100);
	m_sun.setStrokeWidth(10);
	m_sun.setStrokeColor(ofColor::goldenRod);
	m_sun.setFillColor(ofColor::yellow);
	m_sunPos = ofVec2f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);

#pragma region Planet Set Up
	//MERCURY SET UP
    planetSetUp(m_mercury, 10, 255, 165, 0, 255, m_mercuryPos, 100, 0); //orange solid
    trailSetUp(m_mercuryTrail, 100);

	//VENUS SET UP
    planetSetUp(m_venus, 20, 188, 143, 143, 255, m_venusPos, 200, 0); //rosy brown solid
    trailSetUp(m_venusTrail, 200);

	//EARTH SET UP
    planetSetUp(m_earth, 25, 70, 130, 80, 255, m_earthPos, 300, 0); //blue steel solid
    trailSetUp(m_earthTrail, 300);

	//MARS SET UP
    planetSetUp(m_mars, 17, 139, 0, 0, 255, m_marsPos, 400, 0); //dark red solid
    trailSetUp(m_marsTrail, 400);

	//JUPITER SET UP
    planetSetUp(m_jupiter, 40, 244, 164, 96, 255, m_jupiterPos, 500, 0); //sandy brown solid
    trailSetUp(m_jupiterTrail, 500);

	//6th planet
	//SATURN SET UP
    planetSetUp(m_saturn, 35, 210, 180, 140, 255, m_saturnPos, 600, 0); //tan solid
    trailSetUp(m_saturnTrail, 600);

	//URANUS SET UP
    planetSetUp(m_uranus, 20, 127, 255, 212, 255, m_uranusPos, 700, 0); //aquamarine solid
    trailSetUp(m_uranusTrail, 700);

	//NEPTUNE SET UP
    planetSetUp(m_neptune, 20, 100, 149, 237, 255, m_neptunePos, 800, 0); //cornflower blue solid
    trailSetUp(m_neptuneTrail, 800);

	//MOON SET UP
    planetSetUp(m_moon, 5, 250, 235, 215, 255, m_moonPos, 50, 0); //antique white solid

	//PHOBOS SET UP
    planetSetUp(m_phobos, 4, 128, 128, 128, 255, m_phobosPos, -45, 0); //grey solid

	//DEIMOS SET UP
    planetSetUp(m_deimos, 4, 205, 92, 92, 255, m_deimosPos, 50, 25); //indian red solid

	//GANYMEDE SET UP
    planetSetUp(m_ganymede, 10, 119, 136, 153, 255, m_ganymedePos, -60, 0); //light slate grey solid

	//TITAN SET UP
    planetSetUp(m_titan, 9, 112, 128, 144, 255, m_titanPos, 60, 0); //slate grey solid
	planetSetUp(m_smallMoon, 4, 223, 223, 223, 255, m_smallMoonPos, 55, 0);
	planetSetUp(m_smallMoon1, 4, 223, 223, 223, 255, m_smallMoonPos1, 55, 0);

	//TITANIA SET UP
    planetSetUp(m_titania, 7, 211, 211, 211, 255, m_titaniaPos, -50, 0); //light grey solid

	//TRITON SET UP
    planetSetUp(m_triton, 9, 195, 176, 145, 255, m_tritonPos, 50, 0); //khaki solid
#pragma endregion Planet Set Up

	//start mouse and target positions
	m_mousePos = ofVec2f::zero();
	m_targetPos = ofVec2f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
}

//--------------------------------------------------------------
void ofApp::update() {

	//update position to always be in centre no matter the window size
	m_sunPos.x = ofGetWindowWidth() / 2;
	m_sunPos.y = ofGetWindowHeight() / 2;

	//get mouse positions
	m_mousePos.x = ofGetMouseX();
	m_mousePos.y = ofGetMouseY();

	//MERCURY UPDATES
	m_mercuryAngle += 1.5f;

	//VENUS UPDATES
	m_venusAngle += 1.0f;

	//EARTH UPDATES
	m_earthAngle += 0.8f;
	m_moonAngle += 0.03f;
	m_moonPos = ofVec2f(40 * cos(m_moonAngle), 60 * sin(m_moonAngle)); //elliptical orbit

	//MARS UPDATES
	m_marsAngle += 1.0f;
	m_phobosAngle += 0.04f;
	m_phobosPos = ofVec2f(20 * cos(m_phobosAngle), 50 * sin(m_phobosAngle)); //elliptical orbit
	m_deimosAngle += 0.05f;
	m_deimosPos = ofVec2f(25 * cos(m_deimosAngle), 60 * sin(m_deimosAngle)); //elliptical orbit

	//JUPITER UPDATES
	m_jupiterAngle += 0.5f;
	m_ganymedeAngle += 0.05f;
	m_ganymedePos = ofVec2f(55 * cos(m_ganymedeAngle), 85 * sin(m_ganymedeAngle)); //elliptical orbit

	//SATURN UPDATES
	m_saturnAngle += 0.6f;
	m_titanAngle += 0.07f;
	m_titanPos = ofVec2f(60 * cos(m_titanAngle), 90 * sin(m_titanAngle)); //elliptical orbit
	m_smallMoonAngle += 0.09f;
	m_smallMoonPos = ofVec2f(45 * cos(m_smallMoonAngle), 80 * sin(m_smallMoonAngle)); //elliptical orbit
	m_smallMoonAngle1 += 0.09f;
	m_smallMoonPos1 = ofVec2f(80 * cos(m_smallMoonAngle1), 45 * sin(m_smallMoonAngle1)); //elliptical orbit
	
	//URANUS UPDATES
	m_uranusAngle += 0.4f;
	m_titaniaAngle += 0.06f;
	m_titaniaPos = ofVec2f(50 * cos(m_titaniaAngle), 70 * sin(m_titaniaAngle)); //elliptical orbit

	//NEPTUNE UPDATES
	m_neptuneAngle += 0.3f;
	m_tritonAngle += 0.05f;
	m_tritonPos = ofVec2f(50 * cos(m_tritonAngle), 70 * sin(m_tritonAngle)); //elliptical orbit

	//SHIP UPDATES
	//convert position to angle
	ofVec2f shipToMouse = m_mousePos - m_shipPos;
	m_shipAngle = ofRadToDeg(atan2(shipToMouse.x, shipToMouse.y)) * -1.0f + 180; //looks towards mouse

	//lerp ship position
	m_shipPos.x = lerp(m_shipPos.x, m_targetPos.x, 0.03f); //constantly trying to move to target position
	m_shipPos.y = lerp(m_shipPos.y, m_targetPos.y, 0.03f);

	//lerp box position
	ofVec2f boxToShip = m_shipPos - m_boxPos;
	m_boxAngle = ofRadToDeg(atan2(boxToShip.x, boxToShip.y)) * 1.0f + 180.0f;
	m_boxPos.x = lerp(m_boxPos.x, m_shipPos.x, 0.1f);
	m_boxPos.y = lerp(m_boxPos.y, m_shipPos.y, 0.1f);

	//lerp other box position
	ofVec2f boxToBox = m_boxPos - m_boxPos1;
	m_boxAngle1 = ofRadToDeg(atan2(boxToBox.x, boxToBox.y)) * 1.0f + 180.0f;
	m_boxPos1.x = lerp(m_boxPos1.x, m_boxPos.x, 0.09f);
	m_boxPos1.y = lerp(m_boxPos1.y, m_boxPos.y, 0.09f);
}

//--------------------------------------------------------------
void ofApp::draw() {

	//draw sun in centre of screen
	ofPushMatrix();
		m_sun.draw(m_sunPos.x, m_sunPos.y);
	ofPopMatrix();

    //draw trails
    drawTrail();

#pragma region Draw Planets
	//draw mercury
	ofPushMatrix();
		ofTranslate(m_sunPos); //starts from centre where sun is
		ofRotate(m_mercuryAngle);
		ofTranslate(m_mercuryPos);
		m_mercury.draw();
	ofPopMatrix();

	//draw venus
	ofPushMatrix();
		ofTranslate(m_sunPos);
		ofRotate(m_venusAngle);
		ofTranslate(m_venusPos);
		m_venus.draw();
	ofPopMatrix();

	//draw earth
	ofPushMatrix();
		ofTranslate(m_sunPos);
		ofRotate(m_earthAngle);
		ofTranslate(m_earthPos);
		m_earth.draw();
		//draw moon
		ofPushMatrix(); 
			ofRotate(m_moonAngle);
			ofTranslate(m_moonPos);
			m_moon.draw();
		ofPopMatrix();
	ofPopMatrix();

	//draw mars
	ofPushMatrix();
		ofTranslate(m_sunPos);
		ofRotate(m_marsAngle);
		ofTranslate(m_marsPos);
		m_mars.draw();
		//draw phobos
		ofPushMatrix();
			ofRotate(m_phobosAngle);
			ofTranslate(m_phobosPos);
			m_phobos.draw();
		ofPopMatrix();
		//draw deimos
		ofPushMatrix();
			ofRotate(m_deimosAngle);
			ofTranslate(m_deimosPos);
			m_deimos.draw();
		ofPopMatrix();
	ofPopMatrix();

	//draw jupiter
	ofPushMatrix();
		ofTranslate(m_sunPos);
		ofRotate(m_jupiterAngle);
		ofTranslate(m_jupiterPos);
		m_jupiter.draw();
		//draw ganymede
		ofPushMatrix();
			ofRotate(m_ganymedeAngle);
			ofTranslate(m_ganymedePos);
			m_ganymede.draw();
		ofPopMatrix();
	ofPopMatrix();

	/*6th planet*/
	//draw saturn
	ofPushMatrix();
		ofTranslate(m_sunPos);
		ofRotate(m_saturnAngle);
		ofTranslate(m_saturnPos);
		m_saturn.draw();
		//draw titan
		ofPushMatrix();
			ofRotate(m_titanAngle);
			ofTranslate(m_titanPos);
			m_titan.draw();
		ofPopMatrix();
		//draw small moons
		ofPushMatrix();
			ofRotate(m_smallMoonAngle);
			ofTranslate(m_smallMoonPos);
			m_smallMoon.draw();
		ofPopMatrix();
		ofPushMatrix();
			ofRotate(m_smallMoonAngle1 + 30);
			ofTranslate(m_smallMoonPos1);
			m_smallMoon1.draw();
		ofPopMatrix();
		ofPushMatrix();
			ofRotate(m_smallMoonAngle + 60);
			ofTranslate(m_smallMoonPos);
			m_smallMoon.draw();
		ofPopMatrix();
		ofPushMatrix();
			ofRotate(m_smallMoonAngle1 + 90);
			ofTranslate(m_smallMoonPos1);
			m_smallMoon1.draw();
		ofPopMatrix();
		ofPushMatrix();
			ofRotate(m_smallMoonAngle + 120);
			ofTranslate(m_smallMoonPos);
			m_smallMoon.draw();
		ofPopMatrix();
		ofPushMatrix();
			ofRotate(m_smallMoonAngle1 + 150);
			ofTranslate(m_smallMoonPos1);
			m_smallMoon1.draw();
		ofPopMatrix();
		ofPushMatrix();
			ofRotate(m_smallMoonAngle + 180);
			ofTranslate(m_smallMoonPos);
			m_smallMoon.draw();
		ofPopMatrix();
		ofPushMatrix();
			ofRotate(m_smallMoonAngle1 + 210);
			ofTranslate(m_smallMoonPos1);
			m_smallMoon1.draw();
		ofPopMatrix();
		ofPushMatrix();
			ofRotate(m_smallMoonAngle + 240);
			ofTranslate(m_smallMoonPos);
			m_smallMoon.draw();
		ofPopMatrix();
		ofPushMatrix();
			ofRotate(m_smallMoonAngle1 + 270);
			ofTranslate(m_smallMoonPos1);
			m_smallMoon1.draw();
		ofPopMatrix();
		ofPushMatrix();
			ofRotate(m_smallMoonAngle + 300);
			ofTranslate(m_smallMoonPos);
			m_smallMoon.draw();
		ofPopMatrix();
		ofPushMatrix();
			ofRotate(m_smallMoonAngle1 + 330);
			ofTranslate(m_smallMoonPos1);
			m_smallMoon1.draw();
		ofPopMatrix();
	ofPopMatrix();

	//draw uranus
	ofPushMatrix();
		ofTranslate(m_sunPos);
		ofRotate(m_uranusAngle);
		ofTranslate(m_uranusPos);
		m_uranus.draw();
		//draw titania
		ofPushMatrix();
			ofRotate(m_titaniaAngle);
			ofTranslate(m_titaniaPos);
			m_titania.draw();
		ofPopMatrix();
	ofPopMatrix();

	//draw neptune
	ofPushMatrix();
		ofTranslate(m_sunPos);
		ofRotate(m_neptuneAngle);
		ofTranslate(m_neptunePos);
		m_neptune.draw();
		//draw triton
		ofPushMatrix();
			ofRotate(m_tritonAngle);
			ofTranslate(m_tritonPos);
			m_triton.draw();
		ofPopMatrix();
	ofPopMatrix();
#pragma endregion Draw Planets

#pragma region Draw Ship + Boxes
	//draw boxes being pulled by ship (drawn first to not overlap ship)
	ofPushMatrix();
		ofTranslate(m_boxPos);
		ofRotate(m_boxAngle);
		m_boxImage.draw(0, 0);
	ofPopMatrix();
	ofPushMatrix();
		ofTranslate(m_boxPos1);
		ofRotate(m_boxAngle1);
		m_boxImage1.draw(0, 0);
	ofPopMatrix();

	//draw ship
	ofPushMatrix();
		ofTranslate(m_shipPos);
		ofRotate(m_shipAngle);
		m_shipImage.draw(0, 0);
	ofPopMatrix();
#pragma endregion Draw Ship + Boxes
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	m_targetPos.x = (float)x;
	m_targetPos.y = (float)y;
}

void ofApp::mouseDragged(int x, int y, int button)
{
	m_targetPos.x = (float)x;
	m_targetPos.y = (float)y;
}

float ofApp::lerp(float start, float end, float percent)
{
	return (start + percent * (end - start));
}

void ofApp::planetSetUp(ofPath &planet, int radius, int r, int g, int b, int alpha, ofVec2f &planetPos, int posX, int posY)
{
    planet.circle(0, 0, radius);
    planet.setCircleResolution(100);
    planet.setFillColor(ofColor(r, g, b, alpha));
    planetPos = ofVec2f (posX, posY);
}

void ofApp::trailSetUp(ofPath &trail, int radius)
{
    trail.circle(0, 0, radius);
    trail.setCircleResolution(100);
    trail.setStrokeWidth(2);
    trail.setStrokeColor(ofColor(255, 255, 255, 125));
    trail.setFilled(false);
}

void ofApp::drawTrail()
{
    m_mercuryTrail.draw(m_sunPos.x, m_sunPos.y);
    m_venusTrail.draw(m_sunPos.x, m_sunPos.y);
    m_earthTrail.draw(m_sunPos.x, m_sunPos.y);
    m_marsTrail.draw(m_sunPos.x, m_sunPos.y);
    m_jupiterTrail.draw(m_sunPos.x, m_sunPos.y);
    m_saturnTrail.draw(m_sunPos.x, m_sunPos.y);
    m_uranusTrail.draw(m_sunPos.x, m_sunPos.y);
    m_neptuneTrail.draw(m_sunPos.x, m_sunPos.y);
}