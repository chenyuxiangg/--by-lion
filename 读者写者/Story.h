#ifndef STORY_H
#define STORY_H

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

 typedef struct ItemStory{
 	int data;
 	std::mutex mtx;
 	std::condition_variable enable_write;
 	std::condition_variable enable_read;
 	std::condition_variable ready;
 	bool can_read;
 	bool can_write;
 }ItemStory;
 
 #endif
