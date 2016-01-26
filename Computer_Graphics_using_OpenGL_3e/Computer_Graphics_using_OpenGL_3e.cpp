#include "stdafx.h"
#include"OpenglDraw.h"

#include<fstream>
#include<sstream>
#include<vector>
#include<iomanip>

GLsizei winWidth = 680, winHeight = 480;
GLint xRaster = 0, yRaster = 0;
int myClientCount = 0;

GLint dataValue[12] = { 420,342,324,310,262,185,
190,196,217,240,312,438 };

using namespace std;

void myInit() {

	glClearColor(1.0, 1.0, 1.0, 0.0);		// 设置背景颜色为白色
	glColor3f(0.0f, 0.0f, 0.0f);			// 设置绘图颜色为黑色
	glPointSize(2.0);						// 设置点的大小为4x4像素
	glMatrixMode(GL_PROJECTION);			// 设置合适的矩阵
	glLoadIdentity();						// 后台将解释
	gluOrtho2D(0, winWidth, 0, winHeight);	// 接下来将完整的说明
}
/***************************************** myGlutMouse() **********/

void myGlutMouse(int button, int button_state, int x, int y)
{
}
/**************************************** myGlutKeyboard() **********/

void myGlutKeyboard(unsigned char Key, int x, int y)
{
	switch (Key)
	{
	case 27:
	case 'q':
		exit(0);
		break;
	};

	glutPostRedisplay();
}
/***************************************** myGlutIdle() ***********/

int main_window;
void myGlutIdle(void)
{
	/* According to the GLUT specification, the current window is
	undefined during an idle callback.  So we need to explicitly change
	it if necessary */
	if (glutGetWindow() != main_window)
		glutSetWindow(main_window);

	/*  GLUI_Master.sync_live_all();  -- not needed - nothing to sync in this
	application  */

	glutPostRedisplay();
}

/**************************************** control_cb() *******************/
/* GLUI control callback                                                 */
GLUI_RadioGroup *appIdGroup;
GLUI_RadioGroup *platformGroup;
GLUI_EditText *versionText;
GLUI_EditText *channelNoStartText;
GLUI_EditText *channelNoEndText;
GLUI_EditText *filepathText;

int appId;
int platform;
int version;
int channelNoStart;
int channelNoEnd;
string filepath="./channel_number.txt";


// 应用ID
void getAppId(int control)
{
	appId = appIdGroup->get_int_val();
}
// 平台
void getPlatform(int control)
{
	platform = platformGroup->get_int_val()+2;
}
// 版本
void getVersion(int control)
{
	version = versionText->get_int_val();
}
// 渠道号开始
void getChannelNoStart(int control)
{
	channelNoStart = channelNoStartText->get_int_val();
}
// 渠道号结束
void getChannelNoEnd(int control)
{
	channelNoEnd = channelNoEndText->get_int_val();
}

vector<vector<char>> myclientArr;
// 文件路径
void getFilepath(int control)
{
	string file;
	file = filepathText->get_text();
	if (file != "") {
		filepath = file;
		myclientArr.clear();
	}
	fstream fin(filepath, ios::in);
	fstream fcout("channel.txt", ios::out);

	string line;
	while (getline(fin, line)) //从文件中读取字符串到输入输出流中。不可以换成get（）。
	{
		//fcout << app_id << platform << version << setw(4) << setfill('0') << line << "00000" << "\n"; //写入数据
		stringstream myclient_str;
		myclient_str << setw(2) << setfill('0') << appId
			<< setw(1) << platform
			<< setw(4) << setfill('0') << version
			<< setw(4) << setfill('0') << line << "00000";

		cout << myclient_str.str() << endl;
		fcout << myclient_str.str() << "\n"; //写入数据
		vector<char> myclient;
		char ch;
		while ((ch = myclient_str.get()) != EOF) {
			myclient.push_back(ch);
		}
		myclientArr.push_back(myclient);
		myClientCount++;
	}
	fin.close();

}

// 完成
void submit(int control)
{
	cout << "appId:" << appId << endl;
	cout << "platform:" << platform << endl;
	cout << "version:" << version << endl;
	cout << "channel number start:" << channelNoStart << endl;
	cout << "channel number end:" << channelNoEnd << endl;


	char ch;
	if (myclientArr.begin() == myclientArr.end()) {
		fstream fcout("channel.txt", ios::out);
		for (int i = channelNoStart;i <= channelNoEnd;++i) {
			stringstream myclient_str;
			myclient_str << setw(2) << setfill('0') << appId
				<< setw(1) << platform
				<< setw(4) << setfill('0') << version
				<< setw(4) << setfill('0') << i << "00000";

			fcout << myclient_str.str() << "\n"; //写入数据

			vector<char> myclient;
			while ((ch = myclient_str.get()) != EOF) {
				myclient.push_back(ch);
			}
			myclientArr.push_back(myclient);
			myClientCount++;
		}
		fcout.close();
	}

	// 完成后提示语
	GLUI *glui_bt = GLUI_Master.create_glui_subwindow(main_window, GLUI_SUBWINDOW_BOTTOM);
	stringstream result;
	result << "done! " << myClientCount << " myClient number were created. press [q] to quit!";
	string str = result.str();
	glui_bt->add_statictext(str.c_str());
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);					// Clear display window.

	glColor3f(0.0, 0.0, 0.0);						// Set marker color to red.
	xRaster = 10;
	yRaster = winHeight-20;									// Display chart labels.
	for (auto client : myclientArr) {
		glRasterPos2i(xRaster, yRaster);
		for (auto mc : client) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, mc);
		}
		yRaster -= 20;
	}
	glFlush();
}

//------main------
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	main_window = glutCreateWindow("The Famous Sinc Function");
	glutDisplayFunc(myDisplay);
	GLUI_Master.set_glutKeyboardFunc(myGlutKeyboard);
	GLUI_Master.set_glutMouseFunc(myGlutMouse);
	myInit();

	GLUI *glui = GLUI_Master.create_glui_subwindow(main_window,GLUI_SUBWINDOW_RIGHT); /* name, flags,
															  x, and y */
	// 应用ID
	glui->add_statictext("Please Select APP ID:");
	int *liveVar = {0};
	appIdGroup = glui->add_radiogroup(liveVar,1,getAppId);
	glui->add_radiobutton_to_group(appIdGroup,"00:none");
	glui->add_radiobutton_to_group(appIdGroup,"01:jing qi");
	glui->add_radiobutton_to_group(appIdGroup,"02:yun qi");
	glui->add_radiobutton_to_group(appIdGroup,"03:O2O business");
	glui->add_radiobutton_to_group(appIdGroup,"04:shuo sheng");
	glui->add_radiobutton_to_group(appIdGroup,"05:yu er");
	glui->add_radiobutton_to_group(appIdGroup,"06:jing qi PRO");
	glui->add_radiobutton_to_group(appIdGroup,"07:you zi jie");
	glui->add_radiobutton_to_group(appIdGroup,"08:yun qi PRO");
	glui->add_separator();

	//版本号
	versionText = glui->add_edittext("version:", GLUI_EDITTEXT_INT,0,11,getVersion);
	glui->add_separator();

	// 平台
	glui->add_statictext("Please Select platform:");
	platformGroup = glui->add_radiogroup(liveVar,2,getPlatform);
	glui->add_radiobutton_to_group(platformGroup,"2:IOS");
	glui->add_radiobutton_to_group(platformGroup,"3:ANDROID");
	glui->add_radiobutton_to_group(platformGroup,"4:IPAD");
	glui->add_radiobutton_to_group(platformGroup,"5:WINDOWS PHONE");
	glui->add_radiobutton_to_group(platformGroup,"6:ANDROID PAD");
	glui->add_separator();

	//渠道号
	glui->add_statictext("channel number:");
	channelNoStartText = glui->add_edittext("From:",GLUI_EDITTEXT_INT,0,12,getChannelNoStart);
	channelNoEndText = glui->add_edittext("To:",GLUI_EDITTEXT_INT,0,13,getChannelNoEnd);

	glui->add_statictext("or enter file path:");
	filepathText = glui->add_edittext("file path:",GLUI_EDITTEXT_STRING,0,13,getFilepath);

	glui->add_separator();
	glui->add_button("submit",1, submit);
	
	GLUI_Master.set_glutIdleFunc(NULL);
	glui->set_main_gfx_window(main_window);
	GLUI_Master.set_glutIdleFunc(myGlutIdle);

	glutMainLoop();
}






