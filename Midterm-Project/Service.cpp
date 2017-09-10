// In The Name Of God
// ========================================
// * File Name : Service.c
// 
// * Creation Date : 05-12-2014
//
// * Last Modified : Tue 09 Dec 2014 02:34:32 PM IRST
//
// * Created By : Tara Tandel (Tara.tandel.94@gmail.com)
// =======================================
#include <string>

#include "Service.h"

Service::Service(std::string name){
	mName = name;
}

Service::Service(){
	mName = "";
}

Service& Service::operator=(const Service& orig){
	mName = orig.mName;
	return *this;
}

std::string Service::getName() const{
	return mName;
}

void Service::setName(std::string name){
	mName = name;
}

std::string Service::getModel() const{
	return mModel;
}

void Service::setModel(std::string model){
	mModel = model;
}

std::string Service::getCostumerComment() const{
	return mCostumerComment;
}

void Service::setCostumerComment(std::string costumerComment){
	mCostumerComment = costumerComment;
}

std::string Service::getTechnicalComment() const{
	return mTechnicalComment;
}

void Service::setTechnicalComment(std::string technicalComment){
	mTechnicalComment = technicalComment;
}

int Service::getRunTime() const{
	return mRunTime;
}

void Service::setRunTime(int runTime){
	mRunTime = runTime;
}

int Service::getCost() const{
	return mCost;
}

void Service::setCost(int cost){
	mCost = cost;
}

bool Service::operator==(const Service& service) const{
	return (getName() == service.getName());
}

Service::~Service(){
}

std::ostream& operator<<(std::ostream& os, const Service& service){
	os << "Service: " << service.getName();
	return os;
}
