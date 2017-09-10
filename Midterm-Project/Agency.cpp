// In The Name Of God
// ========================================
// * File Name : Agency.c
// 
// * Creation Date : 05-12-2014
//
// * Last Modified : Mon 08 Dec 2014 11:13:17 PM IRST
//
// * Created By : Tara Tandel (Tara.tandel.94@gmail.com)
// =======================================
#include <string>

#include "Request.h"
#include "MaxHeap.h"
#include "Agency.h"

Agency::Agency(std::string name, int id){
	mName = name;
	mId = id;
}

Agency::Agency(){
	mName = "NO_NAME";
	mId = -1;
}

Agency::Agency(const Agency& org){
	mName = org.mName;
	mId = org.mId;
}

std::string Agency::getName() const{
	return mName;
}

void Agency::setName(std::string name){
	mName = name;
}

int Agency::getId() const{
	return mId;
}

void Agency::setId(int id){
	mId = id;
}

bool Agency::operator==(const Agency& agency) const{
	return (mName == agency.mName);
}

Request Agency::getRequest(){
	Request r = mRequest.top();
	mRequest.pop();
	return r;
}

void Agency::addRequest(const Request& request){
	mRequest.push(request);
}


std::ostream& operator <<(std::ostream &os, const Agency &agency){
	os << "Name: " << agency.getName() << ", ID: " << agency.getId();
	return os;
}
