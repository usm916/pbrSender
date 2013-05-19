#include "testApp.h"

#include "ofxPublishScreen.h"

ofColor color;

ofxPublishScreen::FboPublisher pub;

//--------------------------------------------------------------
void testApp::setup()
{
    loadFile("ini.txt");
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	
//	ofBackground(30);
//	
//	color.r = ofRandom(255);
//	color.g = ofRandom(255);
//	color.b = ofRandom(255);
    mClient.setup();
    
    mClient.setApplicationName(appName);
    mClient.setServerName("");
    
	pub.setup(portNum, sWidth, sHeight);
}

//--------------------------------------------------------------
void testApp::update()
{
	pub.begin();
    ofSetColor(255);
    mClient.draw(0, 0);
//    ofClear(color.r, color.g, color.b);
//	ofCircle(ofGetMouseX(), ofGetMouseY(), 100);
	pub.end();
	
	ofSetWindowTitle("get syphon to pbrSender | "+ofToString(pub.getFps(), 2));
}

//--------------------------------------------------------------
void testApp::draw()
{
	pub.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
//	color.r = ofRandom(255);
//	color.g = ofRandom(255);
//	color.b = ofRandom(255);
}

//-----------------------------------------------------------------------------
void testApp::loadFile(string objFileName){
    ifstream fin; //declare a file stream
    fin.open( ofToDataPath(objFileName).c_str() ); //open your text file
    if(!fin.is_open()){
//        stringstream ss;
//        ss.str("");
//        ss << "Faled to import ini file";
//        ofDrawBitmapString(ss.str(), 50,50);
//        cout << "faled to open the file.\nCheck your ini.txt" << endl;
//        cout << "setted address to\nurl: localhost\nport: 20000" << endl;
        address = "localhost";
        portNum = 20000;
    }
    
    while(fin!=NULL) //as long as theres still text to be read
    {
        string str; //declare a string for storage
        stringstream sstr;
        sstr.str("");
        getline(fin, str); //get a line from the file, put it in the string
        sstr << str;
        string typ;
        string adr;
        char c;
        sstr >> typ >> adr;
        if(typ=="url"){
            address = adr;
            cout << "url: " << adr << endl;
        }
        if(typ=="port"){
            portNum = ofToInt(adr);
            cout << "port: " << adr << endl;
        }
        if(typ=="appName"){
            appName = ofToInt(adr);
            cout << "name: " << adr << endl;
        }
        if(typ=="w"){
            sWidth = ofToInt(adr);
            cout << "w: " << adr << endl;
        }
        if(typ=="h"){
            sHeight = ofToInt(adr);
            cout << "h: " << adr << endl;
        }
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}