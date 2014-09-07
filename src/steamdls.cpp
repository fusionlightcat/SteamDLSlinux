#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <cstring>


//Funktion zum ausführen von SHELL-Befehlen
//STRING EXEC

using namespace std;
std::string exec(char* cmd) {
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
    	if(fgets(buffer, 128, pipe) != NULL)
    		result += buffer;
    }
    pclose(pipe);
    return result;
}

//Schleife die die Grösse checkt und ggf. herunterfährt.
//INT CHECK

int check(string a, string b)
{
cout << " \nChecking PATH is: " << a << "\n";
cout << "Interval is: " << b << " Seconds\n\n";


// Defienieren und umwandeln der Variablen
string scmd;
string output1;
string output2;
int endwhile = 0;
int bint;
int c;
istringstream ( b ) >> bint;





//Festlegen und ausführen des Kommandos
std::ostringstream sizecmd;
sizecmd << "du -ks " << a << " | cut -f1";
scmd = sizecmd.str();
char *cstr = new char[scmd.length() + 1];
strcpy(cstr, scmd.c_str());


//Ausführen


//cout << output;


while(endwhile==0){

output1 = exec(cstr);
cout << "START_SIZE = " << output1 << "\n";

sleep(bint);

output2 = exec(cstr);
cout << "END_SIZE =   " << output2 << "\n";

if(output1 == output2){

cout << "Downloads finished. (Foldersize not changed.)\n\n";
return 0;
exit;
}
else{

int intop1;
int intop2;

istringstream ( output1 ) >> intop1;
istringstream ( output2 ) >> intop2;

int diff = intop2 - intop1;
int temp = diff / bint;
cout << "DIFFERENCE = " << diff << "\n";
cout << "VELOCITY =   " << temp << "Kb/" << bint << " sec\n\n";

}











}

//Aufräumen
delete [] cstr;
}


//MAIN

main(void){
	
	//START DES PROGRAMMS
	//Defienieren der Variablen und einholen von Systeminformationen
	
	string user;
	user = getenv("USER");
	string path;
	string suremonitorpath;
	string interval;
	string nullworth;
	char sure;
	//Festlegen des DownloadOrdners.
	cout << "\033[32mSteamDLS - Linux\n\033[0m\n\n";
	cout << "Enter Path to SteamApps [Default is: /home/" << user << "/.steam/steam/SteamApps/]: \033[0m\n";
	getline (cin, path);
	if (path[0] == '\0') {
		std::ostringstream oss;
		oss << "/home/" << user << "/.steam/steam/SteamApps/";		
		path = oss.str();
			
		}
	
	
	//Nachfrage
	
	monitorpath :
	cout << "Are you sure you want to monitor " << path << " ? [(Y)es / (N)o]:";
	getline (cin, suremonitorpath);
	if(suremonitorpath[0] == '\0'){
	goto monitorpath;
	}
	if(suremonitorpath[0] == 'Y'){
	suremonitorpathyes :
	
	//Intervaleingabe
	cout << "Enter Checking Interval in Seconds: [Default: 60]\n";
	getline (cin, interval);
	
	if(interval[0] == '\0'){
		interval = "60";	
	
	}
	//Vorstufe
	cout << "Start your Downloads now. Then press ENTER / RETURN. Press Ctrl+C to abort.";
	getline (cin, nullworth);
	
	
	//Ausführen des Programms
	check(path, interval);	
	
	return 0;
	exit;
	}
//Verschiedene Antwortmöglichkeiten und Schreibweisen der Nachfrage (Eingabe 2)
	if(suremonitorpath[0] == 'y'){
	goto suremonitorpathyes;
	
	}
	if(suremonitorpath[0] == 'N'){
	cout << "Break.\n";	
	
	}
	if(suremonitorpath[0] == 'n'){
	cout << "Break.\n";
	
	}
	return 0;
}
