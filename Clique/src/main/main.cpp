/*
 * main.cpp
 *
 * Description:
 *	 This class is the main driver for the skills based assignment of
 *   capstone project teams. The main method of this class starts the
 *   GUI application. Once the user completes all the GUI entries,
 *   main_run is called which is the main driver for the team assignment
 *   process.
 *
 *
 *  Copyright (C) 2020 ASU
 *	Matthew Cilibraise, Myles Colina, Cristi DeLeo, Elizabeth Marquise, Sean Rogers,
 *	initial idea contributed by Douglas Sandy, All rights reserved
 *
 *
 * List of Functions:
 *  int parseLine(char *line)
 *  	- read char by char for a line given for memory
 *
 *  int getValuePhy()
 *		- a function to monitor system memory usage
 *
 *	int getValueVirt()
 *		- a function to monitor system memory usage
 *
 *	constexpr int toConstInt(int constInt)
 *		- a function to convert an int to a constant
 *
 *	void threadFunction(Student studentPool[], Project projectPool[], const int numStudents,
 *	const int numProjects, const int numSkills, const int teamSize, const int numTopTeams,
 *	string results[], int classSection int parseLine(char* line)
 *		- a function to monitor system memory usage
 *
 *	void Steampunk_Option(Fl_Widget *w)
 *		- Callback function for the Steampunk option button. Opens the Steampunk version
 *
 *  void ASU_Option(Fl_Widget *w)
 * 		- Callback function for the ASU option button. Opens the ASU colors version
 *
 *  int main(void)
 *  	-Initial function to start application. Opens the GUI window.
 *
 *	int main_run
 *		-The main driver for the skills based assignment of Capstone project teams.
 *
 *
 */


/********* BEGINNING OF INCLUSIONS **********/


/* Class Inclusions */
#include "Student.h"
#include "Project.h"
#include "ClassSection.h"
#include "Test.h"
#include "json/json.h"
#include "StudentJson.h"
#include "ProjectJson.h"
#include "ClassSectionJson.h"
#include "Utility.h"
#include "StudentsToProjects.h"
#include "ResultWindow.h"
#include "MainWindow.h"
#include "GUIStyles.h"
#include "main.h"
#include "CookieManager.h"
#include "SteamPunkGUI1.h"


/* Library Inclusions */
#include <iostream>
#include <utility>
#include <array>
#include <algorithm>
#include <vector>
#include <thread>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <chrono>
#include <libsoup/soup.h>
#include <mutex>
#include <bits/stdc++.h>
#include "sys/types.h"
#include "sys/sysinfo.h"
#include <curl/curl.h>


/* FLTK Inclusions */
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Progress.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Scroll.H>


using namespace std;
using namespace std::chrono;


/********* BEGINNING OF PROGRAM CODE **********/


/* Variables */
int ResultWindow::count = 0;
vector<ClassSection> ResultWindow::courses;
vector<SoupCookie> ResultWindow::cookies;
mutex mtx; //global mutex lock declaration
int main::numClasses = 0;
Fl_Progress *progressBar;//progress bar
Fl_Text_Buffer *terminal;//progress window  text display
int tempProj, tempStud, textInput, numCourses;
Fl_Window *optionWindow; //FL Option selection window
Fl_Scroll *scroll;


/*********************************************************
 * parseLine
 *
 * Description: read char by char for a line given for memory
 *
 * Arguments: char* line
 *
 * Returns: integer value.
 */
int parseLine(char *line) {

	// This assumes that a digit will be found and the line ends in " Kb".
	int i = strlen(line);
	const char *p = line;
	while (*p < '0' || *p > '9')
		p++;
	line[i - 3] = '\0';
	i = atoi(p);
	return i;

}


/*********************************************************
 * getValuePhy
 *
 * Author: Sean Rogers
 *
 * Description:
 *    Gets the physical memory usage of the program
 *
 *Arguments:
 *	nothing
 *Returns:
 *  integer value.
 */
int getValuePhy() { //Note: this value is in KB!

	FILE *file = fopen("/proc/self/status", "r");
	int result = -1;
	char line[128];

	while (fgets(line, 128, file) != NULL) {
		if (strncmp(line, "VmRSS:", 6) == 0) {

			result = parseLine(line);
			break;

		}
	}

	fclose(file);
	return result;

}


/*********************************************************
 * getValueVirt
 *
 * Description: Gets the virtual memory usage of the program.
 *
 * Arguments: nothing
 *
 * Returns: integer value.
 */
int getValueVirt() { //Note: this value is in KB!

	FILE *file = fopen("/proc/self/status", "r");
	int result = -1;
	char line[128];

	while (fgets(line, 128, file) != NULL) {
		if (strncmp(line, "VmSize:", 7) == 0) {

			result = parseLine(line);
			break;

		}
	}

	fclose(file);
	return result;
}


/*********************************************************
 * int toConstInt(int constInt)
 *
 * Description: Function to convert integers into constant expressions.
 *
 * Arguments: int constInt
 *
 * Returns: constant integer value
 */
constexpr int toConstInt(int constInt) {

	return constInt;

}


/**********************************************************************
 * threadFunction
 *
 *Description: This function is called by the threads inside main. It
 *	takes in all the students and projects for a given class section,
 *  and partitions each section based on student skill, and project
 *  priority into 3 pools.(3 arrays for students, 3 arrays for projects).
 *  It passes this data, along with the other parameters into 3 calls
 *  to StudetnsToProjectsAssignment function.
 *
 * Arguments: Student studentPool[], Project projectPool[], const int numStudents,
 *	const int numProjects, const int numSkills, const int teamSize,
 *	const int numTopTeams, string results[], int classSection, int numClasses
 *
 * Returns: void
 */
void threadFunction(Student studentPool[], Project projectPool[],
		const int numStudents, const int numProjects, const int numSkills,
		const int teamSize, const int numTopTeams, string results[],
		int classSection, int numClasses, int officialClassID) {

<<<<<<< HEAD:BruteForce/src/main/main.cpp
	// Progress Bar window- calculate the percentage to increment the bar by
	int progressIncrement = (110 / numClasses) / 3;

	// Find the number of teams of 5 and number of teams of 4 needed for 
        // this class section.
=======

	//Progress Bar window- calculate the percentage to increment the bar by
	int progressIncrement = (110 / numClasses) / 3;


	//Find the number of teams of 5 and number of teams of 4 needed for this class section.
>>>>>>> dev:Clique/src/main/main.cpp
	Utility util;

	int numTeamsOf4 = util.NumOfTeamsOf4(numStudents, teamSize);
	int numTeamsOf5 = abs(numTeamsOf4 * 4 - numStudents) / 5;
	int count4T = 0;
	int count5T = 0;

	//vector<int> TeamsNeeded;
        
        int TeamsNeeded[numProjects];
        
/*
        for (int i = 0; i < numProjects; i++) {

		if (count5T < numTeamsOf5) {
			TeamsNeeded.push_back(5);
			count5T++;

		} else if (count4T < numTeamsOf4) {
			TeamsNeeded.push_back(4);
			count4T++;
		}
	}
*/

	for (int i = 0; i < numProjects; i++) {

		if (count5T < numTeamsOf5) {
			TeamsNeeded[i] = 5;
			count5T++;

		} else if (count4T < numTeamsOf4) {
			TeamsNeeded[i] = 4;
			count4T++;
		}
	}


	/***** SORTING STUDENTS BASED ON SKILL *****/

	//creating student skill average
	for (int i = 0; i < numStudents; i++) {

		double average1 = 0;
		for (int m = 0; m < numSkills; m++) {

			average1 += studentPool[i].Skills[m];

		}

		average1 = average1 / numSkills;
		studentPool[i].skillAverage = average1;

	}


	//Averaging student skills into a sorted array
	for (int i = 0; i < numStudents; i++) {

		Student student;
		for (int j = (i + 1); j < numStudents; j++) {
			if (studentPool[j].skillAverage > studentPool[i].skillAverage) {

				student = studentPool[i];
				studentPool[i] = studentPool[j];
				studentPool[j] = student;

			}
		}
	}


	//Counting project priority
	int count1 = 0;
	int count2 = 0;

	for (int i = 0; i < numProjects; i++) {

		if (projectPool[i].Priority == 2) {
			count2++;
		}

		if (projectPool[i].Priority == 1) {
			count1++;
		}

	}


	int count0 = abs(numProjects - count2 - count1);


	//make sure each priority section does not have 1 project.
	//(should have 0, or 3 or more. (P2 can have 2))

	if (count2 == 1) {

		if (count1 > 2) {
			count1--;
			count2++;

		} else if (count1 == 1) {
			count1--;
			count2++;

		} else if (count1 == 2) {
			count1--;
			count2++;
			count1--;
			count2++;

		} else if (count0 > 2) {
			count0--;
			count2++;

		} else if (count0 == 1) {
			count0--;
			count2++;

		} else if (count0 == 2) {
			count0--;
			count2++;
			count0--;
			count2++;
		}
	}


	if (count1 == 1) {

		if (count2 >= 1 && count2 != 2) {
			count2++;
			count1--;

		} else if (count0 >= 1 && count0 != 2) {
			count1--;
			count0++;

		} else if (count0 == 2) {
			count1++;
			count1++;
			count0--;
			count0--;
		}
	}


	if (count0 == 1) {

		if (count2 >= 1 && count2 != 2) {
			count2++;
			count0--;

		} else if (count1 >= 1 && count1 != 2) {
			count0--;
			count1++;

		} else if (count1 == 2) {
			count0++;
			count0++;
			count1--;
			count1--;
		}
	}


	if (count1 == 2) {
		count1--;
		count1--;
		count2++;
		count2++;
	}


	if (count0 == 2) {
		count0--;
		count0--;
		count2++;
		count2++;
	}


	//make sure each priority has no more than 10 projects each,
	//(if the number of projects is 30 or less).
	if (numProjects <= 30) {

		while (count2 > 10) {
			if (count1 < 10) {

				if (count1 > 2) {
					count2--;
					count1++;

				} else {
					count2--;
					count2--;
					count2--;
					count1++;
					count1++;
					count1++;
				}

			} else if (count0 < 10) {

				if (count0 > 2) {
					count2--;
					count0++;

				} else {
					count2--;
					count2--;
					count2--;
					count0++;
					count0++;
					count0++;
				}
			}
		}


		while (count1 > 10) {

			if (count2 < 10) {
				if (count2 > 2) {
					count1--;
					count2++;

				} else {
					count1--;
					count1--;
					count1--;
					count2++;
					count2++;
					count2++;
				}

			} else if (count0 < 10) {

				if (count0 > 2) {
					count1--;
					count0++;

				} else {
					count1--;
					count1--;
					count1--;
					count0++;
					count0++;
					count0++;
				}
			}
		}


		while (count0 > 10) {

			if (count2 < 10) {
				if (count2 > 2) {
					count0--;
					count2++;

				} else {
					count0--;
					count0--;
					count0--;
					count2++;
					count2++;
					count2++;
				}

			} else if (count1 < 10) {
				if (count1 > 2) {
					count0--;
					count1++;

				} else {
					count0--;
					count0--;
					count0--;
					count1++;
					count1++;
					count1++;
				}
			}
		}
	}

<<<<<<< HEAD:BruteForce/src/main/main.cpp
=======

>>>>>>> dev:Clique/src/main/main.cpp
	//If there are more than 30 projects, evenly distribute the projects by priority
	if (numProjects > 30) {

		//Variables
		bool A = true;
		bool B = true;
		bool C = true;
		count2 = 10;
		count1 = 10;
		count0 = 10;

		for (int i = 30; i < numProjects; i++) {

			if (A == true) {
				count2++;
				A = false;
				B = true;

			} else if (B == true) {
				count1++;
				B = false;
				C = true;

			} else if (C == true) {
				count0++;
				C = false;
				A = true;
			}
		}
	}


	int newcount0 = 0;
	int newcount1 = 0;
	int newcount2 = 0;
	int c0 = 0;
	int c1 = 0;
	int c2 = 0;

	for (int i = 0; i < numProjects; i++) {

		if (c2 < count2) {
			newcount2 += TeamsNeeded[i];
			c2++;
		} else if (c1 < count1) {
			newcount1 += TeamsNeeded[i];
			c1++;
		} else if (c0 < count0) {
			newcount0 += TeamsNeeded[i];
			c0++;
		}
	}

	const int count0C = newcount0;
	const int count1C = newcount1;
	const int count2C = newcount2;

	const int COUNT_0 = toConstInt(count0C);
	const int COUNT_1 = toConstInt(count1C);
	const int COUNT_2 = toConstInt(count2C);

	const int PCOUNT_0 = toConstInt(count0);
	const int PCOUNT_1 = toConstInt(count1);
	const int PCOUNT_2 = toConstInt(count2);


	//Pushing students onto project priority arrays
	Student STpriority1[COUNT_1];
	Student STpriority2[COUNT_2];
	Student STpriority0[COUNT_0];

	int snum1 = 0;
	int snum2 = 0;
	int snum0 = 0;

	for (int i = 0; i < numStudents; i++) {

		if (i < COUNT_2) {

			STpriority2[snum2] = studentPool[i];
			snum2++;

		} else if (i >= COUNT_2 && i < COUNT_2 + COUNT_1) {

			STpriority1[snum1] = studentPool[i];
			snum1++;

		} else if (i >= COUNT_2 + COUNT_1) {

			STpriority0[snum0] = studentPool[i];
			snum0++;

		}
	}


	//Pushing projects onto project priority arrays
	Project PRpriority1[PCOUNT_1];
	Project PRpriority2[PCOUNT_2];
	Project PRpriority0[PCOUNT_0];

	int pnum1 = 0;
	int pnum2 = 0;
	int pnum0 = 0;

	for (int i = 0; i < numProjects; i++) {

		if (i < count2) {

			PRpriority2[pnum2] = projectPool[i];
			pnum2++;
		} else if (i >= count2 && i < count2 + count1) {

			PRpriority1[pnum1] = projectPool[i];
			pnum1++;
		} else if (i >= count2 + count1) {

			PRpriority0[pnum0] = projectPool[i];
			pnum0++;
		}
	}


	//print out information to the console for debugging purposes
	mtx.lock();
/*	cout << "Class section # " << classSection << endl;
	cout << "numProjects: " << numProjects << endl;
	cout << "P2: " << PCOUNT_2 << endl;
	cout << "P1: " << PCOUNT_1 << endl;
	cout << "P0: " << PCOUNT_0 << endl;
	cout << "numStudents: " << numStudents << endl;
	cout << "S2: " << COUNT_2 << endl;
	cout << "S1: " << COUNT_1 << endl;
	cout << "S0: " << COUNT_0 << endl;*/
	mtx.unlock();


	StudentsToProjects x;
	if (COUNT_2 != 0 && PCOUNT_2 != 0) {
		//1st Call to function: Highest priority projects and highest skill average students
		*(results + (classSection * 3 + 0)) = x.StudentsToProjectsAssignment(
				STpriority2, PRpriority2, COUNT_2, PCOUNT_2, numSkills,
				teamSize, numTopTeams, progressBar, progressIncrement, terminal,
				officialClassID);
	}

	if (COUNT_1 != 0 && PCOUNT_1 != 0) {
		//2nd Call to function: middle priority projects and middle skill average students
		*(results + (classSection * 3 + 1)) = x.StudentsToProjectsAssignment(
				STpriority1, PRpriority1, COUNT_1, PCOUNT_1, numSkills,
				teamSize, numTopTeams, progressBar, progressIncrement, terminal,
				officialClassID);
	}

	if (COUNT_0 != 0 && PCOUNT_0 != 0) {
		//3rd Call to function: lowest priority projects and lowest skill average students
		*(results + (classSection * 3 + 2)) = x.StudentsToProjectsAssignment(
				STpriority0, PRpriority0, COUNT_0, PCOUNT_0, numSkills,
				teamSize, numTopTeams, progressBar, progressIncrement, terminal,
				officialClassID);
	}


	//output to the GUI
	mtx.lock();
	string output = +"Class Section #" + to_string(classSection)
			+ " Assignment Complete!\n";
	int length = output.length();
	char output_char[length + 1];
	strcpy(output_char, output.c_str());
	//terminal->append(output_char);
	char *text = terminal->text();
	terminal->text("");
	terminal->append(output_char);
	terminal->append(text);
	mtx.unlock();

}
int argc = 0;
char **argv;

/*************************************************************************************
 * Steampunk_Option(Fl_Widget *w)
 *
 * Description: Callback function for the Steampunk option button.
 * 	Opens the Steampunk version of the GUI
 *
 * Arguments: Fl_Widget*w
 *
 * Returns: void
 */
void Steampunk_Option(Fl_Widget *w) {

	optionWindow->hide();
	SteamPunkGUI1 mainWin;
	mainWin.MainWindow2();

}


/*************************************************************************************
 * void ASU_Option(Fl_Widget *w)
 *
 * Description: Callback function for the ASU option button.
 * 	Opens the ASU colors version of the GUI
 *
 * Arguments: Fl_Widget*w
 *
 * Returns: void
 */
void ASU_Option(Fl_Widget *w) {

	optionWindow->hide();
	MainWindow mainWin;
	mainWin.MainWindow2();

}


/*************************************************************************************
 * main
 *
 * Description: This function is the main method, and creates the MainWindow GUI.
 *		It opens the option selection window which allows the user to select
 *		the style of the application.
 *
 * Arguments: void
 *
 * Returns: int value 0.
 */
int main(int argcc, char **argvv) {
	argv = argvv;
	argc = argcc;
	// Variables
	Utility util;
	util.makeStudentCSV(50, 14);
	XInitThreads();


	// Setting up GUI chooser window
	optionWindow = new Fl_Window(650, 320, "CLIQUE");
	optionWindow->begin();
	optionWindow->color(ASU_WHITE);
	scroll =  new Fl_Scroll(0,0,650,320);
	scroll->color(ASU_WHITE);//background color




	// Border and edge boxes
	Fl_Box backBox1(10, 10, 630, 300);
	backBox1.box(FL_FLAT_BOX);
	backBox1.color(ASU_GOLD);


	//Main prompt for user
	Fl_Box promptBox1(10, 20, 630, 50, "Application Style");
	promptBox1.align(FL_ALIGN_CENTER);
	promptBox1.box(FL_FLAT_BOX);
	promptBox1.color(ASU_GREY);
	promptBox1.labelfont(FL_HELVETICA_BOLD);
	promptBox1.labelcolor(ASU_WHITE);
	promptBox1.labelsize(40);

	Fl_Box promptBox2(50, 80, 550, 20,
			"Please select the style option for the look of the application.");
	promptBox2.align(FL_ALIGN_CENTER);
	promptBox2.labelsize(20);
	promptBox2.labelfont(FL_HELVETICA);


	// Buttons for user choice

	//Steampunk
	Fl_Button OptButton1(60, 150, 185, 105);
	OptButton1.color(DARK_TAUPE);
	OptButton1.labelfont(FL_TIMES_BOLD_ITALIC);
	OptButton1.labelcolor(ASU_GREY);
	OptButton1.labelsize(15);
	OptButton1.selection_color(LIGHT_CREAM);
	Fl_PNG_Image SP_Button("./Images/Steampunk_Button.png");
	OptButton1.image(SP_Button);
	OptButton1.callback(Steampunk_Option);

	// ASU
	Fl_Button OptButton2(405, 150, 185, 105);
	OptButton2.color(ASU_WHITE);
	OptButton2.labelfont(FL_HELVETICA_BOLD);
	OptButton2.labelcolor(ASU_BLACK);
	OptButton2.labelsize(15);
	OptButton2.selection_color(ASU_BLACK);
	Fl_PNG_Image ASU_Button("./Images/ASU_Button.png");
	OptButton2.image(ASU_Button);
	OptButton2.callback(ASU_Option);


	// Stylizing and running window
	optionWindow->box(FL_BORDER_BOX);
	scroll->end();
	optionWindow->resizable(scroll);
	optionWindow->end();
	optionWindow->show();
	Fl::run();
	return 0;

}


/*************************************************************************************
 * main_run
 *
 * Description: This class is the main driver for the skills based assignment of
 *	 capstone project teams.
 *
 * Arguments: int projects_input, int students_input, string filepath,
 *		Fl_Progress *pb, Fl_Text_Buffer *tb, vector<vector<Student>> allStudents,
 *		vector<ClassSection> allClassSections, vector<SoupCookie> cookies
 *
 * Returns: int value 0.
 */
int main::main_run(int projects_input, int students_input, string filepath,
		Fl_Progress *pb, Fl_Text_Buffer *tb, vector<vector<Student>> allStudents,
		vector<ClassSection> allClassSections, vector<SoupCookie> cookies) {

	// Locking matrix
	mtx.lock();

	//timer to keep track of program runtime
	auto start = high_resolution_clock::now();

	//assign values to the results window to use when making the groups
	for (int i = 0; i < allClassSections.size(); i++) {
		ResultWindow::courses.push_back(allClassSections[i]);
	}
	ResultWindow::cookies = cookies;

	srand(time(NULL));
	string file = "";
	string file2 = "";


	//set up the progress bar with 5 percent
	progressBar = pb;
	pb->value(5 / 100.0);
	char percent[10];
	sprintf(percent, "%d%%", int((5 / 100.0) * 100.0));
	pb->label(percent);
	Fl::check();
	mtx.unlock();


	//set up the terminal buffer
	terminal = tb;
	numCourses = allClassSections.size();
	tempProj = projects_input;
	tempStud = students_input;


	//reading in inputs
	const int NUM_PROJECTS = toConstInt(tempProj);
	const int NUM_STUDENTS = toConstInt(tempStud);
	const int NUM_SKILLS = 14;
	ResultWindow::count = NUM_PROJECTS;
	Utility util;
	util.makeClassSectionJSON(allClassSections);


	//create the CSV file of random projects
	util.makeProjectCSV(NUM_PROJECTS, NUM_SKILLS);


	// Start 4 class sections test
	const int NUM_CLASS_SECTIONS = 4;
	util.makeStudentJSON(NUM_STUDENTS, NUM_SKILLS, allStudents);
	const string CLASS_SECTION_FILE = "./SampleJsonFiles/4ClassSections.json";


	//cout << "main " << filepath << endl;
	for (int i = filepath.length() - 1; i >= 0; i--) {

		file.push_back(filepath.at(i));
		if (filepath.at(i) == 47) {

			file.push_back('.');
			break;

		}
	}


	for (int i = file.length() - 1; i >= 0; i--) {
		file2.push_back(file.at(i));
	}

	for (int i = 0; i < file.length(); i++) {
		//cout << file2.at(i) << ',';
	}


	//cout << endl;
	//cout << filepath << endl;
	const string PROJECT_FILE = file2;
	const string STUDENT_FILE = "./newStudents.json";


	//Change this value to change the number of top teams stored.
	int tempNumTopTeams = 5;


	//Team size, (must be 5)
	int tempTeamSize = 5;
	const int NUM_TOP_TEAMS = toConstInt(tempNumTopTeams);
	const int TEAM_SIZE = toConstInt(tempTeamSize);

	StudentJson SJson;
	ProjectJson PJson;
	ClassSectionJson CSJson;
	Project PROJECT_POOL[NUM_PROJECTS];
	Student STUDENT_POOL[NUM_STUDENTS];
	ClassSection CLASS_SECTION_POOL[NUM_CLASS_SECTIONS];
	int PROJECT_STUDENT_SKILLS[NUM_PROJECTS * NUM_STUDENTS];
	Test t;


	// INITIALIZE POOLS
<<<<<<< HEAD:BruteForce/src/main/main.cpp
	//util.initProjectPool(PROJECT_FILE, PROJECT_POOL, NUM_PROJECTS);

	// !!! The following line calls a function that returns a vector
	// !!! without assigning it to a vector variable
	//util.csvToProjectsVector(PROJECT_FILE, PROJECT_POOL, NUM_PROJECTS,
	//		NUM_SKILLS);

=======
	util.csvToProjectsVector(PROJECT_FILE, PROJECT_POOL, NUM_PROJECTS, NUM_SKILLS);
>>>>>>> dev:Clique/src/main/main.cpp
	util.initStudentPool(STUDENT_FILE, STUDENT_POOL, NUM_STUDENTS);
	util.initClassSectionPool(CLASS_SECTION_FILE, CLASS_SECTION_POOL,
			STUDENT_POOL, NUM_CLASS_SECTIONS, NUM_STUDENTS);
	util.initProjectStudentSkills(PROJECT_POOL, STUDENT_POOL,
			PROJECT_STUDENT_SKILLS, NUM_PROJECTS, NUM_STUDENTS, NUM_SKILLS);


	// Filling in static results array for data
	for (int j = 0; j < NUM_PROJECTS; j++) {
		ResultWindow::project_pool[0][j] = PROJECT_POOL[j].ProjectID;
		ResultWindow::project_pool[1][j] = PROJECT_POOL[j].Priority;
	}


	int size1 = NUM_CLASS_SECTIONS * 3;

	//Stores the results the assignment of students to projects each class section
	string results[NUM_CLASS_SECTIONS * 3];

	//stores the number of students in each class section
	int studentsInSections[NUM_CLASS_SECTIONS];

	//stores the number of students in each class section
	int projectsInSections[NUM_CLASS_SECTIONS];


	//initialize to 0
	for (int i = 0; i < NUM_CLASS_SECTIONS; i++) {

		studentsInSections[i] = 0;
		projectsInSections[i] = 0;
	/*	cout << "Class Section Data" << endl;
		cout << CLASS_SECTION_POOL[i].OfficialClassID << endl;
		cout << CLASS_SECTION_POOL[i].ClassID << endl;
		cout << CLASS_SECTION_POOL[i].Course_Code << endl;
		cout << CLASS_SECTION_POOL[i].Course_Name << endl;
		cout << CLASS_SECTION_POOL[i].Type << endl;*/

	}


	//initialize results
	for (int i = 0; i < NUM_CLASS_SECTIONS * 3; i++) {
		results[i] = " ";
	}


	//set the number of students in each class section to the indexes of studentsInSections[]
	for (int i = 0; i < NUM_STUDENTS; i++) {
		for (int j = 0; j < NUM_CLASS_SECTIONS; j++) {
			if (STUDENT_POOL[i].ClassID == j) {
				studentsInSections[j]++;
			}
		}
	}


	// PARTITION POOLS BY TYPE (ONLINE/GROUND/HYBRID)
	util.projectTypePartition(PROJECT_POOL, NUM_PROJECTS, 'O', 'G', 'H');
	util.classSectionTypePartition(CLASS_SECTION_POOL, NUM_CLASS_SECTIONS, 'O', 'G');


	// ASSIGN EACH PROJECT TO A CLASS SECTION BASED ON STUDENT-PROJECT SCORE
	util.projectToSectionAssignment(PROJECT_POOL, STUDENT_POOL,
			CLASS_SECTION_POOL, NUM_PROJECTS, NUM_STUDENTS, NUM_CLASS_SECTIONS,
			NUM_SKILLS, studentsInSections);

	//cout << endl << "After Project to Class Section Assignment: " << endl;
	//t.PrintProjectPool(PROJECT_POOL, NUM_PROJECTS, NUM_SKILLS);

	//cout << to_string(getValuePhy() + getValueVirt())
	//		<< " KB total memory usage" << endl;


	/* BEGIN - STUDENTS TO PROJECTS ASSIGNMENT
	 * Threads for each class section will start here. Students will be
	 * partitioned here by skill averages projects will be partitioned by priority */


	//set the number of projects in each class section to the indexes of projectsInSections[]
	for (int i = 0; i < NUM_PROJECTS; i++) {

		ResultWindow::project_pool[3][i] = PROJECT_POOL[i].ClassID;
		ResultWindow::project_pool[4][i] = 0;

		for (int j = 0; j < NUM_CLASS_SECTIONS; j++) {
			if (PROJECT_POOL[i].ClassID == j) {
				projectsInSections[j]++;
			}
		}
	}


	 //Print out for testing
	 for (int i = 0; i < NUM_STUDENTS; i++) {
	//	 cout << STUDENT_POOL[i].ASUriteID << "|" << STUDENT_POOL[i].StudentID
	//	 << "|" << STUDENT_POOL[i].ClassID << "  ";
	 }
	// cout << endl;


	//create a thread for each class section. store each thread in threads[]
	thread threads[NUM_CLASS_SECTIONS];


	for (int i = 0; i < NUM_CLASS_SECTIONS; i++) {

		//store students in a single class section to *STUDENT_POOL_SECTION_X
		Student *STUDENT_POOL_SECTION_X = new Student[studentsInSections[i]];

		//used to add a student to STUDENT_POOL_SECTION_X[] from STUDENT_POOL[]
		int indexToAddStudent = 0;

		for (int j = 0; j < NUM_STUDENTS; j++) {
			if (STUDENT_POOL[j].ClassID == i) {

				STUDENT_POOL_SECTION_X[indexToAddStudent] = STUDENT_POOL[j];
				indexToAddStudent++;

			}
		}


		//store projects in a single class section to *PROJECT_POOL_SECTION_X
		Project *PROJECT_POOL_SECTION_X = new Project[projectsInSections[i]];

		//used to add a project to PROJECT_POOL_SECTION_X[] from PROJECT_POOL[]
		int indexToAddProject = 0;

		//separate the projects into an array by class section
		for (int j = 0; j < NUM_PROJECTS; j++) {
			if (PROJECT_POOL[j].ClassID == i) {

				PROJECT_POOL_SECTION_X[indexToAddProject] = PROJECT_POOL[j];
				indexToAddProject++;

			}
		}


		//sort the projects based on priority
		util.PriorityPartition(PROJECT_POOL_SECTION_X, projectsInSections[i], 2,
				1, 0);


		const int officialID = toConstInt(CLASS_SECTION_POOL[i].OfficialClassID);


		//call the thread (once for each class section)
		threads[i] = thread(threadFunction, STUDENT_POOL_SECTION_X,
				PROJECT_POOL_SECTION_X, studentsInSections[i],
				projectsInSections[i], NUM_SKILLS, TEAM_SIZE, NUM_TOP_TEAMS,
				results, i, NUM_CLASS_SECTIONS,
				CLASS_SECTION_POOL[i].OfficialClassID);


		//uncomment this to use without threads.
		/*	threadFunction( STUDENT_POOL_SECTION_X,
		 PROJECT_POOL_SECTION_X, studentsInSections[i],
		 projectsInSections[i], NUM_SKILLS, TEAM_SIZE, NUM_TOP_TEAMS,
		 results, i, NUM_CLASS_SECTIONS,
		 CLASS_SECTION_POOL[i].OfficialClassID);*/

		//delete STUDENT_POOL_SECTION_X;
		//delete PROJECT_POOL_SECTION_X;

	}


	//join threads
	for (int i = 0; i < NUM_CLASS_SECTIONS; i++) {
		threads[i].join();
	}


	//print out the results to .txt file for saving
	ofstream resultFile;
	resultFile.open("results.txt");
	for (int i = 0; i < NUM_CLASS_SECTIONS * 3; i++) {
		resultFile << results[i] << endl;
	}
	resultFile.close();


	//KEEP TRACK OF TIME THE PROGRAM TAKES TO RUN
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << endl;
	cout << endl;
	cout << getValueVirt() + getValuePhy()
			<< " KB of memory usage: End of entire program" << endl;
	cout << endl;
	cout << "Program Runtime" << endl;
	cout << "time in milliseconds: ";
	cout << duration.count() << endl;
	;
	cout << endl;


	//Set the progress bar to 100%
	pb->value(100);
	sprintf(percent, "%d%%", int(100));
	pb->selection_color(ASU_GREEN);
	pb->label(percent);
	Fl::check();


	//reset the global progress bar value
	progressBarValue = 0;

	//Tests
	//Test t;
	//t.StructTest();
	//t.PrintProjectPool(PROJECT_POOL, NUM_PROJECTS, NUM_SKILLS);
	//t.PrintStudentPool(STUDENT_POOL, NUM_STUDENTS, NUM_SKILLS);
	//t.PrintProjectStudentSkills(PROJECT_STUDENT_SKILLS, NUM_PROJECTS, NUM_STUDENTS);

	return 1;
}
