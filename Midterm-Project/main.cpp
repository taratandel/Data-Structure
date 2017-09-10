// In The Name Of God
// ========================================
// * File Name : main.cpp
// 
// * Creation Date : 05-12-2014
//
// * Last Modified : Tue 09 Dec 2014 07:40:40 PM IRST
//
// * Created By : Tara Tandel (Tara.tandel.94@gmail.com)
// =======================================
#include "List.h"
#include "MaxHeap.h"
#include "Agency.h"
#include "GenList.h"

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]){
	List<Agency> agencies;
	GenList<Service> services;
	
	while(true){
		string command;
		cout << char(27) << "[5;32m" << ">" << char(27) << "[0;0;0m";
		std::getline(cin, command);
		
		istringstream ci(command);
		if(command.find("Add new agency") != string::npos){
			int id;
			string name;
			
			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');	// Just seek after "Add new agency" in stream	
			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
			ci >> id >> name;
			
			agencies.push_back(Agency(name, id));
		}else if(command.find("Exit") != string::npos){
			exit(0);
		}else if(command.find("List services from") != string::npos){
			string name;
			
			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');	// Just seek after "List services from" in stream	
			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
			ci >> name;
		
			cout << char(27) << "[0;36m";
			services.listFrom(services.find(Service(name)));
			cout << char(27) << "[0;0;0m";
		}else if(command.find("List agency") != string::npos){
			cout << char(27) << "[0;36m";
			cout << agencies << endl;
			cout << char(27) << "[0;0;0m";
		}else if(command.find("List services") != string::npos){
			cout << char(27) << "[0;36m";
			services.list();
			cout << char(27) << "[0;0;0m";
		}else if(command.find("Add new service") != string::npos){
			string name;

			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');	// Just seek after "Add new service" in stream	
			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
			ci >> name;
			
			services.push_front(Service(name));
		}else if(command.find("Add subservice") != string::npos){
			string parentName;
			string childName;

			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');	// Just seek after "Add subservice" in stream	
			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
			
			ci >> childName;

			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');	// Just seek after "to" in stream	
			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');		
			
			ci >> parentName;
			
			GenList<Service>::Node* ptr1 = services.find(Service(parentName));
			if(ptr1 == NULL){
				cout << "Service not found" << endl;
				continue;
			}

			GenList<Service>::Node* ptr2 = services.find(Service(childName));
			if(ptr2 == NULL){
				services.addChild(ptr1, Service(childName));
			}else{
				services.addChild(ptr1, ptr2); 
			}
			
		}else if(command.find("Add parent") != string::npos){
			string parentName;
			string childName;

			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');	// Just seek after "Add parent" in stream	
			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');		
			
			ci >> parentName;
			
			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');	// Just seek after "to" in stream
			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');

			ci >> childName;

			GenList<Service>::Node* ptr1 = services.find(Service(childName));
			if(ptr1 == NULL){
				cout << "Service not found" << endl;
				continue;
			}

			GenList<Service>::Node* ptr2 = services.find(Service(parentName));
			if(ptr2 == NULL){
				cout << "Service not found" << endl;
				continue;
			}

			services.addParent(ptr1, ptr2);			
		}else if(command.find("Delete") != string::npos){
			string service;

			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');	// Just seek after "Delete" in stream	
		
			ci >> service;

			GenList<Service>::Node* ptr = services.find(Service(service));
			if(ptr == NULL){
				cout << "Service not found" << endl;
				continue;
			}
			
			services.remove(ptr);
		}else if(command.find("Request") != string::npos){
			string service;
			string agency;
			string username;
			
			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');	// Just seek after "Request" in stream

			ci >> service;

			
			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');	// Just seek after "in" in stream	
			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');	
		
			ci >> agency;

			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');	// Just seek after "by" in stream	
			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');	
		
			ci >> username;
		
			int i = 0;
			for(i = 0; i < agencies.size(); i++){
				if(agencies[i].getName() == agency)
					break;
			}
			if(i == agencies.size()){
				cout << "Agency not found" << endl;
				continue;
			}
			GenList<Service>::Node* ptr = services.find(Service(service));
			if(ptr == NULL){
				cout << "Service not found" << endl;
				continue;
			}

			agencies[i].addRequest(Request(ptr->getData(), username));
		}else if(command.find("Get requests") != string::npos){
			string agency;

			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');	// Just seek after "Get requests" in stream	
			ci.ignore(std::numeric_limits<std::streamsize>::max(), ' ');	
			
			ci >> agency;
			
			int i = 0;
			for(i = 0; i < agencies.size(); i++){
				if(agencies[i].getName() == agency)
					break;
			}
			if(i == agencies.size()){
				cout << "Agency not found" << endl;
				continue;
			}

			cout << agencies[i].getRequest() << endl;
		}else{
			cout << char(27) << "[0;31m";
			cout << "404 Not Found" << endl;
			cout << char(27) << "[0;0;0m";
		}
	}
}
