#include "Event.h"

Event::Event(EventTypeEnum typeOfEvent)
{
	/*
	Depending on the type of event depends on the different subsystems needed
	*/
	if (typeOfEvent == EventTypeEnum(0)) { // if move event
		this->mySubs.push_back(SubSystemEnum(3));
		this->mySubs.push_back(SubSystemEnum(2));
	}
	else if (typeOfEvent == EventTypeEnum(1)) {
		this->mySubs.push_back(SubSystemEnum(2));
	}
	else if (typeOfEvent == EventTypeEnum(2)) {
		this->mySubs.push_back(SubSystemEnum(1)); 
		this->mySubs.push_back(SubSystemEnum(2));
		this->mySubs.push_back(SubSystemEnum(3));
		//this->mySubs.push_back(SubSystemEnum(4)); 
		this->mySubs.push_back(SubSystemEnum(5));
	}
	else if (typeOfEvent == EventTypeEnum(3)) {
		this->mySubs.push_back(SubSystemEnum(3));
	}
	else if (typeOfEvent == EventTypeEnum(4)) {
		this->mySubs.push_back(SubSystemEnum(3));
	}
	else if (typeOfEvent == EventTypeEnum(5)) {
		this->mySubs.push_back(SubSystemEnum(6));
		this->mySubs.push_back(SubSystemEnum(2));
		this->mySubs.push_back(SubSystemEnum(3));
	}
	functPoint = typeOfEvent;
	
}

Event::~Event()
{
}
