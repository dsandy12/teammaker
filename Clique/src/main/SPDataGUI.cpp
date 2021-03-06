/*
 * SPDataGUI.h
 *
 * Description:
 *	This class creates the steampunk data entry window for the GUI, including:
 *	- a project file input selector
 *	- a entry for course survey questionnaire
 *	- entry for semester and year to narrow down course selection *
 *
 * Copyright (C) 2020 ASU
 *	Matthew Cilibraise, Myles Colina, Cristi DeLeo, Elizabeth Marquise, Sean Rogers,
 *	initial idea contributed by Douglas Sandy, All rights reserved
 *
 *
 * List of functions:
 * void SteamAnimate(Fl_Window *w, Fl_Box *b, Fl_Box *b2, int end)
 * 		- Animates steam GUI and gears
 *
 * 	SPDataGUI(Fl_Window *win, vector<SoupCookie> cookies)
 * 		- Constructor function for the class section selector GUI window
 *
 * ~SPDataGUI
 * 		- Destructor function for the class section selector GUI window
 *
 * FindCoursesClick(Fl_Widget  *w)
 *		- updates the Browser based on the year and semester selected. Then
 *		it searches the course sections for the relevant courses, and displays.
 *
 * GobackClick(Fl_Widget  *w)
 *		- callback for the Go back button, returns to the previous GUI window.
 *
 *	YesClick(Fl_Widget  *w)
 *		- callback for the Confirm button, opens the next GUI window.
 *
 *	CancelClick1(Fl_Widget *w)
 *		- event handler to cancel
 *
 *	CancelClick2(Fl_Widget *w)
 *		- event handler to cancel
 *
 *	ConfirmClick(Fl_Widget *w)
 *		- callback for the Confirm button, opens the next GUI window.
 *
 *	GenerateTeamsClick(Fl_Widget *w)
 *		- event handler for generate teams button
 *
 *	chooseProjectFile_cb(Fl_Widget*)
 *		- event handler for the user to select the project file
 */


/********* BEGINNING OF INCLUSIONS **********/


/* Class Inclusions */
#include "SPDataGUI.h"
#include "SteamPunkGUI1.h"
#include "GUIStyles.h"
#include "SteamPunkGUI1.h"
#include "ClassSectionJson.h"
#include "ClassSection.h"
#include "CookieManager.h"
#include "Utility.h"
#include "main.h"


/* Library Inclusions */
#include <libsoup/soup.h>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <thread>
#include <stdio.h>
#include <FL/names.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>


/* FLTK Inclusions */
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Check_Browser.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_RGB_Image.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_File_Chooser.H>


/********* BEGINNING OF PROGRAM CODE **********/


//Forward Variable Declarations
Fl_PNG_Image Pipes1("./Images/Steampunk/PipesBrick1.png");
Fl_PNG_Image Pipes2("./Images/Steampunk/PipesBrick2.png");
Fl_PNG_Image Wall1("./Images/Steampunk/Wall1.png");
Fl_PNG_Image Wall2("./Images/Steampunk/Wall3.png");
Fl_PNG_Image Wall3("./Images/Steampunk/Wall14.png");
Fl_PNG_Image *SteamPngs[13];
Fl_PNG_Image *Steam2Pngs[13];
string projectFilePath;
vector<SoupCookie> cookiedataSP;


/*************************************************************************************
 * Title: SteamAnimate
 *
 * Description: Animates steam GUI and gears
 *
 *Arguments: Fl_Window *w, Fl_Box *b, Fl_Box *b2, int end
 *
 *Returns: nothing
 */
void SteamAnimate(Fl_Window *w, Fl_Box *b, Fl_Box *b2, int end) {

	int i = 0;
	int x = 0;
	int y = 0;

	while (y != end) {

		if (x == 1) {

			b->image(SteamPngs[i]);
			w->redraw();
			Fl::check();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));

		} else if (x == 0) {

			b2->image(Steam2Pngs[i]);
			w->redraw();
			Fl::check();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));

		}

		i++;

		if (i == 13) {

			Fl::check();
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			Fl::check();
			i = 0;
			y++;

			if (x == 1) {
				x = 0;
			} else if (x == 0) {
				x = 1;
			}

		}
	}
}


/*************************************************************************************
 * Title: SPDataGUI
 *
 * Description:
 *		Constructor function for the class section selector GUI window.
 *
 *Arguments: Fl_Window *win, vector<SoupCookie> cookies
 *
 *Returns: nothing
 */
SPDataGUI::SPDataGUI(Fl_Window *win, vector<SoupCookie> cookies) {


	//reference to the homepage window
	prevWindow = win;
	cookiedataSP = cookies;
	ClassSectionJson CSJson;


	//read in all the courses from canvas.
	const string CLASS_SECTION_FILE = "./allCourses.json";
	const int NUM_CLASS_SECTIONS = CSJson.getNumClasses(CLASS_SECTION_FILE);
	num_of_all_courses = NUM_CLASS_SECTIONS;
	num_of_selected_courses = 0;
	ClassSection Courses[NUM_CLASS_SECTIONS];
	CSJson.getAllClassSectionJsonObjects(CLASS_SECTION_FILE, Courses);

	//cout<<"Read in all courses!"<<endl;

	string courses[NUM_CLASS_SECTIONS];
	AllCourseNames = courses;
	AllCourses = Courses;

	for (int i = 0; i < NUM_CLASS_SECTIONS; i++) {

		AllCourseNames[i] = AllCourses[i].Course_Code;
		//cout<<AllCourseNames[i]<<endl;

	}

	remove("allCourses.json");
	cout<<"\n\n\n\n\n\n\n"<<endl;

	// Initialize components in scope, but not on main data entry gui
	GenerateTeamsButton = NULL;
	yesButton = NULL;
	confirmWindow = NULL;
	cancelButton1 = NULL;
	cancelButton2 = NULL;
	backWindow = NULL;


	//read in the steam pngs
	for (int i = 0; i < 13; i++) {

		string filename = "./Images/Steampunk/Steam1/" + to_string(i) + ".png";
		int length = filename.length();
		char png_char[length + 1];
		strcpy(png_char, filename.c_str());
		SteamPngs[i] = new Fl_PNG_Image(png_char);

	}


	//read in the steam pngs
	for (int i = 0; i < 13; i++) {

		string filename = "./Images/Steampunk/Steam2/" + to_string(i) + ".png";
		int length = filename.length();
		char png_char[length + 1];
		strcpy(png_char, filename.c_str());
		Steam2Pngs[i] = new Fl_PNG_Image(png_char);

	}


	// Set up Class Selector Window
	masterWindow = new Fl_Window(750, 800, "CLIQUE - Steampunk");
	scroll =  new Fl_Scroll(0,0,750,800);
	scroll->color(DARK_TAUPE);


	// Set up border / edge boxes
	//background box 3 - background file chooser
	Fl_Box boxBack3(10, 170, 730, 100);
	boxBack3.box(FL_FLAT_BOX);
	boxBack3.color(ASU_BLACK);
	boxBack3.image(Wall2);

	//background for course selector
	Fl_Box boxBack5(10, 390, 730, 237);
	boxBack5.box(FL_FLAT_BOX);
	boxBack5.image(Wall1);
	boxBack5.color(ASU_BLACK);

	//background for course selector
	Fl_Box boxBack6(10, 670, 730, 105);
	boxBack6.box(FL_FLAT_BOX);
	boxBack6.color(ASU_BLACK);
	boxBack6.image(Pipes2);

	boxHeader2 = new Fl_Box(10, 10, 730, 150);
	boxHeader2->box(FL_BORDER_BOX);
	boxHeader2->color(ASU_BLACK);
	boxHeader2->image(Pipes1);
	boxHeader2->redraw();

	//Header box with logo
	boxHeader = new Fl_Box(35, 10, 450, 150,
			"Complete the \ninformation below");
	boxHeader->box(FL_NO_BOX);
	boxHeader->color(ASU_BLACK);
	boxHeader->labelfont(FL_TIMES_BOLD_ITALIC);
	boxHeader->labelsize(30);
	boxHeader->labelcolor(ASU_BLACK);
	boxHeader->redraw();


	//Set up buttons
	// Go back button
	goBack = new Fl_Button(412, 695, 150, 60, "Go Back");
	goBack->color(DARK_BRASS);
	goBack->labelfont(FL_TIMES_BOLD_ITALIC);
	goBack->labelcolor(ASU_BLACK);
	goBack->labelsize(20);
	goBack->selection_color(DARK);
	goBack->callback(static_GobackClick, this);

	// Confirm button
	Confirm = new Fl_Button(576, 695, 150, 60, "Confirm");
	Confirm->color(DARK_BRASS);
	Confirm->labelfont(FL_TIMES_BOLD_ITALIC);
	Confirm->labelcolor(ASU_BLACK);
	Confirm->labelsize(20);
	Confirm->selection_color(DARK);
	Confirm->callback(static_ConfirmClick, this);



	//Initialize Project File Chooser - Step 1 Choose Project File
	projectFileChooserButton = new Fl_Button(20, 210, 50, 50);
	projectFileChooserButton->callback(static_chooseProjectFile_cb, this);
	fileInput_Project = new Fl_Input(80, 220, 650, 30);
	fileInput_Project->color(LIGHT_CREAM);
	fileInput_Project->value(".");
	fileInput_Project->textfont(FL_TIMES_ITALIC);
	Fl_PNG_Image Folder("./Images/folder.png");
	projectFileChooserButton->color(DARK_BRASS);
	projectFileChooserButton->selection_color(DARK);
	projectFileChooserButton->image(Folder);


	//Initialize Student Quiz Textbox - Step 2 Enter name of Capstone Survey
	//background box 3 - background quiz questionnaire
	Fl_Box boxBack4(10, 310, 730, 50);
	boxBack4.box(FL_FLAT_BOX);
	boxBack4.color(ASU_BLACK);
	boxBack4.image(Wall3);
	fileInput_StudentQuizName = new Fl_Input(20, 320, 710, 30);
	fileInput_StudentQuizName->textfont(FL_TIMES_ITALIC);
	fileInput_StudentQuizName->color(LIGHT_CREAM);



//>>>>Set the initial value to Survey. Need to remove for the Final System.
fileInput_StudentQuizName->value("Survey");



	//INITIALIZE CLASS SECTION SELECTOR COMPONENTS
	// input year
	inputYear = new Fl_Input(220, 460, 100, 40, "Enter Year (YYYY):  ");
	inputYear->color(ASU_WHITE);
	inputYear->labelfont(FL_TIMES_BOLD_ITALIC);
	inputYear->labelcolor(LIGHT_CREAM);
	inputYear->textfont(FL_TIMES_ITALIC);
	inputYear->labelsize(15);

	// Class Browser / selector
	classBrowser = new Fl_Check_Browser(360, 410, 370, 190);
	classBrowser->scrollbar;
	classBrowser->color(LIGHT_CREAM);
	classBrowser->labelfont(FL_TIMES_ITALIC);
	classBrowser->textsize(18);
	classBrowser->textfont(FL_TIMES_BOLD_ITALIC);
	classBrowser->callback(static_BrowserSelection, this);

	// Semester Selector
	inputSemester = new Fl_Input_Choice(220, 410, 100, 40,
			"Select Semester:    ");
	inputSemester->add("Spring");
	inputSemester->add("Summer");
	inputSemester->add("Fall");
	inputSemester->value("Fall");
	inputSemester->textsize(15);
	inputSemester->color2(LIGHT_CREAM);
	inputSemester->color(LIGHT_CREAM);
	inputSemester->selection_color(DARK);
	inputSemester->labelfont(FL_TIMES_BOLD_ITALIC);
	inputSemester->labelcolor(LIGHT_CREAM);
	inputSemester->textfont(FL_TIMES_ITALIC);
	inputSemester->labelsize(15);
	inputSemester->menubutton()->color(DARK_BRASS);
	inputSemester->menubutton()->selection_color(DARK);
	inputSemester->menubutton()->textfont(FL_TIMES_ITALIC);
	inputSemester->menubutton()->box(FL_BORDER_BOX);
	inputSemester->menubutton()->textsize(18);

	//Project File Chooser Instructions
	projectFileInstructionsBox = new Fl_Box(10, 170, 730, 30);
	projectFileInstructionsBox->box(FL_FLAT_BOX);
	projectFileInstructionsBox->color(DARK);
	projectFileInstructionsBox->labelfont(FL_TIMES_BOLD_ITALIC);
	projectFileInstructionsBox->labelcolor(LIGHT_CREAM);
	projectFileInstructionsBox->labelsize(18);
	projectFileInstructionsBox->label(
			"Step 1: Choose the Project .csv File to be used.");
	projectFileInstructionsBox->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);

	// Student Quiz Name Instructions
	quizFileInstructionsBox = new Fl_Box(10, 280, 730, 30);
	quizFileInstructionsBox->box(FL_FLAT_BOX);
	quizFileInstructionsBox->color(DARK);
	quizFileInstructionsBox->labelfont(FL_TIMES_BOLD_ITALIC);
	quizFileInstructionsBox->labelcolor(LIGHT_CREAM);
	quizFileInstructionsBox->labelsize(18);
	quizFileInstructionsBox->label(
			"Step 2: Enter name of Capstone Survey Quiz.");
	quizFileInstructionsBox->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);

	// Class Section Instructions
	classSectionInstructionsBox = new Fl_Box(10, 370, 730, 30);
	classSectionInstructionsBox->box(FL_FLAT_BOX);
	classSectionInstructionsBox->color(DARK);
	classSectionInstructionsBox->labelfont(FL_TIMES_BOLD_ITALIC);
	classSectionInstructionsBox->labelcolor(LIGHT_CREAM);
	classSectionInstructionsBox->labelsize(18);
	classSectionInstructionsBox->label("Step 3: Select Class Sections below.");
	classSectionInstructionsBox->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);

	// Go Back or Confirm Instructions
	goBackorConfirmInstructionsBox = new Fl_Box(10, 640, 730, 30);
	goBackorConfirmInstructionsBox->box(FL_FLAT_BOX);
	goBackorConfirmInstructionsBox->color(DARK);
	goBackorConfirmInstructionsBox->labelfont(FL_TIMES_BOLD_ITALIC);
	goBackorConfirmInstructionsBox->labelcolor(LIGHT_CREAM);
	goBackorConfirmInstructionsBox->labelsize(18);
	goBackorConfirmInstructionsBox->label("Step 4: Go Back or Confirm");
	goBackorConfirmInstructionsBox->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);


	// Generates course broswer with selections
	findCourses = new Fl_Button(30, 530, 300, 40, "Search for Courses");
	findCourses->color(DARK_BRASS);
	findCourses->labelfont(FL_TIMES_BOLD_ITALIC);
	findCourses->labelcolor(ASU_BLACK);
	findCourses->labelsize(18);
	findCourses->selection_color(DARK);
	findCourses->callback(static_FindCoursesClick, this);

	steamBox1 = new Fl_Box(575, 100, 150, 150);
	steamBox1->box(FL_NO_BOX);
	steamBox1->image(SteamPngs[12]);

	steamBox2 = new Fl_Box(220, 650, 150, 150);
	steamBox2->box(FL_NO_BOX);
	steamBox2->image(SteamPngs[12]);


	/**** Stylzing and running window *****/
	scroll->end();
	masterWindow->resizable(scroll);
	masterWindow->color(DARK_TAUPE);
	masterWindow->box(FL_BORDER_BOX);
	masterWindow->show();
	masterWindow->end();

	XInitThreads();
	thread threads[1];
	threads[0] = thread(SteamAnimate, masterWindow, steamBox1, steamBox2, 3);

	//join threads
	for (int i = 0; i < 1; i++) {
		threads[i].join();
	}

	Fl::run();

}


/*************************************************************************************
 * Title: ~SPDataGUI
 *
 * Description: Destructor function for GUI window.
 *
 *Arguments: nothing
 *
 *Returns: nothing
 */
SPDataGUI::~SPDataGUI() {
	delete masterWindow;
	delete prevWindow;
	delete boxHeader;
	delete boxHeader2;
	delete classBrowser;
	delete findCourses;
	delete Confirm;
	delete goBack;
	delete inputYear;
	delete inputSemester;
	delete classSectionInstructionsBox;
	delete backWindow;
	delete yesButton;
	delete cancelButton1;
	delete confirmWindow;
	delete GenerateTeamsButton;
	delete cancelButton2;
	delete projectFileInstructionsBox;
	delete projectFileChooserButton;
	delete fileInput_Project;
	delete quizFileInstructionsBox;
	delete fileInput_StudentQuizName;
	delete goBackorConfirmInstructionsBox;
}

//TODO
void SPDataGUI::BrowserSelection(Fl_Widget *w) { }


/*
* Tile: FindCoursesClick
*
* Description: This function is the callback for the Find Courses button.
*		It updates the Browser based on the year entered into the
*		input box, and the semester selected in the input choice box.
*		It searches the course sections for the relevent courses, and
*		only displays those.
*
*Arguments: FL_Widget* w
*
*Returns: nothing
*/
void SPDataGUI::FindCoursesClick(Fl_Widget *w) {

	/* Variables */
	classBrowser->add("");
	string year;
	string semester;

	//clear the browser of all entries
	classBrowser->clear();
	year = inputYear->value();
	semester = inputSemester->value();

	for (int i = 1; i < num_of_all_courses; i++) {

		string course = AllCourseNames[i];

		if ((course.find(year) != string::npos)
		&& (course.find(semester) != string::npos)) {

			int length = course.length();
			char course_char[length + 1];
			strcpy(course_char, course.c_str());
			//cout << course << endl;
			classBrowser->add(course_char);

		}
	}


	XInitThreads();
	thread threads[1];
	threads[0] = thread(SteamAnimate, masterWindow, steamBox1, steamBox2, 2);

	//join threads
	for (int i = 0; i < 1; i++) {
		threads[i].join();
	}
}


/*************************************************************************************
 * Title: GobackClick
 *
 * Description: Callback for the Go back button that returns to the previous GUI window.
 *
 *Arguments: FL_Widget* w
 *
 *Returns: nothing
 */
void SPDataGUI::GobackClick(Fl_Widget *w) {

	/* Sets up GUI window */
	backWindow = new Fl_Window(650, 220, "CLIQUE");
	backWindow->begin();


	/* Title and headers */
	Fl_Box promptBox1(0, 10, 650, 50, "WARNING!");
	promptBox1.align(FL_ALIGN_CENTER);
	promptBox1.labelsize(40);
	promptBox1.labelcolor(DARK_BRASS);
	promptBox1.labelfont(FL_TIMES_BOLD_ITALIC);

	Fl_Box promptBox2(50, 70, 550, 20,
			"You are about to return to the main screen,");
	promptBox2.align(FL_ALIGN_CENTER);
	promptBox2.labelsize(20);
	promptBox2.labelcolor(LIGHT_CREAM);
	promptBox2.labelfont(FL_TIMES);

	Fl_Box promptBox3(50, 90, 550, 20, "All information entered will be lost");
	promptBox3.align(FL_ALIGN_CENTER);
	promptBox3.labelsize(20);
	promptBox3.labelcolor(LIGHT_CREAM);
	promptBox3.labelfont(FL_TIMES_BOLD_ITALIC);


	/* prompt for user */
	Fl_Box promptBox4(50, 110, 550, 20, "Are you sure?");
	promptBox4.align(FL_ALIGN_CENTER);
	promptBox4.labelsize(20);
	promptBox4.labelcolor(LIGHT_CREAM);
	promptBox4.labelfont(FL_TIMES);


	/* User response buttons */
	// Yes
	yesButton = new Fl_Button(425, 150, 175, 50, "Yes");
	yesButton->color(DARK_BRASS);
	yesButton->labelfont(FL_TIMES_BOLD_ITALIC);
	yesButton->labelcolor(ASU_BLACK);
	yesButton->labelsize(15);
	yesButton->selection_color(DARK);
	yesButton->callback(static_YesClick, this);

	// Cancel
	cancelButton1 = new Fl_Button(40, 150, 175, 50, "Cancel");
	cancelButton1->color(DARK_BRASS);
	cancelButton1->labelfont(FL_TIMES_BOLD_ITALIC);
	cancelButton1->labelcolor(ASU_BLACK);
	cancelButton1->labelsize(15);
	cancelButton1->selection_color(DARK);
	cancelButton1->callback(static_CancelClick1, this);


	/* Stylized and run window */
	backWindow->color(DARK_TAUPE);
	backWindow->box(FL_BORDER_BOX);
	backWindow->resizable(w);
	backWindow->end();
	backWindow->show();
	Fl::run();

}


/*************************************************************************************
 * Title: YesClick
 *
 * Description: Callback for the Confirm button that opens the next GUI window.
 *
 * Arguments: Fl_Widget *w
 *
 * Returns: Nothing
 */
void SPDataGUI::YesClick(Fl_Widget *w) {

	backWindow->hide();
	masterWindow->hide();
	prevWindow->show();

}


/*****************************************************************************
 * Title: CancelClick1
 *
 * Description: hides last window when "cancel" is clicked
 *
 * Arguments: Fl_Widget* w
 *
 * Returns: nothing
 */
void SPDataGUI::CancelClick1(Fl_Widget *w) {

	backWindow->hide();

}


/*****************************************************************************
 * Title: CancelClick2
 *
 * Description: hides last window when "cancel" is clicked
 *
 * Arguments: Fl_Widget* w
 *
 * Returns: nothing
 */
void SPDataGUI::CancelClick2(Fl_Widget *w) {

	confirmWindow->hide();

}


/*************************************************************************************
 * Tile: ConfirmClick
 *
 * Description: callback for the Confirm button, opens the next GUI window.
 *
 *Arguments: FL_Widget* w
 *
 *Returns: nothing
 */
void SPDataGUI::ConfirmClick(Fl_Widget *w) {


	/* Sets up GUI window */
	confirmWindow = new Fl_Window(850, 220, "CLIQUE - Confirmation Window");


	//course selection values
	vector <string> selections;
	course_count = 0;


	//project file values
	string proj = fileInput_Project->value();
	projectFilePath = fileInput_Project->value();
	int length = proj.length();
	char prompt1[length + 1];
	strcpy(prompt1, proj.c_str());


	// questionnaire name value
	string quest = fileInput_StudentQuizName->value();
	length = quest.length();
	char prompt2[length + 1];
	strcpy(prompt2, quest.c_str());


	// broswer selection values
	string classes = "";
	int first = 0;
	for (int i = 0; i <= classBrowser->nitems(); i++) {
		if (classBrowser->checked(i)) {
			if (first == 0) {

				classes = classes + classBrowser->text(i);
				selections.push_back(classBrowser->text(i));
				course_count++;
				first = 1;

			} else {

				classes = classes + ", " + classBrowser->text(i);
				selections.push_back(classBrowser->text(i));
				course_count++;

			}
		}
	}

	length = classes.length();
	char prompt3[length + 1];
	strcpy(prompt3, classes.c_str());
	string s[course_count];

	//once courses are selected read and store them in a string array
	if(course_count>0){

		for (int i = 0; i < course_count; i++) {

			s[i] = selections[i];
			//cout<<selections[i]<<endl;

		}

		num_of_selected_courses = course_count;
		SelectedCourseNames = s;
	}


	confirmWindow->begin();


	/* Tile and headers for window */
	Fl_Box promptBox1(0, 10, 850, 30, "Does all the information look correct?");
	promptBox1.align(FL_ALIGN_CENTER);
	promptBox1.labelsize(30);
	promptBox1.labelcolor(LIGHT_CREAM);
	promptBox1.labelfont(FL_TIMES_BOLD_ITALIC);

	Fl_Box promptBox2(20, 60, 20, 20, "Project file:");
	promptBox2.align(FL_ALIGN_RIGHT);
	promptBox2.labelcolor(LIGHT_CREAM);
	promptBox2.labelsize(15);
	promptBox2.labelfont(FL_TIMES_BOLD_ITALIC);
	Fl_Box promptBox2R(130, 60, 50, 20, prompt1);
	promptBox2R.align(FL_ALIGN_RIGHT);
	promptBox2R.labelsize(15);
	promptBox2R.labelcolor(DARK_BRASS);
	promptBox2R.labelfont(FL_TIMES_BOLD);

	Fl_Box promptBox3(20, 80, 20, 20, "Survey Name:");
	promptBox3.align(FL_ALIGN_RIGHT);
	promptBox3.labelsize(15);
	promptBox3.labelcolor(LIGHT_CREAM);
	promptBox3.labelfont(FL_TIMES_BOLD_ITALIC);
	Fl_Box promptBox3R(130, 80, 50, 20, prompt2);
	promptBox3R.align(FL_ALIGN_RIGHT);
	promptBox3R.labelsize(15);
	promptBox3R.labelcolor(DARK_BRASS);
	promptBox3R.labelfont(FL_TIMES_BOLD);

	Fl_Box promptBox4(20, 100, 20, 20, "Courses:");
	promptBox4.align(FL_ALIGN_RIGHT);
	promptBox4.labelsize(15);
	promptBox4.labelcolor(LIGHT_CREAM);
	promptBox4.labelfont(FL_TIMES_BOLD_ITALIC);
	Fl_Box promptBox4R(130, 100, 50, 20, prompt3);
	promptBox4R.align(FL_ALIGN_RIGHT);
	promptBox4R.labelsize(15);
	promptBox4R.labelcolor(DARK_BRASS);
	promptBox4R.labelfont(FL_TIMES_BOLD);


	/* Buttons for user response */
	// Confirm - generate
	GenerateTeamsButton = new Fl_Button(635, 150, 175, 50, "Generate Teams");
	GenerateTeamsButton->color(DARK_BRASS);
	GenerateTeamsButton->labelfont(FL_TIMES_BOLD_ITALIC);
	GenerateTeamsButton->labelcolor(ASU_BLACK);
	GenerateTeamsButton->labelsize(15);
	GenerateTeamsButton->selection_color(DARK);
	GenerateTeamsButton->callback(static_GenerateTeamsClick, this);

	// Cancel
	cancelButton2 = new Fl_Button(40, 150, 175, 50, "Cancel");
	cancelButton2->color(DARK_BRASS);
	cancelButton2->labelfont(FL_TIMES_BOLD_ITALIC);
	cancelButton2->labelcolor(ASU_BLACK);
	cancelButton2->labelsize(15);
	cancelButton2->selection_color(DARK);
	cancelButton2->callback(static_CancelClick2, this);


	/* Stylize and run window */
	confirmWindow->color(DARK_TAUPE);
	confirmWindow->box(FL_BORDER_BOX);
	confirmWindow->resizable(w);
	confirmWindow->end();
	confirmWindow->show();
	Fl::run();

}


/*************************************************************************************
 * Tile: GenerateTeamsClick
 *
 * Description: callback for the generate teams button, opens the next GUI window.
 *
 *Arguments: FL_Widget* w
 *
 *Returns: nothing
 */
void SPDataGUI::GenerateTeamsClick(Fl_Widget *w) {

	//store the selected class sections into a new Class section Array.
	//for use in the assignment system.
	ClassSection classes[num_of_selected_courses];

	for (int i = 0; i < num_of_all_courses; i++) {
		for (int j = 0; j < num_of_selected_courses; j++) {
			if((AllCourses[i].Course_Code).compare(SelectedCourseNames[j]) == 0){
				classes[j] = AllCourses[i];
			}
		}
	}

	SelectedCourses=classes;
	vector <ClassSection> selectedcourses;

	for (int j = 0; j < num_of_selected_courses; j++) {

		//cout<<classes[j].Course_Name<<"  "<<SelectedCourses[j].Course_Code<<endl;
		selectedcourses.push_back(classes[j]);

	}

	//Get the Quiz data from the student survey.
	string QuizName = fileInput_StudentQuizName->value();
    CookieManager CM;
    Utility util;

    //Get Student data from each course
	vector<vector<Student>> allStudents;
	vector<Student> students;

	for (int j = 0; j < num_of_selected_courses; j++) {

		students = CM.getStudents(cookiedataSP, classes[j].OfficialClassID);
		CM.getQuizzes(cookiedataSP, classes[j].OfficialClassID, QuizName, students);

		students = CM.currentStudents;
		allStudents.push_back(students);

	}


	// debug students
	/*cout << endl << "Debugging Students" << endl;
	for (int j = 0; j < allStudents.size(); j++){

		for (int k = 0; k < allStudents.at(j).size(); k++){

			cout << "ClassID: " << allStudents.at(j).at(k).ClassID << endl;
			cout << "StudentID: " << allStudents.at(j).at(k).StudentID << endl;
			cout << "ASUriteID: " << allStudents.at(j).at(k).ASUriteID << endl;
			cout << "name: " << allStudents.at(j).at(k).name << endl;

			cout<<"Affinity: "<<endl;
			for(int x = 0;x < 6;x++){
				cout << allStudents.at(j).at(k).StudentAffinity[x].first << allStudents.at(j).at(k).StudentAffinity[x].second << endl;
			}

			cout << "skill scores: " << endl;
			for(int x = 0; x < 14 ;x++){
				cout << "skill " << to_string(x+1) << ": " << allStudents.at(j).at(k).Skills[x] << endl;
			}

			cout << "Availability: " << endl;
			for(int x = 0; x < 4 ;x++){
				cout << allStudents.at(j).at(k).Availability[x] << endl;
			}
		}
	}*/


	/* sending over variables, running main window */
	masterWindow->hide();
	confirmWindow->hide();
	SteamPunkGUI1 mainWin;
	mainWin.SPGprojfile = projectFilePath;
	mainWin.spCourses = selectedcourses;
	mainWin.spAllStudents = allStudents;
	mainWin.spCookies = cookiedataSP;
	mainWin.spNumCourses = course_count;
	mainWin.callTeams(w);

}


/*************************************************************************************
 * Tile: chooseProjectFile_cb
 *
 * Description: event handler for the user to select the project file
 *
 *Arguments: FL_Widget* w
 *
 *Returns: nothing
 */
void SPDataGUI::chooseProjectFile_cb(Fl_Widget*) {

	// Create the file chooser, and show it
	Fl_File_Chooser chooser(".", "*",
	Fl_File_Chooser::SINGLE,"Select Project CSV file");

	chooser.color(ASU_WHITE);
	chooser.textfont(FL_HELVETICA);
	chooser.show();


	// Block until user picks something.
	while (chooser.shown()) {

		Fl::wait();

		if (chooser.value() != NULL) {
			fileInput_Project->value(chooser.value());
		} else {
			fileInput_Project->value("NULL");
		}
	}

	XInitThreads();
	thread threads[1];
	threads[0] = thread(SteamAnimate, masterWindow, steamBox1, steamBox2, 2);

	//join threads
	for (int i = 0; i < 1; i++) {
		threads[i].join();
	}
}
