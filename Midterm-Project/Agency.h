// In The Name Of God
// ========================================
// * File Name : Agency.h
// 
// * Creation Date : 05-12-2014
//
// * Last Modified : Mon 08 Dec 2014 11:12:05 PM IRST
//
// * Created By : Tara Tandel (Tara.tandel.94@gmail.com)
// =======================================
#pragma once

#include "Request.h"
#include "MaxHeap.h"

#include <string>
#include <iostream>

class Agency{
	private:
		std::string mName;
		int mId;
		MaxHeap<Request> mRequest;
	public:
		Agency(std::string name, int id);
		Agency();
		Agency(const Agency& org);

		std::string getName() const;
		void setName(std::string);
		int getId() const;
		void setId(int id);
		bool operator==(const Agency& agency) const;
		Request getRequest();
		void addRequest(const Request& request);


		friend std::ostream& operator <<(std::ostream &os, const Agency &agency);

};
