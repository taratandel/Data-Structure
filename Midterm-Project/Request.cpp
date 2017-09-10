// In The Name Of God
// ========================================
// * File Name : Request.cpp
// 
// * Creation Date : 08-12-2014
//
// * Last Modified : Tue 09 Dec 2014 05:27:36 AM IRST
//
// * Created By : Tara Tandel (Tara.tandel.94@gmail.com)
// =======================================
#include "Request.h"
#include "Service.h"

#include <ctime>
#include <string>
#include <iostream>

Request::Request(){
	mService = Service();
	mUsername = "";
	mTime = 0;
}

Request::Request(const Service& service, const std::string& username){
	mService = service;
	mUsername = username;
	mTime = time(NULL);
}

Request::Request(const Request& orig){
	mService = orig.mService;
	mUsername = orig.mUsername;
	mTime = orig.mTime;
}

Request& Request::operator=(const Request& orig){
	mService = orig.mService;
	mUsername = orig.mUsername;
	mTime = orig.mTime;
	return *this;
}

bool Request::operator<(const Request& r)const{
	if(mTime < r.mTime)
		return true;
	return false;
}
bool Request::operator>(const Request& r)const{
	if(mTime > r.mTime)
		return true;
	return false;
}
bool Request::operator<=(const Request& r) const{
	if(mTime <= r.mTime)
		return true;
	return false;
}
bool Request::operator>=(const Request& r) const{
	if(mTime <= r.mTime)
		return true;
	return false;
}
bool Request::operator==(const Request& r)const{
	if(mTime == r.mTime)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, const Request& r){
	os << "User: " << r.mUsername << std::endl;
	os << "Time: " << asctime(localtime(&r.mTime));
	os << "Service: " << r.mService.getName();
	return os;
}
